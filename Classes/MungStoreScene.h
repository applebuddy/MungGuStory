//
//  MungStoreScene.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 12..
//
//

#ifndef __MungCo__MungStoreScene__
#define __MungCo__MungStoreScene__

#include "cocos2d.h"
#include "UnitScene.h"
#include "HelloMunggu.h"
#include "MungGuGame.h"
#include "MungGuGameMenuScene.h"

USING_NS_CC;

class MungStoreScene : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    void initData();

    CREATE_FUNC(MungStoreScene);

    Size winSize;
    Point point;
    Sprite* mainImage;
    Label* mungStoreTheme;
    Label* myGold_label;
    Sprite* goldArea;
    int winHeight,winWidth;
    Sprite* logo;
    // implement the "static create()" method manually
    
    bool cryDogTouched;
    bool isReturnBtn;
    bool initByEnglish;
    Sprite* homeBackBtn;
    Sprite* homeBackBtn_;
    Rect cryDogRect;
    Sprite* cryDog;
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    
    void changeScene();
    void changeScene(Ref *sender);

};

#endif /* defined(__MungCo__MungStoreScene__) */
