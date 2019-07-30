//
//  Header.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 4..
//
//

#ifndef MungCo_Common_h
#define MungCo_Common_h

#include "cocos2d.h"
USING_NS_CC;


enum actionList
{
	//monster Actions
	ACTION_MOVE = 0,
	ACTION_ATTACK,
	ACTION_DIE,
	ACTION_STOP,
	ACTION_HITTED,
	ACTION_ANGRY
};

enum monsterNumber
{
	//myMonsters
	MONSTER_MUNGGU = 0,
	MONSTER_MUNGBALL = 1,
	MONSTER_MUNGSAUSAGE = 2,
	MONSTER_MUNGBUT = 3,
	MONSTER_WHANGGU = 4,
    

	//enemyMonsters
	MONSTER_CAT = 100,
	MONSTER_CATBABY = 101,
    MONSTER_CATINU = 102,
    MONSTER_BIGCAT = 103,
    MONSTER_CATJOE = 104,
    MONSTER_CATNAMGU = 105,
    MONSTER_CATBASE = 106,
    MONSTER_CATSINTAEDOLL = 199
};


struct BasicAnimation
{
	//common Animations
	Animate *animate_move;
	Animate *animate_attack;
	Animate *attack_Effect;
	Animate *animate_hit;
    
    Animate *animate_wait;
    float waitFrameValue;

	//Animation Speed Value
	float moveFrameValue;  //움직일때
	float attackFrameValue; //공격 이미지 전환 속도 //공통적으로 필요한 요소들을 담아두는 헤더파일 common.h
	float attackwaitFrameValue; //공격후 기다리는 정도
	float attackmoveFrameValue; //공격할 때 액션 속도
    
    
};

#endif
