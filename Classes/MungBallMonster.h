//
//  MungBallMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 6..
//
//

#ifndef __MungGu__MungBallMonster__
#define __MungGu__MungBallMonster__


#include "Monster.h"

class MungBallMonster : public Monster
{
public:

	BasicAnimation animation;
	Size winSize;

	MungBallMonster(int monsterNumber);
	~MungBallMonster();
    
	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);

    virtual void setHpBar();
    
	void isAttackEffect();
	void deadAndDisappear();
	void hittedAction();
	void deadAction();
	bool isFinishHittedAction;
	void hittedActionFinished();

	void moveAction();
	void attackAction();
	// int rangeValue;

    bool isFinishDiedAction;
	void moveActionFinished();
	void attackActionFinished();

	void stopAction();
	bool isCallStopAction;

	void update(float dt);
    
    
};


#endif /* defined(__MungCo__MungBallMonster__) */
