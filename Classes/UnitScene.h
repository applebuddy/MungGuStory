//
//  UnitScene.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 12..
//
//

#ifndef __MungCo__UnitScene__
#define __MungCo__UnitScene__

#include "cocos2d.h"
#include "MungStoreScene.h"
#include "HelloMunggu.h"
#include "MungGuGame.h"
#include "MungGuGameMenuScene.h"

USING_NS_CC;

class UnitScene : public LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    void initData();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    bool isSong;
    
    bool isM1CostTouched;
    bool isM2CostTouched;
    bool isM3CostTouched;
    bool isM4CostTouched;
    bool isM5CostTouched;
    bool isDogSiteHpCostTouched;
    bool isDogSitePoCostTouched;
    bool isDogSiteRangeCostTouched;
    bool btnTouched;
    bool initByEnglish;
    
    int mungGuDogSiteRangeLv;
    int mungLv,whangLv,mungBallLv,mungButLv,mungSausageLv;
    int mungGuDogSiteHpLv,mungGuDogSitePoLv;
    Size winSize;
    Point point;
    Sprite* mainImage;
    Label* UnitSceneTheme;
    Sprite* logo;
    // implement the "static create()" method manually
    CREATE_FUNC(UnitScene);
    
   
    Sprite* homeBackBtn;
    Sprite* homeBackBtn_;
    
    Sprite* costBar1;
    Sprite* costBar2;
    Sprite* costBar3;
    Sprite* costBar4;
    Sprite* costBar5;
    Sprite* costBar1_;
    Sprite* costBar2_;
    Sprite* costBar3_;
    Sprite* costBar4_;
    Sprite* costBar5_;
    
    Sprite* mungSausageBtn;
    Sprite* mungSausageBtn_;
    
    Sprite* whangGuBtn;
    Sprite* whangGuBtn_;
    
    Sprite* mungBallBtn;
    Sprite* mungBallBtn_;
    
    Sprite* mungGuBtn;
    Sprite* mungGuBtn_;
    
    Sprite* dogSite;
    Sprite* costBarDogSiteHp;
    Sprite* costBarDogSitePo;
    Sprite* costBarDogSiteHp_;
    Sprite* costBarDogSitePo_;
    Sprite* costBarDogSiteRange;
    Sprite* costBarDogSiteRange_;
    
    Sprite* mungButterflyBtn;
    Sprite* mungButterflyBtn_;
    Sprite* goldArea;
    Label* myGold_label;
    Label* exLabel;
    Sprite* ground;
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    //Rect rect;
    void update(float delta);
    void changeScene();
    void changeScene(Ref *sender);
    void unitCheck();
    void setUnitBtn();
    void initLabel();
    bool isReturnBtn;
    
    Label* mungGuLv_Label;
    Label* mungBallLv_Label;
    Label* whangGuLv_Label;
    Label* mungButterflyLv_Label;
    Label* mungSausageLv_Label;
    Label* mungGuDogSiteHpLv_Label;
    Label* mungGuDogSitePoLv_Label;
    Label* mungGuDogSiteRangeLv_Label;
    
    Label* costBar1_Label;
    Label* costBar2_Label;
    Label* costBar3_Label;
    Label* costBar4_Label;
    Label* costBar5_Label;
    Label* costBarDogSiteHp_Label;
    Label* costBarDogSitePo_Label;
    Label* costBarDogSiteRange_Label;
    Rect goldAreaRect;
    Rect costBar1_Rect;
    Rect costBar2_Rect;
    Rect costBar3_Rect;
    Rect costBar4_Rect;
    Rect costBar5_Rect;
    Rect costBarDogSiteHp_Rect;
    Rect costBarDogSitePo_Rect;
    Rect costBarDogSiteRange_Rect;
    
    int cost_dogSiteHp,cost_dogSitePo,cost_dogSiteRange,cost1,cost2,cost3,cost4,cost5;
    
};


#endif /* defined(__MungCo__UnitScene__) */
