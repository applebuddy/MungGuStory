/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
//
//#include "HelloWorldScene.h"
#include "LogoScene.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* LogoScene::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = LogoScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in LogoSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool LogoScene::init()
{
   // CCLOG("Click");
    UserDefault::getInstance()->setBoolForKey("isSong", true);
    winSize = Director::getInstance()->getWinSize();
    
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
    
    initData();
    logoScene = Sprite::create("LogoScene.png");
    logoScene->setPosition(Point(winSize.width / 2, winSize.height / 2));
    logoScene->setAnchorPoint(Point(0.5, 0.5));
    logoScene->setOpacity(0);
    logoScene->setScale(1.5);
    this->addChild(logoScene);
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    int LogoSong;
    LogoSong =
    SimpleAudioEngine::getInstance()->playEffect("LogoSong.mp3");
    auto a0 = FadeTo::create(1.0, 255);
    auto a1 = DelayTime::create(0.5);
    auto a2 = FadeTo::create(1.0, 0);
    auto a3 = DelayTime::create(0.2);
    FiniteTimeAction* logoAction = Sequence::create(a0, a1, a2, a3, CallFunc::create(this, callfunc_selector(LogoScene::changeHelloMungScene)), NULL);
//       FiniteTimeAction* logoAction = Sequence::create(a0, a1, a2, a3, NULL);
    logoScene->runAction(logoAction);
    return true;
}


void LogoScene::initData(){
//    auto listener_logoScene = EventListenerTouchOneByOne::create();
//    listener_logoScene->onTouchBegan = CC_CALLBACK_2
//    (LogoScene::onTouchBegan, this);
//    listener_logoScene->onTouchMoved = CC_CALLBACK_2
//    (LogoScene::onTouchMoved, this);
//    listener_logoScene->onTouchEnded = CC_CALLBACK_2
//    (LogoScene::onTouchEnded, this);
////
//    Director::getInstance()->getEventDispatcher()->
//    addEventListenerWithFixedPriority(listener_logoScene, TAG_HelloMunggu);
}

void LogoScene::changeHelloMungScene(){
    //씬 효과 주는 방법
    bool isProloguePlayed = UserDefault::getInstance()->getBoolForKey("isProloguePlayed",false);

    if(isProloguePlayed == false){
        
        //테스트 끈나면 풀어야함
        UserDefault::getInstance()->setBoolForKey("isProloguePlayed",true);
        Scene *pScene = TransitionCrossFade::create(0.5, HelloMunggu::createScene()); //로고씬 종료후,
        Director::getInstance()->replaceScene(pScene);//맨 처음 실행일 경우, 프롤로그 씬 이동
    }else{
        
        Scene *pScene = TransitionCrossFade::create(0.5, Prologue::createScene()); //로고씬 종료후,
        Director::getInstance()->replaceScene(pScene);//처음 실행이 아니면 바로 메인 화면 이동
    }
}

//bool LogoScene::onTouchBegan(Touch *touch, Event *unused_event){
//    CCLOG("Click");
//    return true;
//}
//void LogoScene::onTouchMoved(Touch *touch, Event *unused_event){
//
//}
//void LogoScene::onTouchEnded(Touch *touch, Event *unused_event){
//
//}

//
//void LogoScene::menuCloseCallback(Ref* pSender)
//{
//    //Close the cocos2d-x game scene and quit the application
//    Director::getInstance()->end();
//
//    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
//
//    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//    //EventCustom customEndEvent("game_scene_close_event");
//    //_eventDispatcher->dispatchEvent(&customEndEvent);
//
//
////}
