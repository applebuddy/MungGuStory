//
//  MunguMonster.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 4..
//
//

#include "MunguMonster.h"
#include "MungGuGame.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
MunguMonster::MunguMonster(int monsterNumber) : isFinishHittedAction(true) , isFinishDiedAction(false)
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

MunguMonster::~MunguMonster()
{


}

void MunguMonster::setHpBar(){
    Rect mungRect = this->getBoundingBox();
    
    mungEnergyBar = Sprite::create("cost_6000.png");//프로그레스바 이미지 생성
    mungEnergyTimer = ProgressTimer::create(mungEnergyBar);//프로그레스바 변수 생성
    mungEnergyTimer->setType(kCCProgressTimerTypeBar);//Bar 타입의 프로그래스바 설정
    mungEnergyTimer->setMidpoint(Point(0,0.5));
    mungEnergyTimer->setAnchorPoint(Point(0.0,0));
    mungEnergyTimer->setScale(0.7);
    mungEnergyTimer->setPosition(Point(mungRect.getMidX()*1.2,mungRect.getMaxY()*4.6));
    this->addChild(mungEnergyTimer,10);}

void MunguMonster::initData()
{
	winSize = Director::getInstance()->getWinSize();//현재 화면의 크기를 가져와 winSize에 정보를 담음
    mySizeDecreaseRate = 0;
}



void MunguMonster::loadMonsterSpriteData()
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	cache->removeSpriteFrames();

	Vector<SpriteFrame *> moveFrames;
	Vector<SpriteFrame *> attackFrames;
	Vector<SpriteFrame *> dieFrames;
    int mungLv = UserDefault::getInstance()->getIntegerForKey("mungLv");
	hp = 120+mungLv*5-5;
	now_hp = hp;
	damageValue = 30+mungLv*3-3;
	attackRangeValue = 5*winSize.width/1200;
	moveVelocity = 45*winSize.width/1200;
    unitSize = 1;
	//기본 이동 액션
	cache->addSpriteFramesWithFile("Mungu.plist");
	for (int i = 0; i<4; i++) {
		char *pString[20] = {};
		sprintf((char *)pString, "Mungu_%d.png", i);
		moveFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
	}

	cache->addSpriteFramesWithFile("Mungu_attack.plist");
	for (int i = 0; i<2; i++){
		char *pString[20] = {};
		sprintf((char *)pString, "Mungu_attack_%d.png", i);
		attackFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
	}


	cache->addSpriteFramesWithFile("mungu_die.plist");
	dieFrames.pushBack(cache->getSpriteFrameByName("mungu_die.png"));

	animation.animate_hit = Animate::create(Animation::createWithSpriteFrames(dieFrames, 10));
	animation.animate_hit->retain();

	animation.moveFrameValue = 1.0 / 3.0f;
	animation.attackFrameValue = 1.0f / 3.0f; //공격 이미지 전환 속도
    if(mungLv>=10){
        animation.attackFrameValue = 1.0f / 4.0f; //공격 이미지 전환 속도
    }
	animation.animate_move = Animate::create(Animation::createWithSpriteFrames(moveFrames, animation.moveFrameValue));
	animation.animate_move->retain();

	animation.attackwaitFrameValue = 3 * animation.attackFrameValue;
	animation.animate_attack = Animate::create(Animation::createWithSpriteFrames(attackFrames, animation.attackFrameValue));
	animation.animate_attack->retain();

	monsterStopImage[0] = cache->getSpriteFrameByName("Mungu_0.png");
    float scaleRate = 1.0*winSize.width/1200+0.013*(float)mungLv-0.013;
	this->setScale(scaleRate);
	cache->removeSpriteFrames();






}

void MunguMonster::monsterAction(int actionNumber)
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

void MunguMonster::deadAction(){//구현중..
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
		//            auto hittedAnimation = Animation::create();
		//            hittedAnimation->addSpriteFrameWithFile("Cat_die.png");//움찔모습이 안나옴..
		//               auto hittedAnimate = Animate::create(hittedAnimation);
		double frameRate = 0.8;
		auto hittedMove = JumpBy::create(0.6*frameRate, Point(-35*winSize.width/1200 * 1.1, 0), 26*winSize.width/1200, 1);
		auto hittedMove2 = JumpBy::create(0.3*frameRate, Point(-20*winSize.width/1200 * 1.1, 0), 20*winSize.width/1200, 1);
		auto hittedMove3 = JumpBy::create(0.2*frameRate, Point(-10*winSize.width/1200 * 1.1, 0), 10*winSize.width/1200, 1);
		FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(MunguMonster::deadAndDisappear)), NULL);
		FiniteTimeAction* pAction2 = Spawn::create(animation.animate_hit, pAction, NULL);
		pAction2->setTag(ACTION_DIE);//뒤로 물러나는 히트백액션
		runAction(pAction2);

    }
}

