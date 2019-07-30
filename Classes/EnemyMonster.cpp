//
//  EnemyMonster.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 31..
//
//

//적 몬스터 클래스
#include "EnemyMonster.h"
#include "CatBossMonster.h"
#include "CatMonster.h"
#include "CatSinTaeDoll.h"
#include "CatInuMonster.h"
#include "CatBigMonster.h"
#include "CatJoe.h"
#include "CatNamGu.h"
#include "CatBase.h"

EnemyMonster::EnemyMonster(){

}

EnemyMonster::~EnemyMonster(){

}

void EnemyMonster::setHpBar(){
    
}

EnemyMonster *EnemyMonster::create(int monsterNumber){
	EnemyMonster* monsterSprite;
	switch (monsterNumber){
	case MONSTER_CAT:
		monsterSprite = new CatBossMonster(monsterNumber);
		break;
	case MONSTER_CATBABY:
		monsterSprite = new CatMonster(monsterNumber);
		break;
    case MONSTER_CATINU:
        monsterSprite = new CatInuMonster(monsterNumber);
        break;
    case MONSTER_BIGCAT:
        monsterSprite = new CatBigMonster(monsterNumber);
        break;
    case MONSTER_CATJOE:
        monsterSprite = new CatJoe(monsterNumber);
        break;
    case MONSTER_CATSINTAEDOLL:
        monsterSprite = new CatSinTaeDoll(monsterNumber);
        break;
    case MONSTER_CATNAMGU:
    monsterSprite = new CatNamGu(monsterNumber);
            break;
        case MONSTER_CATBASE:
    monsterSprite = new CatBase(monsterNumber);
            break;
	default:
		monsterSprite = nullptr;
	}


	if (monsterSprite != nullptr){
		monsterSprite->setAnchorPoint(Point(0.5, 0));
	}

	return monsterSprite;
}

void EnemyMonster::loadMonsterSpriteData(){

}

void EnemyMonster::monsterAction(int actionNumber){

}
