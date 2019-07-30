//
//  CatBossMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//
//

#ifndef __MungCo__CatBossMonster__
#define __MungCo__CatBossMonster__
#include "EnemyMonster.h"

class CatBossMonster : public EnemyMonster
{
public:

	BasicAnimation animation;
	Size winSize;

	CatBossMonster(int monsterNumber);
	~CatBossMonster();

	SpriteFrame *spFrame;

    virtual void setHpBar();
    
	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);
	void angryAction();
	void initAttackEffect2();
	Sprite* attackEffect2;
	void isAttackEffect();
	void initData();
	void moveAction();
	void attackAction();
	void angryEffect();
	void deadAndDisappear();
	void hittedAction();
	void deadAction();
	bool isFinishHittedAction;
	void hittedActionFinished();

	void moveActionFinished();
	void attackActionFinished();

	void stopAction();
	bool isCallStopAction;
	void update(float dt);
};

#endif /* defined(__MungCo__CatBossMonster__) */
