//
//  MungStoreScene.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 12..
//
//
#include "MungStoreScene.h"
#include "MungGuGame.h"
USING_NS_CC;

//bool isHelloMungTouched=false;

Scene* MungStoreScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MungStoreScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MungStoreScene::init()
{
    CCLOG("Click");
    winSize = Director::getInstance()->getWinSize();
    
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0,0,0,0)) )
    {
        return false;
    }
    
    initData();
     initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
    myGold = UserDefault::getInstance()->getIntegerForKey("myGold");
    goldArea = Sprite::create("GoldArea.png");
    goldArea->setPosition(Point(winSize.width, winSize.height));
    goldArea->setAnchorPoint(Point(1, 1));
  //  goldArea->setTag(TAG_SPRITE_GOLDAREA);
    this->addChild(goldArea, 5);
    
    Rect goldAreaRect = goldArea->getBoundingBox();
    myGold_label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", myGold), "NanumBarunGothicBold.otf", 30);
    myGold_label->setAnchorPoint(Point(0, 0.5));
    myGold_label->setPosition(Point(goldAreaRect.getMaxX() - 253, goldAreaRect.getMidY()));
    myGold_label->setTag(55);
    myGold_label->setColor(Color3B::BLACK);
    this->addChild(myGold_label, 5);
    
    logo = Sprite::create("MyLogo.png");
    logo->setPosition(Point(winSize.width*19/20,3));
    logo->setAnchorPoint(Point(0.5,0));
    logo->setScale(0.3);
    this->addChild(logo,2);
    
 
    //홈 버튼
    homeBackBtn = Sprite::create("homeBackBtn.png");
    homeBackBtn_ = Sprite::create("homeBackBtn_.png");
    homeBackBtn->setAnchorPoint(Point(0,0));
    homeBackBtn_->setAnchorPoint(Point(0,0));
    homeBackBtn->setPosition(Point(5,5));
    homeBackBtn_->setPosition(Point(5,5));
    homeBackBtn->setTag(TAG_SPRITE_HOMEBACKBTN);
    homeBackBtn_->setVisible(false);
    homeBackBtn->setScale(0.6);
    homeBackBtn_->setScale(0.6);
    this->addChild(homeBackBtn,10);
    this->addChild(homeBackBtn_,10);
    ///
    
    
    
    mainImage = Sprite::create("MungGuBackground.png");
    Rect mainImageRect = mainImage->getBoundingBox();
    mainImage->setScale(winSize.width/mainImageRect.size.width, winSize.height/mainImageRect.size.height);
    mainImage->setPosition(winSize.width/2, winSize.height/2);
    mainImage->setOpacity(200);
    this->addChild(mainImage,1);
    
    cryDog = Sprite::create("cryDog.png");
    cryDog->setPosition(Point(winSize.width/2,winSize.height/2));
    cryDog->setAnchorPoint(Point(0.5,0.3));
    cryDog->setScale(2.3*winSize.width/1200);
    cryDog->setOpacity(160);
    this->addChild(cryDog,1);
    Rect cryDogRect = cryDog->getBoundingBox();
    
    if(initByEnglish == true){
    mungStoreTheme = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Sorry..\n  Not Yet... ㅠㅠ"), "NanumBarunGothicBold.otf", 50);
    }else{
        mungStoreTheme = Label::createWithTTF //상태버튼 maxMoney
        (StringUtils::format("죄송..\n  미 개발... ㅠㅠ"), "NanumBarunGothicBold.otf", 50);

    }
    mungStoreTheme->setPosition(Point(winSize.width/2,cryDogRect.getMinY()-16));
    mungStoreTheme->setAnchorPoint(Point(0.5,1));
    mungStoreTheme->setColor(Color3B::BLACK);
    this->addChild(mungStoreTheme,2);
    
   
    
    return true;
}

void MungStoreScene::initData(){
    
    cryDogTouched = false;
    
    
    auto listener_changeSceneBtn = EventListenerTouchOneByOne::create();
    listener_changeSceneBtn->onTouchBegan = CC_CALLBACK_2
    (MungStoreScene::onTouchBegan, this);
    listener_changeSceneBtn->onTouchMoved = CC_CALLBACK_2
    (MungStoreScene::onTouchMoved, this);
    listener_changeSceneBtn->onTouchEnded = CC_CALLBACK_2
    (MungStoreScene::onTouchEnded, this);
    
    isReturnBtn = false;
    
    
    
    //홈버튼
    auto listener_homeBackBtn = EventListenerTouchOneByOne::create();
    listener_homeBackBtn->onTouchBegan = CC_CALLBACK_2
    (MungStoreScene::onTouchBegan, this);
    listener_homeBackBtn->onTouchMoved = CC_CALLBACK_2
    (MungStoreScene::onTouchMoved, this);
    listener_homeBackBtn->onTouchEnded = CC_CALLBACK_2
    (MungStoreScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_homeBackBtn, TAG_SPRITE_HOMEBACKBTN);
    ///
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_changeSceneBtn, TAG_HELLOMUNGGU);
}

void MungStoreScene::changeScene(Ref *sender){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    Director::getInstance()->replaceScene(MungGuGameMenuScene::createScene());
}
void MungStoreScene::changeScene(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = TransitionFade::create(0.6, MungGuGameMenuScene::createScene());
    Director::getInstance()->replaceScene(scene);



}

bool MungStoreScene::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
    Point loc = touch->getLocation();
    
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    if(homeBackBtnRect.containsPoint(loc)){
        isReturnBtn = true;
        homeBackBtn->setVisible(false);
        homeBackBtn_->setVisible(true);
    }
    
    if(cryDogTouched==false){
        if(cryDogRect.containsPoint(loc)){
            cryDogTouched=true;
        }
    }

    return true;
}
void MungStoreScene::onTouchMoved(Touch *touch, Event *unused_event){
    Point loc = touch->getLocation();
    
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    
    if(homeBackBtnRect.containsPoint(loc)){
        isReturnBtn = true;
        homeBackBtn->setVisible(false);
        homeBackBtn_->setVisible(true);
    }else{
        isReturnBtn = false;
        homeBackBtn->setVisible(true);
        homeBackBtn_->setVisible(false);
    }
    
    if(cryDogTouched==true){
            cryDog->setPosition(Point(loc.x,loc.y));
    }
}
void MungStoreScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    Point loc = touch->getLocation();
    
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    
    if(homeBackBtnRect.containsPoint(loc)){
        homeBackBtn->setVisible(true);
        homeBackBtn_->setVisible(false);
        changeScene();
    }
    
    
    if(cryDogTouched==true){
        cryDogTouched=false;
    }

}
