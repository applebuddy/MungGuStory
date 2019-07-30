//
//  Epilogue.cpp
//  mungGu
//
//  Created by Kyeongtae Min on 2015. 2. 10..
//
//

#include "Epilogue.h"
#include "HelloMunggu.h"
#include "SimpleAudioEngine.h"

using namespace CocosDenshion;
USING_NS_CC;

Scene* Epilogue::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Epilogue::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Epilogue::init()
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
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    loadMonsterSpriteData();
    initData();
    
    initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
    
    
    auto epilogueLabel = Label::createWithTTF	(StringUtils::format("싸움이 시작된 후... \n\n   어언 몇십일이 지났다.. \n\n\n\n\n 우리 멍구 진영에서 내분이 일기 시작했다. \n\n\n\n\n\n\n\n\n '궂이 고양이들과 싸워야 할까?' \n\n\n '그들과 사이좋게 지낼 수도 있는건데...' \n\n\n\n\n 그리고 오랜 의논 끝에 내린결론. \n\n\n\n\n\n\n '모두가 행복한 세상을 만들기 위해 그래, 고양이 세력과 친하게 지내자!' \n\n\n\n\n  진작에 그럴걸 그랬어... \n\n\n 생각해보니 그렇다... \n\n\n\n\n '싸울 필요가 없었어...!' \n\n\n\n\n 그렇게 결론을 내린 우리는 고양이에게 화해를 신청했다. \n\n\n\n\n 진정한 평화를 위해--!! \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n 그러나 고양이들은 화해를 거절했다... ㅡㅡ;; \n\n\n\n\n '역시 계속 싸워야겠어..!' "), "NanumBarunGothicBold.otf", 30*winSize.width/1200);
    
    epilogueLabel->setAnchorPoint(Point(0.45,1));
    epilogueLabel->setPosition(Point(winSize.width/2,-260));
    epilogueLabel->setColor(Color3B::BLACK);
    
    if(initByEnglish==true){
        epilogueLabel->setString(StringUtils::format("After the fight started ... \n\n   Tens of days has passed... \n\n\n\n\n Infighting occurred in our Area..  \n\n\n\n\n\n\n\n\n 'Should we fight with a cat?' \n\n\n 'We could get along friendly...' \n\n\n\n\n and, Concluded at the end of a long consultation.. \n\n\n\n\n\n\n 'So to make everyone happy world, \n\nWe should get along with cats!' \n\n\n\n\n  Definetly.. \n\n\n\n\n That was good choice.. \n\n\n\n\n 'We didn't need to fight them..!' \n\n\n\n\n So, we went to the Cats Area for reconcilement.. \n\n\n\n\n for the Ture Peace--!! \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n but.. they've denied.. ㅡㅅㅡ;; \n\n\n\n\n 'We should fight continuously..!' "));
        epilogueLabel->setPosition(Point(winSize.width/2,-200));
    }

    this->addChild(epilogueLabel,10);
     Rect epilogueLabelRect = epilogueLabel->getBoundingBox();
    auto logoImage = Sprite::create("ourTrees.png");
    logoImage->setAnchorPoint(Point(0.5,1));
    logoImage->setPosition(Point(winSize.width/2,-10));
    this->addChild(logoImage,11);
    
    ///20스테이지 클리어 버튼
    isStageClearBtn = false;
    stageClearBtn = Sprite::create("stageClearBtn.png");
    stageClearBtn_ = Sprite::create("stageClearBtn_.png");
    stageClearBtn->setAnchorPoint(Point(0.5,0));
    stageClearBtn->setPosition(Point(winSize.width/2,winSize.width/13));
    stageClearBtn_->setAnchorPoint(Point(0.5,0));
    stageClearBtn_->setPosition(Point(winSize.width/2,winSize.width/13));
    stageClearBtn->setScale(2.2);
    stageClearBtn_->setScale(2.2);
    stageClearBtn->setVisible(false);
    stageClearBtn_->setVisible(false);
    this->addChild(stageClearBtn,15);
    this->addChild(stageClearBtn_,15);
    stageClearBtn->setTag(TAG_stageClearBtn);
    
    Rect stageClearBtnRect = stageClearBtn->getBoundingBox();

    
    Rect prologueLabelRect = epilogueLabel->getBoundingBox();
    
    auto moveAction = MoveBy::create(80,Point(0,winSize.height+prologueLabelRect.size.height*1.15));
    auto moveAction2 = Sequence::create(moveAction,CallFunc::create(this,callfunc_selector(Epilogue::clearEvent)),NULL);
    //움직이고, 20스테이지 클리어 액션..버튼 누르기.
    epilogueLabel->runAction(moveAction2);
    
    //이미지 이동..
    auto delayAction = DelayTime::create(47);
    auto moveAction3 = MoveTo::create(3,Point(winSize.width/2,winSize.height/2));
    auto fadeAction = FadeOut::create(3);
    auto logoAction = Sequence::create(delayAction,moveAction3,fadeAction,NULL);
    
    logoImage->runAction(logoAction);
    
    
    
    auto skipBtn = MenuItemImage::create(
                                         "SkipBtn.png",
                                         "SkipBtn_.png",
                                         CC_CALLBACK_1(Epilogue::changeHelloMungScene,this));
    //CallFunc::create(this,callfunc_selector(Prologue::changeHelloMungScene))
    auto skipBtnMenu = Menu::create(skipBtn, NULL);
    Rect skipBtnMenuRect = skipBtnMenu->getBoundingBox();
    skipBtn->setAnchorPoint(Point(1,1));
    skipBtn->setScale(3.3);
    skipBtn->setPosition(Point(winSize.width/2,winSize.height/2));
    this->addChild(skipBtnMenu,12);
    
    return true;
}




