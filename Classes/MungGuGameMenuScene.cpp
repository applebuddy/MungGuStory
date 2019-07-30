

/*        -----------      멍구XXX(미정)         ---------------


=======                                    게임 메뉴 씬                                        =======


//현재 개발 최대 과제: 스테이지선택과정의 이벤트를 어떻게, 코딩을 어떻게 해야할까? 건물뿐만아니라 적과의 충돌도 인식 시켜야 한다. 이제 냥코 적들을 죽여야 한다.
//                 멍구 대포는 어떻게 쓸까? 멍구건물의 대포기능을 냥코와는 다르게 재미를 주고싶다.
//  *생각한 내용 : 멍코가 멋있게? 머리를 움직이며, 누른 만큼의 거리를 향해 멍구대포를 발싸 레벨에 따라 대포의 파괴력과 범위가 다를 수 있다 -> 후에 대포의 속성, 파괴력, 범위, 특징등을 커스터마이징 가능.

//음악은 어떻게 만들까? 좋은 툴이 없을까? 이펙트를 더 화려하게 만드는 방법
//프롤로그 애니메이션의 기획. 항상 무시받는 멍구 어느날 복수심에 불타올라 세상을 개혁하고자 하는 마음을 먹고 개들을 암암리에 모르기 시작하는데...

//개발에 있어서 중요한 요소! 1.콜백함수를 이해해야 한다.
//                     2.싱글톤? 다른 클래스로부터 변수를 받을때, 다시 씬을 생성 안하는 방법.
*/



#include "MungGuGameMenuScene.h"

USING_NS_CC;
using namespace CocosDenshion;



//스테이지 버튼 터치 체크
//bool isStage1_selectBtnTouched = false;
//bool isStage2_selectBtnTouched = false;
//bool isStage3_selectBtnTouched = false;
//bool isStage4_selectBtnTouched = false;
//bool isStage5_selectBtnTouched = false;
//bool isStage6_selectBtnTouched = false;
//bool isStage7_selectBtnTouched = false;
//bool isStage8_selectBtnTouched = false;
//bool isStage9_selectBtnTouched = false;
//bool isStage10_selectBtnTouched = false;
//bool isStage11_selectBtnTouched = false;
//bool isStage12_selectBtnTouched = false;
//bool isStage13_selectBtnTouched = false;
//bool isStage14_selectBtnTouched = false;
//bool isStage15_selectBtnTouched = false;


MungGuGameMenuScene* MungGuGameMenuScene::instance = nullptr;
MungGuGameMenuScene* MungGuGameMenuScene::getInstance() {//싱글톤 방법??

	if (instance == nullptr)
	{
		instance = new MungGuGameMenuScene();
	}

	return instance;
}


MungGuGameMenuScene::MungGuGameMenuScene()
:gStage(nullptr)//gStage 초기화
{
    
}


Scene* MungGuGameMenuScene::createScene()
{
	Director::getInstance()->resume();
  
     SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MungGuGameMenuScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

int isFirstPlayedTest=0;

// on "init" you need to initialize your instance
bool MungGuGameMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!LayerColor::initWithColor(Color4B(0, 0, 0, 0)))
    {
        return false;
    }
    
    gStage = new GameStage;
    
    winSize = Director::getInstance()->getWinSize();
    UserDefault::getInstance()->setIntegerForKey("attemptValue",0);//이 씬에 들어오게되면 무조건 초기화
    isIntroWindow2 = false;
    isIntroWindow = false;
    isFbBtnTouched = false;
    //introWindow
        introWindow = Sprite::create("introWindow.png");
        introWindow->setPosition(Point(winSize.width/2,winSize.height+35));
        introWindow->setAnchorPoint(Point(0.5,1));
        introWindow->setScale(1.1);
     this->addChild(introWindow,100);
    introWindow->setVisible(false);
    
    introWindowEng = Sprite::create("introWindow_eng.png");
    introWindowEng->setPosition(Point(winSize.width/2,winSize.height+35));
    introWindowEng->setAnchorPoint(Point(0.5,1));
    introWindowEng->setScale(1.1);
     this->addChild(introWindowEng,100);
    introWindowEng->setVisible(false);
    
    isIntroWindow2 = false;
    //introWindow
    introWindow2 = Sprite::create("introWindow2.png");
    introWindow2->setPosition(Point(winSize.width/2,winSize.height+35));
    introWindow2->setAnchorPoint(Point(0.5,1));
    introWindow2->setScale(1.1);
    this->addChild(introWindow2,100);
    introWindow2->setVisible(false);
    
    introWindow2Eng = Sprite::create("introWindow2_eng.png");
    introWindow2Eng->setPosition(Point(winSize.width/2,winSize.height+35));
    introWindow2Eng->setAnchorPoint(Point(0.5,1));
    introWindow2Eng->setScale(1.1);
    this->addChild(introWindow2Eng,100);
    introWindow2Eng->setVisible(false);
    
    Rect introWindowRect = introWindow->getBoundingBox();
    introExitBtn = Sprite::create("exitBtn.png");
    introExitBtn->setAnchorPoint(Point(0.5,0.5));
    introExitBtn->setPosition(Point(introWindowRect.getMaxX(),winSize.height*4/5));
    introExitBtn->setVisible(false);
    this->addChild(introExitBtn,101);
    introExitBtn_ = Sprite::create("exitBtn_.png");
    introExitBtn_->setAnchorPoint(Point(0.5,0.5));
    introExitBtn_->setPosition(Point(introWindowRect.getMaxX(),winSize.height*4/5));
    introExitBtn_->setVisible(false);
    
    introExitBtn->setScale(1.2);
    introExitBtn_->setScale(1.2);
    this->addChild(introExitBtn_,101);
    introExitBtnRect = introExitBtn->getBoundingBox();
    

     isIntroWindow = false;
    
    //스크롤뷰 구현
//    auto layer = LayerColor::create(Color4B(0,0,0,0));
//    layer->setContentSize(Size(1000,200));
//    layer->setPosition(Point(20,winSize.height));
//    layer->setAnchorPoint(Point(0.5,1));
//    
//    auto spr = Sprite::create("introWindow.png");
//    spr->setPosition(Point(winSize.width/2,winSize.height));
//    spr->setAnchorPoint(Point(0.5,1));
//    spr->setScale(1.6);
//    lyer->addChild(spr,101);
////    auto scroll = ScrollView::create(Size(1000,1300),layer);
//    scroll->setDirection(ScrollView::Direction::VERTICAL);
//    scroll->setBounceable(false);
//    this->addChild(scroll,100);
  //  scroll->setContentOffset(Point(-100,0));
    
    
    /////testing/////
        //아래 두줄은 테스트 끈나면 지워야 테스트로 초기화 하고, -> 풀고 -> 배포
    //테스트 끝날떄 아래 키고, 이걸 지운다.
    //UserDefault::getInstance()->setIntegerForKey("gameCount",0);
    //gameCount가 0이면 초기화 후, 1이됨 -> 초기화 안됨
    int gameCount = UserDefault::getInstance()->getIntegerForKey("gameCount",0);
    if(gameCount==0){
        UserDefault::getInstance()->setBoolForKey("initByEnglish", true); //영어로 설정
        //한영 변환
        UserDefault::getInstance()->setBoolForKey("initMissionScene", false);
      
       
        
        
        //골드는 프롤로그에서 설정
        
        UserDefault::getInstance()->setIntegerForKey("mungLv", 1);
        UserDefault::getInstance()->setIntegerForKey("whangLv", 0);
        UserDefault::getInstance()->setIntegerForKey("mungBallLv", 0);
        UserDefault::getInstance()->setIntegerForKey("mungButLv", 0);
        UserDefault::getInstance()->setIntegerForKey("mungSausageLv", 0);
        UserDefault::getInstance()->setIntegerForKey("mungGuDogSiteHpLv", 1);
        UserDefault::getInstance()->setIntegerForKey("mungGuDogSitePoLv", 1);
        UserDefault::getInstance()->setIntegerForKey("mungGuDogSiteRangeLv", 1);
        UserDefault::getInstance()->setBoolForKey("m1", false);
        UserDefault::getInstance()->setBoolForKey("m2", false);
        UserDefault::getInstance()->setBoolForKey("m3", false);
        UserDefault::getInstance()->setBoolForKey("m4", false);
        UserDefault::getInstance()->setBoolForKey("m5", false);
        UserDefault::getInstance()->setBoolForKey("m6", false);
        UserDefault::getInstance()->setBoolForKey("m7", false);
        UserDefault::getInstance()->setBoolForKey("m8", false);
        UserDefault::getInstance()->setBoolForKey("m9", false);
        UserDefault::getInstance()->setBoolForKey("m10", false);
        UserDefault::getInstance()->setBoolForKey("m11", false);
        UserDefault::getInstance()->setBoolForKey("m12", false);
        UserDefault::getInstance()->setBoolForKey("m13", false);
        UserDefault::getInstance()->setBoolForKey("m14", false);
        UserDefault::getInstance()->setBoolForKey("m15", false);
        UserDefault::getInstance()->setBoolForKey("m16", false);
        UserDefault::getInstance()->setBoolForKey("m17", false);
        UserDefault::getInstance()->setBoolForKey("m18", false);
        UserDefault::getInstance()->setBoolForKey("m19", false);
        UserDefault::getInstance()->setBoolForKey("m20", false);
        UserDefault::getInstance()->setBoolForKey("m21", false);
        UserDefault::getInstance()->setBoolForKey("m22", false);
        UserDefault::getInstance()->setBoolForKey("m23", false);
        UserDefault::getInstance()->setBoolForKey("m24", false);
        UserDefault::getInstance()->setBoolForKey("m25", false);
        UserDefault::getInstance()->setBoolForKey("m26", false);
        UserDefault::getInstance()->setBoolForKey("m27", false);
        UserDefault::getInstance()->setBoolForKey("m28", false);
        UserDefault::getInstance()->setBoolForKey("m29", false);
        UserDefault::getInstance()->setBoolForKey("m30", false);
        
        
        ////////
        ///////테 스 트 용 코 드/////////////////////////////////// => 배포떄 지움
//        UserDefault::getInstance()->setBoolForKey("m1", true);
//        UserDefault::getInstance()->setBoolForKey("m2", true);
//        UserDefault::getInstance()->setBoolForKey("m3", true);
//        UserDefault::getInstance()->setBoolForKey("m4", true);
//        UserDefault::getInstance()->setBoolForKey("m5", true);
//        UserDefault::getInstance()->setBoolForKey("m6", true);
//        UserDefault::getInstance()->setBoolForKey("m7", true);
//        UserDefault::getInstance()->setBoolForKey("m8", true);
//        UserDefault::getInstance()->setBoolForKey("m9", true);
//        UserDefault::getInstance()->setBoolForKey("m10", true);
//        UserDefault::getInstance()->setBoolForKey("m11", true);
//        UserDefault::getInstance()->setBoolForKey("m12", true);
//        UserDefault::getInstance()->setBoolForKey("m13", true);
//        UserDefault::getInstance()->setBoolForKey("m14", true);
//        UserDefault::getInstance()->setBoolForKey("m15", true);
//        UserDefault::getInstance()->setBoolForKey("m16", true);
//        UserDefault::getInstance()->setBoolForKey("m17", true);
//        UserDefault::getInstance()->setBoolForKey("m18", true);
//        UserDefault::getInstance()->setBoolForKey("m19", true);
//        UserDefault::getInstance()->setBoolForKey("m20", true);
//        UserDefault::getInstance()->setBoolForKey("m21", true);
//        UserDefault::getInstance()->setBoolForKey("m22", true);
//        UserDefault::getInstance()->setBoolForKey("m23", true);
//        UserDefault::getInstance()->setBoolForKey("m24", true);
//        UserDefault::getInstance()->setBoolForKey("m25", true);
//        UserDefault::getInstance()->setBoolForKey("m26", true);
//        UserDefault::getInstance()->setBoolForKey("m27", true);
//        UserDefault::getInstance()->setBoolForKey("m28", true);
//        UserDefault::getInstance()->setBoolForKey("m29", true);
//        UserDefault::getInstance()->setBoolForKey("m30", true);
        ////////////
        
        UserDefault::getInstance()->setIntegerForKey("disabled_count", 0);
         UserDefault::getInstance()->setIntegerForKey("disabled2_count", 0);
        //처음 게임 실행 시를 체크 모든 데이터를 초기화, 그 뒤로 기록을 누적
        
        gStage->setFirstStageData();
        UserDefault::getInstance()->setIntegerForKey("stage1_revangeStartClearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage2_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage3_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage4_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage5_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage6_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage7_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage8_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage9_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage10_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage11_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage12_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage13_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage14_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage15_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage16_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage17_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage18_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage19_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage20_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage21_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage22_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage23_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage24_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage25_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage26_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage27_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage28_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage29_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage30_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage31_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage32_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage33_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage34_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage35_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage36_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage37_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage38_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage39_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage40_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage41_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage42_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage43_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage44_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage45_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage46_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage47_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage48_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage49_clearCount", 0);
        UserDefault::getInstance()->setIntegerForKey("stage50_clearCount", 0);
        
    //테스트 끝 이걸 생기게 학고 위 (set)를 지운다.
          UserDefault::getInstance()->setIntegerForKey("gameCount", gameCount+1);
   // UserDefault::getInstance()->setIntegerForKey("revangeStartClearCount", 0);//1스테이지 클리어 횟수 초기화
      //  isFirstPlayedTest++;
    }else{
        UserDefault::getInstance()->setIntegerForKey("gameCount", gameCount+1);//메인 올때마다 카운트 누적
    }
    
    
    
    gameCount = UserDefault::getInstance()->getIntegerForKey("gameCount");
    if((gameCount == 12)||(gameCount == 60)||(gameCount == 150)){
        //모집 이미지 띄움
        isIntroWindow = true;
        initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
        if(initByEnglish==false){
            introWindow2->setVisible(true);
        }else{
            introWindow2Eng->setVisible(true);
        }
        introExitBtn->setVisible(true);
        introExitBtn_->setVisible(false);
    }
    
    //스테이지 생성 알고리즘....
    
    //*/
    //1.스테이지 선택 정보를 담음
    stage1_clearCount = UserDefault::getInstance()->getIntegerForKey("stage1_revangeStartClearCount");
    stage2_clearCount = UserDefault::getInstance()->getIntegerForKey("stage2_clearCount");
    stage3_clearCount = UserDefault::getInstance()->getIntegerForKey("stage3_clearCount");
    stage4_clearCount = UserDefault::getInstance()->getIntegerForKey("stage4_clearCount");
    stage5_clearCount = UserDefault::getInstance()->getIntegerForKey("stage5_clearCount");
    stage6_clearCount = UserDefault::getInstance()->getIntegerForKey("stage6_clearCount");
    stage7_clearCount = UserDefault::getInstance()->getIntegerForKey("stage7_clearCount");
    stage8_clearCount = UserDefault::getInstance()->getIntegerForKey("stage8_clearCount");stage9_clearCount = UserDefault::getInstance()->getIntegerForKey("stage9_clearCount");stage10_clearCount = UserDefault::getInstance()->getIntegerForKey("stage10_clearCount");
    stage11_clearCount = UserDefault::getInstance()->getIntegerForKey("stage11_clearCount");
    stage12_clearCount = UserDefault::getInstance()->getIntegerForKey("stage12_clearCount");
    stage13_clearCount = UserDefault::getInstance()->getIntegerForKey("stage13_clearCount");stage14_clearCount = UserDefault::getInstance()->getIntegerForKey("stage14_clearCount");stage15_clearCount = UserDefault::getInstance()->getIntegerForKey("stage15_clearCount");
    stage16_clearCount = UserDefault::getInstance()->getIntegerForKey("stage16_clearCount");
    stage17_clearCount = UserDefault::getInstance()->getIntegerForKey("stage17_clearCount");
    stage18_clearCount = UserDefault::getInstance()->getIntegerForKey("stage18_clearCount");stage19_clearCount = UserDefault::getInstance()->getIntegerForKey("stage19_clearCount");stage20_clearCount = UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
    stage21_clearCount = UserDefault::getInstance()->getIntegerForKey("stage21_clearCount");
    stage22_clearCount = UserDefault::getInstance()->getIntegerForKey("stage22_clearCount");
    stage23_clearCount = UserDefault::getInstance()->getIntegerForKey("stage23_clearCount");stage24_clearCount = UserDefault::getInstance()->getIntegerForKey("stage24_clearCount");stage25_clearCount = UserDefault::getInstance()->getIntegerForKey("stage25_clearCount");
    stage26_clearCount = UserDefault::getInstance()->getIntegerForKey("stage26_clearCount");
    stage27_clearCount = UserDefault::getInstance()->getIntegerForKey("stage27_clearCount");
    stage28_clearCount = UserDefault::getInstance()->getIntegerForKey("stage28_clearCount");stage29_clearCount = UserDefault::getInstance()->getIntegerForKey("stage29_clearCount");stage30_clearCount = UserDefault::getInstance()->getIntegerForKey("stage30_clearCount");
    stage31_clearCount = UserDefault::getInstance()->getIntegerForKey("stage31_clearCount");
    stage32_clearCount = UserDefault::getInstance()->getIntegerForKey("stage32_clearCount");
    stage33_clearCount = UserDefault::getInstance()->getIntegerForKey("stage33_clearCount");stage34_clearCount = UserDefault::getInstance()->getIntegerForKey("stage34_clearCount");stage35_clearCount = UserDefault::getInstance()->getIntegerForKey("stage35_clearCount");
    stage36_clearCount = UserDefault::getInstance()->getIntegerForKey("stage36_clearCount");
    stage37_clearCount = UserDefault::getInstance()->getIntegerForKey("stage37_clearCount");
    stage38_clearCount = UserDefault::getInstance()->getIntegerForKey("stage38_clearCount");stage39_clearCount = UserDefault::getInstance()->getIntegerForKey("stage39_clearCount");stage40_clearCount = UserDefault::getInstance()->getIntegerForKey("stage40_clearCount");
    stage41_clearCount = UserDefault::getInstance()->getIntegerForKey("stage41_clearCount");
    stage42_clearCount = UserDefault::getInstance()->getIntegerForKey("stage42_clearCount");
    stage43_clearCount = UserDefault::getInstance()->getIntegerForKey("stage43_clearCount");stage44_clearCount = UserDefault::getInstance()->getIntegerForKey("stage44_clearCount");stage45_clearCount = UserDefault::getInstance()->getIntegerForKey("stage45_clearCount");
    stage46_clearCount = UserDefault::getInstance()->getIntegerForKey("stage46_clearCount");
    stage47_clearCount = UserDefault::getInstance()->getIntegerForKey("stage47_clearCount");
    stage48_clearCount = UserDefault::getInstance()->getIntegerForKey("stage48_clearCount");stage49_clearCount = UserDefault::getInstance()->getIntegerForKey("stage49_clearCount");stage50_clearCount = UserDefault::getInstance()->getIntegerForKey("stage50_clearCount");
    isStageSelected = false;
    //2.스테이지에 따라 보이게함.
    
    
    
    //스테이지 선택 정보를 셋팅
    UserDefault::getInstance()->setBoolForKey("isStage1", false);
    UserDefault::getInstance()->setBoolForKey("isStage2", false);
    UserDefault::getInstance()->setBoolForKey("isStage3", false);
    UserDefault::getInstance()->setBoolForKey("isStage4", false);
    UserDefault::getInstance()->setBoolForKey("isStage5", false);
    UserDefault::getInstance()->setBoolForKey("isStage6", false);
    UserDefault::getInstance()->setBoolForKey("isStage7", false);
    UserDefault::getInstance()->setBoolForKey("isStage8", false);
    UserDefault::getInstance()->setBoolForKey("isStage9", false);
    UserDefault::getInstance()->setBoolForKey("isStage10", false);
    UserDefault::getInstance()->setBoolForKey("isStage11", false);
    UserDefault::getInstance()->setBoolForKey("isStage12", false);
    UserDefault::getInstance()->setBoolForKey("isStage13", false);
    UserDefault::getInstance()->setBoolForKey("isStage14", false);
    UserDefault::getInstance()->setBoolForKey("isStage15", false);
    UserDefault::getInstance()->setBoolForKey("isStage16", false);
    UserDefault::getInstance()->setBoolForKey("isStage17", false);
    UserDefault::getInstance()->setBoolForKey("isStage18", false);
    UserDefault::getInstance()->setBoolForKey("isStage19", false);
    UserDefault::getInstance()->setBoolForKey("isStage20", false);
    UserDefault::getInstance()->setBoolForKey("isStage21", false);
    UserDefault::getInstance()->setBoolForKey("isStage22", false);
    UserDefault::getInstance()->setBoolForKey("isStage23", false);
    UserDefault::getInstance()->setBoolForKey("isStage24", false);
    UserDefault::getInstance()->setBoolForKey("isStage25", false);
    UserDefault::getInstance()->setBoolForKey("isStage26", false);
    UserDefault::getInstance()->setBoolForKey("isStage27", false);
    UserDefault::getInstance()->setBoolForKey("isStage28", false);
    UserDefault::getInstance()->setBoolForKey("isStage29", false);
    UserDefault::getInstance()->setBoolForKey("isStage30", false);
    UserDefault::getInstance()->setBoolForKey("isStage31", false);
    UserDefault::getInstance()->setBoolForKey("isStage32", false);
    UserDefault::getInstance()->setBoolForKey("isStage33", false);
    UserDefault::getInstance()->setBoolForKey("isStage34", false);
    UserDefault::getInstance()->setBoolForKey("isStage35", false);
    UserDefault::getInstance()->setBoolForKey("isStage36", false);
    UserDefault::getInstance()->setBoolForKey("isStage37", false);
    UserDefault::getInstance()->setBoolForKey("isStage38", false);
    UserDefault::getInstance()->setBoolForKey("isStage39", false);
    UserDefault::getInstance()->setBoolForKey("isStage40", false);
    UserDefault::getInstance()->setBoolForKey("isStage41", false);
    UserDefault::getInstance()->setBoolForKey("isStage42", false);
    UserDefault::getInstance()->setBoolForKey("isStage43", false);
    UserDefault::getInstance()->setBoolForKey("isStage44", false);
    UserDefault::getInstance()->setBoolForKey("isStage45", false);
    UserDefault::getInstance()->setBoolForKey("isStage46", false);
    UserDefault::getInstance()->setBoolForKey("isStage47", false);
    UserDefault::getInstance()->setBoolForKey("isStage48", false);
    UserDefault::getInstance()->setBoolForKey("isStage49", false);
    UserDefault::getInstance()->setBoolForKey("isStage50", false);
    ///*
    //UserDefault::getInstance()->setIntegerForKey("gameCount", 0);
     //int gameCount = UserDefault::getInstance()->getIntegerForKey("gameCount");
    //UserDefault::getInstance()->setIntegerForKey("revangeStartClearCount", gameCount+1);
   

   
	
	//SimpleAudioEngine::getInstance()->stopAllEffects();
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){//song 켰나 안켯나 확인
	if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
		SimpleAudioEngine::getInstance()->playBackgroundMusic("myFirstSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
	}
    }

	initData();
    setExitWindow();
    
	setInfoBtn();
	setInfoWindow();
	setGameStartBtn();
	setGameMenuBtn();
    setGameStartEvent();
    setSongPlayedBtn();
    setFacebookBtn();
    
    gameStartBtnRect = gameStartBtn->getBoundingBox();
	myGold = UserDefault::getInstance()->getIntegerForKey("myGold");

	MungGuGameMenuSceneBg = Sprite::create("MungGuGameMenuScene.png");
	Rect MungGuGameMenuSceneRect = MungGuGameMenuSceneBg->getBoundingBox();
	MungGuGameMenuSceneBg->setScale(winSize.width / MungGuGameMenuSceneRect.size.width, winSize.height / MungGuGameMenuSceneRect.size.height);
	MungGuGameMenuSceneBg->setPosition(winSize.width / 2, winSize.height / 2);
	MungGuGameMenuSceneBg->setAnchorPoint(Point(0.5, 0.5));
	this->addChild(MungGuGameMenuSceneBg, 1);

	stageBtn = Sprite::create("StageBtn.png");
	stageBtn->setPosition(Point(0, winSize.height));
	stageBtn->setAnchorPoint(Point(0, 1));
    stageBtn->setScale(0.8);
	this->addChild(stageBtn, 5);
    stageBtnRect = stageBtn->getBoundingBox();

	goldArea = Sprite::create("GoldArea.png");
	goldArea->setPosition(Point(winSize.width, winSize.height));
	goldArea->setAnchorPoint(Point(1, 1));
	//goldArea->setTag(TAG_SPRITE_GOLDAREA);
    goldAreaRect = goldArea->getBoundingBox();
	this->addChild(goldArea, 5);

	Rect goldAreaRect = goldArea->getBoundingBox();
	myGold_label = Label::createWithTTF //최고점수 표시할 라벨 선언
		(StringUtils::format("%d", myGold), "NanumBarunGothicBold.otf", 30);
	myGold_label->setAnchorPoint(Point(0, 0.5));
	myGold_label->setPosition(Point(goldAreaRect.getMaxX() - 253, goldAreaRect.getMidY()));
	myGold_label->setTag(55);
	myGold_label->setColor(Color3B::BLACK);
	this->addChild(myGold_label, 5);
	//setMyGold();
    
	  if(initByEnglish==true){
    stageBtnInfo = Label::createWithTTF(StringUtils::format("It's not a button ^^;;"), "NanumBarunGothic.otf", 20);
      }else{
          stageBtnInfo = Label::createWithTTF(StringUtils::format("버튼 아닙니다.. ^^;;"), "NanumBarunGothic.otf", 20);
      }
    stageBtnInfo->setAnchorPoint(Point(0, 0.5));
    stageBtnInfo->setPosition(Point(stageBtnRect.getMaxX() + 10, stageBtnRect.getMidY()));
    stageBtnInfo->setTag(55);
    stageBtnInfo->setColor(Color3B::BLACK);
    this->addChild(stageBtnInfo, 5);
    stageBtnInfo->setVisible(false);
    
    if(initByEnglish==true){
    gameStartBtnInfo = Label::createWithTTF(StringUtils::format("Hey, select the button!"), "NanumBarunGothic.otf", 20);
    }else{
    gameStartBtnInfo = Label::createWithTTF(StringUtils::format("스테이지 선택 먼저!"), "NanumBarunGothic.otf", 20);
    }
    gameStartBtnInfo->setAnchorPoint(Point(0, 0));
    gameStartBtnInfo->setPosition(Point(gameStartBtnRect.getMinX()+5, gameStartBtnRect.getMaxY()+10));
    gameStartBtnInfo->setTag(55);
    gameStartBtnInfo->setColor(Color3B::BLACK);
    this->addChild(gameStartBtnInfo, 5);
    gameStartBtnInfo->setVisible(false);
    
    setStage();
   
    isSongBtnRect = isSongBtn->getBoundingBox();
    stage1_selectBtnRect = stage1_selectBtn->getBoundingBox();
    stage2_selectBtnRect = stage2_selectBtn->getBoundingBox();
    exitBtnRect = exitBtn_->getBoundingBox();
    littleExitBtnRect = littleExitBtn_->getBoundingBox();
    exitResumeBtnRect = exitResumeBtn_->getBoundingBox();
  //  mungGuGameStartBtnRect = gameStartBtn->getBoundingBox();
    infoBtnRect = infoBtn->getBoundingBox();
    infoExitBtnRect = infoExitBtn->getBoundingBox();
    mungStoreBtnRect = mungStoreBtn->getBoundingBox();
    unitBtnRect = unitBtn->getBoundingBox();
    missionBtnRect = missionBtn->getBoundingBox();
    
    //가운데 이미지(임시 메꾸기 용)
    mainMenuCenter = Sprite::create("mainMenuCenter.png");
    mainMenuCenter->setAnchorPoint(Point(0,1));
    mainMenuCenter->setScale(2.0);
    mainMenuCenter->
    setPosition(Point(stage1_selectBtnRect.getMaxX()-30,stage1_selectBtnRect.getMidY()));
    
    this->addChild(mainMenuCenter,3);//가운데 이미지
    Rect mainMenuCenterRect = mainMenuCenter->getBoundingBox();
    stage_label = Label::createWithTTF(StringUtils::format("Select the stage!"), "NanumBarunGothicBold.otf", 20);
    stage_label->setAnchorPoint(Point(0.5,1));
    stage_label->
    setPosition(Point(mainMenuCenterRect.getMidX(),mainMenuCenterRect.getMaxY()-20));
    stage_label->setColor(Color3B::BLACK);
    if(initByEnglish==false){
        stage_label->setString(StringUtils::format("스테이지를 선택하세요!"));
    }
    this->addChild(stage_label,4);
    
    
	this->scheduleUpdate();

	return true;
}


