

#include "HelloMunggu.h"


USING_NS_CC;



Scene* HelloMunggu::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloMunggu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloMunggu::init()
{
    CCLOG("Click");
    winSize = Director::getInstance()->getWinSize();
    
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
    {
        return false;
    }
    
    //현재 버전을 표기
    nowVersion = 1.07;
    
    
    
    
    
    helloMungGu = Sprite::create("HelloMungGu2.png");
    helloMungGu->setAnchorPoint(Point(0.5, 0));
    helloMungGu->setScale(1.6);
    helloMungGu->setPosition(Point(winSize.width*3/10, winSize.height));
    this->addChild(helloMungGu, 10);
    initTitleAction();
    
    
    initData();
    
    
    
    //t상태를 초기화
    //UserDefault::getInstance()->setIntegerForKey("myGold", 0);
    //UserDefault::getInstance()->setIntegerForKey("clearNum", 0);
    
    item = MenuItemFont::create("Press Any Key", CC_CALLBACK_1(HelloMunggu::changeHelloMungScene, this));
    item->setFontSize(30);
    item->setFontName("Arial Unicode.ttf");//otf, ttc, ttf...
    item->setVisible(false);
    auto menu = Menu::create(item, NULL);
    menu->setPosition(Point(winSize.width*13/18 , winSize.height / 13));
    menu->setColor(Color3B::BLACK);
    this->addChild(menu, 2);
    
    versionInfo = Label::createWithTTF //상태버튼 power
    (StringUtils::format("version %0.2f", nowVersion), "NanumBarunGothic.otf", 25*winSize.width/1200);
    versionInfo->setPosition(Point(winSize.width-50*winSize.width/1200,winSize.height-36*winSize.width/1200));
    versionInfo->setAnchorPoint(Point(1,1));
    versionInfo->setOpacity(200);
    versionInfo->setColor(Color3B(150,30,30));
    this->addChild(versionInfo,2);
    
    
    logo = Sprite::create("MyLogo.png");
    logo->setPosition(Point(winSize.width * 19 / 20, winSize.height / 15));
    logo->setScale(0.3);
    this->addChild(logo, 2);
    
    
    mainImage = Sprite::create("MunguMain_0.png");
    Rect mainImageRect = mainImage->getBoundingBox();
    mainImage->setScale(winSize.width / mainImageRect.size.width, winSize.height / mainImageRect.size.height);
    mainImage->setPosition(winSize.width / 2, winSize.height / 2);
    mainImage->setTag(TAG_HELLOMUNGGU);
    this->addChild(mainImage, 1);
    
    return true;
}
void HelloMunggu::pressAnyKeyAction(){
    auto act1 = Blink::create(1, 1);
    auto act2 = ScaleTo::create(true, 1.3);
    auto act3 = Spawn::create(act1, act2, NULL);
    auto action = RepeatForever::create(act3);
    item->runAction(action);
}

void HelloMunggu::initTitleAction(){
    auto act0 = MoveBy::create(0.6, Point(0, -320));
    auto act1 = MoveBy::create(0.1, Point(0, 50));
    auto act2 = MoveBy::create(0.1, Point(0, -30));
    auto act3 = MoveBy::create(0.1, Point(0, 20));
    
    auto titleAction0 = Sequence::create(act0, act1, act2, act3, CallFunc::create(this, callfunc_selector(HelloMunggu::titleActionFinished)), NULL);
    auto titleAction = EaseIn::create(titleAction0, 1.2);
    helloMungGu->runAction(titleAction);
}

void HelloMunggu::titleActionFinished(){
    isTitleFinished = true;
    if (isTitleFinished == true)
        item->setVisible(true);
    pressAnyKeyAction();
}
void HelloMunggu::initData(){
    
    
    isHelloMungTouched=false;
    isTitleFinished=false;
    
    auto listener_HelloMunggu = EventListenerTouchOneByOne::create();
    listener_HelloMunggu->onTouchBegan = CC_CALLBACK_2
    (HelloMunggu::onTouchBegan, this);
    listener_HelloMunggu->onTouchMoved = CC_CALLBACK_2
    (HelloMunggu::onTouchMoved, this);
    listener_HelloMunggu->onTouchEnded = CC_CALLBACK_2
    (HelloMunggu::onTouchEnded, this);
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_HelloMunggu, TAG_HELLOMUNGGU);
}

void HelloMunggu::changeHelloMungScene(Ref *sender){
    
    auto scene = TransitionCrossFade::create(0.3, MungGuGameMenuScene::createScene());
    Director::getInstance()->pushScene(scene);
}

bool HelloMunggu::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
    return true;
}
void HelloMunggu::onTouchMoved(Touch *touch, Event *unused_event){
    
}
void HelloMunggu::onTouchEnded(Touch *touch, Event *unused_event){
    
    Point loc = touch->getLocation();
    
    auto helloMungGuScene = (Sprite*)this->getChildByTag(TAG_HELLOMUNGGU);
    Rect helloMungGuSceneRect = helloMungGuScene->getBoundingBox();
    if (helloMungGuSceneRect.containsPoint(loc)){//씬 이동
        if (isHelloMungTouched == false){
            isHelloMungTouched = true;
            CCLOG("Click 아 이것도 뜨네");
            
            auto loading_label = Label::createWithTTF(StringUtils::format("Loading..."), "NanumBarunGothicBold.otf", 60*winSize.width/1200);
            loading_label->setAnchorPoint(Point(0.5,0.5));
            loading_label->setColor(Color3B::BLACK);
            loading_label->setPosition(Point(winSize.width/2,winSize.height/3));
            this->addChild(loading_label,100);
            loading_label->setScale(1*winSize.width/1200);
            
            
            changeHelloMungScene(this);//아무키나 누르면 화면 이동.
        }
    }
    
}
