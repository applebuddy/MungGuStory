//
//  CatBossMonster.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//
//

#include "CatMonster.h"
#include "MungGuGame.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;


CatMonster::CatMonster(int monsterNumber) : isFinishHittedAction(true)
{
    isMultiAttack = false;
	initData();
	loadMonsterSpriteData();
	number = monsterNumber;
	SpriteFrame *spFrame = monsterStopImage[0];
	initWithSpriteFrame(spFrame);
    setHpBar();
	autorelease();


	this->scheduleUpdate();

}
CatMonster::~CatMonster()
{


}

void CatMonster::initData()
{
	winSize = Director::getInstance()->getWinSize();//현재 화면의 크기를 가져와 winSize에 정보를 담음
	isEnemyAngryed = false;
    enemySizeDecreaseRate = 5*winSize.width/1200;
}


void CatMonster::loadMonsterSpriteData()
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->removeSpriteFrames();

	Vector<SpriteFrame *> moveFrames;
	Vector<SpriteFrame *> attackFrames;
	Vector<SpriteFrame *> dieFrames;
	hp = 130;
	now_hp = hp;
	damageValue = 35;//30
	attackRangeValue = 5*winSize.width/1200;
	moveVelocity = 50*winSize.width/1200;//30
	dieMoney = 30;
unitSize = 1;
	//기본 이동 액션
	cache->addSpriteFramesWithFile("catBaby.plist");
	for (int i = 0; i<4; i++) {
		char *pString[20] = {};
		sprintf((char *)pString, "catBaby_%d.png", i);
		moveFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
	}

	cache->addSpriteFramesWithFile("catBaby_attack.plist");
	for (int i = 0; i<4; i++){
		char *pString[20] = {};
		sprintf((char *)pString, "catBaby_attack_%d.png", i);
		attackFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
	}

	cache->addSpriteFramesWithFile("catBaby_die.plist");
	dieFrames.pushBack(cache->getSpriteFrameByName("catBaby_die.png"));


	animation.moveFrameValue = 1.0 / 3.0f;
	animation.attackFrameValue = 1.0f / 5.5f; //공격 이미지 전환 속도
	animation.animate_move = Animate::create(Animation::createWithSpriteFrames(moveFrames, animation.moveFrameValue));
	animation.animate_move->retain();

	animation.attackwaitFrameValue = 3 * animation.attackFrameValue;
	animation.animate_attack = Animate::create(Animation::createWithSpriteFrames(attackFrames, animation.attackFrameValue));
	animation.animate_attack->retain();

	monsterStopImage[0] = cache->getSpriteFrameByName("catBaby_0.png");

	animation.animate_hit = Animate::create(Animation::createWithSpriteFrames(dieFrames, 10));
	animation.animate_hit->retain();

	//monsterDeadImage[0] = cache->getSpriteFrameByName("CatBaby_die.png");
    scaleRate = 1.2*winSize.width/1200;
	this->setScale(scaleRate);
	cache->removeSpriteFrames();






}

void CatMonster::monsterAction(int actionNumber)
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
	case ACTION_DIE:
		deadAction();
		break;
	case ACTION_HITTED:
		hittedAction();
		break;
        case ACTION_ANGRY:
            angryAction();
            break;
	}
}

void CatMonster::setHpBar(){
    Rect mungRect = this->getBoundingBox();
    
    catEnergyBar = Sprite::create("cost_6000.png");//프로그레스바 이미지 생성
    catEnergyTimer = ProgressTimer::create(catEnergyBar);//프로그레스바 변수 생성
    catEnergyTimer->setType(kCCProgressTimerTypeBar);//Bar 타입의 프로그래스바 설정
    catEnergyTimer->setMidpoint(Point(0,0.5));
    catEnergyTimer->setAnchorPoint(Point(0.5,0));
    
    catEnergyTimer->setScale(0.73);
    catEnergyTimer->setPosition(Point(mungRect.getMaxX(),mungRect.getMaxY()*3));
    this->addChild(catEnergyTimer,10);
}

void CatMonster::angryAction(){
	auto act0 = ScaleBy::create(0, 1.2); //구현중
	auto act = Sequence::create(CallFunc::create(this, callfunc_selector(CatMonster::angryEffect)), act0, NULL);
	act->setTag(ACTION_ANGRY);
	runAction(act);

}

void CatMonster::angryEffect(){//구현중
	//this->setScale(2.0);
	this->hp = hp*1.3;
	this->now_hp = hp;
	this->damageValue = damageValue*1.5;
}

void CatMonster::deadAction(){//구현중..
	if (isFinishHittedAction == true){
		isFinishHittedAction = false;
         stopAllActions();
        isFinishMoveAction = false;
        isFinishAttackAction = false;
       
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
		int catDead =
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("catDead.wav");
        }
		
		double frameRate = 0.8;

		auto hittedMove = JumpBy::create(0.8*frameRate, Point(50*winSize.width/1200 * 1.2, 0), 50, 1);
		auto hittedMove2 = JumpBy::create(0.5*frameRate, Point(25*winSize.width/1200 * 1.2, 0), 25, 1);
		auto hittedMove3 = JumpBy::create(0.3*frameRate, Point(15*winSize.width/1200 * 1.2, 0), 15, 1);
		FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(CatMonster::deadAndDisappear)), NULL);

		FiniteTimeAction* pAction2 = Spawn::create(animation.animate_hit, pAction, NULL);
		pAction2->setTag(ACTION_DIE);//뒤로 물러나는 히트백액션
		runAction(pAction2);
	}

}