void Epilogue::clearMissionEvent(){
        ///스테이지 미션 클리어///
    
    int stage20_clearCount =
    UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
UserDefault::getInstance()->setIntegerForKey("stage20_clearCount", stage20_clearCount+1);//엔
    stage20_clearCount =
    UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
    
    
        bool isM5Clear = UserDefault::getInstance()->getBoolForKey("m5");

    
            auto m5Clear = Label::createWithTTF(StringUtils::format("mission 5 Clear~!!!\n->20 stage clear"), "NanumBarunGothicBold.otf", 20);
            m5Clear->setColor(Color3B::RED);
            m5Clear->setAnchorPoint(Point(0.5,1));
            m5Clear->setPosition(Point(winSize.width/2,winSize.height-20));
           // m5Clear->setColor(Color3B::BLACK);
    m5Clear->setVisible(false);
            this->addChild(m5Clear,50);
           
    if(initByEnglish==false){
        m5Clear->setString(StringUtils::format("미션 5 클리어~!!!\n -> 20스테이지 클리어"));
    }
    
            auto action = Blink::create(3.6,7);
            // auto delayAction = DelayTime::create(2);
            auto action2 = Sequence::create(action,CallFunc::create(this,callfunc_selector(Epilogue::changeHelloMungScene3)),NULL);
            ///////////
            //엔딩 다 봐야 보상
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
            int myGold = UserDefault::getInstance()->getIntegerForKey("myGold");
            int goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                int goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
                changeHelloMungScene3();
            }
            else{
                        if(isM5Clear==false){
                              m5Clear->setVisible(true);
                            UserDefault::getInstance()->setBoolForKey("m5", true);
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
                  m5Clear->runAction(action2);
                        }
            }
}

void Epilogue::clearEvent(){
    
    isStageClearBtn=true;
    stageClearBtn->setVisible(true);
    stageClearBtn_->setVisible(false);

}


void Epilogue::initData(){
    auto listener_logoScene = EventListenerTouchOneByOne::create();
    listener_logoScene->onTouchBegan = CC_CALLBACK_2
    (Epilogue::onTouchBegan, this);
    listener_logoScene->onTouchMoved = CC_CALLBACK_2
    (Epilogue::onTouchMoved, this);
    listener_logoScene->onTouchEnded = CC_CALLBACK_2
    (Epilogue::onTouchEnded, this);
    
    auto listener_clearBtn = EventListenerTouchOneByOne::create();
    listener_clearBtn->onTouchBegan = CC_CALLBACK_2
    (Epilogue::onTouchBegan, this);
    listener_clearBtn->onTouchMoved = CC_CALLBACK_2
    (Epilogue::onTouchMoved, this);
    listener_clearBtn->onTouchEnded = CC_CALLBACK_2
    (Epilogue::onTouchEnded, this);
    
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_logoScene, TAG_HELLOMUNGGU);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_clearBtn, TAG_stageClearBtn);
    
}

void Epilogue::loadMonsterSpriteData()
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
void Epilogue::changeHelloMungScene3(){
    auto scene = TransitionCrossFade::create(5,HelloMunggu::createScene());
    Director::getInstance()->pushScene(scene);

}



void Epilogue::changeHelloMungScene(Object* pSender){

    //m13 클리어 이벤트
    bool isM15Clear = UserDefault::getInstance()->getBoolForKey("m15");
    if(isM15Clear==false){
        
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
            int disabledSong =
            SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
        }
        
        UserDefault::getInstance()->setBoolForKey("m15",true);//8미션 클리어
        
        auto m15Clear = Label::createWithTTF(StringUtils::format("mission 15 Clear~!!!\n-> ending-??"), "NanumBarunGothicBold.otf", 20);
        m15Clear->setAnchorPoint(Point(0.5,1));
        m15Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m15Clear->setColor(Color3B::BLACK);
        m15Clear->setVisible(false);
        this->addChild(m15Clear,10);
        if(initByEnglish==false){
            m15Clear->setString(StringUtils::format("미션 15 클리어~!!!\n -> 엔딩-??"));
        }
        auto action = Blink::create(3,10);
        m15Clear->runAction(action);
    }

    
    //20스테이지 클리어
    auto scene = TransitionCrossFade::create(3,HelloMunggu::createScene());
    Director::getInstance()->pushScene(scene);
}

void Epilogue::changeHelloMungScene2(Object* pSender){
    //씬 효과 주는 방법
    
   
    
    auto scene = TransitionCrossFade::create(0.5, HelloMunggu::createScene());
    Director::getInstance()->pushScene(scene);
}

bool Epilogue::onTouchBegan(Touch *touch, Event *unused_event){
    CCLOG("Click");
    Point loc = touch->getLocation();
     Rect stageClearBtnRect = stageClearBtn->getBoundingBox();
    if(isStageClearBtn==true){
        if(stageClearBtnRect.containsPoint(loc)){
            stageClearBtn->setVisible(false);
            stageClearBtn_->setVisible(true);
        }
    }
    
    
    return true;
}
void Epilogue::onTouchMoved(Touch *touch, Event *unused_event){
    
}
void Epilogue::onTouchEnded(Touch *touch, Event *unused_event){
    
    Point loc = touch->getLocation();
    
    if(isStageClearBtn==true){
        
        stageClearBtn->setVisible(true);
        stageClearBtn_->setVisible(false);
        Rect stageClearBtnRect = stageClearBtn->getBoundingBox();
        if(stageClearBtnRect.containsPoint(loc)){
            isStageClearBtn=false;
         
            clearMissionEvent();
         //   changeHelloMungScene();
        }
    }
    
}
