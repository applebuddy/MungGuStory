
//  Created by Kyeongtae Min on 2014. 10. 17..
//
//

#include "MungSausage.h"
#include "MungGuGame.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
MungSausage::MungSausage(int monsterNumber)
{
    
    isMultiAttack = true;
    winSize = Director::getInstance()->getWinSize();
    loadMonsterSpriteData();
    number = monsterNumber;
    SpriteFrame *spFrame = monsterStopImage[0];
    initWithSpriteFrame(spFrame);
    setHpBar();
    autorelease();
    
    
    this->scheduleUpdate();
    
}

void MungSausage::setHpBar(){
    Rect mungRect = this->getBoundingBox();
    
    mungEnergyBar = Sprite::create("cost_6000.png");//프로그레스바 이미지 생성
    mungEnergyTimer = ProgressTimer::create(mungEnergyBar);//프로그레스바 변수 생성
    mungEnergyTimer->setType(kCCProgressTimerTypeBar);//Bar 타입의 프로그래스바 설정
    mungEnergyTimer->setMidpoint(Point(0,0.5));
    mungEnergyTimer->setScale(1);
    mungEnergyTimer->setAnchorPoint(Point(0.27,0));
    mungEnergyTimer->setPosition(Point(mungRect.getMaxX(),mungRect.getMaxY()*3.3));
    this->addChild(mungEnergyTimer,10);
}

MungSausage::~MungSausage()
{
    
    
    
    
}

void MungSausage::loadMonsterSpriteData()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFrames();
    
    Vector<SpriteFrame *> moveFrames;
    Vector<SpriteFrame *> attackFrames;
    int mungSausageLv = UserDefault::getInstance()->getIntegerForKey("mungSausageLv");
    hp = 360+mungSausageLv*25-25;
    now_hp = hp;
    damageValue = 30+mungSausageLv*1;//30
    moveVelocity = 36*winSize.width/1200;//60
    attackRangeValue = 20*winSize.width/1200;
    mySizeDecreaseRate = 30*winSize.width/1200;
    unitSize = 3;
    //기본 이동 액션
    cache->addSpriteFramesWithFile("mungSausage.plist");
    for (int i = 0; i<7; i++) {
        char *pString[20] = {};
        sprintf((char *)pString, "mungSausage_%d.png", i);
        moveFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    }
    
    cache->addSpriteFramesWithFile("mungSausage_attack.plist");
    for (int i = 0; i<8; i++){
        char *pString[20] = {};
        sprintf((char *)pString, "mungSausage_attack_%d.png", i);
        attackFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    }
    
    
    Vector<SpriteFrame *> dieFrames;
    cache->addSpriteFramesWithFile("mungSausage_die.plist");
    dieFrames.pushBack(cache->getSpriteFrameByName("mungSausage_die.png"));
    
    animation.animate_hit = Animate::create(Animation::createWithSpriteFrames(dieFrames, 10));
    animation.animate_hit->retain();
    
    animation.moveFrameValue = 1.0 / 6.0f;
    animation.attackFrameValue = 1.0f / 12.0f; //공격 이미지 전환 속도
    if(mungSausageLv>=10){
        animation.attackFrameValue = 1.0f / 13.0f;
    }
    animation.animate_move = Animate::create(Animation::createWithSpriteFrames(moveFrames, animation.moveFrameValue));
    animation.animate_move->retain();
    
    //animation.attackwaitFrameValue =  0*animation.attackFrameValue;
    animation.animate_attack = Animate::create(Animation::createWithSpriteFrames(attackFrames, animation.attackFrameValue));
    animation.animate_attack->retain();
    
    monsterStopImage[0] = cache->getSpriteFrameByName("mungSausage_0.png");
    
    scaleRate = 0.86*winSize.width/1200+0.005*(float)mungSausageLv-0.005;
    this->setScale(scaleRate);
    cache->removeSpriteFrames();
    
    
    
    
    
    
}

