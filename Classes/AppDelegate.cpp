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

#include "AppDelegate.h"
#include "LogoScene.h"
#include "HelloMunggu.h"
#include "Prologue.h"
#include "MungGuGameMenuScene.h"
#include "MungStoreScene.h"
#include "MissionScene.h"
#include "UnitScene.h"
#include "Util.h"
#include "SimpleAudioEngine.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "Don't use AudioEngine and SimpleAudioEngine at the same time. Please just select one in your game!"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms

void AppDelegate::setupResolutionPolicy(float designW, float designH)
{
    auto director = Director::getInstance();
    Size screenSize = director->getOpenGLView()->getFrameSize();
    
    float designRatio = designW / designH;
    float screenRatio = screenSize.height / screenSize.width;
    
    ResolutionPolicy resolutionPolicy = screenRatio < designRatio ?
    ResolutionPolicy::FIXED_HEIGHT : ResolutionPolicy::FIXED_WIDTH;
    
    director->getOpenGLView()->setDesignResolutionSize(designW, designH, resolutionPolicy);
    
}

void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil,multisamplesCount
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8, 0};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages,  
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("mungguStory", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
        glview = GLViewImpl::create("mungguStory");
#endif
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0f / 60);

//    // Set the design resolution
//    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
//    auto frameSize = glview->getFrameSize();
//    // if the frame's height is larger than the height of medium size.
//    if (frameSize.height > mediumResolutionSize.height)
//    {
//        director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
//    }
//    // if the frame's height is larger than the height of small size.
//    else if (frameSize.height > smallResolutionSize.height)
//    {
//        director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
//    }
//    // if the frame's height is smaller than the height of medium size.
//    else
//    {
//        director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
//    }
    setupResolutionPolicy(1136, 640);


    register_all_packages();

    auto scene = MungGuGame::createScene(); //시작씬은 LogoScene이다.
    //시작씬 LogoScene
    //MungStoreScene
    //UnitScene
    //HelloMungCo
    
    //MissionScene
    //이곳에 미리 음악을 로딩해둔다.
    //*음악 셋팅은 두가지 오디오엔진을 이용한다. 목적은 두가지. 1.효과음, 2.배경음 두가지!!
    CocosDenshion::SimpleAudioEngine* audioEngine =
    CocosDenshion::SimpleAudioEngine::getInstance();
    CocosDenshion::SimpleAudioEngine* audioEngine2 =
    CocosDenshion::SimpleAudioEngine::getInstance();
    
    
    //미리 배경음악을 로딩
    audioEngine->setBackgroundMusicVolume(1); //0~1.0
    audioEngine->setEffectsVolume(1);
    audioEngine2->setBackgroundMusicVolume(1); //0~1.0
    audioEngine2->setEffectsVolume(0.6);
    audioEngine->preloadBackgroundMusic("myFirstSong.mp3");//배경음악 로딩
    audioEngine->preloadBackgroundMusic("background.mp3");//배경음악 로딩(스테이지 별)
    audioEngine->preloadBackgroundMusic("gameStart.mp3");//배경음악 로딩(스테이지 별)
    audioEngine->preloadBackgroundMusic("redriver.mp3");//배경음악 로딩(스테이지 별)
    
    audioEngine->preloadEffect("stageLoser.mp3");//게임오버일때 나오는 배경음악
    audioEngine->preloadEffect("warning.wav");//경고음악
    audioEngine->preloadEffect("warning2.wav");//경고음악2
    audioEngine->preloadEffect("LogoSong.mp3");//OurTrees 로고 나올때 들리는 노래
    audioEngine->preloadEffect("mungFireSound.wav");//멍포를 쏠때 나오는 소리
    audioEngine->preloadEffect("mungFireExplosionSound.wav");//멍포 폭발 사운드
    audioEngine->preloadEffect("ChimeSound.wav");//고양이 죽는 소리
    audioEngine->preloadEffect("BreakSound.wav");//부서지는 소리
    audioEngine->preloadEffect("dogDead.wav");//개가 죽을 때 소리
    audioEngine->preloadEffect("catDead.wav");//고양이 죽을때 소리
    audioEngine->preloadEffect("mungBallAttack.wav");//공 개 공격소리
    audioEngine->preloadEffect("slapAttack.wav");//찰싹 뺨따구 떄리는 소리
    audioEngine->preloadEffect("Bite.wav");//확 무는 소리
    audioEngine->preloadEffect("mungFireReady.wav");//멍포 준비소리
    audioEngine2->preloadEffect("clickSound.mp3");//딸깍 클릭하는 소리
    
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    Director::getInstance()->stopAnimation();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseAllEffects();
    //다른씬에 갈때 음원을 끄고
    // if you use SimpleAudioEngine, it must be pause

//#if USE_AUDIO_ENGINE
//    AudioEngine::pauseAll();
//#elif USE_SIMPLE_AUDIO_ENGINE
//    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
//    SimpleAudioEngine::getInstance()->pauseAllEffects();
//#endif
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    //다른씬에 갈때 음원을 재개
}
