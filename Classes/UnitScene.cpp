#include "UnitScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;




Scene* UnitScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = UnitScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool UnitScene::init()
{
    CCLOG("Click");
    winSize = Director::getInstance()->getWinSize();
    
    //////////////////////////////
    // 1. super init first
    if ( !LayerColor::initWithColor(Color4B(0,0,0,0)) )
    {
        return false;
    }
    
    isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    
    initData();
    setUnitBtn();
    
    
    
    
    
    this->scheduleUpdate();
    
    return true;
}

void UnitScene::initData(){
    
    isReturnBtn=false;
    
//    bool isMissionStarted = UserDefault::getInstance()->getBoolForKey("initMissionScene",false);
//    
//    if(isMissionStarted == false){//처음 들어왓을때 초기화 부분
//        UserDefault::getInstance()->setBoolForKey("initMissionScene", true);
//        
//        initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
//
//     }
    initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
    mungGuDogSiteHpLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteHpLv");
    mungGuDogSitePoLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSitePoLv");
    mungGuDogSiteRangeLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteRangeLv");
    mungLv= UserDefault::getInstance()->getIntegerForKey("mungLv");
    whangLv= UserDefault::getInstance()->getIntegerForKey("whangLv");
    mungBallLv= UserDefault::getInstance()->getIntegerForKey("mungBallLv");
    mungButLv= UserDefault::getInstance()->getIntegerForKey("mungButLv");
    mungSausageLv= UserDefault::getInstance()->getIntegerForKey("mungSausageLv");
    
    if(mungGuDogSiteRangeLv==1){
        cost_dogSiteRange = 2500;
    }else if(mungGuDogSiteRangeLv==2){
        cost_dogSiteRange = 2750;
    }else if(mungGuDogSiteRangeLv==3){
        cost_dogSiteRange = 3000;
    }else if(mungGuDogSiteRangeLv==4){
        cost_dogSiteRange = 3250;
    }else if(mungGuDogSiteRangeLv==5){
        cost_dogSiteRange = 3500;
    }else if(mungGuDogSiteRangeLv==6){
        cost_dogSiteRange = 3750;
    }else if(mungGuDogSiteRangeLv==7){
        cost_dogSiteRange = 4000;
    }else if(mungGuDogSiteRangeLv==8){
        cost_dogSiteRange = 4250;
    }else if(mungGuDogSiteRangeLv==9){
        cost_dogSiteRange = 4500;
    }else if(mungGuDogSiteRangeLv==10){
        cost_dogSiteRange = 4750;
    }else if(mungGuDogSiteRangeLv==11){
        cost_dogSiteRange = 5000;
    }else if(mungGuDogSiteRangeLv==12){
        cost_dogSiteRange = 5500;
    }else if(mungGuDogSiteRangeLv==13){
        cost_dogSiteRange = 6000;
    }else if(mungGuDogSiteRangeLv==14){
        cost_dogSiteRange = 6500;
    }else if(mungGuDogSiteRangeLv==15){
        cost_dogSiteRange = 7000;
    }else if(mungGuDogSiteRangeLv==16){
        cost_dogSiteRange = 7500;
    }else if(mungGuDogSiteRangeLv==17){
        cost_dogSiteRange = 8000;
    }else if(mungGuDogSiteRangeLv==18){
        cost_dogSiteRange = 8500;
    }else if(mungGuDogSiteRangeLv==19){
        cost_dogSiteRange = 9000;
    }else if(mungGuDogSiteRangeLv==20){
        cost_dogSiteRange = 10000;
    }
    
    if(mungGuDogSiteHpLv==0){
        cost_dogSiteHp = 3000;
    }else if(mungGuDogSiteHpLv==1){
        cost_dogSiteHp = 3500;
    }else if(mungGuDogSiteHpLv==2){
        cost_dogSiteHp = 4000;
    }else if(mungGuDogSiteHpLv==3){
        cost_dogSiteHp = 4500;
    }else if(mungGuDogSiteHpLv==4){
        cost_dogSiteHp = 4000;
    }else if(mungGuDogSiteHpLv==5){
        cost_dogSiteHp = 4500;
    }else if(mungGuDogSiteHpLv==6){
        cost_dogSiteHp = 5000;
    }else if(mungGuDogSiteHpLv==7){
        cost_dogSiteHp = 5500;
    }else if(mungGuDogSiteHpLv==8){
        cost_dogSiteHp = 6000;
    }else if(mungGuDogSiteHpLv==9){
        cost_dogSiteHp = 6500;
    }else if(mungGuDogSiteHpLv==10){
        cost_dogSiteHp = 7000;
    }else if(mungGuDogSiteHpLv==11){
        cost_dogSiteHp = 7500;
    }else if(mungGuDogSiteHpLv==12){
        cost_dogSiteHp = 8000;
    }else if(mungGuDogSiteHpLv==13){
        cost_dogSiteHp = 8500;
    }else if(mungGuDogSiteHpLv==14){
        cost_dogSiteHp = 9000;
    }else if(mungGuDogSiteHpLv==15){
        cost_dogSiteHp = 9500;
    }else if(mungGuDogSiteHpLv==16){
        cost_dogSiteHp = 10000;
    }else if(mungGuDogSiteHpLv==17){
        cost_dogSiteHp = 11000;
    }else if(mungGuDogSiteHpLv==18){
        cost_dogSiteHp = 12000;
    }else if(mungGuDogSiteHpLv==19){
        cost_dogSiteHp = 13000;
    }else if(mungGuDogSiteHpLv==20){
        cost_dogSiteHp = 14000;
    }else if(mungGuDogSiteHpLv==21){
        cost_dogSiteHp = 15000;
    }else if(mungGuDogSiteHpLv==22){
        cost_dogSiteHp = 16000;
    }else if(mungGuDogSiteHpLv==23){
        cost_dogSiteHp = 17000;
    }else if(mungGuDogSiteHpLv==24){
        cost_dogSiteHp = 18000;
    }else if(mungGuDogSiteHpLv==25){
        cost_dogSiteHp = 19000;
    }else if(mungGuDogSiteHpLv==26){
        cost_dogSiteHp = 20000;
    }else if(mungGuDogSiteHpLv==27){
        cost_dogSiteHp = 21000;
    }else if(mungGuDogSiteHpLv==28){
        cost_dogSiteHp = 22000;
    }else if(mungGuDogSiteHpLv==29){
        cost_dogSiteHp = 23000;
    }else if(mungGuDogSiteHpLv==30){
        cost_dogSiteHp = 24000;
    }
    
    if(mungGuDogSitePoLv==0){
        cost_dogSitePo = 5000;
    }else if(mungGuDogSitePoLv==1){
        cost_dogSitePo = 5250;
    }else if(mungGuDogSitePoLv==2){
        cost_dogSitePo = 5500;
    }else if(mungGuDogSitePoLv==3){
        cost_dogSitePo = 5750;
    }else if(mungGuDogSitePoLv==4){
        cost_dogSitePo = 6000;
    }else if(mungGuDogSitePoLv==5){
        cost_dogSitePo = 6250;
    }else if(mungGuDogSitePoLv==6){
        cost_dogSitePo = 6500;
    }else if(mungGuDogSitePoLv==7){
        cost_dogSitePo = 6750;
    }else if(mungGuDogSitePoLv==8){
        cost_dogSitePo = 7000;
    }else if(mungGuDogSitePoLv==9){
        cost_dogSitePo = 7250;
    }else if(mungGuDogSitePoLv==10){
        cost_dogSitePo = 7500;
    }else if(mungGuDogSitePoLv==11){
        cost_dogSitePo = 8000;
    }else if(mungGuDogSitePoLv==12){
        cost_dogSitePo = 8500;
    }else if(mungGuDogSitePoLv==13){
        cost_dogSitePo = 9000;
    }else if(mungGuDogSitePoLv==14){
        cost_dogSitePo = 9500;
    }else if(mungGuDogSitePoLv==15){
        cost_dogSitePo = 10000;
    }else if(mungGuDogSitePoLv==16){
        cost_dogSitePo = 10500;
    }else if(mungGuDogSitePoLv==17){
        cost_dogSitePo = 11000;
    }else if(mungGuDogSitePoLv==18){
        cost_dogSitePo = 11500;
    }else if(mungGuDogSitePoLv==19){
        cost_dogSitePo = 12000;
    }else if(mungGuDogSitePoLv==20){
        cost_dogSitePo = 13000;
    }

    
    
    isReturnBtn = false;
    isM1CostTouched = false;
    isM2CostTouched = false;
    isM3CostTouched = false;
    isM4CostTouched = false;
    isM5CostTouched = false;
    isDogSiteHpCostTouched = false;
    isDogSitePoCostTouched = false;
    isDogSiteRangeCostTouched = false;
    
    auto listener_changeSceneBtn = EventListenerTouchOneByOne::create();
    listener_changeSceneBtn->onTouchBegan = CC_CALLBACK_2
    (UnitScene::onTouchBegan, this);
    listener_changeSceneBtn->onTouchMoved = CC_CALLBACK_2
    (UnitScene::onTouchMoved, this);
    listener_changeSceneBtn->onTouchEnded = CC_CALLBACK_2
    (UnitScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_changeSceneBtn, TAG_HELLOMUNGGU);
    
    //홈버튼
    auto listener_homeBackBtn = EventListenerTouchOneByOne::create();
    listener_homeBackBtn->onTouchBegan = CC_CALLBACK_2
    (UnitScene::onTouchBegan, this);
    listener_homeBackBtn->onTouchMoved = CC_CALLBACK_2
    (UnitScene::onTouchMoved, this);
    listener_homeBackBtn->onTouchEnded = CC_CALLBACK_2
    (UnitScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_homeBackBtn, TAG_SPRITE_HOMEBACKBTN);
    ///
 

    
  
}