void MungSausage::monsterAction(int actionNumber)
{
    switch (actionNumber) {
        case ACTION_MOVE:
            moveAction();//움직이는 액션
            break;
        case ACTION_STOP:
            stopAction();//멈춤 액션
            break;
        case ACTION_ATTACK:
            attackAction();
            break;
        case ACTION_HITTED:
            hittedAction();
            break;
        case ACTION_DIE:
            deadAction();
            break;
            
    }
}

void MungSausage::deadAction(){//구현중..
    if (isFinishDiedAction == false){
        isFinishDiedAction = true;
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
            int dogDead =
            SimpleAudioEngine::getInstance()->playEffect("dogDead.wav");
        }
        
        isFinishMoveAction = false;
        isFinishAttackAction = false;
        stopAllActions();
        double frameRate = 0.8;
        auto hittedMove = JumpBy::create(0.8*frameRate, Point(-30*winSize.width/1200 * 1.1, 0), 35*winSize.width/1200, 1);
        auto hittedMove2 = JumpBy::create(0.5*frameRate, Point(-22*winSize.width/1200 * 1.1, 0), 20*winSize.width/1200, 1);
        auto hittedMove3 = JumpBy::create(0.3*frameRate, Point(-10*winSize.width/1200 * 1.1, 0), 10*winSize.width/1200, 1);
        FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(MungSausage::deadAndDisappear)), NULL);
        FiniteTimeAction* pAction2 = Spawn::create(animation.animate_hit, pAction, NULL);
        pAction2->setTag(ACTION_DIE);//뒤로 물러나는 히트백액션
        runAction(pAction2);
    }
    
}

void MungSausage::deadAndDisappear(){
    double actionRate = rand()%2+1;
    double moveRate = rand()%35+5;
    auto Action = FadeTo::create(0, 100);
    //  auto Action2 = TintBy::create(0, 5, 5, 50);
    auto Action3 = MoveBy::create(actionRate, Point(0, winSize.height + 10));
    auto Action12 = EaseOut::create(Action3, 1.3);
    FiniteTimeAction* flyAction = Sequence::create(Action, Action12, NULL);
    
    //srand((unsigned int)time(NULL));
    double rotateRate = rand() % 360 + 30;
    int setRotateDir = rand() % 2;
    if (setRotateDir == 0){
        //rotateRate *= 1;
    }
    else{
        rotateRate *= -1;
    }
    auto rotateAction0 = RotateBy::create(actionRate, rotateRate);
    auto rotateAction = EaseOut::create(rotateAction0, 1.3);
    
    auto Action4 = MoveBy::create(actionRate / 8.0, Point(moveRate, 0));
    auto Action5 = MoveBy::create(actionRate / 8.0, Point(-moveRate, 0));
    auto Action6 = MoveBy::create(actionRate / 8.0, Point(-moveRate, 0));
    auto Action7 = MoveBy::create(actionRate / 8.0, Point(moveRate, 0));
    auto Action8 = MoveBy::create(actionRate / 8.0, Point(moveRate + moveRate / 4.0, 0));
    auto Action9 = MoveBy::create(actionRate / 8.0, Point(-moveRate + moveRate / 4.0, 0));
    auto Action10 = MoveBy::create(actionRate / 8.0, Point(-moveRate + moveRate / 4.0, 0));
    auto Action11 = MoveBy::create(actionRate / 8.0, Point(moveRate + moveRate / 4.0, 0));
    auto flyAction02 = Sequence::create(Action4, Action5, Action6, Action7, Action8, Action9, Action10, Action11, NULL);
    auto flyAction2 = EaseOut::create(flyAction02,1.3);
    
    FiniteTimeAction* flyAnimate = Spawn::create(flyAction, flyAction2, rotateAction, NULL);
    runAction(flyAnimate);
    // this->setVisible(false);
    this->removeChild(this, true);
}