//void MungGuGameMenuScene::setNetwork(){
//    HttpRequest* request = new HttpRequest();
//    
//    request->setUrl("http://naver.com");
//    request->setRequestType(HttpRequest::Type::POST);//get post
//   request->setResponseCallback(this, httpresponse_selector(MungGuGameMenuScene::onHttpRequestCompleted));
//    request->setTag("Get test");
//    HttpClient::getInstance()->send(request);
//    request->release();
//}



void MungGuGameMenuScene::setSongPlayedBtn(){
    
    //음악 옵션 버튼
    Rect infoBtnRect = infoBtn->getBoundingBox();
    isSongBtn = Sprite::create("isSongPlayedBtn.png");
    isSongBtn_ = Sprite::create("isSongPlayedBtn_.png");
    isNotSongBtn = Sprite::create("isNotSongPlayedBtn.png");
    isNotSongBtn_ = Sprite::create("isNotSongPlayedBtn_.png");
 //   isSongBtn->setTag(TAG_SPRITE_ISSONGBTN);
    
    isSongBtn->setPosition(Point(infoBtnRect.getMinX()-8,infoBtnRect.getMidY()));
    isSongBtn_->setPosition(Point(infoBtnRect.getMinX()-8,infoBtnRect.getMidY()));
    isNotSongBtn->setPosition(Point(infoBtnRect.getMinX()-8, infoBtnRect.getMidY()));
    isNotSongBtn_->setPosition(Point(infoBtnRect.getMinX()-8,infoBtnRect.getMidY()));
    
    isSongBtn->setAnchorPoint(Point(1, 0.5));
    isSongBtn_->setAnchorPoint(Point(1, 0.5));
    isNotSongBtn->setAnchorPoint(Point(1, 0.5));
    isNotSongBtn_->setAnchorPoint(Point(1, 0.5));
    
    isSongBtnRect = isSongBtn->getBoundingBox();
    
    this->addChild(isSongBtn, 5);//노래버튼
    this->addChild(isSongBtn_, 5);
    this->addChild(isNotSongBtn, 5);
    this->addChild(isNotSongBtn_, 5);
    
    isSongBtn->setScale(0.67);
    isSongBtn_->setScale(0.67);
    isNotSongBtn->setScale(0.67);
    isNotSongBtn_->setScale(0.67);
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){
    isSongBtn->setVisible(true);
    isSongBtn_->setVisible(false);
    isNotSongBtn->setVisible(false);
    isNotSongBtn_->setVisible(false);
    }else{
        isSongBtn->setVisible(false);
        isSongBtn_->setVisible(false);
        isNotSongBtn->setVisible(true);
        isNotSongBtn_->setVisible(false);
    }
}

void MungGuGameMenuScene::setExitWindow(){//exit창 셋팅

	//리스너 3개 필요 작은,큰버튼나가기 버튼, 계속시작 버튼
	exitResumeBtn = Sprite::create("resumeBtn.png");
	exitResumeBtn_ = Sprite::create("resumeBtn_.png");
	littleExitBtn = Sprite::create("littleExitBtn.png");
	littleExitBtn_ = Sprite::create("littleExitBtn_.png");
	exitBtn = Sprite::create("exitBtn.png");
	exitBtn_ = Sprite::create("exitBtn_.png");
	exitWindow = Sprite::create("exitWindow.png");

	littleExitBtn->setScale(0.3);
	littleExitBtn_->setScale(0.3);

	this->addChild(exitWindow, 100);

	//Rect infoBtnRect = infoBtn->getBoundingBox();

	littleExitBtn->setAnchorPoint(Point(0.5, 0));
	littleExitBtn->setPosition(Point(winSize.width-30, 5));
	littleExitBtn->setScale(1.3);
	littleExitBtn_->setAnchorPoint(Point(0.5, 0));
	littleExitBtn_->setPosition(Point(winSize.width-30, 5));
	littleExitBtn_->setScale(1.3);

	exitWindow->setAnchorPoint(Point(0.5, 0.5));
	exitWindow->setPosition(Point(winSize.width / 2, winSize.height / 2));
	Rect exitWindowRect = exitWindow->getBoundingBox();

	exitBtn->setAnchorPoint(Point(0.5, 0.5));
	exitBtn->setPosition(Point(exitWindowRect.getMidX() - 100, exitWindowRect.getMidY() - 30));
	exitBtn_->setAnchorPoint(Point(0.5, 0.5));
	exitBtn_->setPosition(Point(exitWindowRect.getMidX() - 100, exitWindowRect.getMidY() - 30));

	exitResumeBtn->setAnchorPoint(Point(0.5, 0.5));
	exitResumeBtn->setPosition(Point(exitWindowRect.getMidX() + 120, exitWindowRect.getMidY()));
	exitResumeBtn_->setAnchorPoint(Point(0.5, 0.5));
	exitResumeBtn_->setPosition(Point(exitWindowRect.getMidX() + 120, exitWindowRect.getMidY()));

	this->addChild(littleExitBtn, 5);
	this->addChild(littleExitBtn_, 6);
	this->addChild(exitResumeBtn, 111);
	this->addChild(exitResumeBtn_, 112);
	this->addChild(exitBtn, 111);
	this->addChild(exitBtn_, 112);

	//littleExitBtn_->setTag(TAG_SPRITE_LITTLEEXITBTN_);
	//exitResumeBtn_->setTag(TAG_SPRITE_EXITRESUMEBTN_);
	//exitBtn_->setTag(TAG_SPRITE_EXITBTN_);
    

	exitResumeBtn->setVisible(false);
	exitResumeBtn_->setVisible(false);
	littleExitBtn->setVisible(true);
	littleExitBtn_->setVisible(false);
	exitBtn->setVisible(false);
	exitBtn_->setVisible(false);
	exitWindow->setVisible(false);
}

void MungGuGameMenuScene::setInfoBtn(){
    Rect littleExitBtnRect = littleExitBtn->getBoundingBox();
    
    infoBtn = Sprite::create("infoBtn.png");
    infoBtn->setPosition(Point(littleExitBtnRect.getMinX() - 30, 5));
    infoBtn->setAnchorPoint(Point(0.5, 0));
    infoBtn->setScale(0.8);
  //  infoBtn->setTag(TAG_SPRITE_INFOBTN);
    this->addChild(infoBtn, 6);
    
    infoBtn_ = Sprite::create("infoBtn_.png");
    infoBtn_->setPosition(Point(littleExitBtnRect.getMinX() - 30, 5));
    infoBtn_->setAnchorPoint(Point(0.5, 0));
    infoBtn_->setScale(0.8);
   // infoBtn_->setTag(TAG_SPRITE_INFOBTN_);
    this->addChild(infoBtn_, 7);
    infoBtn_->setVisible(false);
    
}

void MungGuGameMenuScene::setFacebookBtn(){
    Rect littleExitBtnRect = littleExitBtn->getBoundingBox();
    fbBtn = Sprite::create("fbBtn2.png");
    fbBtn->setScale(0.5);
    fbBtn->setAnchorPoint(Point(1,0));
    fbBtn->setPosition(Point(littleExitBtnRect.getMinX() - 118,3));
    
    fbBtn_ = Sprite::create("fbBtn2_.png");
    fbBtn_->setPosition(Point(littleExitBtnRect.getMinX() - 118,3));
    fbBtn_->setScale(0.5);
    fbBtn_->setAnchorPoint(Point(1,0));
    
    fbBtn_->setVisible(false);
    this->addChild(fbBtn,7);
    this->addChild(fbBtn_,7);
}
void MungGuGameMenuScene::stageTouchFinished(){
    if(isStageTouched == true)
        isStageTouched = false;
}

