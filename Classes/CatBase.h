//
//  CatBase.h
//  mungGu
//
//  Created by Kyeongtae Min on 2015. 2. 14..
//
//

#ifndef __mungGu__CatBase__
#define __mungGu__CatBase__

#include <stdio.h>

#include "EnemyMonster.h"

class CatBase : public EnemyMonster
{
public:
    
    BasicAnimation animation;
    Size winSize;
    
    virtual void setHpBar();
    
    CatBase(int monsterNumber);
    ~CatBase();
    
    SpriteFrame *spFrame;
    
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

#endif /* defined(__mungGu__CatBase__) */
