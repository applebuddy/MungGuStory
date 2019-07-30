//
//  MungGuGameMenuScene.h
//  MungCo
//
//  Created by Kyeongtae Min on 2014. 10. 17..
//
//

#ifndef __MungGu__MungGuGameMenuScene__
#define __MungGu__MungGuGameMenuScene__


#define TAG_SPRITE_ISSONGBTN 100
#include "cocos2d.h"
#include "Common.h"
#include "SimpleAudioEngine.h"
#include "HelloMunggu.h"
#include "MungGuGame.h"
#include "MungStoreScene.h"
#include "UnitScene.h"
#include "MissionScene.h"
#include "Util.h"
#include "GameStage.hpp"

USING_NS_CC;

static int myGold;
class MungGuGameMenuScene : public LayerColor
{
    
public:
    static MungGuGameMenuScene *instance;
    static MungGuGameMenuScene *getInstance();
    
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    MungGuGameMenuScene();
    
    void initData();

    CREATE_FUNC(MungGuGameMenuScene);
    
    
    
    Rect isSongBtnRect;
    Rect exitBtnRect;
    Rect littleExitBtnRect;
    Rect exitResumeBtnRect;
    Rect mungGuGameStartBtnRect;
    Rect infoBtnRect;
    Rect infoExitBtnRect;
    Rect mungStoreBtnRect;
    Rect unitBtnRect;
    Rect missionBtnRect;
    Sprite* introWindow;
    Sprite* introWindowEng;
    Sprite* introWindow2;
    Sprite* introWindow2Eng;
    Sprite* introExitBtn;
    Sprite* introExitBtn_;
    Sprite* MungGuGameMenuSceneBg;
    Rect introExitBtnRect;
    Rect goldAreaRect;
    Rect stage1_selectBtnRect;
    Rect stage2_selectBtnRect;
    Rect stage3_selectBtnRect;

    Rect stageBtnRect;
    Rect gameStartBtnRect;
    
    Label* myGold_label;
    Label* stage_label;
    Label* stageBtnInfo;
    bool isGameStartBtnTouched;
    void setStage();
    bool isUpperReplaceBtnTouched;
    bool isBottomReplaceBtnTouched;
    bool isIntroWindow;
    bool isIntroWindow2;
    bool isFbBtnTouched;
    bool isInfo;
    bool isInfoBtnTouched;
    bool isInfoExitBtnTouched;
    bool isMungStoreBtnTouched;
    bool isUnitBtnTouched;
    bool isMissionBtnTouched;
    bool isLittleExitBtnTouched;
    bool isExitBtnTouched;
    bool isExitResumeBtnTouched;
    bool isExitWindow;
    
    bool isSongBtnTouched;
    bool isNotSongBtnTouched;
    bool isStageSelected;
    bool isStageTouched;
    
    bool isStage1_selectBtnTouched;
    bool isStage2_selectBtnTouched;
    bool isStage3_selectBtnTouched;
    bool isStage4_selectBtnTouched;
    bool isStage5_selectBtnTouched;
    bool isStage6_selectBtnTouched;
    bool isStage7_selectBtnTouched;
    bool isStage8_selectBtnTouched;
    bool isStage9_selectBtnTouched;
    bool isStage10_selectBtnTouched;
    bool isStage11_selectBtnTouched;
    bool isStage12_selectBtnTouched;
    bool isStage13_selectBtnTouched;
    bool isStage14_selectBtnTouched;
    bool isStage15_selectBtnTouched;
    bool isStage16_selectBtnTouched;
    bool isStage17_selectBtnTouched;
    bool isStage18_selectBtnTouched;
    bool isStage19_selectBtnTouched;
    bool isStage20_selectBtnTouched;
    bool isStage21_selectBtnTouched;
    bool isStage22_selectBtnTouched;
    bool isStage23_selectBtnTouched;
    bool isStage24_selectBtnTouched;
    bool isStage25_selectBtnTouched;
    bool isStage26_selectBtnTouched;
    bool isStage27_selectBtnTouched;
    bool isStage28_selectBtnTouched;
    bool isStage29_selectBtnTouched;
    bool isStage30_selectBtnTouched;
    bool isStage31_selectBtnTouched;
    bool isStage32_selectBtnTouched;
    bool isStage33_selectBtnTouched;
    bool isStage34_selectBtnTouched;
    bool isStage35_selectBtnTouched;
    bool isStage36_selectBtnTouched;
    bool isStage37_selectBtnTouched;
    bool isStage38_selectBtnTouched;
    bool isStage39_selectBtnTouched;
    bool isStage40_selectBtnTouched;
    bool isStage41_selectBtnTouched;
    bool isStage42_selectBtnTouched;
    bool isStage43_selectBtnTouched;
    bool isStage44_selectBtnTouched;
    bool isStage45_selectBtnTouched;
    bool isStage46_selectBtnTouched;
    bool isStage47_selectBtnTouched;
    bool isStage48_selectBtnTouched;
    bool isStage49_selectBtnTouched;
    bool isStage50_selectBtnTouched;
   
