//
//  CatMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//
//

#ifndef __MungCo__CatMonster__
#define __MungCo__CatMonster__

#include "EnemyMonster.h"

class CatMonster : public EnemyMonster
{
public:

	BasicAnimation animation;
	Size winSize;

	CatMonster(int monsterNumber);
	~CatMonster();

	SpriteFrame *spFrame;

    virtual void setHpBar();
    
	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);
	void angryAction();
	void angryEffect();
	void isAttackEffect();
	void deadAndDisappear();
	void initAttackEffect2();
	Sprite* attackEffect2;
	void initData();
	void moveAction();
	void attackAction();

	bool isFinishHittedAction;
	void hittedActionFinished();
	void moveActionFinished();
	void attackActionFinished();
	void stopAction();
	void deadAction();
	void hittedAction();
	bool isCallStopAction;
	void update(float dt);
};

#endif /* defined(__MungCo__CatMonster__) */