void MungGuGameMenuScene::setStage(){
    
  
    
    /////스테이지_버튼_Sprite/////
    ///1스테이지 버튼
    stage1_selectBtn = Sprite::create("selectBtn.png");
    stage1_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage1_selectBtn->setAnchorPoint(Point(0,0.5));
    stage1_selectBtn->setOpacity(160);
    this->addChild(stage1_selectBtn,5);
   // stage1_selectBtn->setTag(TAG_SPRITE_STAGE1_SELECTBTN);
    
    
    stage1_selectBtnRect = stage1_selectBtn->getBoundingBox();
    
    ///6스테이지 버튼
    stage6_selectBtn = Sprite::create("selectBtn.png");
    stage6_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage6_selectBtn->setAnchorPoint(Point(0,0.5));
    stage6_selectBtn->setOpacity(160);
    stage6_selectBtn->setVisible(false);
    this->addChild(stage6_selectBtn,5);
    
    ///11스테이지 버튼
    stage11_selectBtn = Sprite::create("selectBtn.png");
    stage11_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage11_selectBtn->setAnchorPoint(Point(0,0.5));
    stage11_selectBtn->setOpacity(160);
    stage11_selectBtn->setVisible(false);
    this->addChild(stage11_selectBtn,5);
    
    ///16스테이지 버튼
    stage16_selectBtn = Sprite::create("selectBtn.png");
    stage16_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage16_selectBtn->setAnchorPoint(Point(0,0.5));
    stage16_selectBtn->setOpacity(160);
    stage16_selectBtn->setVisible(false);
    this->addChild(stage16_selectBtn,5);
    
    ///21스테이지 버튼
    stage21_selectBtn = Sprite::create("selectBtn.png");
    stage21_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage21_selectBtn->setAnchorPoint(Point(0,0.5));
    stage21_selectBtn->setOpacity(160);
    stage21_selectBtn->setVisible(false);
    this->addChild(stage21_selectBtn,5);
    
    ///26스테이지 버튼
    stage26_selectBtn = Sprite::create("selectBtn.png");
    stage26_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage26_selectBtn->setAnchorPoint(Point(0,0.5));
    stage26_selectBtn->setOpacity(160);
    stage26_selectBtn->setVisible(false);
    this->addChild(stage26_selectBtn,5);
    
    ///31스테이지 버튼
    stage31_selectBtn = Sprite::create("selectBtn.png");
    stage31_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage31_selectBtn->setAnchorPoint(Point(0,0.5));
    stage31_selectBtn->setOpacity(160);
    stage31_selectBtn->setVisible(false);
    this->addChild(stage31_selectBtn,5);
    
    ///36스테이지 버튼
    stage36_selectBtn = Sprite::create("selectBtn.png");
    stage36_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage36_selectBtn->setAnchorPoint(Point(0,0.5));
    stage36_selectBtn->setOpacity(160);
    stage36_selectBtn->setVisible(false);
    this->addChild(stage36_selectBtn,5);
    
    ///41스테이지 버튼
    stage41_selectBtn = Sprite::create("selectBtn.png");
    stage41_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage41_selectBtn->setAnchorPoint(Point(0,0.5));
    stage41_selectBtn->setOpacity(160);
    stage41_selectBtn->setVisible(false);
    this->addChild(stage41_selectBtn,5);
    
    ///46스테이지 버튼
    stage46_selectBtn = Sprite::create("selectBtn.png");
    stage46_selectBtn->setPosition(Point(10,winSize.height*15/20));
    stage46_selectBtn->setAnchorPoint(Point(0,0.5));
    stage46_selectBtn->setOpacity(160);
    stage46_selectBtn->setVisible(false);
    this->addChild(stage46_selectBtn,5);
    
    ///2스테이지 버튼
    stage2_selectBtn = Sprite::create("selectBtn.png");
    stage2_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage2_selectBtn->setAnchorPoint(Point(0,0.5));
    stage2_selectBtn->setOpacity(160);
    this->addChild(stage2_selectBtn,5);
   // stage2_selectBtn->setTag(TAG_SPRITE_STAGE2_SELECTBTN);
    
    stage2_selectBtnRect = stage2_selectBtn->getBoundingBox();
    
    ///7스테이지 버튼
    stage7_selectBtn = Sprite::create("selectBtn.png");
    stage7_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage7_selectBtn->setAnchorPoint(Point(0,0.5));
    stage7_selectBtn->setOpacity(160);
    this->addChild(stage7_selectBtn,5);
    
    ///12스테이지 버튼
    stage12_selectBtn = Sprite::create("selectBtn.png");
    stage12_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage12_selectBtn->setAnchorPoint(Point(0,0.5));
    stage12_selectBtn->setOpacity(160);
    this->addChild(stage12_selectBtn,5);
    
    ///17스테이지 버튼
    stage17_selectBtn = Sprite::create("selectBtn.png");
    stage17_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage17_selectBtn->setAnchorPoint(Point(0,0.5));
    stage17_selectBtn->setOpacity(160);
    this->addChild(stage17_selectBtn,5);
    
    ///22스테이지 버튼
    stage22_selectBtn = Sprite::create("selectBtn.png");
    stage22_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage22_selectBtn->setAnchorPoint(Point(0,0.5));
    stage22_selectBtn->setOpacity(160);
    this->addChild(stage22_selectBtn,5);
    
    ///27스테이지 버튼
    stage27_selectBtn = Sprite::create("selectBtn.png");
    stage27_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage27_selectBtn->setAnchorPoint(Point(0,0.5));
    stage27_selectBtn->setOpacity(160);
    this->addChild(stage27_selectBtn,5);
    
    ///32스테이지 버튼
    stage32_selectBtn = Sprite::create("selectBtn.png");
    stage32_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage32_selectBtn->setAnchorPoint(Point(0,0.5));
    stage32_selectBtn->setOpacity(160);
    this->addChild(stage32_selectBtn,5);
    
    ///37스테이지 버튼
    stage37_selectBtn = Sprite::create("selectBtn.png");
    stage37_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage37_selectBtn->setAnchorPoint(Point(0,0.5));
    stage37_selectBtn->setOpacity(160);
    this->addChild(stage37_selectBtn,5);
    
    ///42스테이지 버튼
    stage42_selectBtn = Sprite::create("selectBtn.png");
    stage42_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage42_selectBtn->setAnchorPoint(Point(0,0.5));
    stage42_selectBtn->setOpacity(160);
    this->addChild(stage42_selectBtn,5);
    
    ///47스테이지 버튼
    stage47_selectBtn = Sprite::create("selectBtn.png");
    stage47_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage1_selectBtnRect.getMinY()-50));
    stage47_selectBtn->setAnchorPoint(Point(0,0.5));
    stage47_selectBtn->setOpacity(160);
    this->addChild(stage47_selectBtn,5);
    
    ///3스테이지 버튼
    stage3_selectBtn = Sprite::create("selectBtn.png");
    stage3_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage3_selectBtn->setAnchorPoint(Point(0,0.5));
    stage3_selectBtn->setOpacity(160);
    this->addChild(stage3_selectBtn,5);
 //   stage3_selectBtn->setTag(TAG_SPRITE_STAGE3_SELECTBTN);
   // Rect stage3_selectBtnRect = stage3_selectBtn->getBoundingBox();
    stage3_selectBtnRect = stage3_selectBtn->getBoundingBox();
    
    ///8스테이지 버튼
    stage8_selectBtn = Sprite::create("selectBtn.png");
    stage8_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage8_selectBtn->setAnchorPoint(Point(0,0.5));
    stage8_selectBtn->setOpacity(160);
    this->addChild(stage8_selectBtn,5);
    
    //13ㅅ
    stage13_selectBtn = Sprite::create("selectBtn.png");
    stage13_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage13_selectBtn->setAnchorPoint(Point(0,0.5));
    stage13_selectBtn->setOpacity(160);
    this->addChild(stage13_selectBtn,5);
    
    //18ㅅ
    stage18_selectBtn = Sprite::create("selectBtn.png");
    stage18_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage18_selectBtn->setAnchorPoint(Point(0,0.5));
    stage18_selectBtn->setOpacity(160);
    this->addChild(stage18_selectBtn,5);
    
    //23ㅅ
    stage23_selectBtn = Sprite::create("selectBtn.png");
    stage23_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage23_selectBtn->setAnchorPoint(Point(0,0.5));
    stage23_selectBtn->setOpacity(160);
    this->addChild(stage23_selectBtn,5);
    
    //28ㅅ
    stage28_selectBtn = Sprite::create("selectBtn.png");
    stage28_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage28_selectBtn->setAnchorPoint(Point(0,0.5));
    stage28_selectBtn->setOpacity(160);
    this->addChild(stage28_selectBtn,5);
    
    //33ㅅ
    stage33_selectBtn = Sprite::create("selectBtn.png");
    stage33_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage33_selectBtn->setAnchorPoint(Point(0,0.5));
    stage33_selectBtn->setOpacity(160);
    this->addChild(stage33_selectBtn,5);
    
    //38ㅅ
    stage38_selectBtn = Sprite::create("selectBtn.png");
    stage38_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage38_selectBtn->setAnchorPoint(Point(0,0.5));
    stage38_selectBtn->setOpacity(160);
    this->addChild(stage38_selectBtn,5);
    
    //43ㅅ
    stage43_selectBtn = Sprite::create("selectBtn.png");
    stage43_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage43_selectBtn->setAnchorPoint(Point(0,0.5));
    stage43_selectBtn->setOpacity(160);
    this->addChild(stage43_selectBtn,5);
    
    //48ㅅ
    stage48_selectBtn = Sprite::create("selectBtn.png");
    stage48_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage2_selectBtnRect.getMinY()-50));
    stage48_selectBtn->setAnchorPoint(Point(0,0.5));
    stage48_selectBtn->setOpacity(160);
    this->addChild(stage48_selectBtn,5);
    
    ///4스테이지 버튼
    stage4_selectBtn = Sprite::create("selectBtn.png");
    stage4_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage4_selectBtn->setAnchorPoint(Point(0,0.5));
    stage4_selectBtn->setOpacity(160);
    this->addChild(stage4_selectBtn,5);
    
    stage4_selectBtnRect = stage4_selectBtn->getBoundingBox();
    
    
    ///9스테이지 버튼
    stage9_selectBtn = Sprite::create("selectBtn.png");
    stage9_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage9_selectBtn->setAnchorPoint(Point(0,0.5));
    stage9_selectBtn->setOpacity(160);
    this->addChild(stage9_selectBtn,5);
    
    ///14스테이지 버튼
    stage14_selectBtn = Sprite::create("selectBtn.png");
    stage14_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage14_selectBtn->setAnchorPoint(Point(0,0.5));
    stage14_selectBtn->setOpacity(160);
    this->addChild(stage14_selectBtn,5);
    
    ///19스테이지 버튼
    stage19_selectBtn = Sprite::create("selectBtn.png");
    stage19_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage19_selectBtn->setAnchorPoint(Point(0,0.5));
    stage19_selectBtn->setOpacity(160);
    this->addChild(stage19_selectBtn,5);
    
    ///24스테이지 버튼
    stage24_selectBtn = Sprite::create("selectBtn.png");
    stage24_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage24_selectBtn->setAnchorPoint(Point(0,0.5));
    stage24_selectBtn->setOpacity(160);
    this->addChild(stage24_selectBtn,5);
    
    ///29스테이지 버튼
    stage29_selectBtn = Sprite::create("selectBtn.png");
    stage29_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage29_selectBtn->setAnchorPoint(Point(0,0.5));
    stage29_selectBtn->setOpacity(160);
    this->addChild(stage29_selectBtn,5);
    
    ///34스테이지 버튼
    stage34_selectBtn = Sprite::create("selectBtn.png");
    stage34_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage34_selectBtn->setAnchorPoint(Point(0,0.5));
    stage34_selectBtn->setOpacity(160);
    this->addChild(stage34_selectBtn,5);
    
    ///39스테이지 버튼
    stage39_selectBtn = Sprite::create("selectBtn.png");
    stage39_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage39_selectBtn->setAnchorPoint(Point(0,0.5));
    stage39_selectBtn->setOpacity(160);
    this->addChild(stage39_selectBtn,5);
    
    ///44스테이지 버튼
    stage44_selectBtn = Sprite::create("selectBtn.png");
    stage44_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage44_selectBtn->setAnchorPoint(Point(0,0.5));
    stage44_selectBtn->setOpacity(160);
    this->addChild(stage44_selectBtn,5);
    
    ///49스테이지 버튼
    stage49_selectBtn = Sprite::create("selectBtn.png");
    stage49_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage3_selectBtnRect.getMinY()-50));
    stage49_selectBtn->setAnchorPoint(Point(0,0.5));
    stage49_selectBtn->setOpacity(160);
    this->addChild(stage49_selectBtn,5);
    
    ///5스테이지 버튼
    stage5_selectBtn = Sprite::create("selectBtn.png");
    stage5_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage5_selectBtn->setAnchorPoint(Point(0,0.5));
    stage5_selectBtn->setOpacity(160);
    this->addChild(stage5_selectBtn,5);
    
    stage5_selectBtnRect = stage5_selectBtn->getBoundingBox();
    
    ///10스테이지 버튼
    stage10_selectBtn = Sprite::create("selectBtn.png");
    stage10_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage10_selectBtn->setAnchorPoint(Point(0,0.5));
    stage10_selectBtn->setOpacity(160);
    this->addChild(stage10_selectBtn,5);
    
    ///15스테이지 버튼
    stage15_selectBtn = Sprite::create("selectBtn.png");
    stage15_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage15_selectBtn->setAnchorPoint(Point(0,0.5));
    stage15_selectBtn->setOpacity(160);
    this->addChild(stage15_selectBtn,5);
    
    ///20스테이지 버튼
    stage20_selectBtn = Sprite::create("selectBtn.png");
    stage20_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage20_selectBtn->setAnchorPoint(Point(0,0.5));
    stage20_selectBtn->setOpacity(160);
    this->addChild(stage20_selectBtn,5);
    
    ///25스테이지 버튼
    stage25_selectBtn = Sprite::create("selectBtn.png");
    stage25_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage25_selectBtn->setAnchorPoint(Point(0,0.5));
    stage25_selectBtn->setOpacity(160);
    this->addChild(stage25_selectBtn,5);
    
    ///30스테이지 버튼
    stage30_selectBtn = Sprite::create("selectBtn.png");
    stage30_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage30_selectBtn->setAnchorPoint(Point(0,0.5));
    stage30_selectBtn->setOpacity(160);
    this->addChild(stage30_selectBtn,5);
    
    ///35스테이지 버튼
    stage35_selectBtn = Sprite::create("selectBtn.png");
    stage35_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage35_selectBtn->setAnchorPoint(Point(0,0.5));
    stage35_selectBtn->setOpacity(160);
    this->addChild(stage35_selectBtn,5);
    
    stage5_selectBtnRect = stage5_selectBtn->getBoundingBox();
    
    ///40스테이지 버튼
    stage40_selectBtn = Sprite::create("selectBtn.png");
    stage40_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage40_selectBtn->setAnchorPoint(Point(0,0.5));
    stage40_selectBtn->setOpacity(160);
    this->addChild(stage40_selectBtn,5);
    
    ///45스테이지 버튼
    stage45_selectBtn = Sprite::create("selectBtn.png");
    stage45_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage45_selectBtn->setAnchorPoint(Point(0,0.5));
    stage45_selectBtn->setOpacity(160);
    this->addChild(stage45_selectBtn,5);
    
    ///50스테이지 버튼
    stage50_selectBtn = Sprite::create("selectBtn.png");
    stage50_selectBtn->setPosition(Point(stage1_selectBtnRect.getMinX(),stage4_selectBtnRect.getMinY()-50));
    stage50_selectBtn->setAnchorPoint(Point(0,0.5));
    stage50_selectBtn->setOpacity(160);
    this->addChild(stage50_selectBtn,5);
    
    /////스테이지_라벨_Sprite/////
    revangeStart = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Hello World"), "NanumBarunGothicBold.otf", 28);
    revangeStart->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    revangeStart->setAnchorPoint(Point(0.5,0.5));
    revangeStart->setColor(Color3B::BLACK);
    this->addChild(revangeStart,11);
    
    stage2_keepGoing = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Keep Going"), "NanumBarunGothicBold.otf", 28);
    stage2_keepGoing->setPosition(Point(stage2_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage2_keepGoing->setAnchorPoint(Point(0.5,0.5));
    stage2_keepGoing->setColor(Color3B::BLACK);
    this->addChild(stage2_keepGoing,11);
    
    stage3_3rd = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("3rd"), "NanumBarunGothicBold.otf", 28);
    stage3_3rd->setPosition(Point(stage3_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage3_3rd->setAnchorPoint(Point(0.5,0.5));
    stage3_3rd->setColor(Color3B::BLACK);
    this->addChild(stage3_3rd,11);
    
    stage4_NeverDie = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Never Die"), "NanumBarunGothicBold.otf", 28);
    stage4_NeverDie->setPosition(Point(stage4_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage4_NeverDie->setAnchorPoint(Point(0.5,0.5));
    stage4_NeverDie->setColor(Color3B::BLACK);
    this->addChild(stage4_NeverDie,11);
    
    stage5_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Oh"), "NanumBarunGothicBold.otf", 28);
    stage5_->setPosition(Point(stage5_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage5_->setAnchorPoint(Point(0.5,0.5));
    stage5_->setColor(Color3B::BLACK);
    this->addChild(stage5_,11);
    
    stage6_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Angry Cats"), "NanumBarunGothicBold.otf", 28);
    stage6_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage6_->setAnchorPoint(Point(0.5,0.5));
    stage6_->setColor(Color3B::BLACK);
    this->addChild(stage6_,11);
    stage6_->setVisible(false);
    
    stage7_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Lucky"), "NanumBarunGothicBold.otf", 28);
    stage7_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage7_->setAnchorPoint(Point(0.5,0.5));
    stage7_->setColor(Color3B::BLACK);
    this->addChild(stage7_,11);
    stage7_->setVisible(false);
    
    stage8_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("I And You"), "NanumBarunGothicBold.otf", 28);
    stage8_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage8_->setAnchorPoint(Point(0.5,0.5));
    stage8_->setColor(Color3B::BLACK);
    this->addChild(stage8_,11);
    stage8_->setVisible(false);
    
    stage9_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Gu"), "NanumBarunGothicBold.otf", 28);
    stage9_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage9_->setAnchorPoint(Point(0.5,0.5));
    stage9_->setColor(Color3B::BLACK);
    this->addChild(stage9_,11);
    stage9_->setVisible(false);
    
    stage10_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("SSip"), "NanumBarunGothicBold.otf", 28);
    stage10_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage10_->setAnchorPoint(Point(0.5,0.5));
    stage10_->setColor(Color3B::BLACK);
    this->addChild(stage10_,11);
    stage10_->setVisible(false);
    
    stage11_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("One of One"), "NanumBarunGothicBold.otf", 28);
    stage11_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage11_->setAnchorPoint(Point(0.5,0.5));
    stage11_->setColor(Color3B::BLACK);
    this->addChild(stage11_,11);
    stage11_->setVisible(false);
    
    stage12_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("12th"), "NanumBarunGothicBold.otf", 28);
    stage12_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage12_->setAnchorPoint(Point(0.5,0.5));
    stage12_->setColor(Color3B::BLACK);
    this->addChild(stage12_,11);
    stage12_->setVisible(false);
    
    stage13_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Omatt"), "NanumBarunGothicBold.otf", 28);
    stage13_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage13_->setAnchorPoint(Point(0.5,0.5));
    stage13_->setColor(Color3B::BLACK);
    this->addChild(stage13_,11);
    stage13_->setVisible(false);
    
    stage14_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Making"), "NanumBarunGothicBold.otf", 28);
    stage14_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage14_->setAnchorPoint(Point(0.5,0.5));
    stage14_->setColor(Color3B::BLACK);
    this->addChild(stage14_,11);
    stage14_->setVisible(false);
    
    stage15_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Stage"), "NanumBarunGothicBold.otf", 28);
    stage15_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage15_->setAnchorPoint(Point(0.5,0.5));
    stage15_->setColor(Color3B::BLACK);
    this->addChild(stage15_,11);
    stage15_->setVisible(false);
    
    stage16_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Namis"), "NanumBarunGothicBold.otf", 28);
    stage16_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage16_->setAnchorPoint(Point(0.5,0.5));
    stage16_->setColor(Color3B::BLACK);
    this->addChild(stage16_,11);
    stage16_->setVisible(false);
    
    stage17_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Difficult"), "NanumBarunGothicBold.otf", 28);
    stage17_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage17_->setAnchorPoint(Point(0.5,0.5));
    stage17_->setColor(Color3B::BLACK);
    this->addChild(stage17_,11);
    stage17_->setVisible(false);
    
    stage18_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("18th"), "NanumBarunGothicBold.otf", 28);
    stage18_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage18_->setAnchorPoint(Point(0.5,0.5));
    stage18_->setColor(Color3B::BLACK);
    this->addChild(stage18_,11);
    stage18_->setVisible(false);
    
    stage19_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("you Sorry"), "NanumBarunGothicBold.otf", 28);
    stage19_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage19_->setAnchorPoint(Point(0.5,0.5));
    stage19_->setColor(Color3B::BLACK);
    this->addChild(stage19_,11);
    stage19_->setVisible(false);
    
    stage20_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("ending"), "NanumBarunGothicBold.otf", 28);
    stage20_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage20_->setAnchorPoint(Point(0.5,0.5));
    stage20_->setColor(Color3B::BLACK);
    this->addChild(stage20_,11);
    stage20_->setVisible(false);
    
    /////21~30/////
    stage21_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Continuously"), "NanumBarunGothicBold.otf", 28);
    stage21_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage21_->setAnchorPoint(Point(0.5,0.5));
    stage21_->setColor(Color3B::BLACK);
    this->addChild(stage21_,11);
    stage21_->setVisible(false);
    
    stage22_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Give"), "NanumBarunGothicBold.otf", 28);
    stage22_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage22_->setAnchorPoint(Point(0.5,0.5));
    stage22_->setColor(Color3B::BLACK);
    this->addChild(stage22_,11);
    stage22_->setVisible(false);
    
    stage23_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Mee"), "NanumBarunGothicBold.otf", 28);
    stage23_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage23_->setAnchorPoint(Point(0.5,0.5));
    stage23_->setColor(Color3B::BLACK);
    this->addChild(stage23_,11);
    stage23_->setVisible(false);
    
    stage24_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("yourDog"), "NanumBarunGothicBold.otf", 28);
    stage24_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage24_->setAnchorPoint(Point(0.5,0.5));
    stage24_->setColor(Color3B::BLACK);
    this->addChild(stage24_,11);
    stage24_->setVisible(false);
    
    stage25_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("I wanna"), "NanumBarunGothicBold.otf", 28);
    stage25_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage25_->setAnchorPoint(Point(0.5,0.5));
    stage25_->setColor(Color3B::BLACK);
    this->addChild(stage25_,11);
    stage25_->setVisible(false);
    
    stage26_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Have"), "NanumBarunGothicBold.otf", 28);
    stage26_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage26_->setAnchorPoint(Point(0.5,0.5));
    stage26_->setColor(Color3B::BLACK);
    this->addChild(stage26_,11);
    stage26_->setVisible(false);
    
    stage27_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Variety"), "NanumBarunGothicBold.otf", 28);
    stage27_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage27_->setAnchorPoint(Point(0.5,0.5));
    stage27_->setColor(Color3B::BLACK);
    this->addChild(stage27_,11);
    stage27_->setVisible(false);
    
    stage28_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Dogs"), "NanumBarunGothicBold.otf", 28);
    stage28_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage28_->setAnchorPoint(Point(0.5,0.5));
    stage28_->setColor(Color3B::BLACK);
    this->addChild(stage28_,11);
    stage28_->setVisible(false);
    
    stage29_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Thanks"), "NanumBarunGothicBold.otf", 28);
    stage29_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage29_->setAnchorPoint(Point(0.5,0.5));
    stage29_->setColor(Color3B::BLACK);
    this->addChild(stage29_,11);
    stage29_->setVisible(false);
    
    stage30_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Bye-"), "NanumBarunGothicBold.otf", 28);
    stage30_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage30_->setAnchorPoint(Point(0.5,0.5));
    stage30_->setColor(Color3B::BLACK);
    this->addChild(stage30_,11);
    stage30_->setVisible(false);
    
    //31~40
    stage31_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("now"), "NanumBarunGothicBold.otf", 28);
    stage31_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage31_->setAnchorPoint(Point(0.5,0.5));
    stage31_->setColor(Color3B::BLACK);
    this->addChild(stage31_,11);
    stage31_->setVisible(false);
    
    stage32_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("I should"), "NanumBarunGothicBold.otf", 28);
    stage32_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage32_->setAnchorPoint(Point(0.5,0.5));
    stage32_->setColor(Color3B::BLACK);
    this->addChild(stage32_,11);
    stage32_->setVisible(false);
    
    stage33_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Go"), "NanumBarunGothicBold.otf", 28);
    stage33_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage33_->setAnchorPoint(Point(0.5,0.5));
    stage33_->setColor(Color3B::BLACK);
    this->addChild(stage33_,11);
    stage33_->setVisible(false);
    
    stage34_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Mandatory"), "NanumBarunGothicBold.otf", 28);
    stage34_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage34_->setAnchorPoint(Point(0.5,0.5));
    stage34_->setColor(Color3B::BLACK);
    this->addChild(stage34_,11);
    stage34_->setVisible(false);
    
    stage35_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Millitary"), "NanumBarunGothicBold.otf", 28);
    stage35_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage35_->setAnchorPoint(Point(0.5,0.5));
    stage35_->setColor(Color3B::BLACK);
    this->addChild(stage35_,11);
    stage35_->setVisible(false);
    
    stage36_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Service"), "NanumBarunGothicBold.otf", 28);
    stage36_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage36_->setAnchorPoint(Point(0.5,0.5));
    stage36_->setColor(Color3B::BLACK);
    this->addChild(stage36_,11);
    stage36_->setVisible(false);
    
    stage37_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("in Korea"), "NanumBarunGothicBold.otf", 28);
    stage37_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage37_->setAnchorPoint(Point(0.5,0.5));
    stage37_->setColor(Color3B::BLACK);
    this->addChild(stage37_,11);
    stage37_->setVisible(false);
    
    stage38_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("But"), "NanumBarunGothicBold.otf", 28);
    stage38_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage38_->setAnchorPoint(Point(0.5,0.5));
    stage38_->setColor(Color3B::BLACK);
    this->addChild(stage38_,11);
    stage38_->setVisible(false);
    
    stage39_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("I will"), "NanumBarunGothicBold.otf", 28);
    stage39_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage39_->setAnchorPoint(Point(0.5,0.5));
    stage39_->setColor(Color3B::BLACK);
    this->addChild(stage39_,11);
    stage39_->setVisible(false);
    
    stage40_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Make"), "NanumBarunGothicBold.otf", 28);
    stage40_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage40_->setAnchorPoint(Point(0.5,0.5));
    stage40_->setColor(Color3B::BLACK);
    this->addChild(stage40_,11);
    stage40_->setVisible(false);
    
    /////41~50/////
    stage41_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("The"), "NanumBarunGothicBold.otf", 28);
    stage41_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage41_->setAnchorPoint(Point(0.5,0.5));
    stage41_->setColor(Color3B::BLACK);
    this->addChild(stage41_,11);
    stage41_->setVisible(false);
    
    stage42_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("mungGu"), "NanumBarunGothicBold.otf", 28);
    stage42_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage42_->setAnchorPoint(Point(0.5,0.5));
    stage42_->setColor(Color3B::BLACK);
    this->addChild(stage42_,11);
    stage42_->setVisible(false);
    
    stage43_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("In My"), "NanumBarunGothicBold.otf", 28);
    stage43_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage43_->setAnchorPoint(Point(0.5,0.5));
    stage43_->setColor(Color3B::BLACK);
    this->addChild(stage43_,11);
    stage43_->setVisible(false);
    
    stage44_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Army"), "NanumBarunGothicBold.otf", 28);
    stage44_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage44_->setAnchorPoint(Point(0.5,0.5));
    stage44_->setColor(Color3B::BLACK);
    this->addChild(stage44_,11);
    stage44_->setVisible(false);
    
    stage45_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Period"), "NanumBarunGothicBold.otf", 28);
    stage45_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage45_->setAnchorPoint(Point(0.5,0.5));
    stage45_->setColor(Color3B::BLACK);
    this->addChild(stage45_,11);
    stage45_->setVisible(false);
    
    stage46_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Um..."), "NanumBarunGothicBold.otf", 28);
    stage46_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMidY()));
    stage46_->setAnchorPoint(Point(0.5,0.5));
    stage46_->setColor(Color3B::BLACK);
    this->addChild(stage46_,11);
    stage46_->setVisible(false);
    
    stage47_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Anyway,"), "NanumBarunGothicBold.otf", 28);
    stage47_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage2_selectBtnRect.getMidY()));
    stage47_->setAnchorPoint(Point(0.5,0.5));
    stage47_->setColor(Color3B::BLACK);
    this->addChild(stage47_,11);
    stage47_->setVisible(false);
    
    stage48_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("Maybe"), "NanumBarunGothicBold.otf", 28);
    stage48_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage3_selectBtnRect.getMidY()));
    stage48_->setAnchorPoint(Point(0.5,0.5));
    stage48_->setColor(Color3B::BLACK);
    this->addChild(stage48_,11);
    stage48_->setVisible(false);
    
    stage49_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("After.."), "NanumBarunGothicBold.otf", 28);
    stage49_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage4_selectBtnRect.getMidY()));
    stage49_->setAnchorPoint(Point(0.5,0.5));
    stage49_->setColor(Color3B::BLACK);
    this->addChild(stage49_,11);
    stage49_->setVisible(false);
    
    stage50_ = Label::createWithTTF //최고점수 표시할 라벨 선언
    (StringUtils::format("4-month..."), "NanumBarunGothicBold.otf", 28);
    stage50_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage5_selectBtnRect.getMidY()));
    stage50_->setAnchorPoint(Point(0.5,0.5));
    stage50_->setColor(Color3B::BLACK);
    this->addChild(stage50_,11);
    stage50_->setVisible(false);
    
    stage1_selectBtn->setColor(Color3B(255,220,220));
    stage2_selectBtn->setColor(Color3B(255,200,200));
    stage3_selectBtn->setColor(Color3B(255,200,200));
    stage4_selectBtn->setColor(Color3B(255,200,200));
    stage5_selectBtn->setColor(Color3B(255,200,200));
    stage6_selectBtn->setColor(Color3B(255,200,200));
    stage7_selectBtn->setColor(Color3B(255,200,200));
    stage8_selectBtn->setColor(Color3B(255,200,200));
    stage9_selectBtn->setColor(Color3B(255,200,200));
    stage10_selectBtn->setColor(Color3B(255,200,200));
    stage11_selectBtn->setColor(Color3B(255,200,200));
    stage12_selectBtn->setColor(Color3B(255,200,200));
    stage13_selectBtn->setColor(Color3B(255,200,200));
    stage14_selectBtn->setColor(Color3B(255,200,200));
    stage15_selectBtn->setColor(Color3B(255,200,200));
    stage16_selectBtn->setColor(Color3B(255,200,200));
    stage17_selectBtn->setColor(Color3B(255,200,200));
    stage18_selectBtn->setColor(Color3B(255,200,200));
    stage19_selectBtn->setColor(Color3B(255,200,200));
    stage20_selectBtn->setColor(Color3B(255,200,200));
    stage21_selectBtn->setColor(Color3B(255,200,200));
    stage22_selectBtn->setColor(Color3B(255,200,200));
    stage23_selectBtn->setColor(Color3B(255,200,200));
    stage24_selectBtn->setColor(Color3B(255,200,200));
    stage25_selectBtn->setColor(Color3B(255,200,200));
    stage26_selectBtn->setColor(Color3B(255,200,200));
    stage27_selectBtn->setColor(Color3B(255,200,200));
    stage28_selectBtn->setColor(Color3B(255,200,200));
    stage29_selectBtn->setColor(Color3B(255,200,200));
    stage30_selectBtn->setColor(Color3B(255,200,200));
    stage31_selectBtn->setColor(Color3B(255,200,200));
    stage32_selectBtn->setColor(Color3B(255,200,200));
    stage33_selectBtn->setColor(Color3B(255,200,200));
    stage34_selectBtn->setColor(Color3B(255,200,200));
    stage35_selectBtn->setColor(Color3B(255,200,200));
    stage36_selectBtn->setColor(Color3B(255,200,200));
    stage37_selectBtn->setColor(Color3B(255,200,200));
    stage38_selectBtn->setColor(Color3B(255,200,200));
    stage39_selectBtn->setColor(Color3B(255,200,200));
    stage40_selectBtn->setColor(Color3B(255,200,200));
    stage41_selectBtn->setColor(Color3B(255,200,200));
    stage42_selectBtn->setColor(Color3B(255,200,200));
    stage43_selectBtn->setColor(Color3B(255,200,200));
    stage44_selectBtn->setColor(Color3B(255,200,200));
    stage45_selectBtn->setColor(Color3B(255,200,200));
    stage46_selectBtn->setColor(Color3B(255,200,200));
    stage47_selectBtn->setColor(Color3B(255,200,200));
    stage48_selectBtn->setColor(Color3B(255,200,200));
    stage49_selectBtn->setColor(Color3B(255,200,200));
    stage50_selectBtn->setColor(Color3B(255,200,200));
    
    
    
    
    ///clear or loser
    if(stage1_clearCount==0){
        stage1_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage1_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage1_Info->setAnchorPoint(Point(0.5,0.5));
        stage1_Info->setColor(Color3B::RED);
        this->addChild(stage1_Info, 10);
    }else{
        stage1_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage1_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage1_Info->setAnchorPoint(Point(0.5,0.5));
        stage1_Info->setColor(Color3B(20,50,20));
        stage1_Info->setScale(1.1);
        this->addChild(stage1_Info, 10);
        
        stage1_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage6_clearCount==0){
        stage6_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage6_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage6_Info->setAnchorPoint(Point(0.5,0.5));
        stage6_Info->setColor(Color3B::RED);
        this->addChild(stage6_Info, 10);
        stage6_Info->setVisible(false);
    }else{
        stage6_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage6_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage6_Info->setAnchorPoint(Point(0.5,0.5));
        stage6_Info->setColor(Color3B(20,50,20));
        stage6_Info->setScale(1.1);
        this->addChild(stage6_Info, 10);
        stage6_Info->setVisible(false);
        
        stage6_selectBtn->setColor(Color3B(200,255,200));
    }
    
    
    if(stage11_clearCount==0){
        stage11_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage11_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage11_Info->setAnchorPoint(Point(0.5,0.5));
        stage11_Info->setColor(Color3B::RED);
        this->addChild(stage11_Info, 10);
        stage11_Info->setVisible(false);
    }else{
        stage11_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage11_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage11_Info->setAnchorPoint(Point(0.5,0.5));
        stage11_Info->setColor(Color3B(20,50,20));
        stage11_Info->setScale(1.1);
        this->addChild(stage11_Info, 10);
        stage11_Info->setVisible(false);
        
        stage11_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage16_clearCount==0){
        stage16_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage16_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage16_Info->setAnchorPoint(Point(0.5,0.5));
        stage16_Info->setColor(Color3B::RED);
        this->addChild(stage16_Info, 10);
    }else{
        stage16_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage16_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage16_Info->setAnchorPoint(Point(0.5,0.5));
        stage16_Info->setColor(Color3B(20,50,20));
        stage16_Info->setScale(1.1);
        this->addChild(stage16_Info, 10);
        
        stage16_selectBtn->setColor(Color3B(200,255,200));
    }
    stage16_Info->setVisible(false);
    
    if(stage21_clearCount==0){
        stage21_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage21_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage21_Info->setAnchorPoint(Point(0.5,0.5));
        stage21_Info->setColor(Color3B::RED);
        this->addChild(stage21_Info, 10);
    }else{
        stage21_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage21_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage21_Info->setAnchorPoint(Point(0.5,0.5));
        stage21_Info->setColor(Color3B(20,50,20));
        stage21_Info->setScale(1.1);
        this->addChild(stage21_Info, 10);
        
        stage21_selectBtn->setColor(Color3B(200,255,200));
    }
    stage21_Info->setVisible(false);
    
    if(stage26_clearCount==0){
        stage26_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage26_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage26_Info->setAnchorPoint(Point(0.5,0.5));
        stage26_Info->setColor(Color3B::RED);
        this->addChild(stage26_Info, 10);
    }else{
        stage26_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage26_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage26_Info->setAnchorPoint(Point(0.5,0.5));
        stage26_Info->setColor(Color3B(20,50,20));
        stage26_Info->setScale(1.1);
        this->addChild(stage26_Info, 10);
        
        stage26_selectBtn->setColor(Color3B(200,255,200));
    }
    stage26_Info->setVisible(false);
    
    if(stage31_clearCount==0){
        stage31_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage31_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage31_Info->setAnchorPoint(Point(0.5,0.5));
        stage31_Info->setColor(Color3B::RED);
        this->addChild(stage31_Info, 10);
    }else{
        stage31_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage31_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage31_Info->setAnchorPoint(Point(0.5,0.5));
        stage31_Info->setColor(Color3B(20,50,20));
        stage31_Info->setScale(1.1);
        this->addChild(stage31_Info, 10);
        
        stage31_selectBtn->setColor(Color3B(200,255,200));
    }
    stage31_Info->setVisible(false);
    
    if(stage36_clearCount==0){
        stage36_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage36_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage36_Info->setAnchorPoint(Point(0.5,0.5));
        stage36_Info->setColor(Color3B::RED);
        this->addChild(stage36_Info, 10);
        stage36_Info->setVisible(false);
    }else{
        stage36_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage36_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage36_Info->setAnchorPoint(Point(0.5,0.5));
        stage36_Info->setColor(Color3B(20,50,20));
        stage36_Info->setScale(1.1);
        this->addChild(stage36_Info, 10);
        stage36_Info->setVisible(false);
        
        stage36_selectBtn->setColor(Color3B(200,255,200));
    }
    
    
    if(stage41_clearCount==0){
        stage41_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage41_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage41_Info->setAnchorPoint(Point(0.5,0.5));
        stage41_Info->setColor(Color3B::RED);
        this->addChild(stage41_Info, 10);
        stage41_Info->setVisible(false);
    }else{
        stage41_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage41_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
        stage41_Info->setAnchorPoint(Point(0.5,0.5));
        stage41_Info->setColor(Color3B(20,50,20));
        stage41_Info->setScale(1.1);
        this->addChild(stage41_Info, 10);
        stage41_Info->setVisible(false);
        
        stage41_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage46_clearCount==0){
        stage46_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage46_Info->setColor(Color3B::RED);
    }else{
        stage46_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage46_Info->setColor(Color3B(20,50,20));
        stage46_Info->setScale(1.1);
        
        stage46_selectBtn->setColor(Color3B(200,255,200));
        
    }
    stage46_Info->setPosition(Point(stage1_selectBtnRect.getMaxX(),stage1_selectBtnRect.getMinY()));
    stage46_Info->setAnchorPoint(Point(0.5,0.5));
    this->addChild(stage46_Info, 10);
    stage46_Info->setVisible(false);
    
    
    if(stage2_clearCount==0){
        stage2_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage2_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage2_Info->setAnchorPoint(Point(0.5,0.5));
        stage2_Info->setColor(Color3B::RED);
        
        this->addChild(stage2_Info, 10);
    }else{
        stage2_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage2_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage2_Info->setAnchorPoint(Point(0.5,0.5));
        stage2_Info->setColor(Color3B(20,50,20));
        stage2_Info->setScale(1.1);
        this->addChild(stage2_Info, 10);
        
        stage2_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage7_clearCount==0){
        stage7_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage7_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage7_Info->setAnchorPoint(Point(0.5,0.5));
        stage7_Info->setColor(Color3B::RED);
        this->addChild(stage7_Info, 10);
    }else{
        stage7_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage7_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage7_Info->setAnchorPoint(Point(0.5,0.5));
        stage7_Info->setColor(Color3B(20,50,20));
        stage7_Info->setScale(1.1);
        this->addChild(stage7_Info, 10);
        
        stage7_selectBtn->setColor(Color3B(200,255,200));
    }
    stage7_Info->setVisible(false);
    
    if(stage12_clearCount==0){
        stage12_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage12_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage12_Info->setAnchorPoint(Point(0.5,0.5));
        stage12_Info->setColor(Color3B::RED);
        this->addChild(stage12_Info, 10);
    }else{
        stage12_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage12_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage12_Info->setAnchorPoint(Point(0.5,0.5));
        stage12_Info->setColor(Color3B(20,50,20));
        stage12_Info->setScale(1.1);
        this->addChild(stage12_Info, 10);
        
        stage12_selectBtn->setColor(Color3B(200,255,200));
    }
    stage12_Info->setVisible(false);
    
    if(stage17_clearCount==0){
        stage17_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage17_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage17_Info->setAnchorPoint(Point(0.5,0.5));
        stage17_Info->setColor(Color3B::RED);
        this->addChild(stage17_Info, 10);
    }else{
        stage17_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage17_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage17_Info->setAnchorPoint(Point(0.5,0.5));
        stage17_Info->setColor(Color3B(20,50,20));
        stage17_Info->setScale(1.1);
        this->addChild(stage17_Info, 10);
        
        stage17_selectBtn->setColor(Color3B(200,255,200));
    }
    stage17_Info->setVisible(false);
    
    if(stage22_clearCount==0){
        stage22_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage22_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage22_Info->setAnchorPoint(Point(0.5,0.5));
        stage22_Info->setColor(Color3B::RED);
        
        this->addChild(stage22_Info, 10);
    }else{
        stage22_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage22_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage22_Info->setAnchorPoint(Point(0.5,0.5));
        stage22_Info->setColor(Color3B(20,50,20));
        stage22_Info->setScale(1.1);
        this->addChild(stage22_Info, 10);
        
        stage22_selectBtn->setColor(Color3B(200,255,200));
        
    }stage22_Info->setVisible(false);
    
    if(stage27_clearCount==0){
        stage27_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage27_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage27_Info->setAnchorPoint(Point(0.5,0.5));
        stage27_Info->setColor(Color3B::RED);
        this->addChild(stage27_Info, 10);
    }else{
        stage27_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage27_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage27_Info->setAnchorPoint(Point(0.5,0.5));
        stage27_Info->setColor(Color3B(20,50,20));
        stage27_Info->setScale(1.1);
        this->addChild(stage27_Info, 10);
        
        stage27_selectBtn->setColor(Color3B(200,255,200));
    }
    stage27_Info->setVisible(false);
    
    if(stage32_clearCount==0){
        stage32_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage32_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage32_Info->setAnchorPoint(Point(0.5,0.5));
        stage32_Info->setColor(Color3B::RED);
        this->addChild(stage32_Info, 10);
    }else{
        stage32_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage32_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage32_Info->setAnchorPoint(Point(0.5,0.5));
        stage32_Info->setColor(Color3B(20,50,20));
        stage32_Info->setScale(1.1);
        this->addChild(stage32_Info, 10);
        
        stage32_selectBtn->setColor(Color3B(200,255,200));
    }
    stage32_Info->setVisible(false);
    
    if(stage37_clearCount==0){
        stage37_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage37_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage37_Info->setAnchorPoint(Point(0.5,0.5));
        stage37_Info->setColor(Color3B::RED);
        this->addChild(stage37_Info, 10);
    }else{
        stage37_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage37_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage37_Info->setAnchorPoint(Point(0.5,0.5));
        stage37_Info->setColor(Color3B(20,50,20));
        stage37_Info->setScale(1.1);
        this->addChild(stage37_Info, 10);
        
        stage37_selectBtn->setColor(Color3B(200,255,200));
    }
    stage37_Info->setVisible(false);
    
    if(stage42_clearCount==0){
        stage42_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage42_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage42_Info->setAnchorPoint(Point(0.5,0.5));
        stage42_Info->setColor(Color3B::RED);
        this->addChild(stage42_Info, 10);
    }else{
        stage42_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage42_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage42_Info->setAnchorPoint(Point(0.5,0.5));
        stage42_Info->setColor(Color3B(20,50,20));
        stage42_Info->setScale(1.1);
        this->addChild(stage42_Info, 10);
        
        stage42_selectBtn->setColor(Color3B(200,255,200));
    }
    stage42_Info->setVisible(false);
    
    if(stage47_clearCount==0){
        stage47_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage47_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage47_Info->setAnchorPoint(Point(0.5,0.5));
        stage47_Info->setColor(Color3B::RED);
        this->addChild(stage47_Info, 10);
    }else{
        stage47_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage47_Info->setPosition(Point(stage2_selectBtnRect.getMaxX(),stage2_selectBtnRect.getMinY()));
        stage47_Info->setAnchorPoint(Point(0.5,0.5));
        stage47_Info->setColor(Color3B(20,50,20));
        stage47_Info->setScale(1.1);
        this->addChild(stage47_Info, 10);
        
        stage47_selectBtn->setColor(Color3B(200,255,200));
    }
    stage47_Info->setVisible(false);
    
    if(stage3_clearCount==0){
        stage3_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage3_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage3_Info->setAnchorPoint(Point(0.5,0.5));
        stage3_Info->setColor(Color3B::RED);
        
        this->addChild(stage3_Info, 10);
    }else{
        stage3_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage3_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage3_Info->setAnchorPoint(Point(0.5,0.5));
        stage3_Info->setColor(Color3B(20,50,20));
        stage3_Info->setScale(1.1);
        this->addChild(stage3_Info, 10);
        
        stage3_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage8_clearCount==0){
        stage8_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage8_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage8_Info->setAnchorPoint(Point(0.5,0.5));
        stage8_Info->setColor(Color3B::RED);
        
        this->addChild(stage8_Info, 10);
    }else{
        stage8_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage8_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage8_Info->setAnchorPoint(Point(0.5,0.5));
        stage8_Info->setColor(Color3B(20,50,20));
        stage8_Info->setScale(1.1);
        this->addChild(stage8_Info, 10);
        
        stage8_selectBtn->setColor(Color3B(200,255,200));
    }
    stage8_Info->setVisible(false);
    
    if(stage13_clearCount==0){
        stage13_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage13_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage13_Info->setAnchorPoint(Point(0.5,0.5));
        stage13_Info->setColor(Color3B::RED);
        
        this->addChild(stage13_Info, 10);
    }else{
        stage13_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage13_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage13_Info->setAnchorPoint(Point(0.5,0.5));
        stage13_Info->setColor(Color3B(20,50,20));
        stage13_Info->setScale(1.1);
        this->addChild(stage13_Info, 10);
        
        stage13_selectBtn->setColor(Color3B(200,255,200));
    }
    stage13_Info->setVisible(false);
    
    if(stage18_clearCount==0){
        stage18_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage18_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage18_Info->setAnchorPoint(Point(0.5,0.5));
        stage18_Info->setColor(Color3B::RED);
        
        this->addChild(stage18_Info, 10);
    }else{
        stage18_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage18_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage18_Info->setAnchorPoint(Point(0.5,0.5));
        stage18_Info->setColor(Color3B(20,50,20));
        stage18_Info->setScale(1.1);
        this->addChild(stage18_Info, 10);
        
        stage18_selectBtn->setColor(Color3B(200,255,200));
    }
    stage18_Info->setVisible(false);
    
    if(stage23_clearCount==0){
        stage23_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage23_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage23_Info->setAnchorPoint(Point(0.5,0.5));
        stage23_Info->setColor(Color3B::RED);
        
        this->addChild(stage23_Info, 10);
    }else{
        stage23_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage23_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage23_Info->setAnchorPoint(Point(0.5,0.5));
        stage23_Info->setColor(Color3B(20,50,20));
        stage23_Info->setScale(1.1);
        this->addChild(stage23_Info, 10);
        
        stage23_selectBtn->setColor(Color3B(200,255,200));
    }
    stage23_Info->setVisible(false);
    
    if(stage28_clearCount==0){
        stage28_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage28_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage28_Info->setAnchorPoint(Point(0.5,0.5));
        stage28_Info->setColor(Color3B::RED);
        
        this->addChild(stage28_Info, 10);
    }else{
        stage28_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage28_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage28_Info->setAnchorPoint(Point(0.5,0.5));
        stage28_Info->setColor(Color3B(20,50,20));
        stage28_Info->setScale(1.1);
        this->addChild(stage28_Info, 10);
        
        stage28_selectBtn->setColor(Color3B(200,255,200));
    }
    stage28_Info->setVisible(false);

    if(stage33_clearCount==0){
        stage33_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage33_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage33_Info->setAnchorPoint(Point(0.5,0.5));
        stage33_Info->setColor(Color3B::RED);
        
        this->addChild(stage33_Info, 10);
    }else{
        stage33_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage33_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage33_Info->setAnchorPoint(Point(0.5,0.5));
        stage33_Info->setColor(Color3B(20,50,20));
        stage33_Info->setScale(1.1);
        this->addChild(stage33_Info, 10);
        
        stage33_selectBtn->setColor(Color3B(200,255,200));
    }
    stage33_Info->setVisible(false);
    
    if(stage38_clearCount==0){
        stage38_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage38_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage38_Info->setAnchorPoint(Point(0.5,0.5));
        stage38_Info->setColor(Color3B::RED);
        
        this->addChild(stage38_Info, 10);
    }else{
        stage38_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage38_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage38_Info->setAnchorPoint(Point(0.5,0.5));
        stage38_Info->setColor(Color3B(20,50,20));
        stage38_Info->setScale(1.1);
        this->addChild(stage38_Info, 10);
        
        stage38_selectBtn->setColor(Color3B(200,255,200));
    }
    stage38_Info->setVisible(false);
    
    if(stage43_clearCount==0){
        stage43_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage43_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage43_Info->setAnchorPoint(Point(0.5,0.5));
        stage43_Info->setColor(Color3B::RED);
        
        this->addChild(stage43_Info, 10);
    }else{
        stage43_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage43_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage43_Info->setAnchorPoint(Point(0.5,0.5));
        stage43_Info->setColor(Color3B(20,50,20));
        stage43_Info->setScale(1.1);
        this->addChild(stage43_Info, 10);
        
        stage43_selectBtn->setColor(Color3B(200,255,200));
    }
    stage43_Info->setVisible(false);
    
    if(stage48_clearCount==0){
        stage48_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage48_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage48_Info->setAnchorPoint(Point(0.5,0.5));
        stage48_Info->setColor(Color3B::RED);
        
        this->addChild(stage48_Info, 10);
    }else{
        stage48_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage48_Info->setPosition(Point(stage3_selectBtnRect.getMaxX(),stage3_selectBtnRect.getMinY()));
        stage48_Info->setAnchorPoint(Point(0.5,0.5));
        stage48_Info->setColor(Color3B(20,50,20));
        stage48_Info->setScale(1.1);
        this->addChild(stage48_Info, 10);
        
        stage48_selectBtn->setColor(Color3B(200,255,200));
    }
    stage48_Info->setVisible(false);
    
    
    
    if(stage4_clearCount==0){
        stage4_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage4_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage4_Info->setAnchorPoint(Point(0.5,0.5));
        stage4_Info->setColor(Color3B::RED);
        
        this->addChild(stage4_Info, 10);
    }else{
        stage4_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage4_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage4_Info->setAnchorPoint(Point(0.5,0.5));
        stage4_Info->setColor(Color3B(20,50,20));
        stage4_Info->setScale(1.1);
        this->addChild(stage4_Info, 10);
        
        stage4_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage9_clearCount==0){
        stage9_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage9_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage9_Info->setAnchorPoint(Point(0.5,0.5));
        stage9_Info->setColor(Color3B::RED);
        
        this->addChild(stage9_Info, 10);
    }else{
        stage9_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage9_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage9_Info->setAnchorPoint(Point(0.5,0.5));
        stage9_Info->setColor(Color3B(20,50,20));
        stage9_Info->setScale(1.1);
        this->addChild(stage9_Info, 10);
        
        stage9_selectBtn->setColor(Color3B(200,255,200));
    }
    stage9_Info->setVisible(false);
    
    if(stage14_clearCount==0){
        stage14_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage14_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage14_Info->setAnchorPoint(Point(0.5,0.5));
        stage14_Info->setColor(Color3B::RED);
        
        this->addChild(stage14_Info, 10);
    }else{
        stage14_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage14_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage14_Info->setAnchorPoint(Point(0.5,0.5));
        stage14_Info->setColor(Color3B(20,50,20));
        stage14_Info->setScale(1.1);
        this->addChild(stage14_Info, 10);
        
        stage14_selectBtn->setColor(Color3B(200,255,200));
    }
    stage14_Info->setVisible(false);
    
    if(stage19_clearCount==0){
        stage19_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage19_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage19_Info->setAnchorPoint(Point(0.5,0.5));
        stage19_Info->setColor(Color3B::RED);
        
        this->addChild(stage19_Info, 10);
    }else{
        stage19_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage19_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage19_Info->setAnchorPoint(Point(0.5,0.5));
        stage19_Info->setColor(Color3B(20,50,20));
        stage19_Info->setScale(1.1);
        this->addChild(stage19_Info, 10);
        
        stage19_selectBtn->setColor(Color3B(200,255,200));
    }
    stage19_Info->setVisible(false);
    
    if(stage24_clearCount==0){
        stage24_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage24_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage24_Info->setAnchorPoint(Point(0.5,0.5));
        stage24_Info->setColor(Color3B::RED);
        
        this->addChild(stage24_Info, 10);
    }else{
        stage24_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage24_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage24_Info->setAnchorPoint(Point(0.5,0.5));
        stage24_Info->setColor(Color3B(20,50,20));
        stage24_Info->setScale(1.1);
        this->addChild(stage24_Info, 10);
        
        stage24_selectBtn->setColor(Color3B(200,255,200));
    }
    stage24_Info->setVisible(false);
    
    if(stage29_clearCount==0){
        stage29_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage29_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage29_Info->setAnchorPoint(Point(0.5,0.5));
        stage29_Info->setColor(Color3B::RED);
        
        this->addChild(stage29_Info, 10);
    }else{
        stage29_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage29_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage29_Info->setAnchorPoint(Point(0.5,0.5));
        stage29_Info->setColor(Color3B(20,50,20));
        stage29_Info->setScale(1.1);
        this->addChild(stage29_Info, 10);
        
        stage29_selectBtn->setColor(Color3B(200,255,200));
    }
    stage29_Info->setVisible(false);
    
    if(stage34_clearCount==0){
        stage34_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage34_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage34_Info->setAnchorPoint(Point(0.5,0.5));
        stage34_Info->setColor(Color3B::RED);
        
        this->addChild(stage34_Info, 10);
    }else{
        stage34_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage34_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage34_Info->setAnchorPoint(Point(0.5,0.5));
        stage34_Info->setColor(Color3B(20,50,20));
        stage34_Info->setScale(1.1);
        this->addChild(stage34_Info, 10);
        
        stage34_selectBtn->setColor(Color3B(200,255,200));
    }
    stage34_Info->setVisible(false);
    
    if(stage39_clearCount==0){
        stage39_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage39_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage39_Info->setAnchorPoint(Point(0.5,0.5));
        stage39_Info->setColor(Color3B::RED);
        
        this->addChild(stage39_Info, 10);
    }else{
        stage39_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage39_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage39_Info->setAnchorPoint(Point(0.5,0.5));
        stage39_Info->setColor(Color3B(20,50,20));
        stage39_Info->setScale(1.1);
        this->addChild(stage39_Info, 10);
        
        stage39_selectBtn->setColor(Color3B(200,255,200));
    }
    stage39_Info->setVisible(false);
    
    if(stage44_clearCount==0){
        stage44_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage44_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage44_Info->setAnchorPoint(Point(0.5,0.5));
        stage44_Info->setColor(Color3B::RED);
        
        this->addChild(stage44_Info, 10);
    }else{
        stage44_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage44_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage44_Info->setAnchorPoint(Point(0.5,0.5));
        stage44_Info->setColor(Color3B(20,50,20));
        stage44_Info->setScale(1.1);
        this->addChild(stage44_Info, 10);
        
        stage44_selectBtn->setColor(Color3B(200,255,200));
    }
    stage44_Info->setVisible(false);
    
    if(stage49_clearCount==0){
        stage49_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage49_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage49_Info->setAnchorPoint(Point(0.5,0.5));
        stage49_Info->setColor(Color3B::RED);
        
        this->addChild(stage49_Info, 10);
    }else{
        stage49_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage49_Info->setPosition(Point(stage4_selectBtnRect.getMaxX(),stage4_selectBtnRect.getMinY()));
        stage49_Info->setAnchorPoint(Point(0.5,0.5));
        stage49_Info->setColor(Color3B(20,50,20));
        stage49_Info->setScale(1.1);
        this->addChild(stage49_Info, 10);
        
        stage49_selectBtn->setColor(Color3B(200,255,200));
    }
    stage49_Info->setVisible(false);
    
    if(stage5_clearCount==0){
        stage5_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage5_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage5_Info->setAnchorPoint(Point(0.5,0.5));
        stage5_Info->setColor(Color3B::RED);
        
        this->addChild(stage5_Info, 10);
    }else{
        stage5_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage5_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage5_Info->setAnchorPoint(Point(0.5,0.5));
        stage5_Info->setColor(Color3B(20,50,20));
        stage5_Info->setScale(1.1);
        this->addChild(stage5_Info, 10);
        
        stage5_selectBtn->setColor(Color3B(200,255,200));
    }
    
    if(stage10_clearCount==0){
        stage10_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage10_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage10_Info->setAnchorPoint(Point(0.5,0.5));
        stage10_Info->setColor(Color3B::RED);
        
        this->addChild(stage10_Info, 10);
    }else{
        stage10_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage10_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage10_Info->setAnchorPoint(Point(0.5,0.5));
        stage10_Info->setColor(Color3B(20,50,20));
        stage10_Info->setScale(1.1);
        this->addChild(stage10_Info, 10);
        
        stage10_selectBtn->setColor(Color3B(200,255,200));
    }
    stage10_Info->setVisible(false);
    
    if(stage15_clearCount==0){
        stage15_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage15_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage15_Info->setAnchorPoint(Point(0.5,0.5));
        stage15_Info->setColor(Color3B::RED);
        
        this->addChild(stage15_Info, 10);
    }else{
        stage15_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage15_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage15_Info->setAnchorPoint(Point(0.5,0.5));
        stage15_Info->setColor(Color3B(20,50,20));
        stage15_Info->setScale(1.1);
        this->addChild(stage15_Info, 10);
        
        stage15_selectBtn->setColor(Color3B(200,255,200));
    }
    stage15_Info->setVisible(false);
    
    if(stage20_clearCount==0){
        stage20_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage20_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage20_Info->setAnchorPoint(Point(0.5,0.5));
        stage20_Info->setColor(Color3B::RED);
        
        bool isStage20_played = UserDefault::getInstance()->getBoolForKey("isStage20_played",false);
        if(isStage20_played==true){
            stage20_Info->setString("Clare");
            stage20_Info->setColor(Color3B(15,40,10));
        }
        
        this->addChild(stage20_Info, 10);
    }else{
        stage20_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage20_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage20_Info->setAnchorPoint(Point(0.5,0.5));
        stage20_Info->setColor(Color3B(20,50,20));
        stage20_Info->setScale(1.1);
        this->addChild(stage20_Info, 10);
        
        stage20_selectBtn->setColor(Color3B(200,255,200));
    }
    stage20_Info->setVisible(false);
    
    if(stage25_clearCount==0){
        stage25_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage25_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage25_Info->setAnchorPoint(Point(0.5,0.5));
        stage25_Info->setColor(Color3B::RED);
        
        this->addChild(stage25_Info, 10);
    }else{
        stage25_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage25_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage25_Info->setAnchorPoint(Point(0.5,0.5));
        stage25_Info->setColor(Color3B(20,50,20));
        stage25_Info->setScale(1.1);
        this->addChild(stage25_Info, 10);
        
        stage25_selectBtn->setColor(Color3B(200,255,200));
    }
    stage25_Info->setVisible(false);
    
    if(stage30_clearCount==0){
        stage30_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage30_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage30_Info->setAnchorPoint(Point(0.5,0.5));
        stage30_Info->setColor(Color3B::RED);
        
        this->addChild(stage30_Info, 10);
    }else{
        stage30_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage30_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage30_Info->setAnchorPoint(Point(0.5,0.5));
        stage30_Info->setColor(Color3B(20,50,20));
        stage30_Info->setScale(1.1);
        this->addChild(stage30_Info, 10);
        
        stage30_selectBtn->setColor(Color3B(200,255,200));
    }
    stage30_Info->setVisible(false);
    
    if(stage35_clearCount==0){
        stage35_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage35_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage35_Info->setAnchorPoint(Point(0.5,0.5));
        stage35_Info->setColor(Color3B::RED);
        
        this->addChild(stage35_Info, 10);
    }else{
        stage35_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage35_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage35_Info->setAnchorPoint(Point(0.5,0.5));
        stage35_Info->setColor(Color3B(20,50,20));
        stage35_Info->setScale(1.1);
        this->addChild(stage35_Info, 10);
        
        stage35_selectBtn->setColor(Color3B(200,255,200));
    }
    stage35_Info->setVisible(false);
    
    if(stage40_clearCount==0){
        stage40_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage40_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage40_Info->setAnchorPoint(Point(0.5,0.5));
        stage40_Info->setColor(Color3B::RED);
        this->addChild(stage40_Info, 10);
    }else{
        stage40_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage40_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage40_Info->setAnchorPoint(Point(0.5,0.5));
        stage40_Info->setColor(Color3B(20,50,20));
        stage40_Info->setScale(1.1);
        this->addChild(stage40_Info, 10);
        
        stage40_selectBtn->setColor(Color3B(200,255,200));
    }
    stage40_Info->setVisible(false);
    
    if(stage45_clearCount==0){
        stage45_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage45_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage45_Info->setAnchorPoint(Point(0.5,0.5));
        stage45_Info->setColor(Color3B::RED);
        
        this->addChild(stage45_Info, 10);
    }else{
        stage45_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage45_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage45_Info->setAnchorPoint(Point(0.5,0.5));
        stage45_Info->setColor(Color3B(20,50,20));
        stage45_Info->setScale(1.1);
        this->addChild(stage45_Info, 10);
        
        stage45_selectBtn->setColor(Color3B(200,255,200));
    }
    stage45_Info->setVisible(false);
    
    if(stage50_clearCount==0){
        stage50_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Loser"), "NanumBarunGothicBold.otf", 23);
        stage50_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage50_Info->setAnchorPoint(Point(0.5,0.5));
        stage50_Info->setColor(Color3B::RED);
        
        this->addChild(stage50_Info, 10);
    }else{
        stage50_Info = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("Clear"), "NanumBarunGothicBold.otf", 23);
        stage50_Info->setPosition(Point(stage5_selectBtnRect.getMaxX(),stage5_selectBtnRect.getMinY()));
        stage50_Info->setAnchorPoint(Point(0.5,0.5));
        stage50_Info->setColor(Color3B(20,50,20));
        stage50_Info->setScale(1.1);
        this->addChild(stage50_Info, 10);
        
        stage50_selectBtn->setColor(Color3B(200,255,200));
    }
    stage50_Info->setVisible(false);
    
    
    /////   스테이지 버튼 이동 버튼  /////
    upperReplaceBtn = Sprite::create("replaceBtn.png");
    upperReplaceBtn->setAnchorPoint(Point(0.5,0));
    upperReplaceBtn->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMaxY()+3));
    upperReplaceBtn_ = Sprite::create("replaceBtn_.png");
    upperReplaceBtn_->setAnchorPoint(Point(0.5,0));
    upperReplaceBtn_->setPosition(Point(stage1_selectBtnRect.getMidX(),stage1_selectBtnRect.getMaxY()+3));
    bottomReplaceBtn = Sprite::create("replaceBtn.png");
    bottomReplaceBtn->setAnchorPoint(Point(0.5,1));
    bottomReplaceBtn->setPosition(Point(stage5_selectBtnRect.getMidX(),stage5_selectBtnRect.getMinY()-3));
    bottomReplaceBtn->setFlippedY(true);
    bottomReplaceBtn_ = Sprite::create("replaceBtn_.png");
    bottomReplaceBtn_->setAnchorPoint(Point(0.5,1));
    bottomReplaceBtn_->setPosition(Point(stage5_selectBtnRect.getMidX(),stage5_selectBtnRect.getMinY()-3));
    bottomReplaceBtn_->setFlippedY(true);
    upperReplaceBtn->setVisible(false);
    bottomReplaceBtn_->setVisible(false);
    bottomReplaceBtn_->setScale(0.9);
    bottomReplaceBtn->setScale(0.9);
    upperReplaceBtn->setScale(0.9);
    upperReplaceBtn_->setScale(0.9);
    bottomReplaceBtn_->setScale(0.9);
    
    bottomReplaceBtn->setOpacity(230);
    upperReplaceBtn->setOpacity(230);
    bottomReplaceBtn_->setOpacity(130);
    upperReplaceBtn_->setOpacity(130);
    this->addChild(upperReplaceBtn,30);
    this->addChild(bottomReplaceBtn,30);
    this->addChild(upperReplaceBtn_,30);
    this->addChild(bottomReplaceBtn_,30);
    
    ///스테이지 생성 알고리즘
    ///1///
    stage1_selectBtn->setVisible(true);
    revangeStart->setVisible(true);
    stage1_Info->setVisible(true);
    
    if(stage1_clearCount==0){
        stage2_selectBtn->setVisible(false);
        stage2_keepGoing->setVisible(false);
        stage2_Info->setVisible(false);
    }else{
        stage2_selectBtn->setVisible(true);
        stage2_keepGoing->setVisible(true);
        stage2_Info->setVisible(true);
    }
    ///2///
    if(stage2_clearCount==0){
        stage3_3rd->setVisible(false);
        stage3_Info->setVisible(false);
        stage3_selectBtn->setVisible(false);
    }else{
        stage3_3rd->setVisible(true);
        stage3_Info->setVisible(true);
        stage3_selectBtn->setVisible(true);
    }
    ///3///
    stageIndexMax=0;
    if(stage3_clearCount==0){
        stage4_Info->setVisible(false);
        stage4_NeverDie->setVisible(false);
        stage4_selectBtn->setVisible(false);
    }else{
        stage4_Info->setVisible(true);
        stage4_NeverDie->setVisible(true);
        stage4_selectBtn->setVisible(true);
    }///4///
    if(stage4_clearCount==0){
        stage5_->setVisible(false);
        stage5_Info->setVisible(false);
        stage5_selectBtn->setVisible(false);
    }else{
        stage5_->setVisible(true);
        stage5_Info->setVisible(true);
        stage5_selectBtn->setVisible(true);
    }
    //    ///5///
    if(stage5_clearCount==0){
        stage6_->setVisible(false);
        stage6_Info->setVisible(false);
        stage6_selectBtn->setVisible(false);
    }else{
        stageIndexMax=1;//6~10으로 이동 가능
    }
    //    ///6///
    if(stage6_clearCount==0){
        stage7_->setVisible(false);
        stage7_Info->setVisible(false);
        stage7_selectBtn->setVisible(false);
    }else{

    }
    //    ///7///
    if(stage7_clearCount==0){
        stage8_->setVisible(false);
        stage8_Info->setVisible(false);
        stage8_selectBtn->setVisible(false);
    }else{

    }
    //    ///8///
    if(stage8_clearCount==0){
        stage9_->setVisible(false);
        stage9_Info->setVisible(false);
        stage9_selectBtn->setVisible(false);
    }else{

    }
    //    ///9///
    if(stage9_clearCount==0){
        stage10_->setVisible(false);
        stage10_Info->setVisible(false);
        stage10_selectBtn->setVisible(false);
    }else{

    }
    //    ///10///
    if(stage10_clearCount==0){
        stage11_->setVisible(false);
        stage11_Info->setVisible(false);
        stage11_selectBtn->setVisible(false);
    }else{
        stageIndexMax=2;
    }
    //    ///11///
    if(stage11_clearCount==0){
        stage12_->setVisible(false);
        stage12_Info->setVisible(false);
        stage12_selectBtn->setVisible(false);
    }else{

    }
    //    ///12///
    if(stage12_clearCount==0){
        stage13_->setVisible(false);
        stage13_Info->setVisible(false);
        stage13_selectBtn->setVisible(false);
    }else{

    }
    //    ///13///
    if(stage13_clearCount==0){
        stage14_->setVisible(false);
        stage14_Info->setVisible(false);
        stage14_selectBtn->setVisible(false);
    }else{

    }
    ///14///
    ///13///
    if(stage14_clearCount==0){
        stage15_->setVisible(false);
        stage15_Info->setVisible(false);
        stage15_selectBtn->setVisible(false);
    }else{

    }
    
    //    ///15///
    if(stage15_clearCount==0){

    }else{
        stageIndexMax=3;//16~20이동 가능
    }
    
    ///16///
    if(stage16_clearCount==0){
        stage17_->setVisible(false);
        stage17_Info->setVisible(false);
        stage17_selectBtn->setVisible(false);
    }else{

    }
    
    ///17///
    if(stage17_clearCount==0){
        stage18_->setVisible(false);
        stage18_Info->setVisible(false);
        stage18_selectBtn->setVisible(false);
    }else{

    }
    
    ///18///
    if(stage18_clearCount==0){
        stage19_->setVisible(false);
        stage19_Info->setVisible(false);
        stage19_selectBtn->setVisible(false);
    }else{

    }
    
    ///19///
    if(stage19_clearCount==0){
        stage20_->setVisible(false);
        stage20_Info->setVisible(false);
        stage20_selectBtn->setVisible(false);
    }else{

    }
    
    //    ///20///
    if(stage20_clearCount==0){
        //        stage21_->setVisible(false);
        //        stage21_Info->setVisible(false);
        //        stage21_selectBtn->setVisible(false);
    }else{
        stageIndexMax=4;//16~20이동 가능
    }
    
    
    ///21///
    if(stage21_clearCount==0){
        stage22_->setVisible(false);
        stage22_Info->setVisible(false);
        stage22_selectBtn->setVisible(false);
    }else{

    }
    
    ///22///
    if(stage22_clearCount==0){
        stage23_->setVisible(false);
        stage23_Info->setVisible(false);
        stage23_selectBtn->setVisible(false);
    }else{

    }
    
    ///23///
    if(stage23_clearCount==0){
        stage24_->setVisible(false);
        stage24_Info->setVisible(false);
        stage24_selectBtn->setVisible(false);
    }else{

    }
    
    ///24///
    if(stage24_clearCount==0){
        stage25_->setVisible(false);
        stage25_Info->setVisible(false);
        stage25_selectBtn->setVisible(false);
    }else{

    }
    
    //    ///25///
    if(stage25_clearCount==0){
        //        stage26_->setVisible(false);
        //        stage26_Info->setVisible(false);
        //        stage26_selectBtn->setVisible(false);
    }else{
        stageIndexMax=5;//21~25이동 가능
    }
    
    ///26///
    if(stage26_clearCount==0){
        stage27_->setVisible(false);
        stage27_Info->setVisible(false);
        stage27_selectBtn->setVisible(false);
    }else{

    }
    
    ///27///
    if(stage27_clearCount==0){
        stage28_->setVisible(false);
        stage28_Info->setVisible(false);
        stage28_selectBtn->setVisible(false);
    }else{

    }
    
    ///28///
    if(stage28_clearCount==0){
        stage29_->setVisible(false);
        stage29_Info->setVisible(false);
        stage29_selectBtn->setVisible(false);
    }else{

    }
    
    ///29///
    if(stage29_clearCount==0){
        stage30_->setVisible(false);
        stage30_Info->setVisible(false);
        stage30_selectBtn->setVisible(false);
    }else{

    }
    //setStage 끝
    
    if(stage30_clearCount==0){

    }else{
        stageIndexMax=6;//31~35이동 가.
    }
    
    if(stage31_clearCount==0){
        stage32_->setVisible(false);
        stage32_Info->setVisible(false);
        stage32_selectBtn->setVisible(false);
    }
    
    if(stage32_clearCount==0){
        stage33_->setVisible(false);
        stage33_Info->setVisible(false);
        stage33_selectBtn->setVisible(false);
    }
    
    if(stage33_clearCount==0){
        stage34_->setVisible(false);
        stage34_Info->setVisible(false);
        stage34_selectBtn->setVisible(false);
    }
    
    if(stage34_clearCount==0){
        stage35_->setVisible(false);
        stage35_Info->setVisible(false);
        stage35_selectBtn->setVisible(false);
    }
    
    if(stage35_clearCount==0){
        
    }else{
        stageIndexMax=7;//
    }
    
    if(stage36_clearCount==0){
        stage37_->setVisible(false);
        stage37_Info->setVisible(false);
        stage37_selectBtn->setVisible(false);
    }
    
    if(stage37_clearCount==0){
        stage38_->setVisible(false);
        stage38_Info->setVisible(false);
        stage38_selectBtn->setVisible(false);
    }
    
    if(stage38_clearCount==0){
        stage39_->setVisible(false);
        stage39_Info->setVisible(false);
        stage39_selectBtn->setVisible(false);
    }
    
    if(stage39_clearCount==0){
        stage40_->setVisible(false);
        stage40_Info->setVisible(false);
        stage40_selectBtn->setVisible(false);
    }
    
    ///41~50
    if(stage40_clearCount==0){
        
    }else{
        stageIndexMax=8;//31~35이동 가.
    }
    
    if(stage41_clearCount==0){
        stage42_->setVisible(false);
        stage42_Info->setVisible(false);
        stage42_selectBtn->setVisible(false);
    }
    
    if(stage42_clearCount==0){
        stage43_->setVisible(false);
        stage43_Info->setVisible(false);
        stage43_selectBtn->setVisible(false);
    }
    
    if(stage43_clearCount==0){
        stage44_->setVisible(false);
        stage44_Info->setVisible(false);
        stage44_selectBtn->setVisible(false);
    }
    
    if(stage44_clearCount==0){
        stage45_->setVisible(false);
        stage45_Info->setVisible(false);
        stage45_selectBtn->setVisible(false);
    }
    
    if(stage45_clearCount==0){
        
    }else{
        stageIndexMax=9;//31~35이동 가.
    }
    
    if(stage46_clearCount==0){
        stage47_->setVisible(false);
        stage47_Info->setVisible(false);
        stage47_selectBtn->setVisible(false);
    }
    
    if(stage47_clearCount==0){
        stage48_->setVisible(false);
        stage48_Info->setVisible(false);
        stage48_selectBtn->setVisible(false);
    }
    
    if(stage48_clearCount==0){
        stage49_->setVisible(false);
        stage49_Info->setVisible(false);
        stage49_selectBtn->setVisible(false);
    }
    
    if(stage49_clearCount==0){
        stage50_->setVisible(false);
        stage50_Info->setVisible(false);
        stage50_selectBtn->setVisible(false);
    }
    
    
    
}
void MungGuGameMenuScene::setStageSelectBtns(){
    
    if(initByEnglish==true){
        stage_label->setString(StringUtils::format("Select the stage!"));
    }else{
        stage_label->setString(StringUtils::format("스테이지를 선택하세요!"));
        
    }

    UserDefault::getInstance()->setBoolForKey("isStage1", false);
    UserDefault::getInstance()->setBoolForKey("isStage2", false);
    UserDefault::getInstance()->setBoolForKey("isStage3", false);
    UserDefault::getInstance()->setBoolForKey("isStage4", false);
    UserDefault::getInstance()->setBoolForKey("isStage5", false);
    UserDefault::getInstance()->setBoolForKey("isStage6", false);
    UserDefault::getInstance()->setBoolForKey("isStage7", false);
    UserDefault::getInstance()->setBoolForKey("isStage8", false);
    UserDefault::getInstance()->setBoolForKey("isStage9", false);
    UserDefault::getInstance()->setBoolForKey("isStage10", false);
    UserDefault::getInstance()->setBoolForKey("isStage11", false);
    UserDefault::getInstance()->setBoolForKey("isStage12", false);
    UserDefault::getInstance()->setBoolForKey("isStage13", false);
    UserDefault::getInstance()->setBoolForKey("isStage14", false);
    UserDefault::getInstance()->setBoolForKey("isStage15", false);
    UserDefault::getInstance()->setBoolForKey("isStage16", false);
    UserDefault::getInstance()->setBoolForKey("isStage17", false);
    UserDefault::getInstance()->setBoolForKey("isStage18", false);
    UserDefault::getInstance()->setBoolForKey("isStage19", false);
    UserDefault::getInstance()->setBoolForKey("isStage20", false);
    UserDefault::getInstance()->setBoolForKey("isStage21", false);
    UserDefault::getInstance()->setBoolForKey("isStage22", false);
    UserDefault::getInstance()->setBoolForKey("isStage23", false);
    UserDefault::getInstance()->setBoolForKey("isStage24", false);
    UserDefault::getInstance()->setBoolForKey("isStage25", false);
    UserDefault::getInstance()->setBoolForKey("isStage26", false);
    UserDefault::getInstance()->setBoolForKey("isStage27", false);
    UserDefault::getInstance()->setBoolForKey("isStage28", false);
    UserDefault::getInstance()->setBoolForKey("isStage29", false);
    UserDefault::getInstance()->setBoolForKey("isStage30", false);
    UserDefault::getInstance()->setBoolForKey("isStage31", false);
    UserDefault::getInstance()->setBoolForKey("isStage32", false);
    UserDefault::getInstance()->setBoolForKey("isStage33", false);
    UserDefault::getInstance()->setBoolForKey("isStage34", false);
    UserDefault::getInstance()->setBoolForKey("isStage35", false);
    UserDefault::getInstance()->setBoolForKey("isStage36", false);
    UserDefault::getInstance()->setBoolForKey("isStage37", false);
    UserDefault::getInstance()->setBoolForKey("isStage38", false);
    UserDefault::getInstance()->setBoolForKey("isStage39", false);
    UserDefault::getInstance()->setBoolForKey("isStage40", false);
    UserDefault::getInstance()->setBoolForKey("isStage41", false);
    UserDefault::getInstance()->setBoolForKey("isStage42", false);
    UserDefault::getInstance()->setBoolForKey("isStage43", false);
    UserDefault::getInstance()->setBoolForKey("isStage44", false);
    UserDefault::getInstance()->setBoolForKey("isStage45", false);
    UserDefault::getInstance()->setBoolForKey("isStage46", false);
    UserDefault::getInstance()->setBoolForKey("isStage47", false);
    UserDefault::getInstance()->setBoolForKey("isStage48", false);
    UserDefault::getInstance()->setBoolForKey("isStage49", false);
    UserDefault::getInstance()->setBoolForKey("isStage50", false);
    
    isStage1_selectBtnTouched = false;
    isStage2_selectBtnTouched = false;
    isStage3_selectBtnTouched = false;
    isStage4_selectBtnTouched = false;
    isStage5_selectBtnTouched = false;
    isStage6_selectBtnTouched = false;
    isStage7_selectBtnTouched = false;
     isStage8_selectBtnTouched = false;
     isStage9_selectBtnTouched = false;
     isStage10_selectBtnTouched = false;
    isStage11_selectBtnTouched = false;
    isStage12_selectBtnTouched = false;
    isStage13_selectBtnTouched = false;
    isStage14_selectBtnTouched = false;
    isStage15_selectBtnTouched = false;
    isStage16_selectBtnTouched = false;
    isStage17_selectBtnTouched = false;
    isStage18_selectBtnTouched = false;
    isStage19_selectBtnTouched = false;
    isStage20_selectBtnTouched = false;
    isStage21_selectBtnTouched = false;
    isStage22_selectBtnTouched = false;
    isStage23_selectBtnTouched = false;
    isStage24_selectBtnTouched = false;
    isStage25_selectBtnTouched = false;
    isStage26_selectBtnTouched = false;
    isStage27_selectBtnTouched = false;
    isStage28_selectBtnTouched = false;
    isStage29_selectBtnTouched = false;
    isStage30_selectBtnTouched = false;
    isStage31_selectBtnTouched = false;
    isStage32_selectBtnTouched = false;
    isStage33_selectBtnTouched = false;
    isStage34_selectBtnTouched = false;
    isStage35_selectBtnTouched = false;
    isStage36_selectBtnTouched = false;
    isStage37_selectBtnTouched = false;
    isStage38_selectBtnTouched = false;
    isStage39_selectBtnTouched = false;
    isStage40_selectBtnTouched = false;
    isStage41_selectBtnTouched = false;
    isStage42_selectBtnTouched = false;
    isStage43_selectBtnTouched = false;
    isStage44_selectBtnTouched = false;
    isStage45_selectBtnTouched = false;
    isStage46_selectBtnTouched = false;
    isStage47_selectBtnTouched = false;
    isStage48_selectBtnTouched = false;
    isStage49_selectBtnTouched = false;
    isStage50_selectBtnTouched = false;
    
    
    isStageSelected = false;
    
    stage1_selectBtn->setScale(1);
    stage2_selectBtn->setScale(1);
    stage3_selectBtn->setScale(1);
    stage4_selectBtn->setScale(1);
    stage5_selectBtn->setScale(1);
    stage6_selectBtn->setScale(1);
    stage7_selectBtn->setScale(1);
    stage8_selectBtn->setScale(1);
    stage9_selectBtn->setScale(1);
    stage10_selectBtn->setScale(1);
    stage11_selectBtn->setScale(1);
    stage12_selectBtn->setScale(1);
    stage13_selectBtn->setScale(1);
    stage14_selectBtn->setScale(1);
    stage15_selectBtn->setScale(1);
    stage16_selectBtn->setScale(1);
    stage17_selectBtn->setScale(1);
    stage18_selectBtn->setScale(1);
    stage19_selectBtn->setScale(1);
    stage20_selectBtn->setScale(1);
    stage21_selectBtn->setScale(1);
    stage22_selectBtn->setScale(1);
    stage23_selectBtn->setScale(1);
    stage24_selectBtn->setScale(1);
    stage25_selectBtn->setScale(1);
    stage26_selectBtn->setScale(1);
    stage27_selectBtn->setScale(1);
    stage28_selectBtn->setScale(1);
    stage29_selectBtn->setScale(1);
    stage30_selectBtn->setScale(1);
    stage31_selectBtn->setScale(1);
    stage32_selectBtn->setScale(1);
    stage33_selectBtn->setScale(1);
    stage34_selectBtn->setScale(1);
    stage35_selectBtn->setScale(1);
    stage36_selectBtn->setScale(1);
    stage37_selectBtn->setScale(1);
    stage38_selectBtn->setScale(1);
    stage39_selectBtn->setScale(1);
    stage40_selectBtn->setScale(1);
    stage41_selectBtn->setScale(1);
    stage42_selectBtn->setScale(1);
    stage43_selectBtn->setScale(1);
    stage44_selectBtn->setScale(1);
    stage45_selectBtn->setScale(1);
    stage46_selectBtn->setScale(1);
    stage47_selectBtn->setScale(1);
    stage48_selectBtn->setScale(1);
    stage49_selectBtn->setScale(1);
    stage50_selectBtn->setScale(1);
    
    revangeStart->setScale(1);
    stage2_keepGoing->setScale(1);
    stage3_3rd->setScale(1);
    stage4_NeverDie->setScale(1);
    stage5_->setScale(1);
    stage6_->setScale(1);
    stage7_->setScale(1);
    stage8_->setScale(1);
    stage9_->setScale(1);
    stage10_->setScale(1);
    stage11_->setScale(1);
    stage12_->setScale(1);
    stage13_->setScale(1);
    stage14_->setScale(1);
    stage15_->setScale(1);
    stage16_->setScale(1);
    stage17_->setScale(1);
    stage18_->setScale(1);
    stage19_->setScale(1);
    stage20_->setScale(1);
    stage21_->setScale(1);
    stage22_->setScale(1);
    stage23_->setScale(1);
    stage24_->setScale(1);
    stage25_->setScale(1);
    stage26_->setScale(1);
    stage27_->setScale(1);
    stage28_->setScale(1);
    stage29_->setScale(1);
    stage30_->setScale(1);
    stage31_->setScale(1);
    stage32_->setScale(1);
    stage33_->setScale(1);
    stage34_->setScale(1);
    stage35_->setScale(1);
    stage36_->setScale(1);
    stage37_->setScale(1);
    stage38_->setScale(1);
    stage39_->setScale(1);
    stage40_->setScale(1);
    stage41_->setScale(1);
    stage42_->setScale(1);
    stage43_->setScale(1);
    stage44_->setScale(1);
    stage45_->setScale(1);
    stage46_->setScale(1);
    stage47_->setScale(1);
    stage48_->setScale(1);
    stage49_->setScale(1);
    stage50_->setScale(1);
}

