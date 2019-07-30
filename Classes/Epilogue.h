//
//  Epilogue.h
//  mungGu
//
//  Created by Kyeongtae Min on 2015. 2. 10..
//
//

#ifndef __mungGu__Epilogue__
#define __mungGu__Epilogue__

#include <stdio.h>

#include "cocos2d.h"

USING_NS_CC;

#define TAG_stageClearBtn 20

class Epilogue : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    void initData();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    Size winSize;
    Point point;
    bool isStageClearBtn;
    bool initByEnglish;
    Sprite* stageClearBtn;
    Sprite* stageClearBtn_;
    Rect stageClearBtnRect;
    
    
    //    Sprite* logoScene;
    // implement the "static create()" method manually
    CREATE_FUNC(Epilogue);
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    void loadMonsterSpriteData();
   void clearEvent();
    void clearMissionEvent();
    void changeHelloMungScene3();
    void changeHelloMungScene(Object* pSender);
    void changeHelloMungScene2(Object* pSender);
};



#endif /* defined(__mungGu__Epilogue__) */
