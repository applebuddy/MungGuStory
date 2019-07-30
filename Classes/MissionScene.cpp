
#include "MissionScene.h"
USING_NS_CC;

//bool isHelloMungTouched=false;



Scene* MissionScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MissionScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MissionScene::init()
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
    
//    UserDefault::getInstance()->setBoolForKey("m11", false);
//    UserDefault::getInstance()->setBoolForKey("m12", false);
//    UserDefault::getInstance()->setBoolForKey("m13", false);
//    UserDefault::getInstance()->setBoolForKey("m14", false);
//    UserDefault::getInstance()->setBoolForKey("m15", false);
//    UserDefault::getInstance()->setBoolForKey("m16", false);
//    UserDefault::getInstance()->setBoolForKey("m17", false);
//    UserDefault::getInstance()->setBoolForKey("m18", false);
//    UserDefault::getInstance()->setBoolForKey("m19", false);
//    UserDefault::getInstance()->setBoolForKey("m20", false);
    
    
    myGold = UserDefault::getInstance()->getIntegerForKey("myGold");
    goldArea = Sprite::create("GoldArea.png");
    goldArea->setPosition(Point(winSize.width, winSize.height));
    goldArea->setAnchorPoint(Point(1, 1));
   // goldArea->setTag(TAG_SPRITE_GOLDAREA);
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
    mainImage->setOpacity(240);
    this->addChild(mainImage,1);
    
    
    
    return true;
}

