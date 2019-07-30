//
//  MungWhangGu.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 7..
//
//

#ifndef __MungGu__MungWhangGu__
#define __MungGu__MungWhangGu__


#include "Monster.h"

class MungWhangGu : public Monster
{
public:

	BasicAnimation animation;
	Size winSize;

	MungWhangGu(int monsterNumber);
	~MungWhangGu();

	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);

	void isAttackEffect();
	void moveAction();
	void attackAction();
	// int rangeValue;

    bool isFinishDiedAction;
	void moveActionFinished();
	void attackActionFinished();

	void deadAndDisappear();
	void hittedAction();
	void deadAction();
	bool isFinishHittedAction;
	void hittedActionFinished();

	void stopAction();
	bool isCallStopAction;
    
    virtual void setHpBar();

	void update(float dt);
};



#endif /* defined(__MungCo__MungWhangGu__) */