//모든버튼 가리기
void MungGuGameMenuScene::hideStageSelectBtns(){
    revangeStart->setVisible(false);

    stage1_selectBtn->setVisible(false);
    stage2_keepGoing->setVisible(false);
    stage2_selectBtn->setVisible(false);
    stage3_3rd->setVisible(false);
    stage3_selectBtn->setVisible(false);
    stage4_selectBtn->setVisible(false);
    stage4_NeverDie->setVisible(false);
    stage5_->setVisible(false);
    stage5_selectBtn->setVisible(false);
    stage6_selectBtn->setVisible(false);
    stage6_->setVisible(false);
    stage7_selectBtn->setVisible(false);
    stage7_->setVisible(false);
    stage8_selectBtn->setVisible(false);
    stage8_->setVisible(false);
    stage9_selectBtn->setVisible(false);
    stage9_->setVisible(false);
    stage10_selectBtn->setVisible(false);
    stage10_->setVisible(false);
    stage11_selectBtn->setVisible(false);
    stage11_->setVisible(false);
    stage12_selectBtn->setVisible(false);
    stage12_->setVisible(false);
    stage13_selectBtn->setVisible(false);
    stage13_->setVisible(false);
    stage14_selectBtn->setVisible(false);
    stage14_->setVisible(false);
    stage15_selectBtn->setVisible(false);
    stage15_->setVisible(false);
    stage16_selectBtn->setVisible(false);
    stage16_->setVisible(false);
    stage17_selectBtn->setVisible(false);
    stage17_->setVisible(false);
    stage18_selectBtn->setVisible(false);
    stage18_->setVisible(false);
    stage19_selectBtn->setVisible(false);
    stage19_->setVisible(false);
    stage20_selectBtn->setVisible(false);
    stage20_->setVisible(false);
    stage21_selectBtn->setVisible(false);
    stage21_->setVisible(false);
    stage22_selectBtn->setVisible(false);
    stage22_->setVisible(false);
    stage23_selectBtn->setVisible(false);
    stage23_->setVisible(false);
    stage24_selectBtn->setVisible(false);
    stage24_->setVisible(false);
    stage25_selectBtn->setVisible(false);
    stage25_->setVisible(false);
    stage26_selectBtn->setVisible(false);
    stage26_->setVisible(false);
    stage27_selectBtn->setVisible(false);
    stage27_->setVisible(false);
    stage28_selectBtn->setVisible(false);
    stage28_->setVisible(false);
    stage29_selectBtn->setVisible(false);
    stage29_->setVisible(false);
    stage30_selectBtn->setVisible(false);
    stage30_->setVisible(false);
    stage31_selectBtn->setVisible(false);
    stage31_->setVisible(false);
    stage32_selectBtn->setVisible(false);
    stage32_->setVisible(false);
    stage33_selectBtn->setVisible(false);
    stage33_->setVisible(false);
    stage34_selectBtn->setVisible(false);
    stage34_->setVisible(false);
    stage35_selectBtn->setVisible(false);
    stage35_->setVisible(false);
    stage36_selectBtn->setVisible(false);
    stage36_->setVisible(false);
    stage37_selectBtn->setVisible(false);
    stage37_->setVisible(false);
    stage38_selectBtn->setVisible(false);
    stage38_->setVisible(false);
    stage39_selectBtn->setVisible(false);
    stage39_->setVisible(false);
    stage40_selectBtn->setVisible(false);
    stage40_->setVisible(false);
    stage41_selectBtn->setVisible(false);
    stage41_->setVisible(false);
    stage42_selectBtn->setVisible(false);
    stage42_->setVisible(false);
    stage43_selectBtn->setVisible(false);
    stage43_->setVisible(false);
    stage44_selectBtn->setVisible(false);
    stage44_->setVisible(false);
    stage45_selectBtn->setVisible(false);
    stage45_->setVisible(false);
    stage46_selectBtn->setVisible(false);
    stage46_->setVisible(false);
    stage47_selectBtn->setVisible(false);
    stage47_->setVisible(false);
    stage48_selectBtn->setVisible(false);
    stage48_->setVisible(false);
    stage49_selectBtn->setVisible(false);
    stage49_->setVisible(false);
    stage50_selectBtn->setVisible(false);
    stage50_->setVisible(false);

    
    stage1_Info->setVisible(false);
    stage2_Info->setVisible(false);
    stage3_Info->setVisible(false);
    stage4_Info->setVisible(false);
    stage5_Info->setVisible(false);
    stage6_Info->setVisible(false);
    stage7_Info->setVisible(false);
    stage8_Info->setVisible(false);
    stage9_Info->setVisible(false);
    stage10_Info->setVisible(false);
    stage11_Info->setVisible(false);
    stage12_Info->setVisible(false);
    stage13_Info->setVisible(false);
    stage14_Info->setVisible(false);
    stage15_Info->setVisible(false);
    stage16_Info->setVisible(false);
    stage17_Info->setVisible(false);
    stage18_Info->setVisible(false);
    stage19_Info->setVisible(false);
    stage20_Info->setVisible(false);
    stage21_Info->setVisible(false);
    stage22_Info->setVisible(false);
    stage23_Info->setVisible(false);
    stage24_Info->setVisible(false);
    stage25_Info->setVisible(false);
    stage26_Info->setVisible(false);
    stage27_Info->setVisible(false);
    stage28_Info->setVisible(false);
    stage29_Info->setVisible(false);
    stage30_Info->setVisible(false);
    stage31_Info->setVisible(false);
    stage32_Info->setVisible(false);
    stage33_Info->setVisible(false);
    stage34_Info->setVisible(false);
    stage35_Info->setVisible(false);
    stage36_Info->setVisible(false);
    stage37_Info->setVisible(false);
    stage38_Info->setVisible(false);
    stage39_Info->setVisible(false);
    stage40_Info->setVisible(false);
    stage41_Info->setVisible(false);
    stage42_Info->setVisible(false);
    stage43_Info->setVisible(false);
    stage44_Info->setVisible(false);
    stage45_Info->setVisible(false);
    stage46_Info->setVisible(false);
    stage47_Info->setVisible(false);
    stage48_Info->setVisible(false);
    stage49_Info->setVisible(false);
    stage50_Info->setVisible(false);
    
    isStageSelected = false;
}