void MissionScene::initData(){
    
    
    ///Mission.///
    
    MissionTheme = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Mission"), "NanumBarunGothicBold.otf", 46*winSize.width/1200);
    MissionTheme->setPosition(Point(winSize.width/2,winSize.height*9/10));
    MissionTheme->setAnchorPoint(Point(0.5,1));
    MissionTheme->setColor(Color3B::BLACK);
    this->addChild(MissionTheme,2);
    
    missionEx = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("clear -> hidden Ability Up-!!"), "NanumBarunGothicBold.otf", 26*winSize.width/1200);
    missionEx->setPosition(Point(winSize.width*3/4,winSize.height*8/10));
    missionEx->setAnchorPoint(Point(0.5,1));
    missionEx->setColor(Color3B(50,5,5));
    this->addChild(missionEx,2);
    
    initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
    if(initByEnglish==false){
        MissionTheme->setString(StringUtils::format("미션"));
    }
    
    
    
    
    isM1Clear = UserDefault::getInstance()->getBoolForKey("m1");
    isM2Clear = UserDefault::getInstance()->getBoolForKey("m2");
    isM3Clear = UserDefault::getInstance()->getBoolForKey("m3");
    isM4Clear = UserDefault::getInstance()->getBoolForKey("m4");
    isM5Clear = UserDefault::getInstance()->getBoolForKey("m5");
    isM6Clear = UserDefault::getInstance()->getBoolForKey("m6");
    isM7Clear = UserDefault::getInstance()->getBoolForKey("m7");
    isM8Clear = UserDefault::getInstance()->getBoolForKey("m8");
    isM9Clear = UserDefault::getInstance()->getBoolForKey("m9");
    isM10Clear = UserDefault::getInstance()->getBoolForKey("m10");
    isM11Clear = UserDefault::getInstance()->getBoolForKey("m11");
    isM12Clear = UserDefault::getInstance()->getBoolForKey("m12");
    isM13Clear = UserDefault::getInstance()->getBoolForKey("m13");
    isM14Clear = UserDefault::getInstance()->getBoolForKey("m14");
    isM15Clear = UserDefault::getInstance()->getBoolForKey("m15");
    isM16Clear = UserDefault::getInstance()->getBoolForKey("m16");
    isM17Clear = UserDefault::getInstance()->getBoolForKey("m17");
    isM18Clear = UserDefault::getInstance()->getBoolForKey("m18");
    isM19Clear = UserDefault::getInstance()->getBoolForKey("m19");
    isM20Clear = UserDefault::getInstance()->getBoolForKey("m20");
   
    ////////
    mission1C = Sprite::create("m1c.png");
    mission1C->setPosition(Point(winSize.width/3,winSize.height-200));
    
    mission1 = Sprite::create("m1.png");
    mission1->setPosition(Point(winSize.width/3,winSize.height-200));
    mission1->setScale(2*winSize.width/1200);
    mission1C->setScale(2*winSize.width/1200);
    this->addChild(mission1,10);
    this->addChild(mission1C,10);
    
    mission1Rect = mission1->getBoundingBox();
    
    mission2C = Sprite::create("m2c.png");
    mission2C->setPosition(Point(mission1Rect.getMidX()+100,mission1Rect.getMidY()));
    
    mission2 = Sprite::create("m2.png");
    mission2->setPosition(Point(mission1Rect.getMidX()+100,mission1Rect.getMidY()));
    mission2->setScale(2*winSize.width/1200);
    mission2C->setScale(2*winSize.width/1200);
    this->addChild(mission2,10);
    this->addChild(mission2C,10);
    
    mission3C = Sprite::create("m3c.png");
    mission3C->setPosition(Point(mission1Rect.getMidX()+200,mission1Rect.getMidY()));
    
    mission3 = Sprite::create("m3.png");
    mission3->setPosition(Point(mission1Rect.getMidX()+200,mission1Rect.getMidY()));
    mission3->setScale(2*winSize.width/1200);
    mission3C->setScale(2*winSize.width/1200);
    this->addChild(mission3,10);
    this->addChild(mission3C,10);
    
    mission4C = Sprite::create("m4c.png");
    mission4C->setPosition(Point(mission1Rect.getMidX()+300,mission1Rect.getMidY()));
    
    mission4 = Sprite::create("m4.png");
    mission4->setPosition(Point(mission1Rect.getMidX()+300,mission1Rect.getMidY()));
    mission4->setScale(2*winSize.width/1200);
    mission4C->setScale(2*winSize.width/1200);
    this->addChild(mission4,10);
    this->addChild(mission4C,10);
    
    mission5C = Sprite::create("m5c.png");
    mission5C->setPosition(Point(mission1Rect.getMidX()+400,mission1Rect.getMidY()));
    
    mission5 = Sprite::create("m5.png");
    mission5->setPosition(Point(mission1Rect.getMidX()+400,mission1Rect.getMidY()));
    mission5->setScale(2*winSize.width/1200);
    mission5C->setScale(2*winSize.width/1200);
    this->addChild(mission5,10);
    this->addChild(mission5C,10);
    
    
    //////6~10
    ////////
    mission6C = Sprite::create("m6c.png");
    mission6C->setPosition(Point(mission1Rect.getMidX(),winSize.height-300));
    
    mission6 = Sprite::create("m6.png");
    mission6->setPosition(Point(mission1Rect.getMidX(),winSize.height-300));
    mission6->setScale(2*winSize.width/1200);
    mission6C->setScale(2*winSize.width/1200);
    this->addChild(mission6,10);
    this->addChild(mission6C,10);
    
    mission6Rect = mission6->getBoundingBox();
    
    mission7C = Sprite::create("m7c.png");
    mission7C->setPosition(Point(mission1Rect.getMidX()+100,mission6Rect.getMidY()));
    
    mission7 = Sprite::create("m7.png");
    mission7->setPosition(Point(mission1Rect.getMidX()+100,mission6Rect.getMidY()));
    mission7->setScale(2*winSize.width/1200);
    mission7C->setScale(2*winSize.width/1200);
    this->addChild(mission7,10);
    this->addChild(mission7C,10);
    
    mission8C = Sprite::create("m8c.png");
    mission8C->setPosition(Point(mission1Rect.getMidX()+200,mission6Rect.getMidY()));
    
    mission8 = Sprite::create("m8.png");
    mission8->setPosition(Point(mission1Rect.getMidX()+200,mission6Rect.getMidY()));
    mission8->setScale(2*winSize.width/1200);
    mission8C->setScale(2*winSize.width/1200);
    this->addChild(mission8,10);
    this->addChild(mission8C,10);
    
    mission9C = Sprite::create("m9c.png");
    mission9C->setPosition(Point(mission1Rect.getMidX()+300,mission6Rect.getMidY()));
    
    mission9 = Sprite::create("m9.png");
    mission9->setPosition(Point(mission1Rect.getMidX()+300,mission6Rect.getMidY()));
    mission9->setScale(2*winSize.width/1200);
    mission9C->setScale(2*winSize.width/1200);
    this->addChild(mission9,10);
    this->addChild(mission9C,10);
    
    mission10C = Sprite::create("m10c.png");
    mission10C->setPosition(Point(mission1Rect.getMidX()+400,mission6Rect.getMidY()));
    
    mission10 = Sprite::create("m10.png");
    mission10->setPosition(Point(mission1Rect.getMidX()+400,mission6Rect.getMidY()));
    mission10->setScale(2*winSize.width/1200);
    mission10C->setScale(2*winSize.width/1200);
    this->addChild(mission10,10);
    this->addChild(mission10C,10);

    
    
    //////11~15
    ////////
    mission11C = Sprite::create("m11c.png");
    mission11C->setPosition(Point(mission1Rect.getMidX(),winSize.height-400));
    
    mission11 = Sprite::create("m11.png");
    mission11->setPosition(Point(mission1Rect.getMidX(),winSize.height-400));
    mission11->setScale(2*winSize.width/1200);
    mission11C->setScale(2*winSize.width/1200);
    this->addChild(mission11,10);
    this->addChild(mission11C,10);
    
    mission11Rect = mission11->getBoundingBox();
    
    mission12C = Sprite::create("m12c.png");
    mission12C->setPosition(Point(mission1Rect.getMidX()+100,mission11Rect.getMidY()));
    
    mission12 = Sprite::create("m12.png");
    mission12->setPosition(Point(mission1Rect.getMidX()+100,mission11Rect.getMidY()));
    mission12->setScale(2*winSize.width/1200);
    mission12C->setScale(2*winSize.width/1200);
    this->addChild(mission12,10);
    this->addChild(mission12C,10);
    
    mission13C = Sprite::create("m13c.png");
    mission13C->setPosition(Point(mission1Rect.getMidX()+200,mission11Rect.getMidY()));
    
    mission13 = Sprite::create("m13.png");
    mission13->setPosition(Point(mission1Rect.getMidX()+200,mission11Rect.getMidY()));
    mission13->setScale(2*winSize.width/1200);
    mission13C->setScale(2*winSize.width/1200);
    this->addChild(mission13,10);
    this->addChild(mission13C,10);
    
    mission14C = Sprite::create("m14c.png");
    mission14C->setPosition(Point(mission1Rect.getMidX()+300,mission11Rect.getMidY()));
    
    mission14 = Sprite::create("m14.png");
    mission14->setPosition(Point(mission1Rect.getMidX()+300,mission11Rect.getMidY()));
    mission14->setScale(2*winSize.width/1200);
    mission14C->setScale(2*winSize.width/1200);
    this->addChild(mission14,10);
    this->addChild(mission14C,10);
    
    mission15C = Sprite::create("m15c.png");
    mission15C->setPosition(Point(mission1Rect.getMidX()+400,mission11Rect.getMidY()));
    
    mission15 = Sprite::create("m15.png");
    mission15->setPosition(Point(mission1Rect.getMidX()+400,mission11Rect.getMidY()));
    mission15->setScale(2*winSize.width/1200);
    mission15C->setScale(2*winSize.width/1200);
    this->addChild(mission15,10);
    this->addChild(mission15C,10);

    
    //////16~20
    ////////
    mission16C = Sprite::create("m16c.png");
    mission16C->setPosition(Point(mission1Rect.getMidX(),winSize.height-500));
    
    mission16 = Sprite::create("m16.png");
    mission16->setPosition(Point(mission1Rect.getMidX(),winSize.height-500));
    mission16->setScale(2*winSize.width/1200);
    mission16C->setScale(2*winSize.width/1200);
    this->addChild(mission16,10);
    this->addChild(mission16C,10);
    
    mission16Rect = mission16->getBoundingBox();
    
    mission17C = Sprite::create("m17c.png");
    mission17C->setPosition(Point(mission1Rect.getMidX()+100,mission16Rect.getMidY()));
    
    mission17 = Sprite::create("m17.png");
    mission17->setPosition(Point(mission1Rect.getMidX()+100,mission16Rect.getMidY()));
    mission17->setScale(2*winSize.width/1200);
    mission17C->setScale(2*winSize.width/1200);
    this->addChild(mission17,10);
    this->addChild(mission17C,10);
    
    mission18C = Sprite::create("m18c.png");
    mission18C->setPosition(Point(mission1Rect.getMidX()+200,mission16Rect.getMidY()));
    
    mission18 = Sprite::create("m18.png");
    mission18->setPosition(Point(mission1Rect.getMidX()+200,mission16Rect.getMidY()));
    mission18->setScale(2*winSize.width/1200);
    mission18C->setScale(2*winSize.width/1200);
    this->addChild(mission18,10);
    this->addChild(mission18C,10);
    
    mission19C = Sprite::create("m19c.png");
    mission19C->setPosition(Point(mission1Rect.getMidX()+300,mission16Rect.getMidY()));
    
    mission19 = Sprite::create("m19.png");
    mission19->setPosition(Point(mission1Rect.getMidX()+300,mission16Rect.getMidY()));
    mission19->setScale(2*winSize.width/1200);
    mission19C->setScale(2*winSize.width/1200);
    this->addChild(mission19,10);
    this->addChild(mission19C,10);
    
    mission20C = Sprite::create("m20c.png");
    mission20C->setPosition(Point(mission1Rect.getMidX()+400,mission16Rect.getMidY()));
    
    mission20 = Sprite::create("m20.png");
    mission20->setPosition(Point(mission1Rect.getMidX()+400,mission16Rect.getMidY()));
    mission20->setScale(2*winSize.width/1200);
    mission20C->setScale(2*winSize.width/1200);
    this->addChild(mission20,10);
    this->addChild(mission20C,10);
    
    
    
    /// Label ///
    Rect m1Rect = mission1->getBoundingBox();
    mission1_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage1 Clear"), "NanumBarunGothicBold.otf", 12);
    mission1_label->setPosition(Point(m1Rect.getMidX(),m1Rect.getMaxY()+10));
    mission1_label->setVisible(false);
    mission1_label->setColor(Color3B::BLACK);
    this->addChild(mission1_label,11);
    if(initByEnglish==false){
        mission1_label->setString(StringUtils::format("첫탄 클리어"));
    }
    
    mission2_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage5 Clear"), "NanumBarunGothicBold.otf", 12);
    mission2_label->setPosition(Point(m1Rect.getMidX()+100,m1Rect.getMaxY()+10));
    mission2_label->setVisible(false);
    mission2_label->setColor(Color3B::BLACK);
    this->addChild(mission2_label,11);
    if(initByEnglish==false){
        mission2_label->setString(StringUtils::format("5탄 클리어"));
    }
    
    mission3_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage10 Clear"), "NanumBarunGothicBold.otf", 12);
    mission3_label->setPosition(Point(m1Rect.getMidX()+200,m1Rect.getMaxY()+10));
    mission3_label->setVisible(false);
    mission3_label->setColor(Color3B::BLACK);
    this->addChild(mission3_label,11);
    if(initByEnglish==false){
        mission3_label->setString(StringUtils::format("10탄 클리어"));
    }
    
    mission4_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage15 Clear"), "NanumBarunGothicBold.otf", 12);
    mission4_label->setPosition(Point(m1Rect.getMidX()+300,m1Rect.getMaxY()+10));
    mission4_label->setVisible(false);
    mission4_label->setColor(Color3B::BLACK);
    this->addChild(mission4_label,11);
    if(initByEnglish==false){
        mission4_label->setString(StringUtils::format("15탄 클리어"));
    }
    
    
    mission5_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage20 Clear"), "NanumBarunGothicBold.otf", 12);
    mission5_label->setPosition(Point(m1Rect.getMidX()+400,m1Rect.getMaxY()+10));
    mission5_label->setVisible(false);
    mission5_label->setColor(Color3B::BLACK);
    this->addChild(mission5_label,11);
    if(initByEnglish==false){
        mission5_label->setString(StringUtils::format("20탄 클리어"));
    }
    
    
    /// Label ///
    Rect m6Rect = mission6->getBoundingBox();
    mission6_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage25 Clear"), "NanumBarunGothicBold.otf", 12);
    mission6_label->setPosition(Point(m1Rect.getMidX(),m6Rect.getMaxY()+10));
    mission6_label->setVisible(false);
    mission6_label->setColor(Color3B::BLACK);
    this->addChild(mission6_label,11);
    if(initByEnglish==false){
        mission6_label->setString(StringUtils::format("25탄 클리어"));
    }
    
    
    
    mission7_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("stage30 Clear"), "NanumBarunGothicBold.otf", 12);
    mission7_label->setPosition(Point(m1Rect.getMidX()+100,m6Rect.getMaxY()+10));
    mission7_label->setVisible(false);
    mission7_label->setColor(Color3B::BLACK);
    this->addChild(mission7_label,11);
    if(initByEnglish==false){
        mission7_label->setString(StringUtils::format("30탄 클리어"));
    }
    
    
    mission8_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("the disabled"), "NanumBarunGothicBold.otf", 12);
    mission8_label->setPosition(Point(m1Rect.getMidX()+200,m6Rect.getMaxY()+10));
    mission8_label->setVisible(false);
    mission8_label->setColor(Color3B::BLACK);
    this->addChild(mission8_label,11);
    if(initByEnglish==false){
        mission8_label->setString(StringUtils::format("장애인 1"));
    }
    
    
    mission9_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("the disabled 2"), "NanumBarunGothicBold.otf", 12);
    mission9_label->setPosition(Point(m1Rect.getMidX()+300,m6Rect.getMaxY()+10));
    mission9_label->setVisible(false);
    mission9_label->setColor(Color3B::BLACK);
    this->addChild(mission9_label,11);
    if(initByEnglish==false){
        mission9_label->setString(StringUtils::format("장애인 2"));
    }
    
    mission10_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Thank you ^^"), "NanumBarunGothicBold.otf", 12);
    mission10_label->setPosition(Point(m1Rect.getMidX()+400,m6Rect.getMaxY()+10));
    mission10_label->setVisible(false);
    mission10_label->setColor(Color3B::BLACK);
    this->addChild(mission10_label,11);
    if(initByEnglish==false){
        mission10_label->setString(StringUtils::format("이해 감사^^"));
    }
    
    
    Rect m11Rect = mission11->getBoundingBox();
    mission11_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Shield Breaker"), "NanumBarunGothicBold.otf", 12);
    mission11_label->setPosition(Point(m1Rect.getMidX(),m11Rect.getMaxY()+10));
    mission11_label->setVisible(false);
    mission11_label->setColor(Color3B::BLACK);
    this->addChild(mission11_label,11);
    if(initByEnglish==false){
        mission11_label->setString(StringUtils::format("쉴드 브레이커"));
    }
    
    mission12_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("mungPo King"), "NanumBarunGothicBold.otf", 12);
    mission12_label->setPosition(Point(m1Rect.getMidX()+100,m11Rect.getMaxY()+10));
    mission12_label->setVisible(false);
    mission12_label->setColor(Color3B::BLACK);
    this->addChild(mission12_label,11);
    if(initByEnglish==false){
        mission12_label->setString(StringUtils::format("멍포 왕"));
    }
    
    mission13_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Watch out"), "NanumBarunGothicBold.otf", 12);
    mission13_label->setPosition(Point(m1Rect.getMidX()+200,m11Rect.getMaxY()+10));
    mission13_label->setVisible(false);
    mission13_label->setColor(Color3B::BLACK);
    this->addChild(mission13_label,11);
    if(initByEnglish==false){
        mission13_label->setString(StringUtils::format("조심하세요."));
    }
    
    mission14_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Pervert"), "NanumBarunGothicBold.otf", 12);
    mission14_label->setPosition(Point(m1Rect.getMidX()+300,m11Rect.getMaxY()+10));
    mission14_label->setVisible(false);
    mission14_label->setColor(Color3B::BLACK);
    this->addChild(mission14_label,11);
    if(initByEnglish==false){
        mission14_label->setString(StringUtils::format("변태"));
    }
    
    
    mission15_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("ending??"), "NanumBarunGothicBold.otf", 12);
    mission15_label->setPosition(Point(m1Rect.getMidX()+400,m11Rect.getMaxY()+10));
    mission15_label->setVisible(false);
    mission15_label->setColor(Color3B::BLACK);
    this->addChild(mission15_label,11);
    if(initByEnglish==false){
        mission15_label->setString(StringUtils::format("엔딩??"));
    }
    
    
    /// Label ///
    Rect m16Rect = mission16->getBoundingBox();
    mission16_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Hard Victory"), "NanumBarunGothicBold.otf", 12);
    mission16_label->setPosition(Point(m1Rect.getMidX(),m16Rect.getMaxY()+10));
    mission16_label->setVisible(false);
    mission16_label->setColor(Color3B::BLACK);
    this->addChild(mission16_label,11);
    if(initByEnglish==false){
        mission16_label->setString(StringUtils::format("힘겨운 승리"));
    }
    
    
    
    mission17_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Hard Defeat"), "NanumBarunGothicBold.otf", 12);
    mission17_label->setPosition(Point(m1Rect.getMidX()+100,m16Rect.getMaxY()+10));
    mission17_label->setVisible(false);
    mission17_label->setColor(Color3B::BLACK);
    this->addChild(mission17_label,11);
    if(initByEnglish==false){
        mission17_label->setString(StringUtils::format("힘겨운 패배"));
    }
    
    
    mission18_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("Thanks"), "NanumBarunGothicBold.otf", 12);
    mission18_label->setPosition(Point(m1Rect.getMidX()+200,m16Rect.getMaxY()+10));
    mission18_label->setVisible(false);
    mission18_label->setColor(Color3B::BLACK);
    this->addChild(mission18_label,11);
    if(initByEnglish==false){
        mission18_label->setString(StringUtils::format("고맙다."));
    }
    
    
    mission19_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("for"), "NanumBarunGothicBold.otf", 12);
    mission19_label->setPosition(Point(m1Rect.getMidX()+300,m16Rect.getMaxY()+10));
    mission19_label->setVisible(false);
    mission19_label->setColor(Color3B::BLACK);
    this->addChild(mission19_label,11);
    if(initByEnglish==false){
        mission19_label->setString(StringUtils::format("대해서"));
    }
    
    mission20_label = Label::createWithTTF //상태버튼 maxMoney
    (StringUtils::format("playing ^^"), "NanumBarunGothicBold.otf", 12);
    mission20_label->setPosition(Point(m1Rect.getMidX()+400,m16Rect.getMaxY()+10));
    mission20_label->setVisible(false);
    mission20_label->setColor(Color3B::BLACK);
    this->addChild(mission20_label,11);
    if(initByEnglish==false){
        mission20_label->setString(StringUtils::format("게임하는 거"));
    }


 //클리어 유무 판단 알고리즘
    
    if(isM1Clear==true){
        mission1->setVisible(false);
         mission1_label->setVisible(true);
    }else{
        mission1C->setVisible(false);
       
    }
    
    if(isM2Clear==true){
        mission2->setVisible(false);
        mission2_label->setVisible(true);
    }else{
        mission2C->setVisible(false);
        
    }
    
    if(isM3Clear==true){
        mission3->setVisible(false);
         mission3_label->setVisible(true);
    }else{
        mission3C->setVisible(false);
       
    }
    
    if(isM4Clear==true){
        mission4->setVisible(false);
        mission4_label->setVisible(true);
    }else{
        mission4C->setVisible(false);
    }
    
    if(isM5Clear==true){
        mission5->setVisible(false);
        mission5_label->setVisible(true);
    }else{
        mission5C->setVisible(false);
    }
    
    if(isM6Clear==true){
        mission6->setVisible(false);
        mission6_label->setVisible(true);
    }else{
        mission6C->setVisible(false);
    }
    
    if(isM7Clear==true){
        mission7->setVisible(false);
        mission7_label->setVisible(true);
    }else{
        mission7C->setVisible(false);
    }
    
    if(isM8Clear==true){
        mission8->setVisible(false);
        mission8_label->setVisible(true);
    }else{
        mission8C->setVisible(false);
    }
    
    if(isM9Clear==true){
        mission9->setVisible(false);
        mission9_label->setVisible(true);
    }else{
        mission9C->setVisible(false);
    }
    
    if(isM10Clear==true){
        mission10->setVisible(false);
        mission10_label->setVisible(true);
    }else{
        mission10C->setVisible(false);
    }
    
    if(isM11Clear==true){
        mission11->setVisible(false);
        mission11_label->setVisible(true);
    }else{
        mission11C->setVisible(false);
        
    }
    
    if(isM12Clear==true){
        mission12->setVisible(false);
        mission12_label->setVisible(true);
    }else{
        mission12C->setVisible(false);
        
    }
    
    if(isM13Clear==true){
        mission13->setVisible(false);
        mission13_label->setVisible(true);
    }else{
        mission13C->setVisible(false);
        
    }
    
    if(isM14Clear==true){
        mission14->setVisible(false);
        mission14_label->setVisible(true);
    }else{
        mission14C->setVisible(false);
    }
    
    if(isM15Clear==true){
        mission15->setVisible(false);
        mission15_label->setVisible(true);
    }else{
        mission15C->setVisible(false);
    }
    
    if(isM16Clear==true){
        mission16->setVisible(false);
        mission16_label->setVisible(true);
    }else{
        mission16C->setVisible(false);
    }
    
    if(isM17Clear==true){
        mission17->setVisible(false);
        mission17_label->setVisible(true);
    }else{
        mission17C->setVisible(false);
    }
    
    if(isM18Clear==true){
        mission18->setVisible(false);
        mission18_label->setVisible(true);
    }else{
        mission18C->setVisible(false);
    }
    
    if(isM19Clear==true){
        mission19->setVisible(false);
        mission19_label->setVisible(true);
    }else{
        mission19C->setVisible(false);
    }
    
    if(isM20Clear==true){
        mission20->setVisible(false);
        mission20_label->setVisible(true);
    }else{
        mission20C->setVisible(false);
    }

    
    auto listener_changeSceneBtn = EventListenerTouchOneByOne::create();
    listener_changeSceneBtn->onTouchBegan = CC_CALLBACK_2
    (MissionScene::onTouchBegan, this);
    listener_changeSceneBtn->onTouchMoved = CC_CALLBACK_2
    (MissionScene::onTouchMoved, this);
    listener_changeSceneBtn->onTouchEnded = CC_CALLBACK_2
    (MissionScene::onTouchEnded, this);
    
    
    isReturnBtn = false;

    //홈버튼
    auto listener_homeBackBtn = EventListenerTouchOneByOne::create();
    listener_homeBackBtn->onTouchBegan = CC_CALLBACK_2
    (MissionScene::onTouchBegan, this);
    listener_homeBackBtn->onTouchMoved = CC_CALLBACK_2
    (MissionScene::onTouchMoved, this);
    listener_homeBackBtn->onTouchEnded = CC_CALLBACK_2
    (MissionScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_homeBackBtn, TAG_SPRITE_HOMEBACKBTN);
    ///
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_changeSceneBtn, TAG_HELLOMUNGGU);
    
  }