void UnitScene::initLabel(){
    
    mungGuDogSiteHpLv_Label->setVisible(true);
    mungGuDogSitePoLv_Label->setVisible(true);
    mungGuDogSiteRangeLv_Label->setVisible(true);

    mungGuLv_Label->setVisible(true);
    whangGuLv_Label->setVisible(true);
    mungBallLv_Label->setVisible(true);
    mungButterflyLv_Label->setVisible(true);
    mungSausageLv_Label->setVisible(true);
}

void UnitScene::setUnitBtn(){
    
    mungGuBtn = Sprite::create("mungGuBtn.png");
    mungGuBtn_ = Sprite::create("mungGuBtn_.png");
    mungGuBtn->setAnchorPoint(Point::ZERO);
    mungGuBtn_->setAnchorPoint(Point::ZERO);
    mungGuBtn->setPosition(Point(winSize.width/3,130));
    mungGuBtn_->setPosition(Point(winSize.width/3,130));
    mungGuBtn_->setVisible(false);
    this->addChild(mungGuBtn,10);
    this->addChild(mungGuBtn_,10);
    Rect mungRect = mungGuBtn->getBoundingBox();
    
    
    whangGuBtn = Sprite::create("whangGuBtn.png");
    whangGuBtn_ = Sprite::create("whangGuBtn_.png");
    whangGuBtn->setAnchorPoint(Point::ZERO);
    whangGuBtn_->setAnchorPoint(Point::ZERO);
    whangGuBtn->setPosition(Point(mungRect.getMaxX()+10,mungRect.getMinY()));
    whangGuBtn_->setPosition(Point(mungRect.getMaxX()+10,mungRect.getMinY()));
    whangGuBtn_->setVisible(false);
    this->addChild(whangGuBtn,10);
    this->addChild(whangGuBtn_,10);
    
    mungBallBtn = Sprite::create("mungBallBtn.png");
    mungBallBtn_ = Sprite::create("mungBallBtn_.png");
    mungBallBtn->setAnchorPoint(Point::ZERO);
    mungBallBtn_->setAnchorPoint(Point::ZERO);
    mungBallBtn->setPosition(Point(mungRect.getMaxX()+130,mungRect.getMinY()));
    mungBallBtn_->setPosition(Point(mungRect.getMaxX()+130,mungRect.getMinY()));
    mungBallBtn_->setVisible(false);
    this->addChild(mungBallBtn,10);
    this->addChild(mungBallBtn_,10);
    
    mungButterflyBtn = Sprite::create("mungButterflyBtn.png");
    mungButterflyBtn_ = Sprite::create("mungButterflyBtn_.png");
    mungButterflyBtn->setAnchorPoint(Point::ZERO);
    mungButterflyBtn_->setAnchorPoint(Point::ZERO);
    mungButterflyBtn->setPosition(Point(mungRect.getMaxX()+250,mungRect.getMinY()));
    mungButterflyBtn_->setPosition(Point(mungRect.getMaxX()+250,mungRect.getMinY()));
    mungButterflyBtn_->setVisible(false);
    this->addChild(mungButterflyBtn,10);
    this->addChild(mungButterflyBtn_,10);
    
    /////Lv Label
    mungSausageBtn = Sprite::create("mungSausageBtn.png");
    mungSausageBtn_ = Sprite::create("mungSausageBtn_.png");
    mungSausageBtn->setAnchorPoint(Point::ZERO);
    mungSausageBtn_->setAnchorPoint(Point::ZERO);
    mungSausageBtn->setPosition(Point(mungRect.getMaxX()+370,mungRect.getMinY()));
    mungSausageBtn_->setPosition(Point(mungRect.getMaxX()+370,mungRect.getMinY()));
    mungSausageBtn_->setVisible(false);
    this->addChild(mungSausageBtn,10);
    this->addChild(mungSausageBtn_,10);

    
    if(mungLv==0){
        cost1 = 10000;
    }else if(mungLv==1){
        cost1 = 500;
    }else if(mungLv==2){
        cost1 = 1000;
    }else if(mungLv==3){
        cost1 = 1500;
    }else if(mungLv==4){
        cost1 = 2000;
    }else if(mungLv==5){
        cost1 = 2500;
    }else if(mungLv==6){
        cost1 = 3000;
    }else if(mungLv==7){
        cost1 = 3500;
    }else if(mungLv==8){
        cost1 = 4000;
    }else if(mungLv==9){
        cost1 = 4500;
    }else if(mungLv==10){
        cost1 = 5000;
    }else if(mungLv==11){
        cost1 = 5500;
    }else if(mungLv==12){
        cost1 = 6000;
    }else if(mungLv==13){
        cost1 = 6500;
    }else if(mungLv==14){
        cost1 = 7000;
    }else if(mungLv==15){
        cost1 = 7500;
    }else if(mungLv==16){
        cost1 = 8000;
    }else if(mungLv==17){
        cost1 = 8500;
    }else if(mungLv==18){
        cost1 = 9000;
    }else if(mungLv==19){
        cost1 = 9500;
    }else if(mungLv==20){
        cost1 = 10000;
    }
    
    if(whangLv==0){
        cost2 = 6000;
        whangGuBtn_->setOpacity(60);
    }else if(whangLv==1){
        cost2 = 1000;
    }else if(whangLv==2){
        cost2 = 1600;
    }else if(whangLv==3){
        cost2 = 2200;
    }else if(whangLv==4){
        cost2 = 2800;
    }else if(whangLv==5){
        cost2 = 3400;
    }else if(whangLv==6){
        cost2 = 4000;
    }else if(whangLv==7){
        cost2 = 4600;
    }else if(whangLv==8){
        cost2 = 5200;
    }else if(whangLv==9){
        cost2 = 5800;
    }else if(whangLv==10){
        cost2 = 6500;
    }else if(whangLv==11){
        cost2 = 7000;
    }else if(whangLv==12){
        cost2 = 7600;
    }else if(whangLv==13){
        cost2 = 8200;
    }else if(whangLv==14){
        cost2 = 8800;
    }else if(whangLv==15){
        cost2 = 9400;
    }else if(whangLv==16){
        cost2 = 10000;
    }else if(whangLv==17){
        cost2 = 10600;
    }else if(whangLv==18){
        cost2 = 11200;
    }else if(whangLv==19){
        cost2 = 12800;
    }else if(whangLv==20){
        cost2 = 13500;
    }
    
    
    if(mungBallLv==0){
        cost3 = 7500;
        mungBallBtn_->setOpacity(60);
    }else if(mungBallLv==1){
        cost3 = 1200;
    }else if(mungBallLv==2){
        cost3 = 1700;
    }else if(mungBallLv==3){
        cost3 = 2200;
    }else if(mungBallLv==4){
        cost3 = 2700;
    }else if(mungBallLv==5){
        cost3 = 3200;
    }else if(mungBallLv==6){
        cost3 = 3700;
    }else if(mungBallLv==7){
        cost3 = 4200;
    }else if(mungBallLv==8){
        cost3 = 4700;
    }else if(mungBallLv==9){
        cost3 = 5200;
    }else if(mungBallLv==10){
        cost3 = 6000;
    }else if(mungBallLv==11){
        cost3 = 6800;
    }else if(mungBallLv==12){
        cost3 = 7600;
    }else if(mungBallLv==13){
        cost3 = 8400;
    }else if(mungBallLv==14){
        cost3 = 9200;
    }else if(mungBallLv==15){
        cost3 = 10000;
    }else if(mungBallLv==16){
        cost3 = 10800;
    }else if(mungBallLv==17){
        cost3 = 11600;
    }else if(mungBallLv==18){
        cost3 = 12400;
    }else if(mungBallLv==19){
        cost3 = 13200;
    }else if(mungBallLv==20){
        cost3 = 14000;
    }
    
    if(mungButLv==0){
        cost4 = 16000;
        mungButterflyBtn_->setOpacity(60);
    }else if(mungButLv==1){
        cost4 = 2000;
    }else if(mungButLv==2){
        cost4 = 2500;
    }else if(mungButLv==3){
        cost4 = 3000;
    }else if(mungButLv==4){
        cost4 = 3500;
    }else if(mungButLv==5){
        cost4 = 4000;
    }else if(mungButLv==6){
        cost4 = 4500;
    }else if(mungButLv==7){
        cost4 = 5000;
    }else if(mungButLv==8){
        cost4 = 5500;
    }else if(mungButLv==9){
        cost4 = 6000;
    }else if(mungButLv==10){
        cost4 = 6500;
    }else if(mungButLv==11){
        cost4 = 7000;
    }else if(mungButLv==12){
        cost4 = 7500;
    }else if(mungButLv==13){
        cost4 = 8000;
    }else if(mungButLv==14){
        cost4 = 8500;
    }else if(mungButLv==15){
        cost4 = 9000;
    }else if(mungButLv==16){
        cost4 = 9500;
    }else if(mungButLv==17){
        cost4 = 10000;
    }else if(mungButLv==18){
        cost4 = 10500;
    }else if(mungButLv==19){
        cost4 = 11000;
    }else if(mungButLv==20){
        cost4 = 12000;
    }
    
    if(mungSausageLv==0){
        cost5 = 20000;
        mungSausageBtn_->setOpacity(60);
    }else if(mungSausageLv==1){
        cost5 = 3000;
    }else if(mungSausageLv==2){
        cost5 = 4000;
    }else if(mungSausageLv==3){
        cost5 = 5000;
    }else if(mungSausageLv==4){
        cost5 = 6000;
    }else if(mungSausageLv==5){
        cost5 = 7000;
    }else if(mungSausageLv==6){
        cost5 = 8000;
    }else if(mungSausageLv==7){
        cost5 = 9000;
    }else if(mungSausageLv==8){
        cost5 = 10000;
    }else if(mungSausageLv==9){
        cost5 = 11000;
    }else if(mungSausageLv==10){
        cost5 = 12000;
    }else if(mungSausageLv==11){
        cost5 = 13000;
    }else if(mungSausageLv==12){
        cost5 = 14000;
    }else if(mungSausageLv==13){
        cost5 = 15000;
    }else if(mungSausageLv==14){
        cost5 = 16000;
    }else if(mungSausageLv==15){
        cost5 = 17000;
    }else if(mungSausageLv==16){
        cost5 = 18000;
    }else if(mungSausageLv==17){
        cost5 = 19000;
    }else if(mungSausageLv==18){
        cost5 = 20000;
    }else if(mungSausageLv==19){
        cost5 = 21000;
    }else if(mungSausageLv==20){
        cost5 = 22000;
    }

    
    //costBar/////
    costBar1 = Sprite::create("costBar.png");
    costBar2 = Sprite::create("costBar.png");
    costBar3 = Sprite::create("costBar.png");
    costBar4 = Sprite::create("costBar.png");
    costBar5 = Sprite::create("costBar.png");
    costBar1->setAnchorPoint(Point(0.5,1));
    costBar2->setAnchorPoint(Point(0.5,1));
    costBar3->setAnchorPoint(Point(0.5,1));
    costBar4->setAnchorPoint(Point(0.5,1));
    costBar5->setAnchorPoint(Point(0.5,1));
    costBar1->setPosition(Point(mungRect.getMidX(),mungRect.getMinY()));
    costBar2->setPosition(Point(mungRect.getMidX()+120,mungRect.getMinY()));
    costBar3->setPosition(Point(mungRect.getMidX()+240,mungRect.getMinY()));
    costBar4->setPosition(Point(mungRect.getMidX()+360,mungRect.getMinY()));
    costBar5->setPosition(Point(mungRect.getMidX()+480,mungRect.getMinY()));
    costBar1->setScale(2*winSize.width/1200);
    costBar2->setScale(2*winSize.width/1200);
    costBar3->setScale(2*winSize.width/1200);
    costBar4->setScale(2*winSize.width/1200);
    costBar5->setScale(2*winSize.width/1200);
    this->addChild(costBar1,10);
    this->addChild(costBar2,10);
    this->addChild(costBar3,10);
    this->addChild(costBar4,10);
    this->addChild(costBar5,10);
    
    costBar1_ = Sprite::create("costBar_.png");
    costBar2_ = Sprite::create("costBar_.png");
    costBar3_ = Sprite::create("costBar_.png");
    costBar4_ = Sprite::create("costBar_.png");
    costBar5_ = Sprite::create("costBar_.png");
    costBar1_->setAnchorPoint(Point(0.5,1));
    costBar2_->setAnchorPoint(Point(0.5,1));
    costBar3_->setAnchorPoint(Point(0.5,1));
    costBar4_->setAnchorPoint(Point(0.5,1));
    costBar5_->setAnchorPoint(Point(0.5,1));
    costBar1_->setPosition(Point(mungRect.getMidX(),mungRect.getMinY()));
    costBar2_->setPosition(Point(mungRect.getMidX()+120,mungRect.getMinY()));
    costBar3_->setPosition(Point(mungRect.getMidX()+240,mungRect.getMinY()));
    costBar4_->setPosition(Point(mungRect.getMidX()+360,mungRect.getMinY()));
    costBar5_->setPosition(Point(mungRect.getMidX()+480,mungRect.getMinY()));
    costBar1_->setScale(2*winSize.width/1200);
    costBar2_->setScale(2*winSize.width/1200);
    costBar3_->setScale(2*winSize.width/1200);
    costBar4_->setScale(2*winSize.width/1200);
    costBar5_->setScale(2*winSize.width/1200);
    costBar1_->setVisible(false);
    costBar2_->setVisible(false);
    costBar3_->setVisible(false);
    costBar4_->setVisible(false);
    costBar5_->setVisible(false);
    this->addChild(costBar1_,10);
    this->addChild(costBar2_,10);
    this->addChild(costBar3_,10);
    this->addChild(costBar4_,10);
    this->addChild(costBar5_,10);
    
    /////DogSite/////
    
    dogSite = Sprite::create("DogSite.png");
    dogSite->setAnchorPoint(Point(1,0));
    dogSite->setPosition(Point(mungRect.getMinX(),mungRect.getMaxY()));
    this->addChild(dogSite,10);
    dogSite->setScale(1.3*winSize.width/1200);
    Rect dogSiteRect = dogSite->getBoundingBox();
    
    ground = Sprite::create("ground_0.png");
    Rect groundRect = ground->getBoundingBox();
    ground->setScale(winSize.width/groundRect.size.width,1);
    ground->setPosition(Point(winSize.width/2,dogSiteRect.getMinY()+30));
    ground->setAnchorPoint(Point(0.5,1));
    ground->setOpacity(150);
    this->addChild(ground,9);
    
    costBarDogSiteHp = Sprite::create("costBar.png");
    costBarDogSiteHp->setPosition(dogSiteRect.getMaxX()-15,dogSiteRect.getMaxY()-15);
    costBarDogSiteHp->setScale(2*winSize.width/1200);
    costBarDogSiteHp->setAnchorPoint(Point(0,0));
    costBarDogSiteHp_ = Sprite::create("costBar_.png");
    costBarDogSiteHp_->setPosition(dogSiteRect.getMaxX()-15,dogSiteRect.getMaxY()-15);
    costBarDogSiteHp_->setScale(2*winSize.width/1200);
    costBarDogSiteHp_->setAnchorPoint(Point(0,0));
    costBarDogSitePo = Sprite::create("costBar.png");
    costBarDogSitePo->setPosition(dogSiteRect.getMaxX()+10,dogSiteRect.getMidY());
    costBarDogSitePo->setScale(2*winSize.width/1200);
    costBarDogSitePo->setAnchorPoint(Point(0,0.5));
    costBarDogSitePo_ = Sprite::create("costBar_.png");
    costBarDogSitePo_->setPosition(dogSiteRect.getMaxX()+10,dogSiteRect.getMidY());
    costBarDogSitePo_->setScale(2*winSize.width/1200);
    costBarDogSitePo_->setAnchorPoint(Point(0,0.5));
    
    costBarDogSiteRange = Sprite::create("costBar.png");
    costBarDogSiteRange->setPosition(dogSiteRect.getMaxX()+160,dogSiteRect.getMidY());
    costBarDogSiteRange->setScale(2*winSize.width/1200);
    costBarDogSiteRange->setAnchorPoint(Point(0,0.5));
    costBarDogSiteRange_ = Sprite::create("costBar_.png");
    costBarDogSiteRange_->setPosition(dogSiteRect.getMaxX()+160,dogSiteRect.getMidY());
    costBarDogSiteRange_->setScale(2*winSize.width/1200);
    costBarDogSiteRange_->setAnchorPoint(Point(0,0.5));
    
    costBarDogSiteRange_->setVisible(false);
    costBarDogSiteHp_->setVisible(false);
    costBarDogSitePo_->setVisible(false);
    
    this->addChild(costBarDogSiteHp,10);
    this->addChild(costBarDogSitePo,10);
    this->addChild(costBarDogSiteHp_,10);
    this->addChild(costBarDogSitePo_,10);
    this->addChild(costBarDogSiteRange,10);
    this->addChild(costBarDogSiteRange_,10);
    /////////

    
    costBar1_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost1), "NanumBarunGothic.otf",20);
    costBar2_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost2), "NanumBarunGothic.otf", 20);
    costBar3_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost3), "NanumBarunGothic.otf", 20);
    costBar4_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost4), "NanumBarunGothic.otf", 20);
    costBar5_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost5), "NanumBarunGothic.otf", 20);

    costBarDogSiteHp_Label= Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost_dogSiteHp), "NanumBarunGothic.otf", 20);
    costBarDogSitePo_Label= Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost_dogSitePo), "NanumBarunGothic.otf", 20);
    costBarDogSiteRange_Label= Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d", cost_dogSiteRange), "NanumBarunGothic.otf", 20);
    
    costBarDogSiteHp_Label->setScale(1*winSize.width/1200);
    costBar1_Rect = costBar1->getBoundingBox();
    costBar2_Rect = costBar2->getBoundingBox();
    costBar3_Rect = costBar3->getBoundingBox();
    costBar4_Rect = costBar4->getBoundingBox();
    costBar5_Rect = costBar5->getBoundingBox();
    costBarDogSiteHp_Rect = costBarDogSiteHp->getBoundingBox();
    costBarDogSitePo_Rect = costBarDogSitePo->getBoundingBox();
     costBarDogSiteRange_Rect = costBarDogSiteRange->getBoundingBox();
    
    costBar1_Label->setAnchorPoint(Point(0.5,0.5));
    costBar1_Label->setPosition(Point(costBar1_Rect.getMidX(),costBar1_Rect.getMidY()));
    costBar2_Label->setAnchorPoint(Point(0.5,0.5));
    costBar2_Label->setPosition(Point(costBar2_Rect.getMidX(),costBar2_Rect.getMidY()));
    costBar3_Label->setAnchorPoint(Point(0.5,0.5));
    costBar3_Label->setPosition(Point(costBar3_Rect.getMidX(),costBar3_Rect.getMidY()));
    costBar4_Label->setAnchorPoint(Point(0.5,0.5));
    costBar4_Label->setPosition(Point(costBar4_Rect.getMidX(),costBar4_Rect.getMidY()));
    costBar5_Label->setAnchorPoint(Point(0.5,0.5));
    costBar5_Label->setPosition(Point(costBar5_Rect.getMidX(),costBar5_Rect.getMidY()));
    costBarDogSiteHp_Label->setAnchorPoint(Point(0.5,0.5));
    costBarDogSiteHp_Label->setPosition(Point(costBarDogSiteHp_Rect.getMidX(),costBarDogSiteHp_Rect.getMidY()));
    costBarDogSitePo_Label->setAnchorPoint(Point(0.5,0.5));
    costBarDogSitePo_Label->setPosition(Point(costBarDogSitePo_Rect.getMidX(),costBarDogSitePo_Rect.getMidY()));
    costBarDogSiteRange_Label->setAnchorPoint(Point(0.5,0.5));
    costBarDogSiteRange_Label->setPosition(Point(costBarDogSiteRange_Rect.getMidX(),costBarDogSitePo_Rect.getMidY()));
    costBar1_Label->setScale(1*winSize.width/1200);
    costBar1_Label->setColor(Color3B::BLACK);
    costBar2_Label->setColor(Color3B::BLACK);
    costBar3_Label->setColor(Color3B::BLACK);
    costBar4_Label->setColor(Color3B::BLACK);
    costBar5_Label->setColor(Color3B::BLACK);
    costBarDogSiteHp_Label->setColor(Color3B::BLACK);
    costBarDogSitePo_Label->setColor(Color3B::BLACK);
    costBarDogSiteRange_Label->setColor(Color3B::BLACK);
    this->addChild(costBar1_Label,11);
    this->addChild(costBar2_Label,11);
    this->addChild(costBar3_Label,11);
    this->addChild(costBar4_Label,11);
    this->addChild(costBar5_Label,11);
    this->addChild(costBarDogSiteHp_Label,11);
    this->addChild(costBarDogSitePo_Label,11);
    this->addChild(costBarDogSiteRange_Label,11);
    
    
    Rect mungGuBtnRect = mungGuBtn->getBoundingBox();
    Rect whangGuBtnRect = whangGuBtn->getBoundingBox();
    Rect mungBallBtnRect = mungBallBtn->getBoundingBox();
    Rect mungButterflyBtnRect = mungButterflyBtn->getBoundingBox();
    Rect mungSausageBtnRect = mungSausageBtn->getBoundingBox();
    
    auto mungLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv"), "NanumBarunGothicBold.otf", 23);
    mungLv_Label->setAnchorPoint(Point(0.2,0.8));
    mungLv_Label->setColor(Color3B::BLACK);
    mungLv_Label->setPosition(Point(mungGuBtnRect.getMinX(),mungGuBtnRect.getMaxY()));
    this->addChild(mungLv_Label,13);
    
    auto mung2Lv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv"), "NanumBarunGothicBold.otf", 23);
    mung2Lv_Label->setAnchorPoint(Point(0.2,0.8));
    mung2Lv_Label->setColor(Color3B::BLACK);
    mung2Lv_Label->setPosition(Point(mungGuBtnRect.getMinX()+120,mungGuBtnRect.getMaxY()));
    this->addChild(mung2Lv_Label,13);
    
    auto mung3Lv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv"), "NanumBarunGothicBold.otf", 23);
    mung3Lv_Label->setAnchorPoint(Point(0.2,0.8));
    mung3Lv_Label->setColor(Color3B::BLACK);
    mung3Lv_Label->setPosition(Point(mungGuBtnRect.getMinX()+240,mungGuBtnRect.getMaxY()));
    this->addChild(mung3Lv_Label,13);
    
    auto mung4Lv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv"), "NanumBarunGothicBold.otf", 23);
    mung4Lv_Label->setAnchorPoint(Point(0.2,0.8));
    mung4Lv_Label->setColor(Color3B::BLACK);
    mung4Lv_Label->setPosition(Point(mungGuBtnRect.getMinX()+360,mungGuBtnRect.getMaxY()));
    this->addChild(mung4Lv_Label,13);
    
    auto mung5Lv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv"), "NanumBarunGothicBold.otf", 23);
    mung5Lv_Label->setAnchorPoint(Point(0.2,0.8));
    mung5Lv_Label->setColor(Color3B::BLACK);
    mung5Lv_Label->setPosition(Point(mungGuBtnRect.getMinX()+480,mungGuBtnRect.getMaxY()));
    this->addChild(mung5Lv_Label,13);
    
    auto mungGuDogSiteHp_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Hp Lv"), "NanumBarunGothicBold.otf", 20);
    mungGuDogSiteHp_Label->setAnchorPoint(Point(0,0));
    mungGuDogSiteHp_Label->setColor(Color3B::BLACK);
    mungGuDogSiteHp_Label->setPosition(Point(costBarDogSiteHp_Rect.getMinX(),costBarDogSiteHp_Rect.getMaxY()));
    this->addChild(mungGuDogSiteHp_Label,13);
    
    auto mungGuDogSitePo_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Power Lv"), "NanumBarunGothicBold.otf", 20);
    mungGuDogSitePo_Label->setAnchorPoint(Point(0,0));
    mungGuDogSitePo_Label->setColor(Color3B::BLACK);
    mungGuDogSitePo_Label->setPosition(Point(costBarDogSitePo_Rect.getMinX(),costBarDogSitePo_Rect.getMaxY()));
    this->addChild(mungGuDogSitePo_Label,13);
    
    auto mungGuDogSiteRange_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Range Lv"), "NanumBarunGothicBold.otf", 20);
    mungGuDogSiteRange_Label->setAnchorPoint(Point(0,0));
    mungGuDogSiteRange_Label->setColor(Color3B::BLACK);
    mungGuDogSiteRange_Label->setPosition(Point(costBarDogSiteRange_Rect.getMinX(),costBarDogSiteRange_Rect.getMaxY()));
    this->addChild(mungGuDogSiteRange_Label,13);
    Rect mungGuDogSiteHp_LabelRect =mungGuDogSiteHp_Label->getBoundingBox();
    Rect mungGuDogSitePo_LabelRect =mungGuDogSitePo_Label->getBoundingBox();
    Rect mungGuDogSiteRange_LabelRect =mungGuDogSiteRange_Label->getBoundingBox();
    ////
     //최고점수 표시할 라벨 선언

    mungLv = UserDefault::getInstance()->getIntegerForKey("mungLv");
    if(mungLv == 20){
        mungGuLv_Label = Label::createWithTTF(StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 16);
    }else{
    mungGuLv_Label = Label::createWithTTF(StringUtils::format("Lv %d",mungLv), "NanumBarunGothicBold.otf", 16);
    
    }
    mungGuLv_Label->setAnchorPoint(Point(0.5,0));
    mungGuLv_Label->setColor(Color3B::RED);
    mungGuLv_Label->setPosition(Point(mungGuBtnRect.getMidX(),mungGuBtnRect.getMinY()+10));
    this->addChild(mungGuLv_Label,13);

    whangLv = UserDefault::getInstance()->getIntegerForKey("whangLv");
    if(whangLv == 20){
        whangGuLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 16);
    }else if(whangLv==0){
        whangGuBtn->setVisible(false);
        whangGuBtn_->setVisible(true);
        whangGuLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Get"), "NanumBarunGothicBold.otf", 16);
       whangGuLv_Label-> setColor(Color3B::BLACK);
    }else{
    whangGuLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv %d",whangLv), "NanumBarunGothicBold.otf", 16);
         whangGuLv_Label->setColor(Color3B::RED);
    }
    whangGuLv_Label->setAnchorPoint(Point(0.5,0));

    whangGuLv_Label->setColor(Color3B::RED);
    whangGuLv_Label->setPosition(Point(whangGuBtnRect.getMidX(),whangGuBtnRect.getMinY()+10));
    this->addChild(whangGuLv_Label,13);
    
    mungBallLv = UserDefault::getInstance()->getIntegerForKey("mungBallLv");
    if(mungBallLv == 20){
        mungBallLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 16);
        
    }else if(mungBallLv==0){
        mungBallBtn->setVisible(false);
        mungBallBtn_->setVisible(true);
        mungBallLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Get",mungBallLv), "NanumBarunGothicBold.otf", 16);
        mungBallLv_Label->setColor(Color3B::BLACK);
    }else{
    mungBallLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv %d",mungBallLv), "NanumBarunGothicBold.otf", 16);
        mungBallLv_Label->setColor(Color3B::RED);

    }
    mungBallLv_Label->setAnchorPoint(Point(0.5,0));
    mungBallLv_Label->setColor(Color3B::RED);
    mungBallLv_Label->setPosition(Point(mungBallBtnRect.getMidX(),mungBallBtnRect.getMinY()+10));
    this->addChild(mungBallLv_Label,13);
    
    mungButLv = UserDefault::getInstance()->getIntegerForKey("mungButLv");
    if(mungButLv == 20){
        mungButterflyLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 16);
        
    }else if(mungButLv==0){
        mungButterflyBtn->setVisible(false);
        mungButterflyBtn_->setVisible(true);
        mungButterflyLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Get",mungButLv), "NanumBarunGothicBold.otf", 16);
        mungButterflyLv_Label->setColor(Color3B::BLACK);
    }else{
    mungButterflyLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv %d",mungButLv), "NanumBarunGothicBold.otf", 16);
         mungButterflyLv_Label->setColor(Color3B::RED);
    
    }
    mungButterflyLv_Label->setAnchorPoint(Point(0.5,0));
   mungButterflyLv_Label->setColor(Color3B::RED);
    mungButterflyLv_Label->setPosition(Point(mungButterflyBtnRect.getMidX(),mungButterflyBtnRect.getMinY()+10));
    this->addChild(mungButterflyLv_Label,13);
    
    mungSausageLv = UserDefault::getInstance()->getIntegerForKey("mungSausageLv");
    if(mungSausageLv == 20){
        mungSausageLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 16);
        
    }else if(mungSausageLv==0){
        mungSausageBtn->setVisible(false);
        mungSausageBtn_->setVisible(true);
        mungSausageLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Get",mungSausageLv), "NanumBarunGothicBold.otf", 16);
        mungSausageLv_Label->setColor(Color3B::BLACK);
    }else{
    mungSausageLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lv %d",mungSausageLv), "NanumBarunGothicBold.otf", 16);
         mungSausageLv_Label->setColor(Color3B::RED);
   
    }
    mungSausageLv_Label->setAnchorPoint(Point(0.5,0));
   mungSausageLv_Label->setColor(Color3B::RED);
    mungSausageLv_Label->setPosition(Point(mungSausageBtnRect.getMidX(),mungSausageBtnRect.getMinY()+10));
    this->addChild(mungSausageLv_Label,13);
    
    
    //멍구 기지 라벨
    mungGuDogSiteHpLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteHpLv");
    if(mungGuDogSiteHpLv == 30){
        mungGuDogSiteHpLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 30);

    }else{
    mungGuDogSiteHpLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d",mungGuDogSiteHpLv), "NanumBarunGothicBold.otf", 30);
   
    }
    mungGuDogSiteHpLv_Label->setAnchorPoint(Point(0,0.5));
    mungGuDogSiteHpLv_Label->setColor(Color3B::RED);
    mungGuDogSiteHpLv_Label->setPosition(Point(mungGuDogSiteHp_LabelRect.getMaxX(),mungGuDogSiteHp_LabelRect.getMidY()));
    this->addChild(mungGuDogSiteHpLv_Label,13);
    
    
    //포
    mungGuDogSitePoLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSitePoLv");
    if(mungGuDogSitePoLv == 20){
        mungGuDogSitePoLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 30);
        
    }else{
    mungGuDogSitePoLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("%d",mungGuDogSitePoLv), "NanumBarunGothicBold.otf", 30);
    
    }
    mungGuDogSitePoLv_Label->setAnchorPoint(Point(0,0.5));
    mungGuDogSitePoLv_Label->setColor(Color3B::RED);
    mungGuDogSitePoLv_Label->setPosition(Point(mungGuDogSitePo_LabelRect.getMaxX(),mungGuDogSitePo_LabelRect.getMidY()));
    this->addChild(mungGuDogSitePoLv_Label,13);
    
    
    //범위
    mungGuDogSiteRangeLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteRangeLv");
    if(mungGuDogSiteRangeLv == 20){
        mungGuDogSiteRangeLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 30);
        
    }else{
        mungGuDogSiteRangeLv_Label = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("%d",mungGuDogSiteRangeLv), "NanumBarunGothicBold.otf", 30);
        
    }
    mungGuDogSiteRangeLv_Label->setAnchorPoint(Point(0,0.5));
    mungGuDogSiteRangeLv_Label->setColor(Color3B::RED);
    mungGuDogSiteRangeLv_Label->setPosition(Point(mungGuDogSiteRange_LabelRect.getMaxX(),mungGuDogSiteRange_LabelRect.getMidY()));
    this->addChild(mungGuDogSiteRangeLv_Label,13);

    
    myGold = UserDefault::getInstance()->getIntegerForKey("myGold");
    goldArea = Sprite::create("GoldArea.png");
    goldArea->setPosition(Point(winSize.width, winSize.height));
    goldArea->setAnchorPoint(Point(1, 1));
    //goldArea->setTag(TAG_SPRITE_GOLDAREA);
    this->addChild(goldArea, 5);
    goldAreaRect = goldArea->getBoundingBox();
    
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
    
    if(initByEnglish==true){
    UnitSceneTheme = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Unit"), "NanumBarunGothicBold.otf", 46);
    }else{
    UnitSceneTheme = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("유닛"), "NanumBarunGothicBold.otf", 46);
    }

    UnitSceneTheme->setColor(Color3B::BLACK);
    UnitSceneTheme->setPosition(Point(winSize.width/2,winSize.height*9/10));
    UnitSceneTheme->setAnchorPoint(Point(0.5,1));
    this->addChild(UnitSceneTheme,2);
    
    
    if(initByEnglish==true){
    exLabel = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format(" \n button Click \n     -> ability up!"), "NanumBarunGothicBold.otf", 25);
    }else{
        exLabel = Label::createWithTTF //상태버튼 maxMoney
        (StringUtils::format(" \n 버튼 누름 \n     -> 강화!"), "NanumBarunGothicBold.otf", 25);
    }
    exLabel->setColor(Color3B(200,20,20));
    exLabel->setPosition(Point(winSize.width*3/4,winSize.height*4/5));
    exLabel->setAnchorPoint(Point(0.5,1));
    this->addChild(exLabel,2);
   
    
    mainImage = Sprite::create("MungGuBackground.png");
    Rect mainImageRect = mainImage->getBoundingBox();
    mainImage->setScale(winSize.width/mainImageRect.size.width, winSize.height/mainImageRect.size.height);
    mainImage->setPosition(winSize.width/2, winSize.height/2);
    this->addChild(mainImage,1);
    
    
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

    //mungGuDogSiteHp_Label
    //mungGuDogSiteHpLv_Label
}
void UnitScene::changeScene(Ref *sender){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = TransitionFade::create(0.6, MungGuGameMenuScene::createScene());
    Director::getInstance()->replaceScene(scene);
}
void UnitScene::changeScene(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    Director::getInstance()->replaceScene(MungGuGameMenuScene::createScene());

}

