//
//  MungButterFlyBtn.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 17..
//
//

#ifndef __MungGu__MungButterFly__
#define __MungGu__MungButterFly__

#include "Monster.h"

class MungButterFly : public Monster
{
public:

	BasicAnimation animation;
	Size winSize;

	MungButterFly(int monsterNumber);
	~MungButterFly();

	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);

	void isAttackEffect();
	void deadAndDisappear();
	void hittedAction();
	void deadAction();
	bool isFinishHittedAction;
    bool isFinishDiedAction;
    
	void hittedActionFinished();

	void moveAction();
	void attackAction();


	void moveActionFinished();
	void attackActionFinished();

	void stopAction();
	bool isCallStopAction;
	// int rangeValue;
	void update(float dt);
    
    virtual void setHpBar();
};


#endif /* defined(__MungCo__MungButterFly__) */
