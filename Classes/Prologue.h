//
//  LogoScene.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 17..
//
//

#ifndef __MungCo__PrologueScene__
#define __MungCo__PrologueScene__

#include "cocos2d.h"
#include "HelloMunggu.h"
#include "SimpleAudioEngine.h"
#include "LogoScene.h"

USING_NS_CC;



class Prologue : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    void initData();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    Size winSize;
    Point point;
    
    //    Sprite* logoScene;
    // implement the "static create()" method manually
    CREATE_FUNC(Prologue);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    void loadMonsterSpriteData();
    void changeHelloMungScene2(Object* pSender);
    void changeHelloMungScene();
    
};


#endif /* defined(__MungCo__LogoScene__) */