void MungGuGameMenuScene::initExitWindow(){//exit 창 생성
	isExitWindow = true;
	exitResumeBtn->setVisible(true);
	exitBtn->setVisible(true);
	exitWindow->setVisible(true);
}
void MungGuGameMenuScene::update(float delta){

    
	changeMyGold();
}
void MungGuGameMenuScene::setMyGold(){
	
}

void MungGuGameMenuScene::changeMyGold(){
	myGold_label->setString(StringUtils::format("%d", myGold, "NanumBarunGothicBold.otf", 30));
}
void MungGuGameMenuScene::setGameMenuBtn(){

	mungStoreBtn = Sprite::create("mungStoreBtn.png");
	mungStoreBtn->setPosition(Point(winSize.width + 10, winSize.height * 7 / 10));
	mungStoreBtn->setAnchorPoint(Point(1, 0.5));
	//mungStoreBtn->setTag(TAG_SPRITE_MUNGSTOREBTN);
	this->addChild(mungStoreBtn, 5);
    mungStoreBtn->setVisible(true);

	unitBtn = Sprite::create("unitBtn.png");
	unitBtn->setPosition(Point(winSize.width + 10, mungStoreBtn->getPositionY() - 100));
	unitBtn->setAnchorPoint(Point(1, 0.5));
	//unitBtn->setTag(TAG_SPRITE_UNITBTN);
	this->addChild(unitBtn, 5);

	missionBtn = Sprite::create("missionBtn.png");
	missionBtn->setPosition(Point(winSize.width + 10, mungStoreBtn->getPositionY() - 200));
	missionBtn->setAnchorPoint(Point(1, 0.5));
	//missionBtn->setTag(TAG_SPRITE_MISSIONBTN);
	this->addChild(missionBtn, 5);


	mungStoreBtn_ = Sprite::create("mungStoreBtn_.png");
	mungStoreBtn_->setPosition(Point(winSize.width, winSize.height * 7 / 10));
	mungStoreBtn_->setAnchorPoint(Point(1, 0.5));
	this->addChild(mungStoreBtn_, 5);
	//mungStoreBtn_->setTag(TAG_SPRITE_MUNGSTOREBTN_);
	mungStoreBtn_->setVisible(false);

	unitBtn_ = Sprite::create("unitBtn_.png");
	unitBtn_->setPosition(Point(winSize.width, mungStoreBtn->getPositionY() - 100));
	unitBtn_->setAnchorPoint(Point(1, 0.5));
	//unitBtn_->setTag(TAG_SPRITE_UNITBTN_);
	this->addChild(unitBtn_, 5);
	unitBtn_->setVisible(false);

	missionBtn_ = Sprite::create("missionBtn_.png");
	missionBtn_->setPosition(Point(winSize.width, mungStoreBtn->getPositionY() - 200));
	missionBtn_->setAnchorPoint(Point(1, 0.5));
//	missionBtn_->setTag(TAG_SPRITE_MISSIONBTN_);
	this->addChild(missionBtn_, 5);
	missionBtn_->setVisible(false);
    
    Rect mungStoreBtnRect = mungStoreBtn->getBoundingBox();
    //한영 전환 버튼
   
    
    eBtn = Sprite::create("eBtn.png");//영어 전환 버튼
    eBtn_ = Sprite::create("eBtn_.png");
    hBtn = Sprite::create("hBtn.png");//한글 전환 버튼
    hBtn_ = Sprite::create("hBtn_.png");
    
    eBtn->setAnchorPoint(Point(1,0));
    eBtn_->setAnchorPoint(Point(1,0));
    hBtn->setAnchorPoint(Point(1,0));
    hBtn_->setAnchorPoint(Point(1,0));
    
    eBtn->setScale(0.6);
    eBtn_->setScale(0.6);
    hBtn->setScale(0.6);
    hBtn_->setScale(0.6);
    
    eBtn->setPosition(Point(winSize.width-20,mungStoreBtnRect.getMaxY()+10));
    eBtn_->setPosition(Point(winSize.width-20,mungStoreBtnRect.getMaxY()+10));
    hBtn->setPosition(Point(winSize.width-20,mungStoreBtnRect.getMaxY()+10));
    hBtn_->setPosition(Point(winSize.width-20,mungStoreBtnRect.getMaxY()+10));

    initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
    if(initByEnglish==true){//영어로 될경우
    hBtn->setVisible(true);
    hBtn_->setVisible(false);
    eBtn->setVisible(false);
    eBtn_->setVisible(false);
    }else{
        hBtn->setVisible(false);
        hBtn_->setVisible(false);
        eBtn->setVisible(true);
        eBtn_->setVisible(false);
    }
    
    this->addChild(hBtn,5);
    this->addChild(hBtn_,5);
    this->addChild(eBtn,5);
    this->addChild(eBtn_,5);
    eBtnRect = eBtn->getBoundingBox();
    
    if(initByEnglish==true){
        ehLabel = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("English"), "NanumBarunGothic.otf", 16);
    }else{
        ehLabel = Label::createWithTTF //최고점수 표시할 라벨 선언
        (StringUtils::format("한국어"), "NanumBarunGothic.otf", 16);
    }
    ehLabel->setAnchorPoint(Point(1,0));
    ehLabel->setPosition(Point(eBtnRect.getMinX()-10,eBtnRect.getMinY()));
    ehLabel->setColor(Color3B::BLACK);
    this->addChild(ehLabel,5);


}

void MungGuGameMenuScene::setGameStartEvent(){
    go = Sprite::create("go2.png");
    go->setPosition(Point(winSize.width/2, winSize.height));
    go->setAnchorPoint(Point(0.5,0));
    go->setScale(0.8);
    go->setVisible(false);
    this->addChild(go,100);
    
    whiteDot = Sprite::create("whiteDot.png");
    this->addChild(whiteDot,80);
    whiteDot->setOpacity(210);
    whiteDot->setColor(Color3B::RED);
    Rect WhiteDotRect = whiteDot->getBoundingBox();
    whiteDot->setScale(winSize.width / WhiteDotRect.size.width, winSize.height / WhiteDotRect.size.height);
    whiteDot->setAnchorPoint(Point(0.5, 0.5));
    whiteDot->setPosition(Point(winSize.width / 2, winSize.height / 2));
    whiteDot->setColor(Color3B::BLACK);
    whiteDot->setVisible(false);
}

void MungGuGameMenuScene::initgameStartEvent(){
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    go->setVisible(true);
    whiteDot->setVisible(true);
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){//song 켰나 안켯나 확인
        SimpleAudioEngine::getInstance()->playBackgroundMusic("gameStart.mp3");//}
    }
    auto action00 = MoveBy::create(0.2,Point(0,-winSize.height/2+20));
    auto action0 = EaseIn::create(action00,1.3);
    auto action1 = MoveBy::create(2.3,Point(0,-80));
    auto action20 = MoveBy::create(0.3,Point(0,-winSize.height));
    auto action2 = EaseOut::create(action20,2);

    //auto action5 = DelayTime::create(2.0);
   
    auto action = Sequence::create(action0,action1,action2,NULL);
    auto gameStartAction = Spawn::create(CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::initDarkAction)),action,NULL);
    auto gameStartAction2 = Sequence::create(gameStartAction,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::changeGameMenuScene)),NULL);
    go->runAction(gameStartAction2);
   
    
}

void MungGuGameMenuScene::initDarkAction(){
    auto action01 = FadeTo::create(1.0,160);
    
    whiteDot->runAction(action01);
}


void MungGuGameMenuScene::setGameStartBtn(){

	gameStartBtn = Sprite::create("gameStartBtn.png");
	gameStartBtn->setPosition(winSize.width * 8 / 10, winSize.height / 6);
	gameStartBtn->setAnchorPoint(Point(0.5, 0.6));
	//gameStartBtn->setTag(TAG_SPRITE_GAMESTARTBTN);
	this->addChild(gameStartBtn, 6);

	gameStartBtn_ = Sprite::create("gameStartBtn_.png");
	gameStartBtn_->setPosition(winSize.width * 8 / 10, winSize.height / 6);
	gameStartBtn_->setAnchorPoint(Point(0.5, 0.6));
	//gameStartBtn_->setTag(TAG_SPRITE_GAMESTARTBTN_);
	this->addChild(gameStartBtn_, 7);
	gameStartBtn_->setVisible(false);
    
    mungGuGameStartBtnRect = gameStartBtn->getBoundingBox();

}



void MungGuGameMenuScene::setInfoWindow(){//정보창 셋팅
	infoWindow = Sprite::create("infoWindow.png");
	infoWindow->setPosition(Point(winSize.width / 2, winSize.height / 2));
	infoWindow->setAnchorPoint(Point(0.5, 0.5));
	//infoWindow->setTag(TAG_SPRITE_INFOWINDOW);
	infoWindow->setOpacity(230);
	this->addChild(infoWindow, 109);
	infoWindow->setVisible(false);

	Rect infoWindowRect = infoWindow->getBoundingBox();

	infoExitBtn = Sprite::create("infoExitBtn.png");
	infoExitBtn->setPosition(Point(infoWindowRect.getMaxX() - 20, infoWindowRect.getMaxY() - 20));
//	infoExitBtn->setTag(TAG_SPRITE_INFOEXITBTN);
	this->addChild(infoExitBtn, 110);
	infoExitBtn->setVisible(false);

	infoExitBtn_ = Sprite::create("infoExitBtn_.png");
	infoExitBtn_->setPosition(Point(infoWindowRect.getMaxX() - 20, infoWindowRect.getMaxY() - 20));
	//infoExitBtn_->setTag(TAG_SPRITE_INFOEXITBTN_);
	this->addChild(infoExitBtn_, 110);
	infoExitBtn_->setVisible(false);
}