    int stage1_clearCount;
    int stage2_clearCount;
    int stage3_clearCount;
    int stage4_clearCount;
    int stage5_clearCount;
    int stage6_clearCount;
    int stage7_clearCount;
    int stage8_clearCount;
    int stage9_clearCount;
    int stage10_clearCount,stage11_clearCount,stage12_clearCount,stage13_clearCount,stage14_clearCount,stage15_clearCount,stage16_clearCount,stage17_clearCount,stage18_clearCount,stage19_clearCount,stage20_clearCount,stage21_clearCount,stage22_clearCount,stage23_clearCount,stage24_clearCount,stage25_clearCount,stage26_clearCount,stage27_clearCount,stage28_clearCount,stage29_clearCount,stage30_clearCount;
    int stage31_clearCount;
    int stage32_clearCount;
    int stage33_clearCount;
    int stage34_clearCount;
    int stage35_clearCount;
    int stage36_clearCount;
    int stage37_clearCount;
    int stage38_clearCount;
    int stage39_clearCount;
    int stage40_clearCount;
    int stage41_clearCount;
    int stage42_clearCount;
    int stage43_clearCount;
    int stage44_clearCount;
    int stage45_clearCount;
    int stage46_clearCount;
    int stage47_clearCount;
    int stage48_clearCount;
    int stage49_clearCount;
    int stage50_clearCount;
    
    
    
    int stageIndexMin, stageIndexMax;
    int stageIndex;
    
    
    Label* gameStartBtnInfo;
    Label* revangeStart;
    Label* stage2_keepGoing;
    Label* stage3_3rd;
    Label* stage4_NeverDie;
    Label* stage5_;
    Label* stage6_;
    Label* stage7_;
    Label* stage8_;
    Label* stage9_;
    Label* stage10_;
    Label* stage11_;
    Label* stage12_;
    Label* stage13_;
    Label* stage14_;
    Label* stage15_;
    Label* stage16_;
    Label* stage17_;
    Label* stage18_;
    Label* stage19_;
    Label* stage20_;
    Label* stage21_;
    Label* stage22_;
    Label* stage23_;
    Label* stage24_;
    Label* stage25_;
    Label* stage26_;
    Label* stage27_;
    Label* stage28_;
    Label* stage29_;
    Label* stage30_;
    Label* stage31_;
    Label* stage32_;
    Label* stage33_;
    Label* stage34_;
    Label* stage35_;
    Label* stage36_;
    Label* stage37_;
    Label* stage38_;
    Label* stage39_;
    Label* stage40_;
    Label* stage41_;
    Label* stage42_;
    Label* stage43_;
    Label* stage44_;
    Label* stage45_;
    Label* stage46_;
    Label* stage47_;
    Label* stage48_;
    Label* stage49_;
    Label* stage50_;
    
    Label* stage1_Info;
    Label* stage2_Info;
    Label* stage3_Info;
    Label* stage4_Info;
    Label* stage5_Info;
    Label* stage6_Info;
    Label* stage7_Info;
    Label* stage8_Info;
    Label* stage9_Info;
    Label* stage10_Info;
    Label* stage11_Info;
    Label* stage12_Info;
    Label* stage13_Info;
    Label* stage14_Info;
    Label* stage15_Info;
    Label* stage16_Info;
    Label* stage17_Info;
    Label* stage18_Info;
    Label* stage19_Info;
    Label* stage20_Info;
    Label* stage21_Info;
    Label* stage22_Info;
    Label* stage23_Info;
    Label* stage24_Info;
    Label* stage25_Info;
    Label* stage26_Info;
    Label* stage27_Info;
    Label* stage28_Info;
    Label* stage29_Info;
    Label* stage30_Info;
    Label* stage31_Info;
    Label* stage32_Info;
    Label* stage33_Info;
    Label* stage34_Info;
    Label* stage35_Info;
    Label* stage36_Info;
    Label* stage37_Info;
    Label* stage38_Info;
    Label* stage39_Info;
    Label* stage40_Info;
    Label* stage41_Info;
    Label* stage42_Info;
    Label* stage43_Info;
    Label* stage44_Info;
    Label* stage45_Info;
    Label* stage46_Info;
    Label* stage47_Info;
    Label* stage48_Info;
    Label* stage49_Info;
    Label* stage50_Info;
    
