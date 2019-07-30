//
//  MissionScene.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 12..
//
//

#ifndef __MungCo__MissionScene__
#define __MungCo__MissionScene__
#include "HelloMunggu.h"
#include "MungGuGame.h"
#include "MungGuGameMenuScene.h"
#include <stdio.h>


USING_NS_CC;

class MissionScene : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    void initData();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    bool isM1Clear;
    bool isM2Clear;
    bool isM3Clear;
    bool isM4Clear;
    bool isM5Clear;
    bool isM6Clear;
    bool isM7Clear;
    bool isM8Clear;
    bool isM9Clear;
    bool isM10Clear;
    bool isM11Clear;
    bool isM12Clear;
    bool isM13Clear;
    bool isM14Clear;
    bool isM15Clear;
    bool isM16Clear;
    bool isM17Clear;
    bool isM18Clear;
    bool isM19Clear;
    bool isM20Clear;
    
    Size winSize;
    Point point;
    Sprite* mainImage;
    Label* MissionTheme;
    Label* myGold_label;
    Label* missionEx;
    Sprite* goldArea;
    int winHeight,winWidth;
    Sprite* logo;
    
    Rect mission1Rect;
    Rect mission6Rect;
    Rect mission11Rect;
    Rect mission16Rect;

    // implement the "static create()" method manually
    CREATE_FUNC(MissionScene);
    bool isReturnBtn;
    bool initByEnglish;
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    
    Sprite* homeBackBtn;
    Sprite* homeBackBtn_;
    Sprite* mission1C;
    Sprite* mission1;
    Sprite* mission2C;
    Sprite* mission2;
    Sprite* mission3C;
    Sprite* mission3;
    Sprite* mission4C;
    Sprite* mission4;
    Sprite* mission5C;
    Sprite* mission5;
    Sprite* mission6C;
    Sprite* mission6;
    Sprite* mission7C;
    Sprite* mission7;
    Sprite* mission8C;
    Sprite* mission8;
    Sprite* mission9C;
    Sprite* mission9;
    Sprite* mission10C;
    Sprite* mission10;
    Sprite* mission11C;
    Sprite* mission11;
    Sprite* mission12C;
    Sprite* mission12;
    Sprite* mission13C;
    Sprite* mission13;
    Sprite* mission14C;
    Sprite* mission14;
    Sprite* mission15C;
    Sprite* mission15;
    Sprite* mission16C;
    Sprite* mission16;
    Sprite* mission17C;
    Sprite* mission17;
    Sprite* mission18C;
    Sprite* mission18;
    Sprite* mission19C;
    Sprite* mission19;
    Sprite* mission20C;
    Sprite* mission20;
    Label* mission1_label;
    Label* mission2_label;
    Label* mission3_label;
    Label* mission4_label;
    Label* mission5_label;
    Label* mission6_label;
    Label* mission7_label;
    Label* mission8_label;
    Label* mission9_label;
    Label* mission10_label;
    Label* mission11_label;
    Label* mission12_label;
    Label* mission13_label;
    Label* mission14_label;
    Label* mission15_label;
    Label* mission16_label;
    Label* mission17_label;
    Label* mission18_label;
    Label* mission19_label;
    Label* mission20_label;
    
    void changeScene();
    void changeScene(Ref *sender);
    
};



#endif /* defined(__MungCo__MissionScene__) */
