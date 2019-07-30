//
//  MyMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 2..
//
//

#ifndef __MungGu__Monster__
#define __MungGu__Monster__

class MungGuGame;

#include "Common.h"


class MungGame;//??
class Monster : public Sprite{
public:
    
    
    Monster();
    ~Monster();
    
    Sprite* mungEnergyBar;
    ProgressTimer* mungEnergyTimer;
    
    virtual void setHpBar();
    
    int number;
    int rangeValue;
    int damageValue;
    int attackRangeValue;
    int mySizeDecreaseRate;
    float scaleRate;
    bool isEnemySiteInFront;
    bool isEnemyUnitInFront;
    bool isMultiAttack; //범위공격 단일공격을 유무를 판단
    bool isStrongAboutSmall,isStrongAboutBig;
    int unitSize;//1:소형 2:중형 3:대형
    //몬스터정지이미지
    SpriteFrame *monsterStopImage[1];
    // SpriteFrame *monsterHitImage[1];
    //전체체력
    float hp;
    //현재체력
    float now_hp;
    bool isMyDie;
    bool isFinishMoveAction=true;
    bool isFinishAttackAction=true;
    bool isFinishDiedAction=false;
    bool isFinishHittedAction=true;
    bool isCallStopAction=false;
    
    //Sprite *hpFullBar;
    //Sprite *hpEmptyBar;
    
    
    //몬스터 이동속도
    int moveVelocity;
    
    //몬스터 넘버에 해당되는 몬스터 한마리 생성
    static Monster* create(int monsterNumber);
    
    //몬스터 이미지 불러오기
    virtual void loadMonsterSpriteData();
    //몬스터 액션 관리자
    virtual void monsterAction(int actionNumber);
    //몬스터 체력바 셋팅
    //virtual void settingHpBar();
    
    
    
    
};

#endif /* defined(__MungCo__MyMonster__) */