void MungGuGameMenuScene::initInfoWindow(){
	infoWindow->setVisible(true);
	infoExitBtn->setVisible(true);
}

void MungGuGameMenuScene::removeInfoWindow(){
	infoWindow->setVisible(false);
	infoExitBtn->setVisible(false);
}
void MungGuGameMenuScene::initData(){

    isUpperReplaceBtnTouched = false;
    isBottomReplaceBtnTouched = false;
    
    isUpperReplaceBtnTouched = false;
    isBottomReplaceBtnTouched = false;
   
    
    isFbBtnTouched = false;
    isInfo = false;
    isInfoBtnTouched = false;
    isInfoExitBtnTouched = false;
    isMungStoreBtnTouched = false;
    isUnitBtnTouched = false;
    isMissionBtnTouched = false;
    isLittleExitBtnTouched = false;
    isExitBtnTouched = false;
    isExitResumeBtnTouched = false;
    isExitWindow = false;
    
    isFbBtnTouched = false;
    isInfo = false;
    isInfoBtnTouched = false;
    isInfoExitBtnTouched = false;
    isMungStoreBtnTouched = false;
    isUnitBtnTouched = false;
    isMissionBtnTouched = false;
    isLittleExitBtnTouched = false;
    isExitBtnTouched = false;
    isExitResumeBtnTouched = false;
    isExitWindow = false;
    
    isSongBtnTouched = false;
    isNotSongBtnTouched = false;
    isStageSelected = false;
    isStageTouched= false;
    
    isEhBtnTouched = false;
    //////stage//////
    isStageSelected = false;
    isStageTouched = false;
    
    isStage1_selectBtnTouched = false;
    isStage2_selectBtnTouched = false;
    isStage3_selectBtnTouched = false;
    isStage4_selectBtnTouched = false;
    isStage5_selectBtnTouched = false;
    isStage6_selectBtnTouched = false;
    isStage7_selectBtnTouched = false;
    isStage8_selectBtnTouched = false;
    isStage9_selectBtnTouched = false;
    isStage10_selectBtnTouched = false;
    isStage11_selectBtnTouched = false;
    isStage12_selectBtnTouched = false;
    isStage13_selectBtnTouched = false;
    isStage14_selectBtnTouched = false;
    isStage15_selectBtnTouched = false;
    isStage16_selectBtnTouched = false;
    isStage17_selectBtnTouched = false;
    isStage18_selectBtnTouched = false;
    isStage19_selectBtnTouched = false;
    isStage20_selectBtnTouched = false;
    isStage21_selectBtnTouched = false;
    isStage22_selectBtnTouched = false;
    isStage23_selectBtnTouched = false;
    isStage24_selectBtnTouched = false;
    isStage25_selectBtnTouched = false;
    isStage26_selectBtnTouched = false;
    isStage27_selectBtnTouched = false;
    isStage28_selectBtnTouched = false;
    isStage29_selectBtnTouched = false;
    isStage30_selectBtnTouched = false;
    
    UserDefault::getInstance()->setIntegerForKey("stageIndex", 0);//초기 인덱스는 0
    stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
    stageIndexMin = 0;//이변이 없는한 최소 인덱스값은 0
    stageIndexMax = 5;//스테이지/5-1 값
    ////
    
    
    
    auto listener_songBtn = EventListenerTouchOneByOne::create();
    listener_songBtn->onTouchBegan = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchBegan, this);
    listener_songBtn->onTouchMoved = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchMoved, this);
    listener_songBtn->onTouchEnded = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchEnded, this);
    Director::getInstance()->getEventDispatcher()->
    addEventListenerWithFixedPriority(listener_songBtn, TAG_SPRITE_ISSONGBTN);
    
    auto listener_stage1_selectBtn = EventListenerTouchOneByOne::create();
    listener_stage1_selectBtn->onTouchBegan = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchBegan, this);
    listener_stage1_selectBtn->onTouchMoved = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchMoved, this);
    listener_stage1_selectBtn->onTouchEnded = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchEnded, this);
    
    auto listener_stage2_selectBtn = EventListenerTouchOneByOne::create();
    listener_stage2_selectBtn->onTouchBegan = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchBegan, this);
    listener_stage2_selectBtn->onTouchMoved = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchMoved, this);
    listener_stage2_selectBtn->onTouchEnded = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchEnded, this);
    
    auto listener_stage3_selectBtn = EventListenerTouchOneByOne::create();
    listener_stage3_selectBtn->onTouchBegan = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchBegan, this);
    listener_stage3_selectBtn->onTouchMoved = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchMoved, this);
    listener_stage3_selectBtn->onTouchEnded = CC_CALLBACK_2
    (MungGuGameMenuScene::onTouchEnded, this);
    
	auto listener_littleExitBtn = EventListenerTouchOneByOne::create();
	listener_littleExitBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_littleExitBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_littleExitBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	auto listener_exitBtn = EventListenerTouchOneByOne::create();
	listener_exitBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_exitBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_exitBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	auto listener_exitResumeBtn = EventListenerTouchOneByOne::create();
	listener_exitResumeBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_exitResumeBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_exitResumeBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);


	auto listener_mungStoreBtn = EventListenerTouchOneByOne::create();
	listener_mungStoreBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_mungStoreBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_mungStoreBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	auto listener_unitBtn = EventListenerTouchOneByOne::create();
	listener_unitBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_unitBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_unitBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	auto listener_missionBtn = EventListenerTouchOneByOne::create();
	listener_missionBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_missionBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_missionBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	//정보창 버튼
	auto listener_infoBtn = EventListenerTouchOneByOne::create();
	listener_infoBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_infoBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_infoBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	//정보창 나가기
	auto listener_infoExitBtn = EventListenerTouchOneByOne::create();
	listener_infoExitBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_infoExitBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_infoExitBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);

	auto listener_MungguGameStartBtn = EventListenerTouchOneByOne::create();
	listener_MungguGameStartBtn->onTouchBegan = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchBegan, this);
	listener_MungguGameStartBtn->onTouchMoved = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchMoved, this);
	listener_MungguGameStartBtn->onTouchEnded = CC_CALLBACK_2
		(MungGuGameMenuScene::onTouchEnded, this);
//
//    
//   
//	Director::getInstance()->getEventDispatcher()->
//		addEventListenerWithFixedPriority(listener_infoExitBtn, stage1_sele);
}

void MungGuGameMenuScene::changeGameMenuScene(Ref *sender){
	//터치이벤트를 계속 초기화 시켜줌
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionFade::create(2, MungGuGame::createScene());
	Director::getInstance()->replaceScene(scene);
}

void MungGuGameMenuScene::changeGameMenuScene(){
    //터치이벤트를 계속 초기화 시켜줌
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = TransitionFade::create(2, MungGuGame::createScene());
    Director::getInstance()->replaceScene(scene);
}

void MungGuGameMenuScene::changeMungStoreScene(Ref *sender){
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionFade::create(0.6, MungStoreScene::createScene());
	Director::getInstance()->replaceScene(scene);
}


void MungGuGameMenuScene::changeUnitScene(Ref *sender){//구현중
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionFade::create(0.6, UnitScene::createScene());
	Director::getInstance()->replaceScene(scene);
}

void MungGuGameMenuScene::changeMissionScene(Ref *sender){
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	auto scene = TransitionFade::create(0.6, MissionScene::createScene());
	Director::getInstance()->replaceScene(scene);
}