bool UnitScene::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
    Point loc = touch->getLocation();
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
//    costBar1_Rect = costBar1->getBoundingBox();
//    costBar2_Rect = costBar2->getBoundingBox();
//    costBar3_Rect = costBar3->getBoundingBox();
//    costBar4_Rect = costBar4->getBoundingBox();
//    costBar5_Rect = costBar5->getBoundingBox();
//    costBarDogSiteHp_Rect = costBarDogSiteHp->getBoundingBox();
//    costBarDogSitePo_Rect = costBarDogSitePo->getBoundingBox();
    
    if(homeBackBtnRect.containsPoint(loc)){
        isReturnBtn = true;
        homeBackBtn->setVisible(false);
        homeBackBtn_->setVisible(true);
    }
    
    if(costBar1_Rect.containsPoint(loc)){
        isM1CostTouched = true;
        costBar1->setVisible(false);
        costBar1_->setVisible(true);
    }else if(costBar2_Rect.containsPoint(loc)){
        isM2CostTouched = true;
        costBar2->setVisible(false);
        costBar2_->setVisible(true);
    }else if(costBar3_Rect.containsPoint(loc)){
        isM3CostTouched = true;
        costBar3->setVisible(false);
        costBar3_->setVisible(true);
    }else if(costBar4_Rect.containsPoint(loc)){
        isM4CostTouched = true;
        costBar4->setVisible(false);
        costBar4_->setVisible(true);
    }else if(costBar5_Rect.containsPoint(loc)){
        isM5CostTouched = true;
        costBar5->setVisible(false);
        costBar5_->setVisible(true);
    }else if(costBarDogSiteHp_Rect.containsPoint(loc)){
        isDogSiteHpCostTouched = true;
        costBarDogSiteHp->setVisible(false);
        costBarDogSiteHp_->setVisible(true);
    }else if(costBarDogSitePo_Rect.containsPoint(loc)){
        isDogSitePoCostTouched = true;
        costBarDogSitePo->setVisible(false);
        costBarDogSitePo_->setVisible(true);
    }else if(costBarDogSiteRange_Rect.containsPoint(loc)){
        isDogSiteRangeCostTouched = true;
        costBarDogSiteRange->setVisible(false);
        costBarDogSiteRange_->setVisible(true);
    }
    
    
    
    
    
    
    
       return true;
}
void UnitScene::onTouchMoved(Touch *touch, Event *unused_event){
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
    
   
}
void UnitScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    Point loc = touch->getLocation();
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    isReturnBtn = false;


    
    if(homeBackBtnRect.containsPoint(loc)){

        homeBackBtn->setVisible(true);
        homeBackBtn_->setVisible(false);
        changeScene(this);
    }
    
    
        if(isM1CostTouched == true){//1번째 버튼 코스트
            isM1CostTouched = false;
            if(mungLv != 20){
            costBar1->setVisible(true);
            costBar1_->setVisible(false);
            }
            if(costBar1_Rect.containsPoint(loc)){
                
                if((myGold >= cost1)&&(mungLv<=19)){
                    if (isSong == true){
                        SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                    }
                    auto blinkAction = Blink::create(1,6);
                     auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                    
                 UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost1);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                    
                    
                    UserDefault::getInstance()->setIntegerForKey("mungLv",mungLv+1);
                    mungLv = UserDefault::getInstance()->getIntegerForKey("mungLv");
                    
                    if(mungLv==0){
                        cost1 = 10000;
                    }else if(mungLv==1){
                        cost1 = 500;
                    }else if(mungLv==2){
                        cost1 = 1000;
                    }else if(mungLv==3){
                        cost1 = 1500;
                    }else if(mungLv==4){
                        cost1 = 2000;
                    }else if(mungLv==5){
                        cost1 = 2500;
                    }else if(mungLv==6){
                        cost1 = 3000;
                    }else if(mungLv==7){
                        cost1 = 3500;
                    }else if(mungLv==8){
                        cost1 = 4000;
                    }else if(mungLv==9){
                        cost1 = 4500;
                    }else if(mungLv==10){
                        cost1 = 5000;
                    }else if(mungLv==11){
                        cost1 = 5500;
                    }else if(mungLv==12){
                        cost1 = 6000;
                    }else if(mungLv==13){
                        cost1 = 6500;
                    }else if(mungLv==14){
                        cost1 = 7000;
                    }else if(mungLv==15){
                        cost1 = 7500;
                    }else if(mungLv==16){
                        cost1 = 8000;
                    }else if(mungLv==17){
                        cost1 = 8500;
                    }else if(mungLv==18){
                        cost1 = 9000;
                    }else if(mungLv==19){
                        cost1 = 9500;
                    }else if(mungLv==20){
                        cost1 = 10000;
                        costBar1->setVisible(false);
                        costBar1_->setVisible(true);

                    }
                    
                    
    costBar1_Label->setString(StringUtils::format("%d", cost1));
                    
                    if(mungLv == 20){
                        mungGuLv_Label->setString(StringUtils::format("MAX"));

                    }else{
                    mungGuLv_Label->setString(StringUtils::format("Lv %d", mungLv));
                    }
                
                    
                    mungGuLv_Label->runAction(action);
                }
                
        }
        
        
    }else if(isM2CostTouched == true){//2번째 버튼 코스트
            isM2CostTouched = false;
        if(whangLv != 20){
        costBar2->setVisible(true);
        costBar2_->setVisible(false);
        }
        if(costBar2_Rect.containsPoint(loc)){
            
            if((myGold >= cost2)&&(whangLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost2);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()->setIntegerForKey("whangLv",whangLv+1);
                whangLv = UserDefault::getInstance()->getIntegerForKey("whangLv");
                
                
                
                
                if(whangLv==0){
                    cost2 = 6000;
                    whangGuBtn_->setOpacity(60);
                }else if(whangLv==1){
                    cost2 = 1000;
                    whangGuLv_Label->setColor(Color3B::RED);
                }else if(whangLv==2){
                    cost2 = 1600;
                }else if(whangLv==3){
                    cost2 = 2200;
                }else if(whangLv==4){
                    cost2 = 2800;
                }else if(whangLv==5){
                    cost2 = 3400;
                }else if(whangLv==6){
                    cost2 = 4000;
                }else if(whangLv==7){
                    cost2 = 4600;
                }else if(whangLv==8){
                    cost2 = 5200;
                }else if(whangLv==9){
                    cost2 = 5800;
                }else if(whangLv==10){
                    cost2 = 6500;
                }else if(whangLv==11){
                    cost2 = 7000;
                }else if(whangLv==12){
                    cost2 = 7600;
                }else if(whangLv==13){
                    cost2 = 8200;
                }else if(whangLv==14){
                    cost2 = 8800;
                }else if(whangLv==15){
                    cost2 = 9400;
                }else if(whangLv==16){
                    cost2 = 10000;
                }else if(whangLv==17){
                    cost2 = 10600;
                }else if(whangLv==18){
                    cost2 = 11200;
                }else if(whangLv==19){
                    cost2 = 12800;
                }else if(whangLv==20){
                    cost2 = 13500;
                    costBar2->setVisible(false);
                    costBar2_->setVisible(true);

                }
                
                
               
                costBar2_Label->setString(StringUtils::format("%d", cost2));
                
                if(whangLv == 20){
                    whangGuLv_Label->setString(StringUtils::format("MAX"));
                    
                }else if(whangLv == 1){
                    whangGuBtn->setVisible(true);
                    whangGuBtn_->setVisible(false);
                    
                    whangGuLv_Label->setString(StringUtils::format("Lv %d", whangLv));
                }else{
                    whangGuLv_Label->setString(StringUtils::format("Lv %d", whangLv));
                }
                
                
                whangGuLv_Label->runAction(action);
            }
            
        
        }
        
        
    }else if(isM3CostTouched == true){//3번째 버튼 코스트
            isM3CostTouched = false;
        if(mungBallLv != 20){
        costBar3->setVisible(true);
        costBar3_->setVisible(false);
        }
        if(costBar3_Rect.containsPoint(loc)){
            
            if((myGold >= cost3)&&(mungBallLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost3);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                UserDefault::getInstance()->setIntegerForKey("mungBallLv",mungBallLv+1);
                mungBallLv = UserDefault::getInstance()->getIntegerForKey("mungBallLv");
                
                
                
                if(mungBallLv==0){
                    cost3 = 7500;
                    mungBallBtn_->setOpacity(60);
                }else if(mungBallLv==1){
                    cost3 = 1200;
                    mungBallLv_Label->setColor(Color3B::RED);
                }else if(mungBallLv==2){
                    cost3 = 1700;
                }else if(mungBallLv==3){
                    cost3 = 2200;
                }else if(mungBallLv==4){
                    cost3 = 2700;
                }else if(mungBallLv==5){
                    cost3 = 3200;
                }else if(mungBallLv==6){
                    cost3 = 3700;
                }else if(mungBallLv==7){
                    cost3 = 4200;
                }else if(mungBallLv==8){
                    cost3 = 4700;
                }else if(mungBallLv==9){
                    cost3 = 5200;
                }else if(mungBallLv==10){
                    cost3 = 6000;
                }else if(mungBallLv==11){
                    cost3 = 6800;
                }else if(mungBallLv==12){
                    cost3 = 7600;
                }else if(mungBallLv==13){
                    cost3 = 8400;
                }else if(mungBallLv==14){
                    cost3 = 9200;
                }else if(mungBallLv==15){
                    cost3 = 10000;
                }else if(mungBallLv==16){
                    cost3 = 10800;
                }else if(mungBallLv==17){
                    cost3 = 11600;
                }else if(mungBallLv==18){
                    cost3 = 12400;
                }else if(mungBallLv==19){
                    cost3 = 13200;
                }else if(mungBallLv==20){
                    cost3 = 14000;
                    costBar3->setVisible(false);
                    costBar3_->setVisible(true);
                    
                }
                
                
           
                
                costBar3_Label->setString(StringUtils::format("%d", cost3));
                
                
                
                if(mungBallLv == 20){
                    mungBallLv_Label->setString(StringUtils::format("MAX"));
                    
                }else if(mungBallLv == 1){
                    mungBallBtn->setVisible(true);
                    mungBallBtn_->setVisible(false);
                    
                    mungBallLv_Label->setString(StringUtils::format("Lv %d", mungBallLv));
                }else{
                    mungBallLv_Label->setString(StringUtils::format("Lv %d", mungBallLv));
                }
                
                
                mungBallLv_Label->runAction(action);
            }
        
        }
        
    }else if(isM4CostTouched == true){//4번째 버튼 코스트
            isM4CostTouched = false;
        if(mungButLv != 20){
        costBar4->setVisible(true);
        costBar4_->setVisible(false);
        }
        if(costBar4_Rect.containsPoint(loc)){
            
            if((myGold >= cost4)&&(mungButLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost4);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()->setIntegerForKey("mungButLv",mungButLv+1);
                mungButLv = UserDefault::getInstance()->getIntegerForKey("mungButLv");
             

                if(mungButLv==0){
                    cost4 = 16000;
                    mungButterflyBtn_->setOpacity(60);
                }else if(mungButLv==1){
                    cost4 = 2000;
                    mungButterflyLv_Label->setColor(Color3B::RED);
                }else if(mungButLv==2){
                    cost4 = 2500;
                }else if(mungButLv==3){
                    cost4 = 3000;
                }else if(mungButLv==4){
                    cost4 = 3500;
                }else if(mungButLv==5){
                    cost4 = 4000;
                }else if(mungButLv==6){
                    cost4 = 4500;
                }else if(mungButLv==7){
                    cost4 = 5000;
                }else if(mungButLv==8){
                    cost4 = 5500;
                }else if(mungButLv==9){
                    cost4 = 6000;
                }else if(mungButLv==10){
                    cost4 = 6500;
                }else if(mungButLv==11){
                    cost4 = 7000;
                }else if(mungButLv==12){
                    cost4 = 7500;
                }else if(mungButLv==13){
                    cost4 = 8000;
                }else if(mungButLv==14){
                    cost4 = 8500;
                }else if(mungButLv==15){
                    cost4 = 9000;
                }else if(mungButLv==16){
                    cost4 = 9500;
                }else if(mungButLv==17){
                    cost4 = 10000;
                }else if(mungButLv==18){
                    cost4 = 10500;
                }else if(mungButLv==19){
                    cost4 = 11000;
                }else if(mungButLv==20){
                    cost4 = 12000;
                    costBar4->setVisible(false);
                    costBar4_->setVisible(true);
                }
    costBar4_Label->setString(StringUtils::format("%d", cost4));
                
                if(mungButLv == 20){
                    mungButterflyLv_Label->setString(StringUtils::format("MAX"));
                    
                }else if(mungButLv == 1){
                    mungButterflyBtn->setVisible(true);
                    mungButterflyBtn_->setVisible(false);
                    
                    mungButterflyLv_Label->setString(StringUtils::format("Lv %d", mungButLv));
                }else{
                    mungButterflyLv_Label->setString(StringUtils::format("Lv %d", mungButLv));
                }
                
                
                mungButterflyLv_Label->runAction(action);
            }
            
            
               }
        
    }else if(isM5CostTouched == true){//5번째 버튼 코스트
            isM5CostTouched = false;
        if(mungSausageLv != 20){
        costBar5->setVisible(true);
        costBar5_->setVisible(false);
        }
        if(costBar5_Rect.containsPoint(loc)){
            
            if((myGold >= cost5)&&(mungSausageLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost5);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()->setIntegerForKey("mungSausageLv",mungSausageLv+1);
                mungSausageLv = UserDefault::getInstance()->getIntegerForKey("mungSausageLv");
                
                if(mungSausageLv==0){
                    cost5 = 20000;
                    mungSausageBtn_->setOpacity(60);
                }else if(mungSausageLv==1){
                    cost5 = 3000;
                    mungSausageLv_Label->setColor(Color3B::RED);
                }else if(mungSausageLv==2){
                    cost5 = 4000;
                }else if(mungSausageLv==3){
                    cost5 = 5000;
                }else if(mungSausageLv==4){
                    cost5 = 6000;
                }else if(mungSausageLv==5){
                    cost5 = 7000;
                }else if(mungSausageLv==6){
                    cost5 = 8000;
                }else if(mungSausageLv==7){
                    cost5 = 9000;
                }else if(mungSausageLv==8){
                    cost5 = 10000;
                }else if(mungSausageLv==9){
                    cost5 = 11000;
                }else if(mungSausageLv==10){
                    cost5 = 12000;
                }else if(mungSausageLv==11){
                    cost5 = 13000;
                }else if(mungSausageLv==12){
                    cost5 = 14000;
                }else if(mungSausageLv==13){
                    cost5 = 15000;
                }else if(mungSausageLv==14){
                    cost5 = 16000;
                }else if(mungSausageLv==15){
                    cost5 = 17000;
                }else if(mungSausageLv==16){
                    cost5 = 18000;
                }else if(mungSausageLv==17){
                    cost5 = 19000;
                }else if(mungSausageLv==18){
                    cost5 = 20000;
                }else if(mungSausageLv==19){
                    cost5 = 21000;
                }else if(mungSausageLv==20){
                    cost5 = 22000;
                    costBar5->setVisible(false);
                    costBar5_->setVisible(true);
            }
                
                costBar5_Label->setString(StringUtils::format("%d",cost5));
                
                if(mungSausageLv == 20){
                    mungSausageLv_Label->setString(StringUtils::format("MAX"));
                    
                }else if(mungSausageLv == 1){
                    mungSausageBtn->setVisible(true);
                    mungSausageBtn_->setVisible(false);
                    
                    mungSausageLv_Label->setString(StringUtils::format("Lv %d", mungSausageLv));
                }else{
                    mungSausageLv_Label->setString(StringUtils::format("Lv %d", mungSausageLv));
                }
                
                
                mungSausageLv_Label->runAction(action);
            }
        }
        
        
    }else if(isDogSiteHpCostTouched == true){//hp 버튼 코스트
            isDogSiteHpCostTouched = false;
         if(mungGuDogSiteHpLv != 30){
        costBarDogSiteHp->setVisible(true);
        costBarDogSiteHp_->setVisible(false);
         }
        if(costBarDogSiteHp_Rect.containsPoint(loc)){

            if((myGold >= cost_dogSiteHp)&&(mungGuDogSiteHpLv<=29)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost_dogSiteHp);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()
                ->setIntegerForKey("mungGuDogSiteHpLv",mungGuDogSiteHpLv+1);
                mungGuDogSiteHpLv = UserDefault::getInstance()
                ->getIntegerForKey("mungGuDogSiteHpLv");
                
                if(mungGuDogSiteHpLv==1){
                    cost_dogSiteHp = 3500;
                }else if(mungGuDogSiteHpLv==2){
                    cost_dogSiteHp = 4000;
                }else if(mungGuDogSiteHpLv==3){
                    cost_dogSiteHp = 4500;
                }else if(mungGuDogSiteHpLv==4){
                    cost_dogSiteHp = 4000;
                }else if(mungGuDogSiteHpLv==5){
                    cost_dogSiteHp = 4500;
                }else if(mungGuDogSiteHpLv==6){
                    cost_dogSiteHp = 5000;
                }else if(mungGuDogSiteHpLv==7){
                    cost_dogSiteHp = 5500;
                }else if(mungGuDogSiteHpLv==8){
                    cost_dogSiteHp = 6000;
                }else if(mungGuDogSiteHpLv==9){
                    cost_dogSiteHp = 6500;
                }else if(mungGuDogSiteHpLv==10){
                    cost_dogSiteHp = 7000;
                }else if(mungGuDogSiteHpLv==11){
                    cost_dogSiteHp = 7500;
                }else if(mungGuDogSiteHpLv==12){
                    cost_dogSiteHp = 8000;
                }else if(mungGuDogSiteHpLv==13){
                    cost_dogSiteHp = 8500;
                }else if(mungGuDogSiteHpLv==14){
                    cost_dogSiteHp = 9000;
                }else if(mungGuDogSiteHpLv==15){
                    cost_dogSiteHp = 9500;
                }else if(mungGuDogSiteHpLv==16){
                    cost_dogSiteHp = 10000;
                }else if(mungGuDogSiteHpLv==17){
                    cost_dogSiteHp = 10500;
                }else if(mungGuDogSiteHpLv==18){
                    cost_dogSiteHp = 11000;
                }else if(mungGuDogSiteHpLv==19){
                    cost_dogSiteHp = 11500;
                }else if(mungGuDogSiteHpLv==20){
                    cost_dogSiteHp = 12000;
                    
                }else if(mungGuDogSiteHpLv==21){
                    cost_dogSiteHp = 12500;
                }else if(mungGuDogSiteHpLv==22){
                    cost_dogSiteHp = 13000;
                }else if(mungGuDogSiteHpLv==23){
                    cost_dogSiteHp = 13500;
                }else if(mungGuDogSiteHpLv==24){
                    cost_dogSiteHp = 14000;
                }else if(mungGuDogSiteHpLv==25){
                    cost_dogSiteHp = 14500;
                }else if(mungGuDogSiteHpLv==26){
                    cost_dogSiteHp = 15000;
                }else if(mungGuDogSiteHpLv==27){
                    cost_dogSiteHp = 15500;
                }else if(mungGuDogSiteHpLv==28){
                    cost_dogSiteHp = 16000;
                }else if(mungGuDogSiteHpLv==29){
                    cost_dogSiteHp = 16500;
                }else if(mungGuDogSiteHpLv==30){
                    cost_dogSiteHp = 17000;
                    costBarDogSiteHp->setVisible(false);
                    costBarDogSiteHp_->setVisible(true);
                }
    
                costBarDogSiteHp_Label->setString(StringUtils::format("%d", cost_dogSiteHp));
                
                if(mungGuDogSiteHpLv == 30){
                    mungGuDogSiteHpLv_Label->setString(StringUtils::format("MAX"));
                    
                }else{
                    mungGuDogSiteHpLv_Label->setString(StringUtils::format("%d", mungGuDogSiteHpLv));
                }
                
                
                mungGuDogSiteHpLv_Label->runAction(action);
            }
        
        }
        
    }else if(isDogSitePoCostTouched ==true){//po 버튼 코스트
            isDogSitePoCostTouched = false;
        if(mungGuDogSitePoLv!=20){
        costBarDogSitePo->setVisible(true);
        costBarDogSitePo_->setVisible(false);
        }
        if(costBarDogSitePo_Rect.containsPoint(loc)){
            
            if((myGold >= cost_dogSitePo)&&(mungGuDogSitePoLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost_dogSitePo);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()
                ->setIntegerForKey("mungGuDogSitePoLv",mungGuDogSitePoLv+1);
                mungGuDogSitePoLv = UserDefault::getInstance()
                ->getIntegerForKey("mungGuDogSitePoLv");
                
                if(mungGuDogSitePoLv==1){
                    cost_dogSitePo = 5000;
                }else if(mungGuDogSitePoLv==2){
                    cost_dogSitePo = 5250;
                }else if(mungGuDogSitePoLv==3){
                    cost_dogSitePo = 5500;
                }else if(mungGuDogSitePoLv==4){
                    cost_dogSitePo = 5750;
                }else if(mungGuDogSitePoLv==5){
                    cost_dogSitePo = 6000;
                }else if(mungGuDogSitePoLv==6){
                    cost_dogSitePo = 6250;
                }else if(mungGuDogSitePoLv==7){
                    cost_dogSitePo = 6500;
                }else if(mungGuDogSitePoLv==8){
                    cost_dogSitePo = 6750;
                }else if(mungGuDogSitePoLv==9){
                    cost_dogSitePo = 7000;
                }else if(mungGuDogSitePoLv==10){
                    cost_dogSitePo = 7250;
                }else if(mungGuDogSitePoLv==11){
                    cost_dogSitePo = 7500;
                }else if(mungGuDogSitePoLv==12){
                    cost_dogSitePo = 8000;
                }else if(mungGuDogSitePoLv==13){
                    cost_dogSitePo = 8500;
                }else if(mungGuDogSitePoLv==14){
                    cost_dogSitePo = 9000;
                }else if(mungGuDogSitePoLv==15){
                    cost_dogSitePo = 9500;
                }else if(mungGuDogSitePoLv==16){
                    cost_dogSitePo = 10000;
                }else if(mungGuDogSitePoLv==17){
                    cost_dogSitePo = 10500;
                }else if(mungGuDogSitePoLv==18){
                    cost_dogSitePo = 11000;
                }else if(mungGuDogSitePoLv==19){
                    cost_dogSitePo = 11500;
                }else if(mungGuDogSitePoLv==20){
                    cost_dogSitePo = 12000;
                    costBarDogSitePo->setVisible(false);
                    costBarDogSitePo_->setVisible(true);
                }
                
                costBarDogSitePo_Label->setString(StringUtils::format("%d", cost_dogSitePo));
                
                if(mungGuDogSitePoLv == 20){
                    mungGuDogSitePoLv_Label->setString(StringUtils::format("MAX"));
                    
                }else{
                    mungGuDogSitePoLv_Label->setString(StringUtils::format("%d", mungGuDogSitePoLv));
                }
                
                
                mungGuDogSitePoLv_Label->runAction(action);
            }
        
        }
    }else if(isDogSiteRangeCostTouched==true){//po 버튼 코스트
        isDogSiteRangeCostTouched = false;
        if(mungGuDogSiteRangeLv!=20){
            costBarDogSiteRange->setVisible(true);
            costBarDogSiteRange_->setVisible(false);
        }
        if(costBarDogSiteRange_Rect.containsPoint(loc)){
            
            if((myGold >= cost_dogSiteRange)&&(mungGuDogSiteRangeLv<=19)){
                if (isSong == true){
                    SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
                }
                auto blinkAction = Blink::create(1,6);
                auto action = Sequence::create(blinkAction,CallFunc::create(this,callfunc_selector(UnitScene::initLabel)),NULL);
                
                UserDefault::getInstance()->setIntegerForKey("myGold",myGold-cost_dogSiteRange);//
                myGold = UserDefault::getInstance()->getIntegerForKey("myGold"); //내 돈 값 받아
                myGold_label->setString(StringUtils::format("%d", myGold));//소지금 업뎃
                
                
                UserDefault::getInstance()
                ->setIntegerForKey("mungGuDogSiteRangeLv",mungGuDogSiteRangeLv+1);
                mungGuDogSiteRangeLv = UserDefault::getInstance()
                ->getIntegerForKey("mungGuDogSiteRangeLv");
                
                if(mungGuDogSiteRangeLv==1){
                    cost_dogSiteRange = 2500;
                }else if(mungGuDogSiteRangeLv==2){
                    cost_dogSiteRange = 2750;
                }else if(mungGuDogSiteRangeLv==3){
                    cost_dogSiteRange = 3000;
                }else if(mungGuDogSiteRangeLv==4){
                    cost_dogSiteRange = 3250;
                }else if(mungGuDogSiteRangeLv==5){
                    cost_dogSiteRange = 3500;
                }else if(mungGuDogSiteRangeLv==6){
                    cost_dogSiteRange = 3750;
                }else if(mungGuDogSiteRangeLv==7){
                    cost_dogSiteRange = 4000;
                }else if(mungGuDogSiteRangeLv==8){
                    cost_dogSiteRange = 4250;
                }else if(mungGuDogSiteRangeLv==9){
                    cost_dogSiteRange = 4500;
                }else if(mungGuDogSiteRangeLv==10){
                    cost_dogSiteRange = 4750;
                }else if(mungGuDogSiteRangeLv==11){
                    cost_dogSiteRange = 5000;
                }else if(mungGuDogSiteRangeLv==12){
                    cost_dogSiteRange = 5500;
                }else if(mungGuDogSiteRangeLv==13){
                    cost_dogSiteRange = 6000;
                }else if(mungGuDogSiteRangeLv==14){
                    cost_dogSiteRange = 6500;
                }else if(mungGuDogSiteRangeLv==15){
                    cost_dogSiteRange = 7000;
                }else if(mungGuDogSiteRangeLv==16){
                    cost_dogSiteRange = 7500;
                }else if(mungGuDogSiteRangeLv==17){
                    cost_dogSiteRange = 8000;
                }else if(mungGuDogSiteRangeLv==18){
                    cost_dogSiteRange = 8500;
                }else if(mungGuDogSiteRangeLv==19){
                    cost_dogSiteRange = 9000;
                }else if(mungGuDogSiteRangeLv==20){
                    cost_dogSiteRange = 10000;
                    costBarDogSiteRange->setVisible(false);
                    costBarDogSiteRange_->setVisible(true);
                }

                
                costBarDogSiteRange_Label->setString(StringUtils::format("%d", cost_dogSiteRange));
                
                if(mungGuDogSiteRangeLv == 20){
                    mungGuDogSiteRangeLv_Label->setString(StringUtils::format("MAX"));
                    
                }else{
                    mungGuDogSiteRangeLv_Label->setString(StringUtils::format("%d", mungGuDogSiteRangeLv));
                }
                
                
                mungGuDogSiteRangeLv_Label->runAction(action);
            }
            
        }
    }
}

void UnitScene::unitCheck(){
    
    }

void UnitScene::update(float delta){


}