    Sprite* stage1_selectBtn;
    Sprite* stage2_selectBtn;
    Sprite* stage3_selectBtn;
    Sprite* stage4_selectBtn;
    Sprite* stage5_selectBtn;
    Sprite* stage6_selectBtn;
    Sprite* stage7_selectBtn;
    Sprite* stage8_selectBtn;
    Sprite* stage9_selectBtn;
    Sprite* stage10_selectBtn;
    Sprite* stage11_selectBtn;
    Sprite* stage12_selectBtn;
    Sprite* stage13_selectBtn;
    Sprite* stage14_selectBtn;
    Sprite* stage15_selectBtn;
    Sprite* stage16_selectBtn;
    Sprite* stage17_selectBtn;
    Sprite* stage18_selectBtn;
    Sprite* stage19_selectBtn;
    Sprite* stage20_selectBtn;
    Sprite* stage21_selectBtn;
    Sprite* stage22_selectBtn;
    Sprite* stage23_selectBtn;
    Sprite* stage24_selectBtn;
    Sprite* stage25_selectBtn;
    Sprite* stage26_selectBtn;
    Sprite* stage27_selectBtn;
    Sprite* stage28_selectBtn;
    Sprite* stage29_selectBtn;
    Sprite* stage30_selectBtn;
    Sprite* stage31_selectBtn;
    Sprite* stage32_selectBtn;
    Sprite* stage33_selectBtn;
    Sprite* stage34_selectBtn;
    Sprite* stage35_selectBtn;
    Sprite* stage36_selectBtn;
    Sprite* stage37_selectBtn;
    Sprite* stage38_selectBtn;
    Sprite* stage39_selectBtn;
    Sprite* stage40_selectBtn;
    Sprite* stage41_selectBtn;
    Sprite* stage42_selectBtn;
    Sprite* stage43_selectBtn;
    Sprite* stage44_selectBtn;
    Sprite* stage45_selectBtn;
    Sprite* stage46_selectBtn;
    Sprite* stage47_selectBtn;
    Sprite* stage48_selectBtn;
    Sprite* stage49_selectBtn;
    Sprite* stage50_selectBtn;
    
    Size winSize;
    Point point;
//    Sprite* MungGuGameMenuScene;
    Sprite* logo;
    Sprite* gameStartBtn;
    Sprite* gameStartBtn_;
    Sprite* upperReplaceBtn;
    Sprite* upperReplaceBtn_;
    Sprite* bottomReplaceBtn;
    Sprite* bottomReplaceBtn_;
    
    
    Sprite* isSongBtn;
    Sprite* isSongBtn_;
    Sprite* isNotSongBtn;
    Sprite* isNotSongBtn_;
    
    Sprite* infoBtn;
    Sprite* infoBtn_;
    Sprite* infoWindow;
    Sprite* infoExitBtn;
    Sprite* infoExitBtn_;
    Sprite* stageBtn;
    Sprite* goldArea;
    Sprite* mungStoreBtn;
    Sprite* mungStoreBtn_;
    Sprite* unitBtn;
    Sprite* unitBtn_;
    Sprite* missionBtn;
    Sprite* missionBtn_;
    
    Sprite* exitWindow;
    Sprite* littleExitBtn;
    Sprite* littleExitBtn_;
    Sprite* exitBtn;
    Sprite* exitBtn_;
    Sprite* exitResumeBtn;
    Sprite* exitResumeBtn_;
    Sprite* go;
    Sprite* whiteDot;
    
    void setMyGold();
    void stageTouchFinished();
    void setSongPlayedBtn();
    void hideStageSelectBtns();
    Rect stage4_selectBtnRect;
    Rect stage5_selectBtnRect;
    void setStageSelectBtns();
    void initDarkAction();
    void changeGameMenuScene();
    void initgameStartEvent();
    void setGameStartEvent();
    void setExitWindow();
    void initExitWindow();
    void initBtnAction();
    void changeMyGold();
    void setInfoBtn();
    void setInfoWindow();
    void initInfoWindow();
    void removeInfoWindow();
    void setGameStartBtn();
    void setGameMenuBtn();
    void update(float delta);
    void setFacebookBtn();
    Sprite* fbBtn;
    Sprite* fbBtn_;
    // int winHeight,winWidth;
    // implement the "static create()" method manually
    Sprite* mainMenuCenter;
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
    void changeGameMenuScene(Ref *sender);
    void changeUnitScene(Ref *sender);
    void changeMungStoreScene(Ref *sender);
    void changeMissionScene(Ref *sender);
    
    Sprite* eBtn;//영어버튼
    Sprite* hBtn;//한국버튼
    Sprite* eBtn_;//영어버튼
    Sprite* hBtn_;//한국버튼
    Rect eBtnRect;
    bool initByEnglish;
    Label* ehLabel;
    bool isEhBtnTouched;
    GameStage * gStage;

    
};




#endif /* defined(__MungCo__MungGuGameMenuScene__) */