void CatMonster::deadAndDisappear(){

	if ((MungGuGame::getInstance()->myMoney += dieMoney)< MungGuGame::getInstance()->maxMoney){
		MungGuGame::getInstance()->myMoney += dieMoney;
	}
	else{
		MungGuGame::getInstance()->myMoney = MungGuGame::getInstance()->maxMoney;
	}
    double actionRate = rand()%2+1;
    double moveRate = rand()%35+10;
	double rotateRate = rand() % 360 + 60;
	int setRotateDir = rand() % 2;
	if (setRotateDir == 0){
		//rotateRate *= 1;
	}
	else{
		rotateRate *= -1;
	}
	auto rotateAction0 = RotateBy::create(1.3, rotateRate);
	auto rotateAction = EaseOut::create(rotateAction0, 1.3);

	auto Action = FadeTo::create(0, 100);
	//  auto Action2 = TintBy::create(0, 5, 5, 50);
	auto Action3 = MoveBy::create(1.3, Point(0, winSize.height + 10));
	auto Action12 = EaseOut::create(Action3, 1.3);
	FiniteTimeAction* flyAction = Sequence::create(Action, Action12, NULL);

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

void CatMonster::hittedAction(){
	//    SpriteFrame *spFrame = monsterDeadImage[0];
	//    initWithSpriteFrame(spFrame);
	//    autorelease();

    
    if ((isFinishHittedAction == true)&&(now_hp!=0)){
		isFinishHittedAction = false;

        
		auto hittedMove = JumpBy::create(0.8, Point(50, 0), 50, 1);
		auto hittedMove2 = JumpBy::create(0.5, Point(25, 0), 25, 1);
		auto hittedMove3 = JumpBy::create(0.3, Point(15, 0), 15, 1);
		FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(CatMonster::hittedActionFinished)), NULL);
		pAction->setTag(ACTION_HITTED);//뒤로 물러나는 히트백액션
		runAction(pAction);
	}
}

void CatMonster::stopAction() {//게임신에서 멈춤 지시가 오면
	// if(isFinishAttackAction == true){
	stopAllActions();
	isCallStopAction = true; //멈춤 지시 했음
	isFinishMoveAction = true;//움직임 액션 끝냇음
	//isFinishAttackAction = false;
	//  }
}

void CatMonster::moveAction() {
	if ((isFinishMoveAction == true) && (isFinishHittedAction == true)){//움직임 액션이 끝났으면 움직임 액션 진행

		isFinishMoveAction = false;
		FiniteTimeAction* moveAction = Sequence::create(animation.animate_move, CallFunc::create(this, callfunc_selector(CatMonster::moveActionFinished)), NULL);//
		FiniteTimeAction* moveDistance = Sequence::create(MoveTo::create(animation.moveFrameValue * 4.3, Point(getPositionX() + moveVelocity * -1, getPositionY())), NULL);
		FiniteTimeAction* pAction = Spawn::create(moveAction, moveDistance, NULL);
		pAction->setTag(ACTION_MOVE);
		runAction(pAction);

	}
}



void CatMonster::attackAction(){
	if ((isFinishAttackAction == true) && (isFinishHittedAction == true)) {
		isFinishAttackAction = false;
      //  if(isFinishMoveAction == false){
        //    stopAllActions();
            
       // }

                if(isFinishMoveAction==false){
                    isFinishMoveAction=true;
                    stopAction();
                }

		auto act00 = DelayTime::create(animation.attackFrameValue * 3);
		auto act1 = Sequence::create(act00, CallFunc::create(this, callfunc_selector(CatMonster::isAttackEffect)), NULL);
		FiniteTimeAction* attackAction = Sequence::create(animation.animate_attack, CallFunc::create(this, callfunc_selector(CatMonster::attackActionFinished)), NULL);

		auto act2 = Spawn::create(act1, attackAction, NULL);
		auto act3 = DelayTime::create(0.2);
		auto action = Sequence::create(act2, act3, NULL);

		runAction(action);
		action->setTag(ACTION_ATTACK);
	}





}

void CatMonster::isAttackEffect(){
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

void CatMonster::moveActionFinished() {

	isFinishMoveAction = true;
}
void CatMonster::attackActionFinished(){

	if (now_hp == 0){
		deadAction();
	}
	else{
	}
	isFinishAttackAction = true;
}
void CatMonster::hittedActionFinished(){
	if (now_hp == 0){
		deadAction();
	}
	else{
	}
	isFinishHittedAction = true;
}
void CatMonster::update(float dt) {
	//srand((unsigned int)time(NULL));
    catEnergyTimer->setPercentage(100.0f*(now_hp/hp));
    
	if (now_hp <= 0){
        isEnemyDie = true;
		deadAction();
	}

}