void MunguMonster::deadAndDisappear(){
	double actionRate = rand()%2+1;
    double moveRate = rand()%35+10;
	auto Action = FadeTo::create(0, 100);
	//  auto Action2 = TintBy::create(0, 5, 5, 50);
	auto Action3 = MoveBy::create(actionRate, Point(0, winSize.height + 10));
	auto Action12 = EaseOut::create(Action3, 1.3);
	FiniteTimeAction* flyAction = Sequence::create(Action, Action12, NULL);

	double rotateRate = rand() % 360 + 100;
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

void MunguMonster::hittedAction(){

    if ((isFinishHittedAction == true)&&(now_hp!=0)){
        isFinishHittedAction = false;
        
		//stopAction();

		auto hittedMove = JumpBy::create(1.3, Point(-40*winSize.width/1200, 0), 35, 1);
		auto hittedMove2 = JumpBy::create(0.8, Point(-25*winSize.width/1200, 0), 20, 1);
		auto hittedMove3 = JumpBy::create(0.3, Point(-10*winSize.width/1200, 0), 10, 1);
		FiniteTimeAction* pAction = Sequence::create(hittedMove, hittedMove2, hittedMove3, CallFunc::create(this, callfunc_selector(MunguMonster::hittedActionFinished)), NULL);
		pAction->setTag(ACTION_HITTED);//뒤로 물러나는 히트백액션
		runAction(pAction);
	}
}


void MunguMonster::stopAction() {//게임신에서 멈춤 지시가 오면
	// if(isFinishAttackAction == true){
	stopAllActions();
	isCallStopAction = true; //멈춤 지시 했음
	isFinishMoveAction = true;//움직임 액션 끝냇음
	//isFinishAttackAction = false;
	//  }
}

void MunguMonster::moveAction() {
		if ((isFinishMoveAction == true)&&(isFinishHittedAction == true)){//움직임 액션이 끝났으면 움직임 액션 진행

            
		isFinishMoveAction = false;
		FiniteTimeAction* moveAction = Sequence::create(animation.animate_move, CallFunc::create(this, callfunc_selector(MunguMonster::moveActionFinished)), NULL);//
		FiniteTimeAction* moveDistance = Sequence::create(MoveTo::create(animation.moveFrameValue * 4, Point(getPositionX() + moveVelocity * 1, getPositionY())), NULL);
		FiniteTimeAction* pAction = Spawn::create(moveAction, moveDistance, NULL);
		pAction->setTag(ACTION_MOVE);
		runAction(pAction);

	}
}



void MunguMonster::attackAction(){
if ((isFinishAttackAction == true)&&(isFinishHittedAction == true)) {
		isFinishAttackAction = false;

    if(isFinishMoveAction==false){
        isFinishMoveAction=true;
        stopAction();
    }
		auto act00 = DelayTime::create(0.3);
		auto act1 = Sequence::create(act00, CallFunc::create(this, callfunc_selector(MunguMonster::isAttackEffect)), NULL);
		FiniteTimeAction* attackAction = Sequence::create(animation.animate_attack, CallFunc::create(this, callfunc_selector(MunguMonster::attackActionFinished)), NULL);

		auto act2 = Spawn::create(act1, attackAction, NULL);
		auto act3 = DelayTime::create(0.3);
		auto action = Sequence::create(act2, act3, NULL);

		runAction(action);
		action->setTag(ACTION_ATTACK);


	}
}



//
//
//void MunguMonster::initAttackEffect2(){
//    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");
//    
//    attackEffect2 = Sprite::createWithSpriteFrameName("attackEffect_0.png");
//    
//    attackEffect2->setPosition(Point(winSize.width/2,winSize.height/2));
//    
//    attackEffect2->setAnchorPoint(Point(0.5,0.5));
//    //attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
//    this->addChild(attackEffect2,5);
//    
//    auto animation = Animation::create();
//    animation->setDelayPerUnit(0.06);
//    
//    for (int i = 0; i<6; i++) {
//        auto attackEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
//        animation->addSpriteFrame(attackEffect);
//    }
//    
//    auto attackEffectAnimate = Animate::create(animation);
//    attackEffect2->runAction(attackEffectAnimate);
//    
//}


void MunguMonster::isAttackEffect(){
	MungGuGame::getInstance()->catSiteHitted(this);
	//if (MungGuGame::getInstance()->isNotSongBtnTouched == false){
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
//}

void MunguMonster::moveActionFinished() {

	isFinishMoveAction = true;
}
void MunguMonster::attackActionFinished(){

	isFinishAttackAction = true;
}
void MunguMonster::hittedActionFinished(){
    isFinishHittedAction = true;
  

}
void MunguMonster::update(float dt) {
	//srand((unsigned int)time(NULL));
    mungEnergyTimer->setPercentage(100.0f*(now_hp/hp));
    
    if ((now_hp <= 0)){
        isMyDie = true;
        deadAction();
    }
}