void MissionScene::changeScene(Ref *sender){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    Director::getInstance()->replaceScene(MungGuGameMenuScene::createScene());
}
void MissionScene::changeScene(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = TransitionFade::create(0.6, MungGuGameMenuScene::createScene());
    Director::getInstance()->replaceScene(scene);}


bool MissionScene::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
//    changeScene(this);
     Point loc = touch->getLocation();
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    if(homeBackBtnRect.containsPoint(loc)){
        isReturnBtn = true;
        homeBackBtn->setVisible(false);
        homeBackBtn_->setVisible(true);
    }
    
   // Rect m1Rect = mission1->getBoundingBox();
//    if(m1Rect.containsPoint(loc)){
//        auto blinkAction = Blink::create(2, 3);
//
//        if(isM1Clear==true){
//                        mission1_label->runAction(blinkAction);
//        }
//        
//    }
    
    
    return true;
}
void MissionScene::onTouchMoved(Touch *touch, Event *unused_event){
    
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
void MissionScene::onTouchEnded(Touch *touch, Event *unused_event){
    
    Point loc = touch->getLocation();
    
    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
    
    if(homeBackBtnRect.containsPoint(loc)){
        homeBackBtn->setVisible(true);
        homeBackBtn_->setVisible(false);
        changeScene();
    }

    
}
