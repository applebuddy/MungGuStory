//
//  MyMonster.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 2..
//
//

#include "Monster.h"
#include "MungGuGame.h"
#include "MungSausage.h"
#include "MunguMonster.h"
#include "MungBallMonster.h"
#include "MungButterFly.h"
#include "MungWhangGu.h"

Monster::Monster()
{
    
}

Monster::~Monster()
{
    
}



Monster *Monster::create(int monsterNumber)
{
    
    Monster* monsterSprite;
    switch (monsterNumber) {
            //select create Monster
        case MONSTER_MUNGGU:
            monsterSprite = new MunguMonster(monsterNumber);
            break;
        case MONSTER_MUNGBALL:
            monsterSprite = new MungBallMonster(monsterNumber);
            break;
        case MONSTER_MUNGBUT:
            monsterSprite = new MungButterFly(monsterNumber);
            break;
        case MONSTER_MUNGSAUSAGE:
            monsterSprite = new MungSausage(monsterNumber);
            break;
        case MONSTER_WHANGGU:
            monsterSprite = new MungWhangGu(monsterNumber);
            break;
        default:
            monsterSprite = nullptr;
            
    }
    
    if (monsterSprite != nullptr) {
        monsterSprite->setAnchorPoint(Point(0.5, 0));
    }
    
    
    return monsterSprite;
}

void Monster::setHpBar(){
    
}


void Monster::loadMonsterSpriteData()
{
    
}

void Monster::monsterAction(int actionNumber) {
    
}
