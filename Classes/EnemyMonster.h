//
//  EnemyMonster.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//
//

#ifndef __MungGu__EnemyMonster__
#define __MungGu__EnemyMonster__
class MungGuGame;
#include "Common.h"


class EnemyMonster : public Sprite{
public:
    EnemyMonster();
    ~EnemyMonster();
    
    Sprite* catEnergyBar;
    ProgressTimer* catEnergyTimer;
    
    float scaleRate;
    float hp;
    float now_hp;
    
    //현재체력
    virtual void setHpBar();
    
    
    int number;
    int attackRangeValue;
    int damageValue;
    int dieMoney;
    int enemySizeDecreaseRate; //공격 모션시에 길어지는 너비값을 조정
    bool isUnitInFront;
    bool isFinishDiedAction=false;
    bool isFinishHittedAction=true;
    bool isCallStopAction=false;
    bool isFinishMoveAction=true;
    bool isFinishAttackAction=true;
    bool isMultiAttack; //범위공격 단일공격을 유무를 판단
    bool isStrongAboutSmall,isStrongAboutBig;
    int unitSize; //1:소형 2:중형 3:대형
    
    //정리할 필요가 있음...
    
    //몬스터 정지 이미지
    SpriteFrame *monsterStopImage[1];
    bool isEnemyAngryed;
    bool isMySiteInFront;
    
    void angryAction();
    //몬스터 이동속도
    int moveVelocity;
    bool isEnemyDie;
    //몬스터 넘버에 해당되는 몬스터 한마리 생성
    static EnemyMonster* create(int monsterNumber);
    
    //몬스터 이미지 불러오기
    virtual void loadMonsterSpriteData();
    //몬스터 액션 관리자
    virtual void monsterAction(int actionNumber);
    ///
};

#endif /* defined(__MungCo__EnemyMonster__) */
