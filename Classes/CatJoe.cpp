//
//  CatJoe.cpp
//  mungGu
//
//  Created by Kyeongtae Min on 2015. 2. 4..
//
//

#include "CatJoe.h"
#include "MungGuGame.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;

//
//  CatBossMonster.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//




CatJoe::CatJoe(int monsterNumber)
{
    
    initData();
    loadMonsterSpriteData();
    number = monsterNumber;
    SpriteFrame *spFrame = monsterStopImage[0];
    //SpriteFrame *spFrame2 = monsterDeadImage[0];//죽을때 이미지
    initWithSpriteFrame(spFrame);
    setHpBar();
    autorelease();
    
    
    this->scheduleUpdate();
    
}
CatJoe::~CatJoe()
{
    
    
}

void CatJoe::initData()
{
    winSize = Director::getInstance()->getWinSize();//현재 화면의 크기를 가져와 winSize에 정보를 담음
    isEnemyAngryed = false;
    isMultiAttack = true;
    enemySizeDecreaseRate = 55*winSize.width/1200;
}


void CatJoe::loadMonsterSpriteData()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFrames();
    
    Vector<SpriteFrame *> moveFrames;
    Vector<SpriteFrame *> attackFrames;
    Vector<SpriteFrame *> dieFrames;
    Vector<SpriteFrame *> waitFrames;
    
    
    hp = 1630;
    now_hp = hp;
    damageValue = 160;
    attackRangeValue = 55*winSize.width/1200;
    moveVelocity = 16*winSize.width/1200;
    dieMoney = 260;
    
    isStrongAboutSmall=false;
    isStrongAboutBig=true;//큰 상대할테 세다.
    unitSize = 2;
    //기본 이동 액션
    cache->addSpriteFramesWithFile("CatHair.plist");
    for (int i = 0; i<4; i++) {
        char *pString[20] = {};
        sprintf((char *)pString, "CatHair_%d.png", i);
        moveFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    }
    
    cache->addSpriteFramesWithFile("CatHair_attack.plist");
    for (int i = 0; i<7; i++){
        char *pString[20] = {};
        sprintf((char *)pString, "CatHair_attack_%d.png", i);
        attackFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    }
    
    cache->addSpriteFramesWithFile("CatHair_die.plist");
    dieFrames.pushBack(cache->getSpriteFrameByName("CatHair_die.png"));
    
    animation.animate_hit = Animate::create(Animation::createWithSpriteFrames(dieFrames, 10));
    animation.animate_hit->retain();
    
    animation.moveFrameValue = 1.0 / 5.0f;
    animation.attackFrameValue = 1.0f / 16.0f; //공격 이미지 전환 속도
    animation.waitFrameValue = 2.3f;
    animation.animate_move = Animate::create(Animation::createWithSpriteFrames(moveFrames, animation.moveFrameValue));
    animation.animate_move->retain();
    
    animation.attackwaitFrameValue = 3 * animation.attackFrameValue;
    animation.animate_attack = Animate::create(Animation::createWithSpriteFrames(attackFrames, animation.attackFrameValue));
    animation.animate_attack->retain();
    
    
    char *pString[20] = {};
    sprintf((char *)pString, "CatHair_attack_%d.png", 0);
    waitFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    
    animation.attackwaitFrameValue = 3 * animation.attackFrameValue;
    animation.animate_attack = Animate::create(Animation::createWithSpriteFrames(attackFrames, animation.attackFrameValue));
    animation.animate_attack->retain();
    
    animation.animate_wait = Animate::create(Animation::createWithSpriteFrames(waitFrames,animation.waitFrameValue));
    animation.animate_wait->retain();
    
    
    monsterStopImage[0] = cache->getSpriteFrameByName("CatHair_0.png");
    //monsterDeadImage[0] = cache->getSpriteFrameByName("Cat_die.png");
    scaleRate = 2.2*winSize.width/1200;
    this->setScale(scaleRate);
    cache->removeSpriteFrames();
    
    
    
    
    
    
}

void CatJoe::monsterAction(int actionNumber)
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
        case ACTION_ANGRY:
            angryAction();
            break;
            
    }
}


void CatJoe::setHpBar(){
    Rect mungRect = this->getBoundingBox();
    
    catEnergyBar = Sprite::create("cost_6000.png");//프로그레스바 이미지 생성
    catEnergyTimer = ProgressTimer::create(catEnergyBar);//프로그레스바 변수 생성
    catEnergyTimer->setType(kCCProgressTimerTypeBar);//Bar 타입의 프로그래스바 설정
    catEnergyTimer->setMidpoint(Point(0,0.5));
    catEnergyTimer->setAnchorPoint(Point(0.5,0));
    catEnergyTimer->setScale(0.6);
    catEnergyTimer->setPosition(Point(mungRect.getMaxX(),mungRect.getMaxY()*1.3));
    this->addChild(catEnergyTimer,10);
}

void CatJoe::deadAction(){//구현중..
    
    if (isFinishHittedAction == true){
        isFinishHittedAction = false;
        // stopAction();
        stopAllActions();
        isFinishMoveAction = false;
        isFinishAttackAction = false;
        
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
            int catDead =
            SimpleAudioEngine::getInstance()->playEffect("catJoeDied.wav");
        }
        
        
        //            auto hittedAnimation = Animation::create();
        //            hittedAnimation->addSpriteFrameWithFile("Cat_die.png");//움찔모습이 안나옴..
        //               auto hittedAnimate = Animate::create(hittedAnimation);
        double frameRate = 0.5;
        auto hittedMove = JumpBy::create(0.36*frameRate, Point(17 * 1.1, 0), 35, 1);
        auto hittedMove2 = JumpBy::create(0.16*frameRate, Point(10 * 1.1, 0), 20, 1);
        auto hittedMove3 = JumpBy::create(0.1*frameRate, Point(3 * 1.1, 0), 10, 1);
        FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(CatJoe::deadAndDisappear)), NULL);
        FiniteTimeAction* pAction2 = Spawn::create(animation.animate_hit, pAction, NULL);
        pAction2->setTag(ACTION_DIE);//뒤로 물러나는 히트백액션
        runAction(pAction2);
    }
}

