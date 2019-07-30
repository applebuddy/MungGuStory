
//
//  MungSausage.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 10..
//
//

#ifndef __MungGu__MungSausage__
#define __MungGu__MungSausage__

#include "Monster.h"

class MungSausage : public Monster
{
public:

	BasicAnimation animation;
	Size winSize;

	MungSausage(int monsterNumber);
	~MungSausage();
	void isAttackEffect();
	virtual void loadMonsterSpriteData();
	virtual void monsterAction(int actionNumber);

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
    
    void setHpBar();
};



#endif /* defined(__MungCo__MungSausage__) */