void MungSausage::hittedAction(){
    
    if ((isFinishHittedAction == true)&&(now_hp!=0)){
        isFinishHittedAction = false;
        
        
        auto hittedMove = JumpBy::create(0.6, Point(-35*winSize.width/1200, 0), 35, 1);
        auto hittedMove2 = JumpBy::create(0.3, Point(-20*winSize.width/1200, 0), 20, 1);
        auto hittedMove3 = JumpBy::create(0.2, Point(-10*winSize.width/1200, 0), 10, 1);
        FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(MungSausage::hittedActionFinished)), NULL);
        pAction->setTag(ACTION_HITTED);//뒤로 물러나는 히트백액션
        runAction(pAction);
    }
}



void MungSausage::stopAction() {//게임신에서 멈춤 지시가 오면
    // if(isFinishAttackAction == true){
    stopAllActions();
    isCallStopAction = true; //멈춤 지시 했음
    isFinishMoveAction = true;//움직임 액션 끝냇음
    //isFinishAttackAction = false;
    //  }
}

void MungSausage::moveAction() {
    if ((isFinishMoveAction == true)&&(isFinishHittedAction == true)){//움직임 액션이 끝났으면 움직임 액션 진행
        isFinishMoveAction = false;
        
        
        FiniteTimeAction* moveAction = Sequence::create(animation.animate_move, CallFunc::create(this, callfunc_selector(MungSausage::moveActionFinished)), NULL);//
        FiniteTimeAction* moveDistance = Sequence::create(MoveTo::create(animation.moveFrameValue * 7, Point(getPositionX() + moveVelocity * 1, getPositionY())), NULL);
        FiniteTimeAction* pAction = Spawn::create(moveAction, moveDistance, NULL);
        pAction->setTag(ACTION_MOVE);
        runAction(pAction);
        
    }
}

void MungSausage::attackAction(){
    if ((isFinishAttackAction == true)&&(isFinishHittedAction == true)) {
        isFinishAttackAction = false;
        
        if(isFinishMoveAction==false){
            isFinishMoveAction=true;
            stopAction();
        }
        
        auto act00 = DelayTime::create(animation.attackFrameValue * 1);
        auto act0 = DelayTime::create(animation.attackFrameValue * 4);
        auto act1 = Sequence::create(act00, CallFunc::create(this, callfunc_selector(MungSausage::isAttackEffect)), act0, CallFunc::create(this, callfunc_selector(MungSausage::isAttackEffect)), NULL);
        FiniteTimeAction* attackAction = Sequence::create(animation.animate_attack, CallFunc::create(this, callfunc_selector(MungSausage::attackActionFinished)), NULL);
        
        auto act2 = Spawn::create(act1, attackAction, NULL);
        auto act3 = DelayTime::create(0.15);
        auto action = Sequence::create(act2, act3, NULL);
        
        runAction(action);
        action->setTag(ACTION_ATTACK);
        
    }
    
}

void MungSausage::isAttackEffect(){
    MungGuGame::getInstance()->catSiteHitted(this);
    if ((MungGuGame::getInstance()->isFirstStageLoser == true) ||
        (MungGuGame::getInstance()->isFirstStageClear == true)){
        
    }
    else{
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
            int BiteSound =
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("slapAttack.wav");
        }
    }
}

void MungSausage::moveActionFinished() {
    
    isFinishMoveAction = true;
}
void MungSausage::attackActionFinished(){
    //MungGuGame::getInstance()->initAttackEffect(this);
    //MungGuGame::getInstance()->catSiteHitted(this);
    isFinishAttackAction = true;
}
void MungSausage::hittedActionFinished(){
    isFinishHittedAction = true;
    
}


void MungSausage::update(float dt) {
    mungEnergyTimer->setPercentage(100.0f*(now_hp/hp));
    
    if ((now_hp <= 0)){
        isMyDie = true;
        deadAction();
    }
    // srand((unsigned int)time(NULL));
}