void CatJoe::angryAction(){
    auto act0 = ScaleBy::create(0, 1.2); //구현중
    auto act = Sequence::create(CallFunc::create(this, callfunc_selector(CatJoe::angryEffect)), act0, NULL);
    act->setTag(ACTION_ANGRY);
    runAction(act);
    
}

void CatJoe::angryEffect(){//구현중
    //this->setScale(2.0);
    this->hp = hp*1.3;
    this->now_hp = hp;
    this->damageValue = damageValue*1.5;
}

void CatJoe::deadAndDisappear(){
    
    if ((MungGuGame::getInstance()->myMoney += dieMoney)< MungGuGame::getInstance()->maxMoney){
        MungGuGame::getInstance()->myMoney += dieMoney;
    }
    else{
        MungGuGame::getInstance()->myMoney = MungGuGame::getInstance()->maxMoney;
    }
    double actionRate = rand()%2+1;
    double moveRate = rand()%25+5;
    auto Action = FadeTo::create(0, 100);
    //  auto Action2 = TintBy::create(0, 5, 5, 50);
    auto Action3 = MoveBy::create(actionRate, Point(0, winSize.height + 10));
    auto Action12 = EaseOut::create(Action3, 1.3);
    FiniteTimeAction* flyAction = Sequence::create(Action, Action12, NULL);
    
    
    double rotateRate = rand() % 720 + 30;
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
    // auto flyAction2 = EaseOut::create(flyAction2_0,1.3);
    
    FiniteTimeAction* flyAnimate = Spawn::create(flyAction, flyAction2, rotateAction, NULL);
    runAction(flyAnimate);
    //this->setVisible(false);
    this->removeChild(this, true);
}


void CatJoe::hittedAction(){
    
    if ((isFinishHittedAction == true)&&(now_hp!=0)){
        isFinishHittedAction = false;
        
        
        auto hittedMove = JumpBy::create(0.5, Point(20*winSize.width/1200, 0), 35, 1);
        auto hittedMove2 = JumpBy::create(0.2, Point(10*winSize.width/1200, 0), 20, 1);
        auto hittedMove3 = JumpBy::create(0.1, Point(5*winSize.width/1200, 0), 10, 1);
        FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(CatJoe::hittedActionFinished)), NULL);
        pAction->setTag(ACTION_HITTED);//뒤로 물러나는 히트백액션
        runAction(pAction);
    }
}


void CatJoe::stopAction() {//게임신에서 멈춤 지시가 오면
    // if(isFinishAttackAction == true){
    stopAllActions();
    isCallStopAction = true; //멈춤 지시 했음
    isFinishMoveAction = true;//움직임 액션 끝냇음
    //isFinishAttackAction = false;
    //  }
}

void CatJoe::moveAction() {
    if ((isFinishMoveAction == true) && (isFinishHittedAction == true)){//움직임 액션이 끝났으면 움직임 액션 진행
        
        isFinishMoveAction = false;
        FiniteTimeAction* moveAction = Sequence::create(animation.animate_move, CallFunc::create(this, callfunc_selector(CatJoe::moveActionFinished)), NULL);//
        FiniteTimeAction* moveDistance = Sequence::create(MoveTo::create(animation.moveFrameValue * 4, Point(getPositionX() - moveVelocity * 1, getPositionY())), NULL);
        FiniteTimeAction* pAction = Spawn::create(moveAction, moveDistance, NULL);
        pAction->setTag(ACTION_MOVE);
        runAction(pAction);
        
    }
}

void CatJoe::attackAction(){
    if ((isFinishAttackAction == true) && (isFinishHittedAction == true)) {
        isFinishAttackAction = false;
        //   if(isFinishMoveAction == false){
        //      stopAllActions();
        //  }
        
        if(isFinishMoveAction==false){
            isFinishMoveAction=true;
            stopAction();
        }
        
        auto act00 = DelayTime::create(animation.attackFrameValue * 5);
        auto act1 = Sequence::create(act00, CallFunc::create(this, callfunc_selector(CatJoe::isAttackEffect)), NULL);
        FiniteTimeAction* attackAction = Sequence::create(animation.animate_attack,animation.animate_wait, CallFunc::create(this, callfunc_selector(CatJoe::attackActionFinished)), NULL);
        
        auto act2 = Spawn::create(act1, attackAction, NULL);
        runAction(act2);
        act2->setTag(ACTION_ATTACK);
    }
    
    
    
    
    
}

void CatJoe::isAttackEffect(){
    MungGuGame::getInstance()->dogSiteHitted(this);
    if ((MungGuGame::getInstance()->isFirstStageLoser == true) ||
        (MungGuGame::getInstance()->isFirstStageClear == true)){
        
    }
    else{
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
            int BiteSound =
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Bite.wav");
        }
    }
}

void CatJoe::moveActionFinished() {
    
    isFinishMoveAction = true;
}
void CatJoe::attackActionFinished(){
    
    isFinishAttackAction = true;
}
void CatJoe::hittedActionFinished(){
    
    isFinishHittedAction = true;
}
void CatJoe::update(float dt) {
    //srand((unsigned int)time(NULL));
    
    catEnergyTimer->setPercentage(100.0f*(now_hp/hp));
    
    if (now_hp <= 0){
        isEnemyDie = true;
        deadAction();
    }
    
}
