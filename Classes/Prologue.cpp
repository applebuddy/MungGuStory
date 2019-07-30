//
//  Prologue.cpp
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 11. 17..
//
//

#include "Prologue.h"


using namespace CocosDenshion;
USING_NS_CC;

Scene* Prologue::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Prologue::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Prologue::init()
{
    CCLOG("Click");
    UserDefault::getInstance()->setBoolForKey("isSong", true);
    winSize = Director::getInstance()->getWinSize();
    
    bool isSong = UserDefault::getInstance()->getBoolForKey("isSong");
    if(isSong == true){//song 켰나 안켯나 확인
        SimpleAudioEngine::getInstance();
        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
        }
    }
    
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B::BLACK))
    {
        return false;
    }
    loadMonsterSpriteData();
    initData();
    
    auto prologueLabel = Label::createWithTTF
    (StringUtils::format("This is the Prologue... \n\n\n Many cats bother ourselves.. \n\n\n continuously... \n\n\n so. we will ready to fight...! \n\n\n\n\n It's time to fight to get peace--!!!\n\n\n\n\n We will keep going to live in Happy World!! \n\n\n  Let's go fighting-!!\n\n\n\n\n\n 이것은 Prologue다... \n\n\n 고양이들이 너무 설친다.. \n\n\n 고양이는 이전 과는 달리 개와 그 외 다른 생물들을 괴롭히고 있다..\n\n\n 그에 맞서 우리의 멍구 주도하에 전쟁을 준비한다...\n\n\n\n\n 이제는 우리가 반란을 일으킬때가 된 것이었다.\n\n\n\n\n 모두가 행복한 세상을 만들기 위해 우리가 간다...! \n\n\n  가자 화이팅-!!"), "NanumBarunGothicBold.otf", 30);
    
    prologueLabel->setAnchorPoint(Point(0.45,1));
    prologueLabel->setColor(Color3B::WHITE);
    this->addChild(prologueLabel,10);
    
    Rect prologueLabelRect = prologueLabel->getBoundingBox();
    prologueLabel->setPosition(Point(winSize.width/2,-prologueLabelRect.size.height/2));
    auto moveAction = MoveBy::create(35*winSize.height/700,Point(0,winSize.height+prologueLabelRect.size.height));
    auto moveAction2 = Sequence::create(moveAction,CallFunc::create(this,callfunc_selector(Prologue::changeHelloMungScene)),NULL);
    prologueLabel->runAction(moveAction2);
    
    auto skipBtn = MenuItemImage::create(
                                         "SkipBtn.png",
                                         "SkipBtn_.png",
                                         CC_CALLBACK_1(Prologue::changeHelloMungScene2,this));
    //CallFunc::create(this,callfunc_selector(Prologue::changeHelloMungScene))
    auto skipBtnMenu = Menu::create(skipBtn, NULL);
    Rect skipBtnMenuRect = skipBtnMenu->getBoundingBox();
    skipBtn->setAnchorPoint(Point(1,1));
    skipBtn->setScale(3.3);
    skipBtn->setPosition(Point(winSize.width/2,winSize.height/2));
    this->addChild(skipBtnMenu,12);
    
    return true;
}

void Prologue::initData(){
    auto listener_logoScene = EventListenerTouchOneByOne::create();
    listener_logoScene->onTouchBegan = CC_CALLBACK_2
    (Prologue::onTouchBegan, this);
    listener_logoScene->onTouchMoved = CC_CALLBACK_2
    (Prologue::onTouchMoved, this);
    listener_logoScene->onTouchEnded = CC_CALLBACK_2
    (Prologue::onTouchEnded, this);
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_logoScene, TAG_HELLOMUNGGU);
}

void Prologue::loadMonsterSpriteData()
{
    SpriteFrameCache *cache = SpriteFrameCache::getInstance();
    cache->removeSpriteFrames();
    
    Vector<SpriteFrame *> moveFrames;
    //기본 이동 액션
    cache->addSpriteFramesWithFile("mungSausage.plist");
    for (int i = 0; i<4; i++) {
        char *pString[20] = {};
        sprintf((char *)pString, "mungSausage_%d.png", i);
        moveFrames.pushBack(cache->getSpriteFrameByName((const char*)pString));
    }
    auto mungGu = Sprite::createWithSpriteFrameName("mungSausage_0.png");
    mungGu->setFlippedX(false);
    mungGu->setPosition(Point(winSize.width*1/4,0));
    mungGu->setAnchorPoint(Point(1,0.3));
    mungGu->setScale(3.3);
    mungGu->setOpacity(200);
    this->addChild(mungGu,5);
    
    
}

void Prologue::changeHelloMungScene(){
    //씬 효과 주는 방법
    UserDefault::getInstance()->setIntegerForKey("myGold", 5000);
    auto scene = TransitionCrossFade::create(0.5, HelloMunggu::createScene());
    Director::getInstance()->pushScene(scene);
}

void Prologue::changeHelloMungScene2(Object* pSender){
    //씬 효과 주는 방법
  //  UserDefault::getInstance()->setIntegerForKey("myGold", 0);
     UserDefault::getInstance()->setIntegerForKey("myGold", 0);//테스트용
    auto scene = TransitionCrossFade::create(0.5, HelloMunggu::createScene());
    Director::getInstance()->pushScene(scene);
}

bool Prologue::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
    return true;
}
void Prologue::onTouchMoved(Touch *touch, Event *unused_event){
    
}
void Prologue::onTouchEnded(Touch *touch, Event *unused_event){
    
}