bool MungGuGameMenuScene::onTouchBegan(Touch *touch, Event *unused_event){
	Point loc = touch->getLocation();


    
    if( isIntroWindow==true){
        if(introExitBtnRect.containsPoint(loc)){
            introExitBtn->setVisible(false);
            introExitBtn_->setVisible(true);
        }
    }
    
    if( isIntroWindow2==true){
        if(introExitBtnRect.containsPoint(loc)){
            introExitBtn->setVisible(false);
            introExitBtn_->setVisible(true);
        }
    }
    
    //뭐냐
    if ((isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){
         initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
        if(eBtnRect.containsPoint(loc)){
            isEhBtnTouched = true;
            if(initByEnglish==true){//영어 상태임 이떄는 한국 버튼이 나와있음 누르면 한국버튼이 눌림
        hBtn->setVisible(false);
        hBtn_->setVisible(true);
        eBtn->setVisible(false);
        eBtn_->setVisible(false);
            }else{//반대면 영어 버튼이 눌림
                hBtn->setVisible(false);
                hBtn_->setVisible(false);
                eBtn->setVisible(false);
                eBtn_->setVisible(true);
            }
        }
    
    }
    //소리 설정
    if((isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){
    if (isSongBtnRect.containsPoint(loc)){
        if (isNotSongBtnTouched == false){
                if (isSongBtnTouched == false){
                    
                    isSongBtnTouched = true;
                    isSongBtn->setVisible(false);
                    isSongBtn_->setVisible(true);
                    isNotSongBtn->setVisible(false);
                    isNotSongBtn_->setVisible(false);
                }
            }else{
                isSongBtnTouched = true;
                isSongBtn->setVisible(false);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(false);
                isNotSongBtn_->setVisible(true);
        }
    }
}
    
    //스테이지 대체
    //upperReplaceBtn
    Rect upperReplaceBtnRect = upperReplaceBtn->getBoundingBox();
    if ((upperReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (isIntroWindow == false)){//씬 이동
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
        if ((isSong == true)&&(stageIndex!=0)){
            SimpleAudioEngine::getInstance()->playEffect("switch.wav");
        }else{
            if(isSong == true){//더이상 올라갈 수 없음..
                SimpleAudioEngine::getInstance()->playEffect("warning2.wav");//}
            }
        }
        if(isUpperReplaceBtnTouched==false){
            isUpperReplaceBtnTouched=true;

            upperReplaceBtn->setVisible(false);
            upperReplaceBtn_->setVisible(true);
           
        }
    }
    
    Rect bottomReplaceBtnRect = bottomReplaceBtn->getBoundingBox();
    if ((bottomReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false&& (isIntroWindow == false))){//씬 이동
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
        if ((isSong == true)&&(stageIndex!=stageIndexMax)){
            SimpleAudioEngine::getInstance()->playEffect("switch.wav");
        }else{
                if(isSong == true){//더이상 내려갈 수 없음..
                    SimpleAudioEngine::getInstance()->playEffect("warning2.wav");//}
                }
        }
        if(isBottomReplaceBtnTouched==false){
            isBottomReplaceBtnTouched=true;
            bottomReplaceBtn->setVisible(false);
            bottomReplaceBtn_->setVisible(true);
            
        }
    }
    
    
        stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
    
    //stage1 btn
    if ((stage1_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (stageIndex == 0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 1"));
            }else{
                stage_label->setString(StringUtils::format("Stage 1"));
            }
            
            
             bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
        isStage1_selectBtnTouched = true;
      //  stopAllActions();
        
        //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
        isStageSelected=true;
        
        UserDefault::getInstance()->setBoolForKey("isStage1", true);
        auto action_0 = ScaleTo::create(0.05, 0.8);
        auto action_1 = ScaleTo::create(0.05, 2);
        auto action_2 = ScaleTo::create(0.05, 1.2);
        auto action_3 = ScaleTo::create(0.05, 1.6);
        auto action_4 = ScaleTo::create(0.05, 1.1);
        auto action_5 = ScaleTo::create(0.05, 1.3);
        auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)),NULL);
        auto btnAction = EaseIn::create(action, 0.3);
      //  if(isStageTouched==false){
      //      isStageTouched=true;
        revangeStart->runAction(btnAction);
      //  }
        }
    }
    
    //stage2 btn
    if ((stage2_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 0) && (stage1_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 2"));
            }else{
                stage_label->setString(StringUtils::format("Stage 2"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
        isStage2_selectBtnTouched = true;
      //  stopAllActions();
        
        isStageSelected=true;
        UserDefault::getInstance()->setBoolForKey("isStage2", true);
        auto action_0 = ScaleTo::create(0.05, 0.8);
        auto action_1 = ScaleTo::create(0.05, 2);
        auto action_2 = ScaleTo::create(0.05, 1.2);
        auto action_3 = ScaleTo::create(0.05, 1.6);
        auto action_4 = ScaleTo::create(0.05, 1.1);
        auto action_5 = ScaleTo::create(0.05, 1.3);
        auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
        auto btnAction = EaseIn::create(action, 0.3);
      //  if(isStageTouched==false){
      //      isStageTouched=true;
        stage2_keepGoing->runAction(btnAction);
        }
    }
    
    //stage1 btn
    if ((stage3_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 0)&& (stage2_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 3"));
            }else{
                stage_label->setString(StringUtils::format("Stage 3"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
        isStage3_selectBtnTouched = true;
     //   stopAllActions();
        
        //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
        isStageSelected=true;
        UserDefault::getInstance()->setBoolForKey("isStage3", true);
        auto action_0 = ScaleTo::create(0.05, 0.8);
        auto action_1 = ScaleTo::create(0.05, 2);
        auto action_2 = ScaleTo::create(0.05, 1.2);
        auto action_3 = ScaleTo::create(0.05, 1.6);
        auto action_4 = ScaleTo::create(0.05, 1.1);
        auto action_5 = ScaleTo::create(0.05, 1.3);
        auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
        auto btnAction = EaseIn::create(action, 0.3);

        stage3_3rd->runAction(btnAction);
        }
        
    }
    
    //stage4 btn
    if ((stage4_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 0)&& (stage3_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
             setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 4"));
            }else{
                stage_label->setString(StringUtils::format("Stage 4"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage4_selectBtnTouched = true;
            //   stopAllActions();
           
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage4", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage4_NeverDie->runAction(btnAction);
        }
        
    }
    
    
    //stage5 btn
    if ((stage5_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 0)&& (stage4_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 5"));
            }else{
                stage_label->setString(StringUtils::format("Stage 5"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage5_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage5", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage5_->runAction(btnAction);
        }
        
    }
    
    //stage6 btn
    Rect stage6_selectBtnRect = stage6_selectBtn->getBoundingBox();
    if ((stage6_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 1)&& (stage5_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 6"));
            }else{
                stage_label->setString(StringUtils::format("Stage 6"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage6_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage6", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage6_->runAction(btnAction);
        }
        
    }
    
    //stage7 btn
    Rect stage7_selectBtnRect = stage7_selectBtn->getBoundingBox();
    if ((stage7_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 1)&& (stage6_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 7"));
            }else{
                stage_label->setString(StringUtils::format("Stage 7"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage7_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage7", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage7_->runAction(btnAction);
        }
    }
    
    Rect stage8_selectBtnRect = stage8_selectBtn->getBoundingBox();
    if ((stage8_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 1)&& (stage7_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 8"));
            }else{
                stage_label->setString(StringUtils::format("Stage 8"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage8_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage8", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage8_->runAction(btnAction);
        }
        
    }

    
    Rect stage9_selectBtnRect = stage9_selectBtn->getBoundingBox();
    if ((stage9_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 1)&& (stage8_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 9"));
            }else{
                stage_label->setString(StringUtils::format("Stage 9"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage9_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage9", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage9_->runAction(btnAction);
        }
        
    }

    Rect stage10_selectBtnRect = stage10_selectBtn->getBoundingBox();
    if ((stage10_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 1)&& (stage9_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 10"));
            }else{
                stage_label->setString(StringUtils::format("Stage 10"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage10_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage10", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage10_->runAction(btnAction);
        }
        
    }
    
    
    //////11~15
    //stage6 btn
    Rect stage11_selectBtnRect = stage11_selectBtn->getBoundingBox();
    if ((stage11_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 2)&& (stage10_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 11"));
            }else{
                stage_label->setString(StringUtils::format("Stage 11"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage11_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage11", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage11_->runAction(btnAction);
        }
        
    }
    
    //stage7 btn
    Rect stage12_selectBtnRect = stage12_selectBtn->getBoundingBox();
    if ((stage12_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 2)&& (stage11_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 12"));
            }else{
                stage_label->setString(StringUtils::format("Stage 12"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage12_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage12", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage12_->runAction(btnAction);
        }
    }
    
    Rect stage13_selectBtnRect = stage13_selectBtn->getBoundingBox();
    if ((stage13_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 2)&& (stage12_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 13"));
            }else{
                stage_label->setString(StringUtils::format("Stage 13"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage13_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage13", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage13_->runAction(btnAction);
        }
        
    }
    
    
    Rect stage14_selectBtnRect = stage14_selectBtn->getBoundingBox();
    if ((stage14_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 2)&& (stage13_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 14"));
            }else{
                stage_label->setString(StringUtils::format("Stage 14"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage14_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage14", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage14_->runAction(btnAction);
        }
        
    }
    
    Rect stage15_selectBtnRect = stage15_selectBtn->getBoundingBox();
    if ((stage15_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 2)&& (stage14_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 15"));
            }else{
                stage_label->setString(StringUtils::format("Stage 15"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage15_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage15", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage15_->runAction(btnAction);
        }
        
    }
    
    //////16~20
    //stage16 btn
    if ((stage11_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 3)&& (stage15_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 16"));
            }else{
                stage_label->setString(StringUtils::format("Stage 16"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage16_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage16", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage16_->runAction(btnAction);
        }
        
    }

    //17
    if ((stage12_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 3)&& (stage16_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 17"));
            }else{
                stage_label->setString(StringUtils::format("Stage 17"));
            }
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage17_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage17", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage17_->runAction(btnAction);
        }
    }

    if ((stage13_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 3)&& (stage17_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 18"));
            }else{
                stage_label->setString(StringUtils::format("Stage 18"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage18_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage18", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage18_->runAction(btnAction);
        }
        
    }
    

    if ((stage14_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 3)&& (stage18_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 19"));
            }else{
                stage_label->setString(StringUtils::format("Stage 19"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage19_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage19", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage19_->runAction(btnAction);
        }
        
    }
    

    if ((stage15_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 3)&& (stage19_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 20"));
            }else{
                stage_label->setString(StringUtils::format("Stage 20"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage20_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage20", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage20_->runAction(btnAction);
        }
        
    }
    
    //21~25
    //stage21
    if ((stage11_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 4)&& (stage20_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
             setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 21"));
            }else{
                stage_label->setString(StringUtils::format("Stage 21"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage21_selectBtnTouched = true;
            //   stopAllActions();
           
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage21", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage21_->runAction(btnAction);
        }
        
    }
    
    //17
    if ((stage12_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 4)&& (stage21_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 22"));
            }else{
                stage_label->setString(StringUtils::format("Stage 22"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage22_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage22", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage22_->runAction(btnAction);
        }
    }
    
    if ((stage13_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 4)&& (stage22_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 23"));
            }else{
                stage_label->setString(StringUtils::format("Stage 23"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage23_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage23", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage23_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage14_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 4)&& (stage23_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 24"));
            }else{
                stage_label->setString(StringUtils::format("Stage 24"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage24_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage24", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage24_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage15_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 4)&& (stage24_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 25"));
            }else{
                stage_label->setString(StringUtils::format("Stage 25"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage25_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage25", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage25_->runAction(btnAction);
        }
        
    }
    
    //26~30
    //stage26
    if ((stage11_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 5)&& (stage25_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 26"));
            }else{
                stage_label->setString(StringUtils::format("Stage 26"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage26_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage26", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage26_->runAction(btnAction);
        }
        
    }
    
    //27
    if ((stage12_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 5)&& (stage26_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 27"));
            }else{
                stage_label->setString(StringUtils::format("Stage 27"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage27_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage27", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage27_->runAction(btnAction);
        }
    }
    
    if ((stage13_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 5)&& (stage27_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 28"));
            }else{
                stage_label->setString(StringUtils::format("Stage 28"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage28_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage28", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage28_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage14_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 5)&& (stage28_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 29"));
            }else{
                stage_label->setString(StringUtils::format("Stage 29"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage29_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage29", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage29_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage15_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 5)&& (stage29_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 30"));
            }else{
                stage_label->setString(StringUtils::format("Stage 30"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage30_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage30", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage30_->runAction(btnAction);
        }
        
    }
    //////===============1 ~ 30==================//////////
    
    ////====31~50===///
    
    //////31~

    if ((stage1_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 6)&& (stage30_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 31"));
            }else{
                stage_label->setString(StringUtils::format("Stage 31"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage31_selectBtnTouched = true;

            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage31", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage31_->runAction(btnAction);
        }
        
    }
    

    if ((stage2_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 6)&& (stage31_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 32"));
            }else{
                stage_label->setString(StringUtils::format("Stage 32"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage32_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage32", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage32_->runAction(btnAction);
        }
    }

    if ((stage3_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 6)&& (stage32_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 33"));
            }else{
                stage_label->setString(StringUtils::format("Stage 33"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage33_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage33", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage33_->runAction(btnAction);
        }
        
    }
    

    if ((stage4_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 6)&& (stage33_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 34"));
            }else{
                stage_label->setString(StringUtils::format("Stage 34"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage34_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage34", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage34_->runAction(btnAction);
        }
        
    }

    if ((stage5_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 6)&& (stage34_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 35"));
            }else{
                stage_label->setString(StringUtils::format("Stage 35"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage35_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage35", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage35_->runAction(btnAction);
        }
        
    }
    
    //////36~
    if ((stage1_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 7)&& (stage35_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 36"));
            }else{
                stage_label->setString(StringUtils::format("Stage 36"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage36_selectBtnTouched = true;

            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage36", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage36_->runAction(btnAction);
        }
        
    }
    
    //17
    if ((stage2_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 7)&& (stage36_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 37"));
            }else{
                stage_label->setString(StringUtils::format("Stage 37"));
            }
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage37_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage37", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage37_->runAction(btnAction);
        }
    }
    
    if ((stage3_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 7)&& (stage37_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 38"));
            }else{
                stage_label->setString(StringUtils::format("Stage 38"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage38_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage38", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage38_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage4_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 7)&& (stage38_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 39"));
            }else{
                stage_label->setString(StringUtils::format("Stage 39"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage39_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage39", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage39_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage5_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 7)&& (stage39_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 40"));
            }else{
                stage_label->setString(StringUtils::format("Stage 40"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage40_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage40", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage40_->runAction(btnAction);
        }
        
    }
    
    //stage41~
    if ((stage1_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 8)&& (stage40_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 41"));
            }else{
                stage_label->setString(StringUtils::format("Stage 41"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage41_selectBtnTouched = true;
            //   stopAllActions();
            
            //stage1_selectBtn->setOpacity(<#GLubyte opacity#>)
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage41", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage41_->runAction(btnAction);
        }
        
    }
    
    //17
    if ((stage2_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 8)&& (stage41_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 42"));
            }else{
                stage_label->setString(StringUtils::format("Stage 42"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage22_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage42", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage42_->runAction(btnAction);
        }
    }
    
    if ((stage3_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 8)&& (stage42_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 43"));
            }else{
                stage_label->setString(StringUtils::format("Stage 43"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage43_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage43", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage43_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage4_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 8)&& (stage43_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 44"));
            }else{
                stage_label->setString(StringUtils::format("Stage 44"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage44_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage44", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage44_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage5_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 8)&& (stage44_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 45"));
            }else{
                stage_label->setString(StringUtils::format("Stage 45"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage45_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage45", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage45_->runAction(btnAction);
        }
        
    }

    //stage46~
    if ((stage1_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 9)&& (stage45_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 46"));
            }else{
                stage_label->setString(StringUtils::format("Stage 46"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage46_selectBtnTouched = true;

            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage46", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage46_->runAction(btnAction);
        }
        
    }

    if ((stage2_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 9)&& (stage46_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 47"));
            }else{
                stage_label->setString(StringUtils::format("Stage 47"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage47_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage47", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage47_->runAction(btnAction);
        }
    }
    
    if ((stage3_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 9)&& (stage47_clearCount!=0) && (isIntroWindow == false)) {//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 48"));
            }else{
                stage_label->setString(StringUtils::format("Stage 48"));
            }
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage48_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage48", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage48_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage4_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 9)&& (stage48_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 49"));
            }else{
                stage_label->setString(StringUtils::format("Stage 49"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage49_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage49", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage49_->runAction(btnAction);
        }
        
    }
    
    
    if ((stage5_selectBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (stageIndex == 9)&& (stage29_clearCount!=0) && (isIntroWindow == false)){//씬 이동
        if(isStageTouched==false){
            isStageTouched=true;
            setStageSelectBtns();
            if(initByEnglish==false){
                stage_label->setString(StringUtils::format("스테이지 50"));
            }else{
                stage_label->setString(StringUtils::format("Stage 50"));
            }
            
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            }
            isStage50_selectBtnTouched = true;
            
            
            isStageSelected=true;
            UserDefault::getInstance()->setBoolForKey("isStage50", true);
            auto action_0 = ScaleTo::create(0.05, 0.8);
            auto action_1 = ScaleTo::create(0.05, 2);
            auto action_2 = ScaleTo::create(0.05, 1.2);
            auto action_3 = ScaleTo::create(0.05, 1.6);
            auto action_4 = ScaleTo::create(0.05, 1.1);
            auto action_5 = ScaleTo::create(0.05, 1.3);
            auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5,CallFunc::create(this,callfunc_selector(MungGuGameMenuScene::stageTouchFinished)), NULL);
            auto btnAction = EaseIn::create(action, 0.3);
            
            stage50_->runAction(btnAction);
        }
        
    }
    
    
    
    
    
  
    if((stageBtnRect.containsPoint(loc))&& (isInfo == false) && (isExitWindow == false)&& (isIntroWindow == false)){
        //스테이지 설명 버튼 클릭 시,
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
          //  int warningSound =
            SimpleAudioEngine::getInstance()->playEffect("warning2.wav");//}
        }
        auto action = Blink::create(1, 1);
        stageBtnInfo->runAction(action);
        
        //m8 클리어 이벤트
        bool isM8Clear = UserDefault::getInstance()->getBoolForKey("m8");
        
        if(isM8Clear==false){
        int disabled_count = UserDefault::getInstance()->getIntegerForKey("disabled_count");
        UserDefault::getInstance()->setIntegerForKey("disabled_count", disabled_count+1);
         disabled_count = UserDefault::getInstance()->getIntegerForKey("disabled_count");
        if(disabled_count==50){//50번을 장애인 짓 하면,
            
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if(isSong == true){//song 켰나 안켯나 확인
                int disabledSong =
                SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
            }
            
            
            UserDefault::getInstance()->setBoolForKey("m8",true);//8미션 클리어
          
            auto m8Clear = Label::createWithTTF(StringUtils::format("mission 8 Clear~!!!\n-> The disabled"), "NanumBarunGothicBold.otf", 20);
            m8Clear->setColor(Color3B::RED);
            m8Clear->setAnchorPoint(Point(0.5,1));
            m8Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m8Clear->setColor(Color3B::RED);
            m8Clear->setVisible(false);
            this->addChild(m8Clear,10);
            if(initByEnglish==false){
                m8Clear->setString(StringUtils::format("미션 8 클리어~!!!\n -> 장애인"));
            }
            auto action = Blink::create(3,10);
            m8Clear->runAction(action);
            

        }
        }
    }
    
    
    
	//gameStartBtn
	if ((littleExitBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (isIntroWindow == false)){//씬 이동
		isLittleExitBtnTouched = true;

		littleExitBtn->setVisible(false);
		littleExitBtn_->setVisible(true);
        auto action_0 = ScaleTo::create(0.05, 0.8);
        auto action_1 = ScaleTo::create(0.05, 2);
        auto action_2 = ScaleTo::create(0.05, 1.2);
        auto action_3 = ScaleTo::create(0.05, 1.6);
        auto action_4 = ScaleTo::create(0.05, 1.1);
        auto action_5 = ScaleTo::create(0.05, 1.3);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		littleExitBtn_->runAction(btnAction);
	}
    
    Rect fbBtnRect = fbBtn->getBoundingBox();
    if ((fbBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){//페북
        isFbBtnTouched = true;
        
        fbBtn->setVisible(false);
        fbBtn_->setVisible(true);
    }

	if ((exitResumeBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == true)&& (isIntroWindow == false)){//씬 이동
		isExitResumeBtnTouched = true;

		exitResumeBtn->setVisible(false);
		exitResumeBtn_->setVisible(true);
        auto action_0 = ScaleTo::create(0.05, 0.8);
        auto action_1 = ScaleTo::create(0.05, 2);
        auto action_2 = ScaleTo::create(0.05, 1.2);
        auto action_3 = ScaleTo::create(0.05, 1.6);
        auto action_4 = ScaleTo::create(0.05, 1.1);
        auto action_5 = ScaleTo::create(0.05, 1.3);
        auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		exitResumeBtn_->runAction(btnAction);
	}

	if ((exitBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == true)&& (isIntroWindow == false)){//씬 이동
		isExitBtnTouched = true;

		exitBtn->setVisible(false);
		exitBtn_->setVisible(true);
		auto action_0 = ScaleTo::create(0.05, 0.8);
		auto action_1 = ScaleTo::create(0.05, 2);
		auto action_2 = ScaleTo::create(0.05, 1.2);
		auto action_3 = ScaleTo::create(0.05, 1.6);
		auto action_4 = ScaleTo::create(0.05, 1.1);
		auto action_5 = ScaleTo::create(0.05, 1.3);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		exitBtn_->runAction(btnAction);
	}


	//m9
	if ((mungGuGameStartBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){//씬 이동
		// if(isSongPlayed==true){
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isStageSelected == false){
            auto action = Blink::create(1,1);
            if(isSong == true){//song 켰나 안켯나 확인
            //    int warningSound =
                SimpleAudioEngine::getInstance()->playEffect("warning2.wav");//}
            }
            
            //m9 클리어 이벤트
            bool isM9Clear = UserDefault::getInstance()->getBoolForKey("m9");
            
            if(isM9Clear==false){
            int disabled2_count = UserDefault::getInstance()->getIntegerForKey("disabled2_count");
            UserDefault::getInstance()->setIntegerForKey("disabled2_count", disabled2_count+1);
            disabled2_count = UserDefault::getInstance()->getIntegerForKey("disabled2_count");
            if(disabled2_count==50){//50번을 장애인 짓 하면,
                
                
                bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                if(isSong == true){//song 켰나 안켯나 확인
                    int disabledSong =
                    SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
                }
            
                
                
                UserDefault::getInstance()->setBoolForKey("m9",true);//8미션 클리어
                
                auto m9Clear = Label::createWithTTF(StringUtils::format("mission 9 Clear~!!!\n-> The disabled"), "NanumBarunGothicBold.otf", 20);
                m9Clear->setColor(Color3B::RED);
                m9Clear->setAnchorPoint(Point(0.5,1));
                m9Clear->setPosition(Point(winSize.width/2,winSize.height-20));
                m9Clear->setColor(Color3B::RED);
                m9Clear->setVisible(false);
                this->addChild(m9Clear,10);
                auto action = Blink::create(3,8);
                if(initByEnglish==false){
                    m9Clear->setString(StringUtils::format("미션 9 클리어~!!!\n -> 장애인2"));
                }
                
                m9Clear->runAction(action);
                
            }
            }
            gameStartBtnInfo->runAction(action);
            
        }else{
        
        if(isSong == true){//song 켰나 안켯나 확인
			SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
        }
		isGameStartBtnTouched = true;
		gameStartBtn->setVisible(false);
		gameStartBtn_->setVisible(true);

		auto action_0 = ScaleTo::create(0.05, 1.05);
		auto action_1 = ScaleTo::create(0.05, 1.1);
		auto action_2 = ScaleTo::create(0.05, 1.13);
		auto action_3 = ScaleTo::create(0.05, 1.16);
		auto action_4 = ScaleTo::create(0.05, 1.14);
		auto action_5 = ScaleTo::create(0.05, 1.16);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		gameStartBtn_->runAction(btnAction);
        }
	}

	//mungStore
	if ((mungStoreBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){
		// if(isSongPlayed==true){
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
			SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
        }
		isMungStoreBtnTouched = true;
		mungStoreBtn->setVisible(false);
		mungStoreBtn_->setVisible(true);
		auto action_0 = ScaleTo::create(0.05, 1.05);
		auto action_1 = ScaleTo::create(0.05, 1.1);
		auto action_2 = ScaleTo::create(0.05, 1.13);
		auto action_3 = ScaleTo::create(0.05, 1.16);
		auto action_4 = ScaleTo::create(0.05, 1.14);
		auto action_5 = ScaleTo::create(0.05, 1.16);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		mungStoreBtn_->runAction(btnAction);
	}

	//unit
	if ((unitBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){
		// if(isSongPlayed==true){
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
			SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
        }
		isUnitBtnTouched = true;
		unitBtn->setVisible(false);
		unitBtn_->setVisible(true);
		auto action_0 = ScaleTo::create(0.05, 1.05);
		auto action_1 = ScaleTo::create(0.05, 1.1);
		auto action_2 = ScaleTo::create(0.05, 1.13);
		auto action_3 = ScaleTo::create(0.05, 1.16);
		auto action_4 = ScaleTo::create(0.05, 1.14);
		auto action_5 = ScaleTo::create(0.05, 1.16);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		unitBtn_->runAction(btnAction);
	}

	//mission
	if ((missionBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false) && (isIntroWindow == false)){
		//  if(isSongPlayed==true){
        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        if(isSong == true){//song 켰나 안켯나 확인
			SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
        }
		isMissionBtnTouched = true;
		missionBtn->setVisible(false);
		missionBtn_->setVisible(true);
		auto action_0 = ScaleTo::create(0.05, 1.05);
		auto action_1 = ScaleTo::create(0.05, 1.1);
		auto action_2 = ScaleTo::create(0.05, 1.13);
		auto action_3 = ScaleTo::create(0.05, 1.16);
		auto action_4 = ScaleTo::create(0.05, 1.14);
		auto action_5 = ScaleTo::create(0.05, 1.16);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		missionBtn_->runAction(btnAction);
	}


	if ((infoBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)&& (isIntroWindow == false)){//정보창 취소 버튼
		isInfoBtnTouched = true;
		infoBtn->setVisible(false);
		infoBtn_->setVisible(true);

    }

	if ((infoExitBtnRect.containsPoint(loc)) && (isInfo == true) && (isExitWindow == false)&& (isIntroWindow == false)){//정보창 취소 버튼
		isInfoExitBtnTouched = true;
		infoExitBtn->setVisible(false);
		infoExitBtn_->setVisible(true);
		auto action_0 = ScaleTo::create(0.05, 1.05);
		auto action_1 = ScaleTo::create(0.05, 1.1);
		auto action_2 = ScaleTo::create(0.05, 1.13);
		auto action_3 = ScaleTo::create(0.05, 1.16);
		auto action_4 = ScaleTo::create(0.05, 1.14);
		auto action_5 = ScaleTo::create(0.05, 1.16);
		auto action = Sequence::create(action_0, action_1, action_2, action_3, action_4, action_5, NULL);
		auto btnAction = EaseIn::create(action, 0.3);
		infoExitBtn_->runAction(btnAction);

	}
	return true;
}
void MungGuGameMenuScene::onTouchMoved(Touch *touch, Event *unused_event){
	Point loc = touch->getLocation();



    
    //스테이지 대체
    //upperReplaceBtn
    if(isUpperReplaceBtnTouched == true){
    Rect upperReplaceBtnRect = upperReplaceBtn->getBoundingBox();
    if ((upperReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)){//씬 이동
            //            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            //            if(isSong == true){//song 켰나 안켯나 확인
            //                SimpleAudioEngine::getInstance()->playEffect("clickSound.mp3");//}
            //            }
            upperReplaceBtn->setVisible(false);
            upperReplaceBtn_->setVisible(true);
    }else{
        upperReplaceBtn->setVisible(true);
        upperReplaceBtn_->setVisible(false);
    }
    }
    
    Rect bottomReplaceBtnRect = bottomReplaceBtn->getBoundingBox();
    if(isBottomReplaceBtnTouched==true){
    if ((bottomReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)){//씬 이동
        
            bottomReplaceBtn->setVisible(false);
            bottomReplaceBtn_->setVisible(true);
    }else{
        bottomReplaceBtn->setVisible(true);
        bottomReplaceBtn_->setVisible(false);
        
    }
    }


	if (isExitBtnTouched == true){
		if (exitBtnRect.containsPoint(loc)){
			exitBtn->setVisible(false);
			exitBtn_->setVisible(true);
		}
		else{
			exitBtn->setVisible(true);
			exitBtn_->setVisible(false);
		}
	}


	if (isLittleExitBtnTouched == true){
		if (littleExitBtnRect.containsPoint(loc)){
			littleExitBtn->setVisible(false);
			littleExitBtn_->setVisible(true);
		}
		else{
			littleExitBtn->setVisible(true);
			littleExitBtn_->setVisible(false);
		}
	}

    Rect fbBtnRect = fbBtn->getBoundingBox();
    if (isFbBtnTouched == true){
        if (fbBtnRect.containsPoint(loc)){
            fbBtn->setVisible(false);
            fbBtn_->setVisible(true);
        }
        else{
            fbBtn->setVisible(true);
            fbBtn_->setVisible(false);
        }
    }

	if (isExitResumeBtnTouched == true){
		if (exitResumeBtnRect.containsPoint(loc)){
			exitResumeBtn->setVisible(false);
			exitResumeBtn_->setVisible(true);
		}
		else{
			exitResumeBtn->setVisible(true);
			exitResumeBtn_->setVisible(false);
		}
	}

	//////

	if (isGameStartBtnTouched == true){
		if (mungGuGameStartBtnRect.containsPoint(loc)){
			gameStartBtn->setVisible(false);
			gameStartBtn_->setVisible(true);
		}
		else{
			gameStartBtn->setVisible(true);
			gameStartBtn_->setVisible(false);
		}
	}


	if (isMungStoreBtnTouched == true){
		if (mungStoreBtnRect.containsPoint(loc)){
			mungStoreBtn->setVisible(false);
			mungStoreBtn_->setVisible(true);
		}
		else{
			mungStoreBtn->setVisible(true);
			mungStoreBtn_->setVisible(false);
		}
	}

	if (isUnitBtnTouched == true){
		if (unitBtnRect.containsPoint(loc)){
			unitBtn->setVisible(false);
			unitBtn_->setVisible(true);
		}
		else{
			unitBtn->setVisible(true);
			unitBtn_->setVisible(false);
		}
	}

	if (isMissionBtnTouched == true){
		if (missionBtnRect.containsPoint(loc)){
			missionBtn->setVisible(false);
			missionBtn_->setVisible(true);
		}
		else{
			missionBtn->setVisible(true);
			missionBtn_->setVisible(false);
		}
	}

	if (isInfoBtnTouched == true){
		if (isInfo == false){
			CCLOG("info");
			if (infoBtnRect.containsPoint(loc)){
				infoBtn->setVisible(false);
				infoBtn_->setVisible(true);
			}
			else{
				infoBtn->setVisible(true);
				infoBtn_->setVisible(false);
			}
		}
	}


	if (isInfoExitBtnTouched == true){
		if (isInfo == true){
			if (infoExitBtnRect.containsPoint(loc)){
				infoExitBtn->setVisible(false);
				infoExitBtn_->setVisible(true);
			}
			else{
				infoExitBtn->setVisible(true);
				infoExitBtn_->setVisible(false);
			}
		}
	}
    
    //소리 설정
    if (isSongBtnTouched == true){
        
        if (isSongBtnRect.containsPoint(loc)){
            
            if (isNotSongBtnTouched == false){
                isSongBtn->setVisible(false);
                isSongBtn_->setVisible(true);
                isNotSongBtn->setVisible(false);
                isNotSongBtn_->setVisible(false);
            }
            else{
                isSongBtn->setVisible(false);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(false);
                isNotSongBtn_->setVisible(true);
            }
        }else{
            if (isNotSongBtnTouched == false){
                isSongBtn->setVisible(true);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(false);
                isNotSongBtn_->setVisible(false);
            }
            else{
                isSongBtn->setVisible(false);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(true);
                isNotSongBtn_->setVisible(false);
            }
        }
    }
}

void MungGuGameMenuScene::onTouchEnded(Touch *touch, Event *unused_event){
	Point loc = touch->getLocation();

  
    
    //intro
    if(isIntroWindow==true){
        introExitBtn->setVisible(true);
        introExitBtn_->setVisible(false);
        if(introExitBtnRect.containsPoint(loc)){
            isIntroWindow=false;
            introExitBtn->setVisible(false);
            introWindow->setVisible(false);
            introWindowEng->setVisible(false);
            isIntroWindow2=false;
            introExitBtn->setVisible(false);
            introWindow2->setVisible(false);
            introWindow2Eng->setVisible(false);
        }
    }
    
//    //intro2
//    if(isIntroWindow2==true){
//        introExitBtn->setVisible(true);
//        introExitBtn_->setVisible(false);
//        if(introExitBtnRect.containsPoint(loc)){
//            isIntroWindow2=false;
//            introExitBtn->setVisible(false);
//            introWindow2->setVisible(false);
//            introWindow2Eng->setVisible(false);
//        }
//    }
    
    //스테이지 대체
    //upperReplaceBtn
        
    if(isUpperReplaceBtnTouched == true){
        Rect upperReplaceBtnRect = upperReplaceBtn->getBoundingBox();
        
        isUpperReplaceBtnTouched = false;
        if ((upperReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)){
           // setStage();
            setStageSelectBtns();
            
            bottomReplaceBtn->setVisible(true);
            bottomReplaceBtn_->setVisible(false);
            
            stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
            if(stageIndex > stageIndexMin){//1일때 감소 가능
            //상위 5스테이지로 이동 인덱스 증가

                UserDefault::getInstance()->setIntegerForKey("stageIndex", stageIndex-1);
                stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
                ///감소 후에 최소 인덱스에 도달하면
                if(stageIndexMin==stageIndex){
                upperReplaceBtn->setVisible(false);
                upperReplaceBtn_->setVisible(true);
                }else{
                    upperReplaceBtn->setVisible(true);//아직 누를 수 있으면
                    upperReplaceBtn_->setVisible(false);

                }
            }
        }
         stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
        //스테이지 변경 내역을 갱신
        hideStageSelectBtns();//다 지운 후, 나와야하는 스테이지만 보여짐.
        setStageSelectBtns();
        
        //////////
        if(stageIndex == 0){
            
            stage1_selectBtn->setVisible(true);
            stage1_Info->setVisible(true);
            revangeStart->setVisible(true);
            
            
            if(stage1_clearCount==0){
                stage2_selectBtn->setVisible(false);
                stage2_keepGoing->setVisible(false);
                stage2_Info->setVisible(false);
            }else{
                stage2_selectBtn->setVisible(true);
                stage2_keepGoing->setVisible(true);
                stage2_Info->setVisible(true);
            }
            ///2///
            if(stage2_clearCount==0){
                stage3_3rd->setVisible(false);
                stage3_Info->setVisible(false);
                stage3_selectBtn->setVisible(false);
            }else{
                stage3_3rd->setVisible(true);
                stage3_Info->setVisible(true);
                stage3_selectBtn->setVisible(true);
            }
            ///3///
            if(stage3_clearCount==0){
                stage4_Info->setVisible(false);
                stage4_NeverDie->setVisible(false);
                stage4_selectBtn->setVisible(false);
            }else{
                stage4_Info->setVisible(true);
                stage4_NeverDie->setVisible(true);
                stage4_selectBtn->setVisible(true);
            }///4///
            if(stage4_clearCount==0){
                stage5_->setVisible(false);
                stage5_Info->setVisible(false);
                stage5_selectBtn->setVisible(false);
            }else{
                stage5_->setVisible(true);
                stage5_Info->setVisible(true);
                stage5_selectBtn->setVisible(true);
            }
     

            
            
        }else if(stageIndex == 1){
            
          
            ///5///
            if(stage5_clearCount==0){
                stage6_->setVisible(false);
                stage6_Info->setVisible(false);
                stage6_selectBtn->setVisible(false);
            }else{
                stage6_->setVisible(true);
                stage6_Info->setVisible(true);
                stage6_selectBtn->setVisible(true);
            }
            ///6///
            if(stage6_clearCount==0){
                stage7_->setVisible(false);
                stage7_Info->setVisible(false);
                stage7_selectBtn->setVisible(false);
            }else{
                stage7_->setVisible(true);
                stage7_Info->setVisible(true);
                stage7_selectBtn->setVisible(true);
            }
            ///7///
            if(stage7_clearCount==0){
                stage8_->setVisible(false);
                stage8_Info->setVisible(false);
                stage8_selectBtn->setVisible(false);
            }else{
                stage8_->setVisible(true);
                stage8_Info->setVisible(true);
                stage8_selectBtn->setVisible(true);
            }
            ///8///
            if(stage8_clearCount==0){
                stage9_->setVisible(false);
                stage9_Info->setVisible(false);
                stage9_selectBtn->setVisible(false);
            }else{
                stage9_->setVisible(true);
                stage9_Info->setVisible(true);
                stage9_selectBtn->setVisible(true);
            }
            ///9///
            if(stage9_clearCount==0){
                stage10_->setVisible(false);
                stage10_Info->setVisible(false);
                stage10_selectBtn->setVisible(false);
            }else{
                stage10_->setVisible(true);
                stage10_Info->setVisible(true);
                stage10_selectBtn->setVisible(true);
            }
      

        }else if(stageIndex == 2){
         
            ///10///
            if(stage10_clearCount==0){
                stage11_->setVisible(false);
                stage11_Info->setVisible(false);
                stage11_selectBtn->setVisible(false);
            }else{
                stage11_->setVisible(true);
                stage11_Info->setVisible(true);
                stage11_selectBtn->setVisible(true);
            }
            ///11///
            if(stage11_clearCount==0){
                stage12_->setVisible(false);
                stage12_Info->setVisible(false);
                stage12_selectBtn->setVisible(false);
            }else{
                stage12_->setVisible(true);
                stage12_Info->setVisible(true);
                stage12_selectBtn->setVisible(true);
            }
            ///12///
            if(stage12_clearCount==0){
                stage13_->setVisible(false);
                stage13_Info->setVisible(false);
                stage13_selectBtn->setVisible(false);
            }else{
                stage13_->setVisible(true);
                stage13_Info->setVisible(true);
                stage13_selectBtn->setVisible(true);
            }
            ///13///
            if(stage13_clearCount==0){
                stage14_->setVisible(false);
                stage14_Info->setVisible(false);
                stage14_selectBtn->setVisible(false);
            }else{
                stage14_->setVisible(true);
                stage14_Info->setVisible(true);
                stage14_selectBtn->setVisible(true);
            }
            ///14///
            if(stage14_clearCount==0){
                stage15_->setVisible(false);
                stage15_Info->setVisible(false);
                stage15_selectBtn->setVisible(false);
            }else{
                stage15_->setVisible(true);
                stage15_Info->setVisible(true);
                stage15_selectBtn->setVisible(true);
            }


        }else if(stageIndex == 3){
          
            ///15///
            if(stage15_clearCount==0){
                stage16_->setVisible(false);
                stage16_Info->setVisible(false);
                stage16_selectBtn->setVisible(false);
            }else{
              //  stageIndexMax=3;//16~20이동 가능
                stage16_->setVisible(true);
                stage16_Info->setVisible(true);
                stage16_selectBtn->setVisible(true);
            }
            ///16///
            if(stage16_clearCount==0){
                stage17_->setVisible(false);
                stage17_Info->setVisible(false);
                stage17_selectBtn->setVisible(false);
            }else{
                stage17_->setVisible(true);
                stage17_Info->setVisible(true);
                stage17_selectBtn->setVisible(true);
            }
            ///17///
            if(stage17_clearCount==0){
                stage18_->setVisible(false);
                stage18_Info->setVisible(false);
                stage18_selectBtn->setVisible(false);
            }else{
                stage18_->setVisible(true);
                stage18_Info->setVisible(true);
                stage18_selectBtn->setVisible(true);
            }
            ///18///
            if(stage18_clearCount==0){
                stage19_->setVisible(false);
                stage19_Info->setVisible(false);
                stage19_selectBtn->setVisible(false);
            }else{
                stage19_->setVisible(true);
                stage19_Info->setVisible(true);
                stage19_selectBtn->setVisible(true);
            }
            ///19///
            if(stage19_clearCount==0){
                stage20_->setVisible(false);
                stage20_Info->setVisible(false);
                stage20_selectBtn->setVisible(false);
            }else{
                stage20_->setVisible(true);
                stage20_Info->setVisible(true);
                stage20_selectBtn->setVisible(true);
            }
            

        }else if(stageIndex == 4){
            
            ///20///
            if(stage20_clearCount==0){
                stage21_->setVisible(false);
                stage21_Info->setVisible(false);
                stage21_selectBtn->setVisible(false);
            }else{
                stage21_->setVisible(true);
                stage21_Info->setVisible(true);
                stage21_selectBtn->setVisible(true);
            }
            ///11///
            if(stage21_clearCount==0){
                stage22_->setVisible(false);
                stage22_Info->setVisible(false);
                stage22_selectBtn->setVisible(false);
            }else{
                stage22_->setVisible(true);
                stage22_Info->setVisible(true);
                stage22_selectBtn->setVisible(true);
            }
            ///12///
            if(stage22_clearCount==0){
                stage23_->setVisible(false);
                stage23_Info->setVisible(false);
                stage23_selectBtn->setVisible(false);
            }else{
                stage23_->setVisible(true);
                stage23_Info->setVisible(true);
                stage23_selectBtn->setVisible(true);
            }
            ///13///
            if(stage23_clearCount==0){
                stage24_->setVisible(false);
                stage24_Info->setVisible(false);
                stage24_selectBtn->setVisible(false);
            }else{
                stage24_->setVisible(true);
                stage24_Info->setVisible(true);
                stage24_selectBtn->setVisible(true);
            }
            ///14///
            if(stage24_clearCount==0){
                stage25_->setVisible(false);
                stage25_Info->setVisible(false);
                stage25_selectBtn->setVisible(false);
            }else{
                stage25_->setVisible(true);
                stage25_Info->setVisible(true);
                stage25_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 5){
            
            ///15///
            if(stage25_clearCount==0){
                stage26_->setVisible(false);
                stage26_Info->setVisible(false);
                stage26_selectBtn->setVisible(false);
            }else{
                //stageIndexMax=5;//16~20이동 가능
                stage26_->setVisible(true);
                stage26_Info->setVisible(true);
                stage26_selectBtn->setVisible(true);
            }
            ///16///
            if(stage26_clearCount==0){
                stage27_->setVisible(false);
                stage27_Info->setVisible(false);
                stage27_selectBtn->setVisible(false);
            }else{
                stage27_->setVisible(true);
                stage27_Info->setVisible(true);
                stage27_selectBtn->setVisible(true);
            }
            ///17///
            if(stage27_clearCount==0){
                stage28_->setVisible(false);
                stage28_Info->setVisible(false);
                stage28_selectBtn->setVisible(false);
            }else{
                stage28_->setVisible(true);
                stage28_Info->setVisible(true);
                stage28_selectBtn->setVisible(true);
            }
            ///18///
            if(stage28_clearCount==0){
                stage29_->setVisible(false);
                stage29_Info->setVisible(false);
                stage29_selectBtn->setVisible(false);
            }else{
                stage29_->setVisible(true);
                stage29_Info->setVisible(true);
                stage29_selectBtn->setVisible(true);
            }
            ///19///
            if(stage29_clearCount==0){
                stage30_->setVisible(false);
                stage30_Info->setVisible(false);
                stage30_selectBtn->setVisible(false);
            }else{
                stage30_->setVisible(true);
                stage30_Info->setVisible(true);
                stage30_selectBtn->setVisible(true);
            }
        }else if(stageIndex == 6){
            
            ///30///
            if(stage30_clearCount==0){
                stage31_->setVisible(false);
                stage31_Info->setVisible(false);
                stage31_selectBtn->setVisible(false);
            }else{
                stage31_->setVisible(true);
                stage31_Info->setVisible(true);
                stage31_selectBtn->setVisible(true);
            }
            ///31///
            if(stage31_clearCount==0){
                stage32_->setVisible(false);
                stage32_Info->setVisible(false);
                stage32_selectBtn->setVisible(false);
            }else{
                stage32_->setVisible(true);
                stage32_Info->setVisible(true);
                stage32_selectBtn->setVisible(true);
            }
            ///32///
            if(stage32_clearCount==0){
                stage33_->setVisible(false);
                stage33_Info->setVisible(false);
                stage33_selectBtn->setVisible(false);
            }else{
                stage33_->setVisible(true);
                stage33_Info->setVisible(true);
                stage33_selectBtn->setVisible(true);
            }
            ///13///
            if(stage33_clearCount==0){
                stage34_->setVisible(false);
                stage34_Info->setVisible(false);
                stage34_selectBtn->setVisible(false);
            }else{
                stage34_->setVisible(true);
                stage34_Info->setVisible(true);
                stage34_selectBtn->setVisible(true);
            }
            ///34///
            if(stage34_clearCount==0){
                stage35_->setVisible(false);
                stage35_Info->setVisible(false);
                stage35_selectBtn->setVisible(false);
            }else{
                stage35_->setVisible(true);
                stage35_Info->setVisible(true);
                stage35_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 7){
            
            ///35///
            if(stage35_clearCount==0){
                stage36_->setVisible(false);
                stage36_Info->setVisible(false);
                stage36_selectBtn->setVisible(false);
            }else{
                stage36_->setVisible(true);
                stage36_Info->setVisible(true);
                stage36_selectBtn->setVisible(true);
            }
            ///36///
            if(stage36_clearCount==0){
                stage37_->setVisible(false);
                stage37_Info->setVisible(false);
                stage37_selectBtn->setVisible(false);
            }else{
                stage37_->setVisible(true);
                stage37_Info->setVisible(true);
                stage37_selectBtn->setVisible(true);
            }
            ///37///
            if(stage37_clearCount==0){
                stage38_->setVisible(false);
                stage38_Info->setVisible(false);
                stage38_selectBtn->setVisible(false);
            }else{
                stage38_->setVisible(true);
                stage38_Info->setVisible(true);
                stage38_selectBtn->setVisible(true);
            }
            ///38///
            if(stage38_clearCount==0){
                stage39_->setVisible(false);
                stage39_Info->setVisible(false);
                stage39_selectBtn->setVisible(false);
            }else{
                stage39_->setVisible(true);
                stage39_Info->setVisible(true);
                stage39_selectBtn->setVisible(true);
            }
            ///39///
            if(stage39_clearCount==0){
                stage40_->setVisible(false);
                stage40_Info->setVisible(false);
                stage40_selectBtn->setVisible(false);
            }else{
                stage40_->setVisible(true);
                stage40_Info->setVisible(true);
                stage40_selectBtn->setVisible(true);
            }
        }else if(stageIndex == 8){
            
            ///40///
            if(stage40_clearCount==0){
                stage41_->setVisible(false);
                stage41_Info->setVisible(false);
                stage41_selectBtn->setVisible(false);
            }else{
                stage41_->setVisible(true);
                stage41_Info->setVisible(true);
                stage41_selectBtn->setVisible(true);
            }
            ///41///
            if(stage41_clearCount==0){
                stage42_->setVisible(false);
                stage42_Info->setVisible(false);
                stage42_selectBtn->setVisible(false);
            }else{
                stage42_->setVisible(true);
                stage42_Info->setVisible(true);
                stage42_selectBtn->setVisible(true);
            }
            ///42///
            if(stage42_clearCount==0){
                stage43_->setVisible(false);
                stage43_Info->setVisible(false);
                stage43_selectBtn->setVisible(false);
            }else{
                stage43_->setVisible(true);
                stage43_Info->setVisible(true);
                stage43_selectBtn->setVisible(true);
            }
            ///43///
            if(stage43_clearCount==0){
                stage44_->setVisible(false);
                stage44_Info->setVisible(false);
                stage44_selectBtn->setVisible(false);
            }else{
                stage44_->setVisible(true);
                stage44_Info->setVisible(true);
                stage44_selectBtn->setVisible(true);
            }
            ///44///
            if(stage44_clearCount==0){
                stage45_->setVisible(false);
                stage45_Info->setVisible(false);
                stage45_selectBtn->setVisible(false);
            }else{
                stage45_->setVisible(true);
                stage45_Info->setVisible(true);
                stage45_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 9){
            
            ///45///
            if(stage45_clearCount==0){
                stage46_->setVisible(false);
                stage46_Info->setVisible(false);
                stage46_selectBtn->setVisible(false);
            }else{
                //stageIndexMax=5;//16~20이동 가능
                stage46_->setVisible(true);
                stage46_Info->setVisible(true);
                stage46_selectBtn->setVisible(true);
            }
            ///46///
            if(stage46_clearCount==0){
                stage47_->setVisible(false);
                stage47_Info->setVisible(false);
                stage47_selectBtn->setVisible(false);
            }else{
                stage47_->setVisible(true);
                stage47_Info->setVisible(true);
                stage47_selectBtn->setVisible(true);
            }
            ///47///
            if(stage47_clearCount==0){
                stage48_->setVisible(false);
                stage48_Info->setVisible(false);
                stage48_selectBtn->setVisible(false);
            }else{
                stage48_->setVisible(true);
                stage48_Info->setVisible(true);
                stage48_selectBtn->setVisible(true);
            }
            ///48///
            if(stage48_clearCount==0){
                stage49_->setVisible(false);
                stage49_Info->setVisible(false);
                stage49_selectBtn->setVisible(false);
            }else{
                stage49_->setVisible(true);
                stage49_Info->setVisible(true);
                stage49_selectBtn->setVisible(true);
            }
            ///49///
            if(stage49_clearCount==0){
                stage50_->setVisible(false);
                stage50_Info->setVisible(false);
                stage50_selectBtn->setVisible(false);
            }else{
                stage50_->setVisible(true);
                stage50_Info->setVisible(true);
                stage50_selectBtn->setVisible(true);
            }
        }
        //////////////////
    }
    
    Rect bottomReplaceBtnRect = bottomReplaceBtn->getBoundingBox();
    if(isBottomReplaceBtnTouched==true){
        isBottomReplaceBtnTouched = false;

        if ((bottomReplaceBtnRect.containsPoint(loc)) && (isInfo == false) && (isExitWindow == false)){//씬 이동
            //setStage();
            setStageSelectBtns();
            
            upperReplaceBtn->setVisible(true);
            upperReplaceBtn_->setVisible(false);
            //하위 5스테이지로 이동, 인덱스 증가
            stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
            if(stageIndex < stageIndexMax){//0일때 증가 가능
            UserDefault::getInstance()->setIntegerForKey("stageIndex", stageIndex+1);
                //증가 후에 최대 인덱스에 도달 하면,
                stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
                 if(stageIndex == stageIndexMax){
                bottomReplaceBtn->setVisible(false);
                bottomReplaceBtn_->setVisible(true);
                 }else{
                     bottomReplaceBtn->setVisible(true);
                     bottomReplaceBtn_->setVisible(false);
                 }
            }
        }
         stageIndex = UserDefault::getInstance()->getIntegerForKey("stageIndex");
        //스테이지 변경 내역을 갱신
        hideStageSelectBtns();//다 지운 후, 나와야하는 스테이지만 보여짐.
        setStageSelectBtns();
        //////////
        if(stageIndex == 0){
            
            stage1_selectBtn->setVisible(true);
            stage1_Info->setVisible(true);
            revangeStart->setVisible(true);
            
            
            if(stage1_clearCount==0){
                stage2_selectBtn->setVisible(false);
                stage2_keepGoing->setVisible(false);
                stage2_Info->setVisible(false);
            }else{
                stage2_selectBtn->setVisible(true);
                stage2_keepGoing->setVisible(true);
                stage2_Info->setVisible(true);
            }
            ///2///
            if(stage2_clearCount==0){
                stage3_3rd->setVisible(false);
                stage3_Info->setVisible(false);
                stage3_selectBtn->setVisible(false);
            }else{
                stage3_3rd->setVisible(true);
                stage3_Info->setVisible(true);
                stage3_selectBtn->setVisible(true);
            }
            ///3///
            if(stage3_clearCount==0){
                stage4_Info->setVisible(false);
                stage4_NeverDie->setVisible(false);
                stage4_selectBtn->setVisible(false);
            }else{
                stage4_Info->setVisible(true);
                stage4_NeverDie->setVisible(true);
                stage4_selectBtn->setVisible(true);
            }///4///
            if(stage4_clearCount==0){
                stage5_->setVisible(false);
                stage5_Info->setVisible(false);
                stage5_selectBtn->setVisible(false);
            }else{
                stage5_->setVisible(true);
                stage5_Info->setVisible(true);
                stage5_selectBtn->setVisible(true);
            }
            
            
            
            
        }else if(stageIndex == 1){
            
            
            ///5///
            if(stage5_clearCount==0){
                stage6_->setVisible(false);
                stage6_Info->setVisible(false);
                stage6_selectBtn->setVisible(false);
            }else{
                stage6_->setVisible(true);
                stage6_Info->setVisible(true);
                stage6_selectBtn->setVisible(true);
            }
            ///6///
            if(stage6_clearCount==0){
                stage7_->setVisible(false);
                stage7_Info->setVisible(false);
                stage7_selectBtn->setVisible(false);
            }else{
                stage7_->setVisible(true);
                stage7_Info->setVisible(true);
                stage7_selectBtn->setVisible(true);
            }
            ///7///
            if(stage7_clearCount==0){
                stage8_->setVisible(false);
                stage8_Info->setVisible(false);
                stage8_selectBtn->setVisible(false);
            }else{
                stage8_->setVisible(true);
                stage8_Info->setVisible(true);
                stage8_selectBtn->setVisible(true);
            }
            ///8///
            if(stage8_clearCount==0){
                stage9_->setVisible(false);
                stage9_Info->setVisible(false);
                stage9_selectBtn->setVisible(false);
            }else{
                stage9_->setVisible(true);
                stage9_Info->setVisible(true);
                stage9_selectBtn->setVisible(true);
            }
            ///9///
            if(stage9_clearCount==0){
                stage10_->setVisible(false);
                stage10_Info->setVisible(false);
                stage10_selectBtn->setVisible(false);
            }else{
                stage10_->setVisible(true);
                stage10_Info->setVisible(true);
                stage10_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 2){
            
            ///10///
            if(stage10_clearCount==0){
                stage11_->setVisible(false);
                stage11_Info->setVisible(false);
                stage11_selectBtn->setVisible(false);
            }else{
                stage11_->setVisible(true);
                stage11_Info->setVisible(true);
                stage11_selectBtn->setVisible(true);
            }
            ///11///
            if(stage11_clearCount==0){
                stage12_->setVisible(false);
                stage12_Info->setVisible(false);
                stage12_selectBtn->setVisible(false);
            }else{
                stage12_->setVisible(true);
                stage12_Info->setVisible(true);
                stage12_selectBtn->setVisible(true);
            }
            ///12///
            if(stage12_clearCount==0){
                stage13_->setVisible(false);
                stage13_Info->setVisible(false);
                stage13_selectBtn->setVisible(false);
            }else{
                stage13_->setVisible(true);
                stage13_Info->setVisible(true);
                stage13_selectBtn->setVisible(true);
            }
            ///13///
            if(stage13_clearCount==0){
                stage14_->setVisible(false);
                stage14_Info->setVisible(false);
                stage14_selectBtn->setVisible(false);
            }else{
                stage14_->setVisible(true);
                stage14_Info->setVisible(true);
                stage14_selectBtn->setVisible(true);
            }
            ///14///
            if(stage14_clearCount==0){
                stage15_->setVisible(false);
                stage15_Info->setVisible(false);
                stage15_selectBtn->setVisible(false);
            }else{
                stage15_->setVisible(true);
                stage15_Info->setVisible(true);
                stage15_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 3){
            
            ///15///
            if(stage15_clearCount==0){
                stage16_->setVisible(false);
                stage16_Info->setVisible(false);
                stage16_selectBtn->setVisible(false);
            }else{
                //  stageIndexMax=3;//16~20이동 가능
                stage16_->setVisible(true);
                stage16_Info->setVisible(true);
                stage16_selectBtn->setVisible(true);
            }
            ///16///
            if(stage16_clearCount==0){
                stage17_->setVisible(false);
                stage17_Info->setVisible(false);
                stage17_selectBtn->setVisible(false);
            }else{
                stage17_->setVisible(true);
                stage17_Info->setVisible(true);
                stage17_selectBtn->setVisible(true);
            }
            ///17///
            if(stage17_clearCount==0){
                stage18_->setVisible(false);
                stage18_Info->setVisible(false);
                stage18_selectBtn->setVisible(false);
            }else{
                stage18_->setVisible(true);
                stage18_Info->setVisible(true);
                stage18_selectBtn->setVisible(true);
            }
            ///18///
            if(stage18_clearCount==0){
                stage19_->setVisible(false);
                stage19_Info->setVisible(false);
                stage19_selectBtn->setVisible(false);
            }else{
                stage19_->setVisible(true);
                stage19_Info->setVisible(true);
                stage19_selectBtn->setVisible(true);
            }
            ///19///
            if(stage19_clearCount==0){
                stage20_->setVisible(false);
                stage20_Info->setVisible(false);
                stage20_selectBtn->setVisible(false);
            }else{
                stage20_->setVisible(true);
                stage20_Info->setVisible(true);
                stage20_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 4){
            
            ///20///
            if(stage20_clearCount==0){
                stage21_->setVisible(false);
                stage21_Info->setVisible(false);
                stage21_selectBtn->setVisible(false);
            }else{
                stage21_->setVisible(true);
                stage21_Info->setVisible(true);
                stage21_selectBtn->setVisible(true);
            }
            ///11///
            if(stage21_clearCount==0){
                stage22_->setVisible(false);
                stage22_Info->setVisible(false);
                stage22_selectBtn->setVisible(false);
            }else{
                stage22_->setVisible(true);
                stage22_Info->setVisible(true);
                stage22_selectBtn->setVisible(true);
            }
            ///12///
            if(stage22_clearCount==0){
                stage23_->setVisible(false);
                stage23_Info->setVisible(false);
                stage23_selectBtn->setVisible(false);
            }else{
                stage23_->setVisible(true);
                stage23_Info->setVisible(true);
                stage23_selectBtn->setVisible(true);
            }
            ///13///
            if(stage23_clearCount==0){
                stage24_->setVisible(false);
                stage24_Info->setVisible(false);
                stage24_selectBtn->setVisible(false);
            }else{
                stage24_->setVisible(true);
                stage24_Info->setVisible(true);
                stage24_selectBtn->setVisible(true);
            }
            ///14///
            if(stage24_clearCount==0){
                stage25_->setVisible(false);
                stage25_Info->setVisible(false);
                stage25_selectBtn->setVisible(false);
            }else{
                stage25_->setVisible(true);
                stage25_Info->setVisible(true);
                stage25_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 5){
            
            ///15///
            if(stage25_clearCount==0){
                stage26_->setVisible(false);
                stage26_Info->setVisible(false);
                stage26_selectBtn->setVisible(false);
            }else{
                //stageIndexMax=5;//16~20이동 가능
                stage26_->setVisible(true);
                stage26_Info->setVisible(true);
                stage26_selectBtn->setVisible(true);
            }
            ///16///
            if(stage26_clearCount==0){
                stage27_->setVisible(false);
                stage27_Info->setVisible(false);
                stage27_selectBtn->setVisible(false);
            }else{
                stage27_->setVisible(true);
                stage27_Info->setVisible(true);
                stage27_selectBtn->setVisible(true);
            }
            ///17///
            if(stage27_clearCount==0){
                stage28_->setVisible(false);
                stage28_Info->setVisible(false);
                stage28_selectBtn->setVisible(false);
            }else{
                stage28_->setVisible(true);
                stage28_Info->setVisible(true);
                stage28_selectBtn->setVisible(true);
            }
            ///18///
            if(stage28_clearCount==0){
                stage29_->setVisible(false);
                stage29_Info->setVisible(false);
                stage29_selectBtn->setVisible(false);
            }else{
                stage29_->setVisible(true);
                stage29_Info->setVisible(true);
                stage29_selectBtn->setVisible(true);
            }
            ///19///
            if(stage29_clearCount==0){
                stage30_->setVisible(false);
                stage30_Info->setVisible(false);
                stage30_selectBtn->setVisible(false);
            }else{
                stage30_->setVisible(true);
                stage30_Info->setVisible(true);
                stage30_selectBtn->setVisible(true);
            }
        }else if(stageIndex == 6){
            
            ///30///
            if(stage30_clearCount==0){
                stage31_->setVisible(false);
                stage31_Info->setVisible(false);
                stage31_selectBtn->setVisible(false);
            }else{
                stage31_->setVisible(true);
                stage31_Info->setVisible(true);
                stage31_selectBtn->setVisible(true);
            }
            ///31///
            if(stage31_clearCount==0){
                stage32_->setVisible(false);
                stage32_Info->setVisible(false);
                stage32_selectBtn->setVisible(false);
            }else{
                stage32_->setVisible(true);
                stage32_Info->setVisible(true);
                stage32_selectBtn->setVisible(true);
            }
            ///32///
            if(stage32_clearCount==0){
                stage33_->setVisible(false);
                stage33_Info->setVisible(false);
                stage33_selectBtn->setVisible(false);
            }else{
                stage33_->setVisible(true);
                stage33_Info->setVisible(true);
                stage33_selectBtn->setVisible(true);
            }
            ///13///
            if(stage33_clearCount==0){
                stage34_->setVisible(false);
                stage34_Info->setVisible(false);
                stage34_selectBtn->setVisible(false);
            }else{
                stage34_->setVisible(true);
                stage34_Info->setVisible(true);
                stage34_selectBtn->setVisible(true);
            }
            ///34///
            if(stage34_clearCount==0){
                stage35_->setVisible(false);
                stage35_Info->setVisible(false);
                stage35_selectBtn->setVisible(false);
            }else{
                stage35_->setVisible(true);
                stage35_Info->setVisible(true);
                stage35_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 7){
            
            ///35///
            if(stage35_clearCount==0){
                stage36_->setVisible(false);
                stage36_Info->setVisible(false);
                stage36_selectBtn->setVisible(false);
            }else{
                stage36_->setVisible(true);
                stage36_Info->setVisible(true);
                stage36_selectBtn->setVisible(true);
            }
            ///36///
            if(stage36_clearCount==0){
                stage37_->setVisible(false);
                stage37_Info->setVisible(false);
                stage37_selectBtn->setVisible(false);
            }else{
                stage37_->setVisible(true);
                stage37_Info->setVisible(true);
                stage37_selectBtn->setVisible(true);
            }
            ///37///
            if(stage37_clearCount==0){
                stage38_->setVisible(false);
                stage38_Info->setVisible(false);
                stage38_selectBtn->setVisible(false);
            }else{
                stage38_->setVisible(true);
                stage38_Info->setVisible(true);
                stage38_selectBtn->setVisible(true);
            }
            ///38///
            if(stage38_clearCount==0){
                stage39_->setVisible(false);
                stage39_Info->setVisible(false);
                stage39_selectBtn->setVisible(false);
            }else{
                stage39_->setVisible(true);
                stage39_Info->setVisible(true);
                stage39_selectBtn->setVisible(true);
            }
            ///39///
            if(stage39_clearCount==0){
                stage40_->setVisible(false);
                stage40_Info->setVisible(false);
                stage40_selectBtn->setVisible(false);
            }else{
                stage40_->setVisible(true);
                stage40_Info->setVisible(true);
                stage40_selectBtn->setVisible(true);
            }
        }else if(stageIndex == 8){
            
            ///40///
            if(stage40_clearCount==0){
                stage41_->setVisible(false);
                stage41_Info->setVisible(false);
                stage41_selectBtn->setVisible(false);
            }else{
                stage41_->setVisible(true);
                stage41_Info->setVisible(true);
                stage41_selectBtn->setVisible(true);
            }
            ///41///
            if(stage41_clearCount==0){
                stage42_->setVisible(false);
                stage42_Info->setVisible(false);
                stage42_selectBtn->setVisible(false);
            }else{
                stage42_->setVisible(true);
                stage42_Info->setVisible(true);
                stage42_selectBtn->setVisible(true);
            }
            ///42///
            if(stage42_clearCount==0){
                stage43_->setVisible(false);
                stage43_Info->setVisible(false);
                stage43_selectBtn->setVisible(false);
            }else{
                stage43_->setVisible(true);
                stage43_Info->setVisible(true);
                stage43_selectBtn->setVisible(true);
            }
            ///43///
            if(stage43_clearCount==0){
                stage44_->setVisible(false);
                stage44_Info->setVisible(false);
                stage44_selectBtn->setVisible(false);
            }else{
                stage44_->setVisible(true);
                stage44_Info->setVisible(true);
                stage44_selectBtn->setVisible(true);
            }
            ///44///
            if(stage44_clearCount==0){
                stage45_->setVisible(false);
                stage45_Info->setVisible(false);
                stage45_selectBtn->setVisible(false);
            }else{
                stage45_->setVisible(true);
                stage45_Info->setVisible(true);
                stage45_selectBtn->setVisible(true);
            }
            
            
        }else if(stageIndex == 9){
            
            ///45///
            if(stage45_clearCount==0){
                stage46_->setVisible(false);
                stage46_Info->setVisible(false);
                stage46_selectBtn->setVisible(false);
            }else{
                //stageIndexMax=5;//16~20이동 가능
                stage46_->setVisible(true);
                stage46_Info->setVisible(true);
                stage46_selectBtn->setVisible(true);
            }
            ///46///
            if(stage46_clearCount==0){
                stage47_->setVisible(false);
                stage47_Info->setVisible(false);
                stage47_selectBtn->setVisible(false);
            }else{
                stage47_->setVisible(true);
                stage47_Info->setVisible(true);
                stage47_selectBtn->setVisible(true);
            }
            ///47///
            if(stage47_clearCount==0){
                stage48_->setVisible(false);
                stage48_Info->setVisible(false);
                stage48_selectBtn->setVisible(false);
            }else{
                stage48_->setVisible(true);
                stage48_Info->setVisible(true);
                stage48_selectBtn->setVisible(true);
            }
            ///48///
            if(stage48_clearCount==0){
                stage49_->setVisible(false);
                stage49_Info->setVisible(false);
                stage49_selectBtn->setVisible(false);
            }else{
                stage49_->setVisible(true);
                stage49_Info->setVisible(true);
                stage49_selectBtn->setVisible(true);
            }
            ///49///
            if(stage49_clearCount==0){
                stage50_->setVisible(false);
                stage50_Info->setVisible(false);
                stage50_selectBtn->setVisible(false);
            }else{
                stage50_->setVisible(true);
                stage50_Info->setVisible(true);
                stage50_selectBtn->setVisible(true);
            }
        }
        //////////////////
    }
    
    
    
    
    
    
    Rect fbBtnRect = fbBtn->getBoundingBox();
    if(isFbBtnTouched == true){
        fbBtn->setVisible(true);
        fbBtn_->setVisible(false);
        if(fbBtnRect.containsPoint(loc)){
            
            //인트로 버튼임 그냥.
            isIntroWindow = true;
            if(initByEnglish==false){
            introWindow->setVisible(true);
            }else{
                introWindowEng->setVisible(true);
            }
            introExitBtn->setVisible(true);
            introExitBtn_->setVisible(false);
            
            
        }
    }
    
    if(isIntroWindow2==true){
        isIntroWindow2=false;
        if(introExitBtnRect.containsPoint(loc)){
            introExitBtn->setVisible(false);
            introExitBtn_->setVisible(false);
            introWindow2->setVisible(false);
            introWindow2Eng->setVisible(false);
        }
    }

	if (isGameStartBtnTouched == true){

		CCLOG("GameStart");
		gameStartBtn->setVisible(true);
		gameStartBtn_->setVisible(false);
		isGameStartBtnTouched = false;

		if (mungGuGameStartBtnRect.containsPoint(loc)){
			//isGameStartBtnTouchEnded = true;
			//Game Start
			
			//음악 메모리 해제

		//	changeGameMenuScene(this);
            
            if(isStageSelected == true){
            Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
            SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
            initgameStartEvent();
            }else{

            }
            

		}


	}
    
   


	if (isLittleExitBtnTouched == true){

		littleExitBtn->setVisible(true);
		littleExitBtn_->setVisible(false);
		isLittleExitBtnTouched = false;

		if (littleExitBtnRect.containsPoint(loc)){

			//exit창을 연다.
			initExitWindow();

		}


	}
    
   
    

	if (isExitBtnTouched == true){

		exitBtn->setVisible(true);
		exitBtn_->setVisible(false);
		isExitBtnTouched = false;

		if (exitBtnRect.containsPoint(loc)){

			//게임을 종료한다.
			Director::getInstance()->end();

		}


	}

	if (isExitResumeBtnTouched == true){

		exitResumeBtn->setVisible(true);
		exitResumeBtn_->setVisible(false);
		isExitResumeBtnTouched = false;

		if (exitResumeBtnRect.containsPoint(loc)){
			isExitWindow = false;
			//exit창을 닫는다.
			exitWindow->setVisible(false);
			exitBtn->setVisible(false);
			exitResumeBtn->setVisible(false);

		}


	}
    
    //한영 전환 버튼
    if ((isInfo == false) && (isExitWindow == false) && (isEhBtnTouched==true)){
        isEhBtnTouched = false;
         initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");
        if(eBtnRect.containsPoint(loc)){
            
           bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
            if (isSong == true){
                //			int chimeSound =
                SimpleAudioEngine::getInstance()->playEffect("switch.wav");
            }
            
            if(initByEnglish==true){
                //영어 상태일때 한글로 바뀌므로, 영어버튼으로 바뀜.
                hBtn->setVisible(false);
                hBtn_->setVisible(false);
                eBtn->setVisible(true);
                eBtn_->setVisible(false);
                UserDefault::getInstance()->setBoolForKey("initByEnglish",false);
                initByEnglish = false;
                ehLabel->setString(StringUtils::format("한국어", "NanumBarunGothic.otf", 16));
                stageBtnInfo->setString(StringUtils::format("버튼 아닙니다.. ^^;;"));
                gameStartBtnInfo->setString(StringUtils::format("스테이지 선택 먼저!"));

            }else{
              
                hBtn->setVisible(true);
                hBtn_->setVisible(false);
                eBtn->setVisible(false);
                eBtn_->setVisible(false);
                UserDefault::getInstance()->setBoolForKey("initByEnglish",true);
                initByEnglish = true;
                gameStartBtnInfo->setString(StringUtils::format("Hey, select the button!"));
                stageBtnInfo->setString(StringUtils::format("It's not a button ^^;;"));
               
                ehLabel->setString(StringUtils::format("English", "NanumBarunGothic.otf", 16));

                //여기몬몬
            }
        }else{
            if(initByEnglish==true){//영어 일때

                hBtn->setVisible(true);
                hBtn_->setVisible(false);
                eBtn->setVisible(false);
                eBtn_->setVisible(false);

            }else{
                hBtn->setVisible(false);
                hBtn_->setVisible(false);
                eBtn->setVisible(true);
                eBtn_->setVisible(false);

            }
        }
        setStageSelectBtns();
        
    }

	if (isMungStoreBtnTouched == true){

		CCLOG("MungStore");
		mungStoreBtn->setVisible(true);
		mungStoreBtn_->setVisible(false);
		isMungStoreBtnTouched = false;

		if (mungStoreBtnRect.containsPoint(loc)){

			//Go to the MungStoreScene
			changeMungStoreScene(this);//상점으로 이동

		}


	}
	//unit
	if (isUnitBtnTouched == true){

		CCLOG("Unit");
		unitBtn->setVisible(true);
		unitBtn_->setVisible(false);
		isUnitBtnTouched = false;

		if (unitBtnRect.containsPoint(loc)){


			//changeGameMenuScene(this);
			changeUnitScene(this);
			//Go to the UnitScene
		}


	}
	//mission
	if (isMissionBtnTouched == true){

		CCLOG("Mission");
		missionBtn->setVisible(true);
		missionBtn_->setVisible(false);
		isMissionBtnTouched = false;

		if (missionBtnRect.containsPoint(loc)){

			//Go to the missionScene
			changeMissionScene(this);
		}


	}


	if (isInfoBtnTouched == true){
		CCLOG("info");
		if (isInfo == false){

			isInfoBtnTouched = false;

			if (infoBtnRect.containsPoint(loc)){
				CCLOG("infoWindow");
				initInfoWindow();
				infoBtn->setVisible(true);
				infoBtn_->setVisible(false);
				isInfo = true;
			}
		}
	}


	if (isInfoExitBtnTouched == true){
		if (isInfo == true){
			CCLOG("infoExit");
			// gameStartBtn_->setVisible(false);
			isInfoExitBtnTouched = false;

			if (infoExitBtnRect.containsPoint(loc)){

				removeInfoWindow();
				infoExitBtn_->setVisible(false);
				isInfo = false;
			}

		}

	}

    //소리 설정
    if (isSongBtnTouched == true){
        if (isSongBtnRect.containsPoint(loc)){

            isSongBtnTouched = false;
            if (isNotSongBtnTouched == false){
                //음악 꺼진다.
                isSongBtn->setVisible(false);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(true);
                isNotSongBtn_->setVisible(false);
                isNotSongBtnTouched = true;
                
                SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
                UserDefault::getInstance()->setBoolForKey("isSong", false);
                
            }
            else{

                isSongBtn->setVisible(true);
                isSongBtn_->setVisible(false);
                isNotSongBtn->setVisible(false);
                isNotSongBtn_->setVisible(false);
                isNotSongBtnTouched = false;
                
                
                SimpleAudioEngine::getInstance()->playBackgroundMusic("myFirstSong.mp3", true);
                UserDefault::getInstance()->setBoolForKey("isSong", true);
            }
        }
    }
}
