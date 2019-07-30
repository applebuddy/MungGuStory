#ifndef __HELLOMUNGCO_SCENE_H__
#define __HELLOMUNGCO_SCENE_H__

#include "MungGuGameMenuScene.h"
#include "cocos2d.h"

USING_NS_CC;//cocos2d의 이미지 넣기(Sprite*)등 사용할때 cocos:: 안쓰려면 써야함.

#define TAG_HELLOMUNGGU 1

class HelloMunggu : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    void initData();
    void titleActionFinished();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    CREATE_FUNC(HelloMunggu);
    
    
    void initTitleAction();
    void pressAnyKeyAction();
    Size winSize;
    Point point;
    Sprite* mainImage;
    Sprite* helloMungGu;
    int winHeight, winWidth;
    MenuItemFont* item;
    double nowVersion;
    Label* versionInfo;
    Sprite* logo;
    // implement the "static create()" method manually
    
    bool isHelloMungTouched;
    bool isTitleFinished;
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    
    void changeHelloMungScene(Ref *sender);
};

#endif // __HELLOWORLD_SCENE_H__
