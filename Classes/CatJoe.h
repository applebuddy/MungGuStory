//
//  CatJoe.h
//  mungGu
//
//  Created by Kyeongtae Min on 2015. 2. 4..
//
//

#ifndef __mungGu__CatJoe__
#define __mungGu__CatJoe__


#include "EnemyMonster.h"

class CatJoe : public EnemyMonster
{
public:
    
    BasicAnimation animation;
    Size winSize;
    
    CatJoe(int monsterNumber);
    ~CatJoe();
    
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
#endif /* defined(__mungGu__CatJoe__) */
