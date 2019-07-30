//
//  MunguMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 4..
//
//

#ifndef __MungGu__MunguMonster__
#define __MungGu__MunguMonster__

#include "Monster.h"
class MunguMonster : public Monster
{
public:

	BasicAnimation animation;
	Size winSize;

	MunguMonster(int monsterNumber);
	~MunguMonster();

	SpriteFrame *spFrame;
    
    void setHpBar();

	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);

	void isAttackEffect();
	void initAttackEffect2();
	Sprite* attackEffect2;

	void deadAndDisappear();
	void hittedAction();
	void deadAction();
    
	bool isFinishHittedAction;
    bool isFinishDiedAction;
	void hittedActionFinished();

	void initData();
	void moveAction();
	void attackAction();

	void moveActionFinished();
	void attackActionFinished();
	void stopAction();
	bool isCallStopAction;
	void update(float dt);
};


#endif /* defined(__MungCo__MunguMonster__) */
