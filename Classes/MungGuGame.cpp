


#include "MungGuGame.h"
#include "MungGuGameMenuScene.h"
#include "Epilogue.h"

#include "MunguMonster.h"
#include "MungBallMonster.h"
#include "MungButterFly.h"
#include "MungSausage.h"
#include "MungWhangGu.h"

#include "CatBossMonster.h"
#include "CatMonster.h"
#include "math.h"
#include "SimpleAudioEngine.h"

//#include "stdio.h"
USING_NS_CC;
using namespace CocosDenshion;

Monster *myMonst;
EnemyMonster *enemyMonst;

MungGuGame* MungGuGame::instance = nullptr;
MungGuGame* MungGuGame::getInstance() {//싱글톤 방법??

	if (instance == nullptr)
	{
        
		instance = new MungGuGame();
	}

	return instance;
}

MungGuGame::MungGuGame()
:isNeededToMove(true)
{
    
}
Scene* MungGuGame::createScene()
{

	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MungGuGame::create();
	instance = layer;

	// add layer as a child to scene
	scene->addChild(layer);//Scene에 Layer를 추가

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool MungGuGame::init()
{             //////////////////////////////
	// 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
	{
		return false;
	}
    
    

    myGold = UserDefault::getInstance()->getIntegerForKey("myGold");
    
    isStage1 = UserDefault::getInstance()->getBoolForKey("isStage1");
    isStage2 = UserDefault::getInstance()->getBoolForKey("isStage2");
    isStage3 = UserDefault::getInstance()->getBoolForKey("isStage3");
    isStage4 = UserDefault::getInstance()->getBoolForKey("isStage4");
    isStage5 = UserDefault::getInstance()->getBoolForKey("isStage5");
    isStage6 = UserDefault::getInstance()->getBoolForKey("isStage6");
    isStage7 = UserDefault::getInstance()->getBoolForKey("isStage7");
    isStage8 = UserDefault::getInstance()->getBoolForKey("isStage8");
    isStage9 = UserDefault::getInstance()->getBoolForKey("isStage9");
    isStage10 = UserDefault::getInstance()->getBoolForKey("isStage10");
    isStage11 = UserDefault::getInstance()->getBoolForKey("isStage11");
    isStage12 = UserDefault::getInstance()->getBoolForKey("isStage12");
    isStage13 = UserDefault::getInstance()->getBoolForKey("isStage13");
    isStage14 = UserDefault::getInstance()->getBoolForKey("isStage14");
    isStage15 = UserDefault::getInstance()->getBoolForKey("isStage15");
    isStage16 = UserDefault::getInstance()->getBoolForKey("isStage16");
    isStage17 = UserDefault::getInstance()->getBoolForKey("isStage17");
    isStage18 = UserDefault::getInstance()->getBoolForKey("isStage18");
    isStage19 = UserDefault::getInstance()->getBoolForKey("isStage19");
    isStage20 = UserDefault::getInstance()->getBoolForKey("isStage20");
    isStage21 = UserDefault::getInstance()->getBoolForKey("isStage21");
    isStage22 = UserDefault::getInstance()->getBoolForKey("isStage22");
    isStage23 = UserDefault::getInstance()->getBoolForKey("isStage23");
    isStage24 = UserDefault::getInstance()->getBoolForKey("isStage24");
    isStage25 = UserDefault::getInstance()->getBoolForKey("isStage25");
    isStage26 = UserDefault::getInstance()->getBoolForKey("isStage26");
    isStage27 = UserDefault::getInstance()->getBoolForKey("isStage27");
    isStage28 = UserDefault::getInstance()->getBoolForKey("isStage28");
    isStage29 = UserDefault::getInstance()->getBoolForKey("isStage29");
    isStage30 = UserDefault::getInstance()->getBoolForKey("isStage30");
    
    isDevsQuestion = false;

    //멍구 기지 레벨
    mungGuDogSiteHpLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteHpLv");
    mungGuDogSitePoLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSitePoLv");
    mungLv = UserDefault::getInstance()->getIntegerForKey("mungLv");
    whangLv = UserDefault::getInstance()->getIntegerForKey("whangLv");
    mungBallLv = UserDefault::getInstance()->getIntegerForKey("mungBallLv");
    mungButLv = UserDefault::getInstance()->getIntegerForKey("mungButLv");
    mungSausageLv = UserDefault::getInstance()->getIntegerForKey("mungSausageLv");

   // //11스테이지 테스트
//       isStage9=true; //대포로 죽이기
//    isStage1=false;
     
	initData();
    
    //Test Stage
    //isStage9 = true;
    
    
    

    
    
    setDogSiteMaxHp = 1000 + mungGuDogSiteHpLv*300;//멍구기지 체력
    
    dogSiteScaleRate = 1*winSize.width/1360;
    catSiteScaleRate = 1*winSize.width/1360; //적, 아군기지 크기 조절
	myMoney = 0;
	audioCount = 0;
	//myMonsterNum = myMonsters.size();
	//enemyMonsterNum=enemyMonsters.size();
	
	maxMoneyValue = 2000;

	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3");
	//배경음악 삽입하기.
    
    auto action0 = DelayTime::create(1.2);
    auto action = Sequence::create(action0,CallFunc::create(this,callfunc_selector(MungGuGame::setSong)),NULL);
    runAction(action);

    
    
    
	//배경음악 일시정지
	//SimpleAudioEngine::getInstance()->pauseBackGroundMusic();

	//배경음악 재시작 ->resumeBackGroundMusic();
	//배경음악 정지 ->stopBackgroundMusic();
	//배경음원 메모리 해제 SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    //스테이지 판별
    
    moneyIncreaseRate = 1;//머니 스피드 증가율
    damageValueIncreaseRate = 1; //데미지 증가율


    
    if(isStage1 == true){

	setCatSiteMaxHp = 1000;
	goldForStage = 2000;
    }else if(isStage2 == true){
        setCatSiteMaxHp = 2600;
        goldForStage = 2500;
    }else if(isStage3 == true) {
        setCatSiteMaxHp = 3000;
        goldForStage = 3000;
    }else if(isStage4 == true) {
        setCatSiteMaxHp = 4444;
        goldForStage = 4444;
    }else if(isStage5 == true){
        setCatSiteMaxHp = 3600;
        goldForStage = 4200;
    }else if(isStage6 == true){
        setCatSiteMaxHp = 5200;
        goldForStage = 5200;
    }else if(isStage7 == true){
        setCatSiteMaxHp = 6100;
        goldForStage = 6500;
    }else if(isStage8 == true){
        setCatSiteMaxHp = 6800;
        goldForStage = 6800;
    }else if(isStage9 == true){
        setCatSiteMaxHp = 7500;
        goldForStage = 7500;
    }else if(isStage10 == true){
        setCatSiteMaxHp = 10000;
        goldForStage = 10000;
    }else if(isStage11 == true){
        setCatSiteMaxHp = 9100;
        goldForStage = 10600;
    }else if(isStage12 == true){
        setCatSiteMaxHp = 9500;
        goldForStage = 11200;
    }else if(isStage13 == true){
        setCatSiteMaxHp = 11000;
        goldForStage = 12600;
    }else if(isStage14 == true){
        setCatSiteMaxHp = 10500;
        goldForStage = 13000;
    }else if(isStage15 == true){
        setCatSiteMaxHp = 13000;
        goldForStage = 15000;
    }else if(isStage16 == true){
        setCatSiteMaxHp = 15000;
        goldForStage = 15500;
    }else if(isStage17 == true){
        setCatSiteMaxHp = 16400;
        goldForStage = 16200;
    }else if(isStage18 == true){
        setCatSiteMaxHp = 16500;
        goldForStage = 16000;
    }else if(isStage19 == true){
        setCatSiteMaxHp = 17200;
        goldForStage = 16500;
    }else if(isStage20 == true){
        setCatSiteMaxHp = 20000; //20000
        goldForStage = 20000;
    }else if(isStage21 == true){
        setCatSiteMaxHp = 20500;
        goldForStage = 20800;
    }else if(isStage22 == true){
        setCatSiteMaxHp = 20300;
        goldForStage = 21500;
    }else if(isStage23 == true){
        setCatSiteMaxHp = 21000;
        goldForStage = 22000;
    }else if(isStage24 == true){
        setCatSiteMaxHp = 22000;
        goldForStage = 23000;
    }else if(isStage25 == true){
        setCatSiteMaxHp = 23000;
        goldForStage = 23500;
    }else if(isStage26 == true){
        setCatSiteMaxHp = 25000;
        goldForStage = 24200;
    }else if(isStage27 == true){
        setCatSiteMaxHp = 30000;
        goldForStage = 23400;
    }else if(isStage28 == true){
        setCatSiteMaxHp = 32000;
        goldForStage = 27600;
    }else if(isStage29 == true){
        setCatSiteMaxHp = 45000;
        goldForStage = 26000;
    }else if(isStage30 == true){
        setCatSiteMaxHp = 55000;
        goldForStage = 32100;
    }else{
        setCatSiteMaxHp = 9999;
        goldForStage = 0;
    }
    
  //  setCatSiteMaxHp = 0;//테스트용
    //-20~ ~76~ 가까워짐.
    if(isStage1==true){//catDogDistance값이 클수록 서로 가깝다.
        catDogDistance = 110*(winSize.width/1000);
    }else if(isStage2==true){
        catDogDistance = 80*(winSize.width/1000);
    }else if(isStage3==true){
        catDogDistance = 50*(winSize.width/1000);
    }else if(isStage4==true){
        catDogDistance = 80*(winSize.width/1000);
    }else if(isStage5==true){
        catDogDistance = 105*(winSize.width/1000);
    }else if(isStage6==true){
        catDogDistance = 60*(winSize.width/1000);
    }else if(isStage7==true){
        catDogDistance = 94*(winSize.width/1000);
    }else if(isStage8==true){
        catDogDistance = 61*(winSize.width/1000);
    }else if(isStage9==true){
        catDogDistance = 41*(winSize.width/1000);
    }else if(isStage10==true){
        catDogDistance = -5*(winSize.width/1000);
    }else if(isStage11==true){
        catDogDistance = 76*(winSize.width/1000);
    }else if(isStage12==true){
        catDogDistance = 58*(winSize.width/1000);
    }else if(isStage13==true){
        catDogDistance = 78*(winSize.width/1000);
    }else if(isStage14==true){
        catDogDistance = 58*(winSize.width/1000);
    }else if(isStage15==true){
        catDogDistance = 65*(winSize.width/1000);
    }else if(isStage16==true){
        catDogDistance = 90*(winSize.width/1000);
    }else if(isStage17==true){
        catDogDistance = 80*(winSize.width/1000);
    }else if(isStage18==true){
        catDogDistance = -20*(winSize.width/1000);
    }else if(isStage19==true){
        catDogDistance =  70*(winSize.width/1000);
    }else if(isStage20==true){
        catDogDistance = 30*(winSize.width/1000);
    }else if(isStage21==true){
        catDogDistance = 0*(winSize.width/1000);
    }else if(isStage22==true){
        catDogDistance = 40*(winSize.width/1000);
    }else if(isStage23==true){
        catDogDistance = 105*(winSize.width/1000);
    }else if(isStage24==true){
        catDogDistance = 60*(winSize.width/1000);
    }else if(isStage25==true){
        catDogDistance = 80*(winSize.width/1000);
    }else if(isStage26==true){
        catDogDistance = 120*(winSize.width/1000);
    }else if(isStage27==true){
        catDogDistance = -20*(winSize.width/1000);
    }else if(isStage28==true){
        catDogDistance = -5*(winSize.width/1000);
    }else if(isStage29==true){
        catDogDistance = 30*(winSize.width/1000);
    }else if(isStage30==true){
        catDogDistance = 45*(winSize.width/1000);
    }

    
	missileDamage = 100 + mungGuDogSitePoLv*20-20;//멍구기지 미사일 데미지
    setGround();
	setCatSite();
	setDogSite();
    catSiteRect = catSite->getBoundingBox();
    dogSiteRect = dogSite->getBoundingBox();
    dogSitePos = dogSiteRect.getMaxX() - (dogSiteRect.getMaxX()-dogSiteRect.getMinX())*0.23; //멍구 기지의 충돌 지정값
    catSitePos = catSiteRect.getMinX() + (catSiteRect.getMaxX()-catSiteRect.getMinX())*0.23; //적 기지의 충돌 지정값

    
    //1스테이지 아군 대화
    stageTalk_label = Label::createWithTTF
    (StringUtils::format("Let's go-!!"), "NanumBarunGothic.otf", 26);
    stageTalk_label->setPosition(Point(dogSiteRect.getMaxX(),dogSiteRect.getMaxY()));
    stageTalk_label->setAnchorPoint(Point(0,0));
    stageTalk_label->setVisible(false);
    stageTalk_label->setColor(Color3B::BLACK);
    stageTalk_label->setScale(winSize.width/1360);
    if(initByEnglish==false){
        stageTalk_label->setString(StringUtils::format("이제 시작이다. 고고!"));
    }
    this->addChild(stageTalk_label,10);
    if((isStage1==true)||(isStage2==true)||(isStage5==true)|| (isStage11==true)||(isStage28==true)){
    initStageTalk();
    }
    if(isStage9 == true){
        initDevsQuestion();
    }
    
    
	//가까운 적, 아군 위치 초기화
	nearMungPos = dogSiteRect.getMaxX()-10;
	nearCatPos = catSiteRect.getMinX();

    answerBtn1 = Sprite::create("selectBtn.png");
    answerBtn1->setPosition(Point(winSize.width/2-250,winSize.height*3/4));
    answerBtn1->setAnchorPoint(Point(0.5,0.5));
    answerBtn1->setOpacity(200);
    answerBtn1->setScale(0.9,1.1);
    answerBtn2 = Sprite::create("selectBtn.png");
     answerBtn2->setPosition(Point(winSize.width/2,winSize.height*3/4));
    answerBtn2->setScale(0.9,1.1);
    answerBtn2->setAnchorPoint(Point(0.5,0.5));
     answerBtn2->setOpacity(200);
    answerBtn3 = Sprite::create("selectBtn.png");
     answerBtn3->setPosition(Point(winSize.width/2+250,winSize.height*3/4));
    answerBtn3->setScale(0.9,1.1);
    answerBtn3->setAnchorPoint(Point(0.5,0.5));
     answerBtn3->setOpacity(200);
    
     answerBtn1Rect = answerBtn1->getBoundingBox();
     answerBtn2Rect = answerBtn2->getBoundingBox();
     answerBtn3Rect = answerBtn3->getBoundingBox();
    
    //ㅏ랄라라라라라
    answerBtn1_label = Label::createWithTTF(StringUtils::format("No. Actually, \nYou are good builder ^^"), "NanumBarunGothic.otf", 18);
    answerBtn1_label->setPosition(Point(answerBtn1Rect.getMidX(),answerBtn1Rect.getMidY()));
    answerBtn1_label->setColor(Color3B::BLACK);
    
    answerBtn2_label =
    Label::createWithTTF(StringUtils::format("I already crushed that building!\n     How can you do!!!"), "NanumBarunGothic.otf", 16);
    answerBtn2_label->setPosition(Point(answerBtn2Rect.getMidX(),answerBtn2Rect.getMidY()));
 answerBtn2_label->setColor(Color3B::BLACK);

    answerBtn3_label = Label::createWithTTF(StringUtils::format("Shut up!"), "NanumBarunGothic.otf", 25);
    answerBtn3_label->setPosition(Point(answerBtn3Rect.getMidX(),answerBtn3Rect.getMidY()));
 answerBtn3_label->setColor(Color3B::BLACK);
    
    if(initByEnglish==false){
        answerBtn1_label->setString(StringUtils::format("아뇨 그럴 수도 있죠 ㅎㅎ ^^"));
        answerBtn2_label->setString(StringUtils::format("저건물은 이미 부쉈는데..\n   어떻게 한거죠??"));
        answerBtn3_label->setString(StringUtils::format("적당히 하거라."));
    }
    
    this->addChild(answerBtn1_label,101);
     this->addChild(answerBtn2_label,101);
     this->addChild(answerBtn3_label,101);
    
    this->addChild(answerBtn1,100);
	this->addChild(answerBtn2,100);
    this->addChild(answerBtn3,100);
    
    answerBtn1_label->setVisible(false);
    answerBtn2_label->setVisible(false);
    answerBtn3_label->setVisible(false);
    answerBtn1->setVisible(false);
    answerBtn2->setVisible(false);
    answerBtn3->setVisible(false);
    
    
	setStageName();
	setMissileAttackEffect();
	setMyMoney();
	setCatSiteHp();
	setDogSiteHp();
	setMungBtn();

	setMungFireMissile();
	setBG();
	setStatusBar();
	setFireBtn();
	setExploreMileStone();
	setPauseBtn();
	setPauseWindow();
	setSongPlayedBtn();
	setGameClearEvent();
	setGameLoserEvent();
	myMonsters.clear();
	enemyMonsters.clear(); //백터 초기화
    setCoolTime();
    
     isSongBtnRect = isSongBtn->getBoundingBox();
     whangGuBtnRect = whangGuBtn->getBoundingBox();
    
     resumeBtnRect = resumeBtn->getBoundingBox();
     pauseBtnRect = pauseBtn->getBoundingBox();
     mungGuFireBtnRect = mungCoFireBtn->getBoundingBox();
     mungButBtnRect = mungButterFlyBtn->getBoundingBox();
     mungBtnRect = mungBtn->getBoundingBox();
     mungBallBtnRect = mungBallBtn->getBoundingBox();
     mungSausageBtnRect = mungSausageBtn->getBoundingBox();
    
    statusBarForMaxMoney_Rect = statusPushBar_maxMoney->getBoundingBox();
    statusBarForPower_Rect = statusPushBar_power->getBoundingBox();
    statusBarForSpeed_Rect = statusPushBar_speed->getBoundingBox();

    //catSiteNowHp=0; //클리어 이벤트 테스트용(클리어이벤트 바로 확인해야 할때)
   // catSiteNowHp = 0;

  //  UserDefault::getInstance()->setIntegerForKey("myGold", 10000000);
    ///맨 처음 실행 시 튜토리얼
    int stage1_clearCount = UserDefault::getInstance()
    ->getIntegerForKey("stage1_revangeStartClearCount");
    if((stage1_clearCount==0)&&(isStage1==true)){
        isTutorialFinished = false;
        //        Director::getInstance()->pause();
        tutorialWindow = Sprite::create("tutorialWindow.png");
        tutorialWindow->setAnchorPoint(Point(0.5,0.5));
        tutorialWindow->setPosition(Point(winSize.width/2,winSize.height/2));
        tutorialWindow->setScale(2);
        this->addChild(tutorialWindow,100);
        Rect tutorialWindowRect = tutorialWindow->getBoundingBox();
        tutExitBtn = Sprite::create("exitBtn.png");
        tutExitBtn_ = Sprite::create("exitBtn_.png");
        tutExitBtn->setAnchorPoint(Point(0.5,0.5));
        tutExitBtn_->setAnchorPoint(Point(0.5,0.5));
        tutExitBtn->setPosition(Point(tutorialWindowRect.getMaxX(),tutorialWindowRect.getMaxY()));
        tutExitBtn_->setPosition(Point(tutorialWindowRect.getMaxX(),tutorialWindowRect.getMaxY()));
        tutExitBtn_->setVisible(false);
        this->addChild(tutExitBtn,101);
        this->addChild(tutExitBtn_,101);
        tutRect = tutExitBtn->getBoundingBox();
    }else{
        isTutorialFinished=true;
    }
    //////

    
	this->scheduleUpdate(); //충돌 판정때 프레임마다 계속 체크하기 위해 사용**

	return true;
}


//데이터 초기화하는 곳
void MungGuGame::initData()
{
    
   
    
    

    
    myMonsters.clear();
    enemyMonsters.clear();
    
    //몬스터들 가격
    mungSausageCost=600;//600
    mungButCost=300;//300
    mungBallCost=150;//150
    whangCost=160;//160
    mungCost=100;//100
    mungPoCost=600;//1000 nowNeededMoneyForMungPo
    
    
    messageCount = 0;
    
    initByEnglish = UserDefault::getInstance()->getBoolForKey("initByEnglish");//한영 상태
    
    isReadyToRemoveTheShild = false;
    winSize = Director::getInstance()->getWinSize();//현재 화면의 크기를 가져와 winSize에 정보를 담음
    winHeight = winSize.height;
    winWidth = winSize.width;
    sizeCheck();
    groundPosY = winSize.height * 2 / 5;
    
    mungFireCoolTimeFinished = false;
    isStage18_trap=false;
    isSinBtnTouched=false;
    isSongBtnTouched=false;
    
    isHomeBackBtnTouched=false;
    isInitMissile=false;
    isEnemyMonsterHitted=false;
    isExploreRangeAction=false;
    isMung=false;
    isMungButBtnTouched=false;
    isWhangGuBtnTouched=false;
    isMungFire=false;
    maxMoneyValue=false;
    isMungBtnTouched=false;
    isMungBallBtnTouched=false;
    isMungSausageBtnTouched=false;
    isStatusBarForMaxMoneyTouched=false;
    isStatusBarForSpeedTouched=false;
    isStatusBarForPowerTouched=false;
    isMungGuFireBtnTouched=false;
    
    enemyMonsterAngryCheck=false;
    isEnemyMonsterAngry=false;
    isStopAction=false;
    isFinishActionAttack=false;
    isPauseBtnTouched=false;
    isPause=false;
    isResumeBtnTouched=false;
    isInfoCancelBtnTouched=false;
    isGoHomeBtnTouched=false;
    isGameOverMessage=false;
    isRegameBtnTouched=false;
    isStageEnded=false;
    
    isFirstGenFinished = false;
    isSecondGenFinished = false;
    isThirdGenFinished = false;
    
    isCatSiteAngryed = false;
    isInitRedriverMusic = false;
    isInitSinTaeDoll = false;
    isStop = true;
    isCatSiteShild = false;
    shildAttackCount=0;
    enemyMonsterAngryCheck = false;
    isEnemyMonsterAngry = false;
    isGoldCalc = false;
    isSongBtnTouched = false;
    isNotSongBtnTouched = false;
    isInitMissile = false;
    isEnemyMonsterHitted = false;
    isExploreRangeAction = false;
    isMung = false;
    isMungButBtnTouched = false;
    isWhangGuBtnTouched = false;
    isMungFire = false;
    isMungBtnTouched = false;
    isMungBallBtnTouched = false;
    isMungSausageBtnTouched = false;
    isStatusBarForMaxMoneyTouched = false;
    isStatusBarForSpeedTouched = false;
    isStatusBarForPowerTouched = false;
    isMungGuFireBtnTouched = false;
    isHomeBackBtnTouched = false;
    isStopAction = false;
    isFinishActionAttack = true;
    isPauseBtnTouched = false;
    isPause = false;
    isResumeBtnTouched = false;
    isInfoCancelBtnTouched = false;
    isGoHomeBtnTouched = false;
    isFirstStageClear = false;
    isFirstStageLoser = false;
    isRegameBtnTouched = false;
    isStageEnded = false;
    isStopFinger = false;//5스테이지 용
    
    ///쿨타임 불린 변수////
    isFirstBtnCoolTimeFinished=false;
    is2ndBtnCoolTimeFinished=false;
    is3rdBtnCoolTimeFinished=false;
    is4thBtnCoolTimeFinished=false;
    is5thBtnCoolTimeFinished=false;
    is6thBtnCoolTimeFinished=false;
    is7thBtnCoolTimeFinished=false;
    is8thBtnCoolTimeFinished=false;
    is9thBtnCoolTimeFinished=false;
    is10thBtnCoolTimeFinished=false;
    
    
    auto listener_regameBtn = EventListenerTouchOneByOne::create();
    listener_regameBtn->onTouchBegan = CC_CALLBACK_2
    (MungGuGame::onTouchBegan, this);
    listener_regameBtn->onTouchMoved = CC_CALLBACK_2
    (MungGuGame::onTouchMoved, this);
    listener_regameBtn->onTouchEnded = CC_CALLBACK_2
    (MungGuGame::onTouchEnded, this);
    
//    Director::getInstance()->getEventDispatcher()->
//    addEventListenerWithFixedPriority
//    (listener_regameBtn, TAG_SPRITE_REGAMEBTN);
    
    Director* dir = Director::sharedDirector();
    dir->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener_regameBtn, this);
    
}
//
//void MungGuGame::setHpBar(){
//    Sprite* tmr = Sprite::create("cost_6000.png");//프로그레스바 이미지 생성
//    ProgressTimer* timer = ProgressTimer::create(tmr);//프로그레스바 변수 생성
//    timer->setType(kCCProgressTimerTypeBar);//Bar 타입의 프로그래스바 설정
//    timer->setMidpoint(Point(0,0.5));
//    timer->setPosition(Point(winSize.width/2, winSize.height/2));
//    timer->setPercentage(60.0f);
//    this->addChild(timer,10);
//}

void MungGuGame::initStageTalk(){
    if(isStage1==true){
    
    
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(0.5);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
    
    }
    
        
        
    if(isStage13==true){
        //13스테이지 아군 대화
        
        stageTalk_label->setString(StringUtils::format("-,.-;;"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("-,.-;;"));
        }
        
        auto blinkAction = Blink::create(3, 2);
        auto delayAction = DelayTime::create(0.5);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
        
    }
    
    
    if(isStage18==true){
        stageTalk_label->setString(StringUtils::format("How can I do!"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("어쩌란거임..."));
        }
        stageTalk_label->setVisible(false);
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(0.5);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"

    }
    
    if(isStage2==true){
        //1스테이지 아군 대화
        
        stageTalk_label->setString(StringUtils::format("Keep Going!!"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("계속 ㄱㄱ"));
        }
        
        auto blinkAction = Blink::create(3, 2);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
        
    }
    
    if((isStage4==true)&&(isCatSiteShild==true)){
        stageTalk_label->setString(StringUtils::format("I can't believe it-!\n How can I remove his shield..?!"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("뭥미..;;\n어떻게 무적갑옷을 벗겨내지??"));
        }
        
        auto blinkAction = Blink::create(3, 2);
        auto delayAction = DelayTime::create(2);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);
    }
    
    if((isStage4==true)&&(isCatSiteShild==false)){
        stageTalk_label->setString(StringUtils::format("Are you kidding me?;;"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("장난??;;"));
        }
        
        auto blinkAction = Blink::create(6, 3);
        auto delayAction = DelayTime::create(2);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);
    }
    
    if(isStage5==true){
        //5스테이지 아군 대화
        
        stageTalk_label->setString(StringUtils::format("Our world is weird.."));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("세상이 너무 혼란스러워.."));
            
        }
        
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
        
    }
    
    if(isStage6==true){
        stageTalk_label->setString(StringUtils::format("= ㅅ=....;;"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("= ㅅ=....;;"));
            stageTalk_label->setScale(2.6*winSize.width/1200);
        }
        
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(3);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initDevsQuestion)),NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
    }
    
//    if(isStage9==true){
//        stageTalk_label->setString(StringUtils::format("yep ^-^ㅗ"));
//        if(initByEnglish==false){
//            stageTalk_label->setString(StringUtils::format("응 ^-^ㅗ"));
//            stageTalk_label->setScale(0.8*winSize.width/1200);
//        }
//        stageTalk_label->setVisible(false);
//        auto blinkAction = Blink::create(5, 1);
//        auto delayAction = DelayTime::create(1.3);
//        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
//        
//        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
//    }
    
    if(isStage11==true){
        //11스테이지 아군 대화
        
        stageTalk_label->setString(StringUtils::format("I guess.. \n They like baseball.."));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("야구를 좋아하는 놈들인듯.."));
            stageTalk_label->setScale(0.8*winSize.width/1200);
        }
        
        auto blinkAction = Blink::create(5.3, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
        
    }
    
    if((isStage9==true)&&(isStage13==true)){
        stageTalk_label->setString(StringUtils::format("What the..."));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("....."));
        }
        
        auto blinkAction = Blink::create(5.3, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"

    }
    
    if(isStage28==true){
        //28스테이지 아군 대화
        if(messageCount==0){
        stageTalk_label->setString(StringUtils::format("???"));
            stageTalk_label->setScale(0.8*winSize.width/1200);
            stageTalk_label->setColor(Color3B::BLACK);
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("???"));
        }
            stageTalk_label->setVisible(false);

        
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(6);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initDevsQuestion)),NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
        
        }else if(messageCount==1){
            stage13_message->setString(StringUtils::format("I couldn't afford it..."));
            if(initByEnglish==false){
                stage13_message->setString(StringUtils::format("어쩔 수 없었어..."));
            }
            stage13_message->setScale(1.6*winSize.width/1200);
            stage13_message->setColor(Color3B::RED);
            stage13_message->setAnchorPoint(Point(0.5,1));
            stage13_message->setPosition(Point(winSize.width/2,winSize.height-30));
            auto blinkAction = Blink::create(2, 3);
            auto delayAction = DelayTime::create(2);
            auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initDevsQuestion)),NULL);
            stage13_message->runAction(talkAction);
            
        }else if(messageCount==2){
            stage13_message->setString(StringUtils::format("I'm catSite builder.."));
            if(initByEnglish==false){
                stage13_message->setString(StringUtils::format("저 건물 만든사람입니다.."));
            }
            auto blinkAction = Blink::create(3, 5);
            auto delayAction = DelayTime::create(1);
            auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initDevsQuestion)),NULL);
            stage13_message->runAction(talkAction);
         //   stageTalk_label->setVisible(false);
        }
        else if(messageCount==3){
            stage13_message->setVisible(true);
            stageTalk_label->setVisible(true);
            isDevsQuestion=true;
            //28스테이지 질문 답항
            answerBtn1_label->setVisible(true);
            answerBtn2_label->setVisible(true);
            answerBtn3_label->setVisible(true);
            answerBtn1->setVisible(true);
            answerBtn2->setVisible(true);
            answerBtn3->setVisible(true);
            messageCount++;
            Director::getInstance()->pause();//멈추고 질문 시작 //개발자와의 질문1
            //여기에 질문을 나오게 한 후, 답변에따라 이벤트 발생
        }
    }
    
    
    
}

void MungGuGame::initDevsQuestion(){

    
    if(isStage9==true){
        auto stage9_message = Label::createWithTTF("Push the button in my backyard \n Please~~!! >o <","NanumBarunGothicBold.otf",20);
        stage9_message->setColor(Color3B(230,50,50));
        Rect catSiteRect = catSite->getBoundingBox();
        stage9_message->setAnchorPoint(Point(1,0));
        stage9_message->setVisible(false);
        stage9_message->setPosition(catSiteRect.getMinX(),catSiteRect.getMaxY());
        stage9_message->setVisible(false);
        if(initByEnglish==false){
            stage9_message->setString(StringUtils::format("뒤에 버튼좀 눌러줘 부탁~~!! >9 <"));
            stage9_message->setScale(0.8*winSize.width/1200);
        }
        this->addChild(stage9_message,50);
        
        auto blinkAction = Blink::create(5, 3);
        auto delayAction = DelayTime::create(6);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
        stage9_message->runAction(talkAction);
    }
    
    
    if(isStage6==true){
        stageTalk_label->setVisible(false);
        
        auto stage6_message = Label::createWithTTF("Surprise~~!!","NanumBarunGothicBold.otf",20);
        stage6_message->setColor(Color3B(230,50,50));
        Rect catSiteRect = catSite->getBoundingBox();
        stage6_message->setAnchorPoint(Point(1,0));
        stage6_message->setVisible(false);
           stage6_message->setPosition(catSiteRect.getMinX(),catSiteRect.getMaxY());
        if(initByEnglish==false){
            stage6_message->setString(StringUtils::format("서프라이즈~ ^-^"));
            
        }
        this->addChild(stage6_message,50);

        messageCount++;
        auto blinkAction = Blink::create(2, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        stage6_message->runAction(talkAction);
    
    
    }
    
    
    
    if(isStage28==true){
    if(messageCount==0){
        stageTalk_label->setVisible(true);
        

        stageTalk_label->setString(StringUtils::format("I already crash that building!\n it's not possible..!!"));
        stageTalk_label->setColor(Color3B::BLACK);
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("이미 저 건물은 부쉈잖아! \n 말도 안돼..!"));
        }
        auto blinkAction = Blink::create(2, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
        
        stageTalk_label->runAction(talkAction);
        messageCount++;
    }else if(messageCount==1){
        stageTalk_label->setString(StringUtils::format("Who are you?!"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("누구신지..?!"));
        }
        messageCount++;
        auto blinkAction = Blink::create(2, 6);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
        stageTalk_label->runAction(talkAction);
    }else if(messageCount==2){
        stage13_message->setString(StringUtils::format("Making building is borning..\n What's wrong with you???"));
        if(initByEnglish==false){
            stage13_message->setString(StringUtils::format("건물 만드는게 귀찮음.. \n 무슨 일 있나요???"));
           
        }
        
        stageTalk_label->setString(StringUtils::format("?!"));
        if(initByEnglish==false){
            stageTalk_label->setString(StringUtils::format("?!"));
        }
        messageCount++;
        auto blinkAction = Blink::create(3, 1);
        auto delayAction = DelayTime::create(1);
        auto talkAction = Sequence::create(delayAction,blinkAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
        stage13_message->runAction(talkAction);
    
    }
    }
}

void MungGuGame::setSong(){//노래 설정
    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    
   ///배경음 셋팅
    ////////스 테 이 지 별 음 악 넣 는 부 분///////////
    
    if(isStage1 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage2 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage3 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage4 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage5 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage6 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage7 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage8 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage9 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("song.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage10 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage11 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage12 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("goodSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage13 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage14 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage15 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage16 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage17 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage18 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage19 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage20 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage21 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage22 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("goodSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage23 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage24 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage25 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage26 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage27 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage28 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage29 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else if(isStage30 == true){
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }else{
        if(isSong == true){//song 켰나 안켯나 확인
            SimpleAudioEngine::getInstance();
            if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
            }
        }
    }
    }

void MungGuGame::setGround(){

	ground = Sprite::create("ground_0.png");
	Rect groundRect = ground->getBoundingBox();
	ground->setScale(winSize.width / groundRect.size.width, groundPosY / groundRect.size.height);
	ground->setPosition(Point(0, groundPosY));
	ground->setAnchorPoint(Point(0, 1));
	this->addChild(ground, 1);
	


}

void MungGuGame::setStageSelect(){
    UserDefault::getInstance()->getBoolForKey("isStage1",false);
    UserDefault::getInstance()->getBoolForKey("isStage2",false);
    UserDefault::getInstance()->getBoolForKey("isStage3",false);
    UserDefault::getInstance()->getBoolForKey("isStage4",false);
    UserDefault::getInstance()->getBoolForKey("isStage5",false);
    UserDefault::getInstance()->getBoolForKey("isStage6",false);
    UserDefault::getInstance()->getBoolForKey("isStage7",false);
    UserDefault::getInstance()->getBoolForKey("isStage8",false);
    UserDefault::getInstance()->getBoolForKey("isStage9",false);
    UserDefault::getInstance()->getBoolForKey("isStage10",false);
    UserDefault::getInstance()->getBoolForKey("isStage11",false);
    UserDefault::getInstance()->getBoolForKey("isStage12",false);
    UserDefault::getInstance()->getBoolForKey("isStage13",false);
    UserDefault::getInstance()->getBoolForKey("isStage14",false);
    UserDefault::getInstance()->getBoolForKey("isStage15",false);
    UserDefault::getInstance()->getBoolForKey("isStage16",false);
    UserDefault::getInstance()->getBoolForKey("isStage17",false);
    UserDefault::getInstance()->getBoolForKey("isStage18",false);
    UserDefault::getInstance()->getBoolForKey("isStage19",false);
    UserDefault::getInstance()->getBoolForKey("isStage20",false);
    UserDefault::getInstance()->getBoolForKey("isStage21",false);
    UserDefault::getInstance()->getBoolForKey("isStage22",false);
    UserDefault::getInstance()->getBoolForKey("isStage23",false);
    UserDefault::getInstance()->getBoolForKey("isStage24",false);
    UserDefault::getInstance()->getBoolForKey("isStage25",false);
    UserDefault::getInstance()->getBoolForKey("isStage26",false);
    UserDefault::getInstance()->getBoolForKey("isStage27",false);
    UserDefault::getInstance()->getBoolForKey("isStage28",false);
    UserDefault::getInstance()->getBoolForKey("isStage29",false);
    UserDefault::getInstance()->getBoolForKey("isStage30",false);
    
}

void MungGuGame::setPauseBtn(){
	pauseBtn = Sprite::create("pauseBtn.png");
	pauseBtn->setPosition(Point(winSize.width / 20, winSize.height * 9 / 10));
	//pauseBtn->setTag(TAG_SPRITE_PAUSEBTN);
	this->addChild(pauseBtn, 2);

	pauseBtn_ = Sprite::create("pauseBtn_.png");
	pauseBtn_->setPosition(Point(winSize.width / 20, winSize.height * 9 / 10));
	this->addChild(pauseBtn_, 2);
	//pauseBtn_->setTag(TAG_SPRITE_PAUSEBTN_);
	pauseBtn_->setVisible(false);
}

void MungGuGame::setPauseWindow(){//pauseWindow

	pauseWindow = Sprite::create("pauseWindow.png");
	pauseWindow->setPosition(Point(winSize.width / 2, winSize.height / 2));
	pauseWindow->setAnchorPoint(Point(0.5, 0.5));
	pauseWindow->setOpacity(230);
	//pauseWindow->setTag(TAG_SPRITE_PAUSEWINDOW);
	this->addChild(pauseWindow, 300);
	pauseWindow->setVisible(false);

	Rect pauseWindowRect = pauseWindow->getBoundingBox();

	resumeBtn = Sprite::create("resumeBtn.png");
	resumeBtn->setPosition(Point(20 + pauseWindowRect.getMinX() + ((pauseWindowRect.getMaxX() - pauseWindowRect.getMinX()) / 4), pauseWindow->getPositionY() + 50));
//	resumeBtn->setTag(TAG_SPRITE_RESUMEBTN);
	this->addChild(resumeBtn, 310);
	resumeBtn->setVisible(false);

	resumeBtn_ = Sprite::create("resumeBtn_.png");
	resumeBtn_->
		setPosition(Point(20 + pauseWindowRect.getMinX() + ((pauseWindowRect.getMaxX() - pauseWindowRect.getMinX()) / 4), pauseWindow->getPositionY() + 50));
	//resumeBtn_->setTag(TAG_SPRITE_RESUMEBTN_);
	this->addChild(resumeBtn_, 320);
	resumeBtn_->setVisible(false);

	goHomeBtn = Sprite::create("goHomeBtn.png");
	goHomeBtn->
		setPosition(Point(-20 + pauseWindowRect.getMinX() + ((pauseWindowRect.getMaxX() - pauseWindowRect.getMinX()) * 3 / 4), pauseWindow->getPositionY() + 50));
//	goHomeBtn->setTag(TAG_SPRITE_GOHOMEBTN);
	this->addChild(goHomeBtn, 310);
	goHomeBtn->setVisible(false);
    goHomeBtnRect = goHomeBtn->getBoundingBox();
    
  

	goHomeBtn_ = Sprite::create("goHomeBtn_.png");
	goHomeBtn_->
		setPosition(Point(-20 + pauseWindowRect.getMinX() + ((pauseWindowRect.getMaxX() - pauseWindowRect.getMinX()) * 3 / 4), pauseWindow->getPositionY() + 50));
//	goHomeBtn_->setTag(TAG_SPRITE_GOHOMEBTN_);
	this->addChild(goHomeBtn_, 320);
	goHomeBtn_->setVisible(false);
}

void MungGuGame::initPauseWindow(){
	resumeBtn->setVisible(true);
	// resumeBtn_->setVisible(false);
	pauseWindow->setVisible(true);
	bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){
		isSongBtn->setVisible(true);
	}
	else{
		isNotSongBtn->setVisible(true);
	}
	goHomeBtn->setVisible(true);
}


void MungGuGame::removePauseWindow(){
	resumeBtn->setVisible(false);
	resumeBtn_->setVisible(false);
	pauseWindow->setVisible(false);
	isSongBtn->setVisible(false);
	isNotSongBtn->setVisible(false);
	goHomeBtn->setVisible(false);
	goHomeBtn_->setVisible(false);

}

//쿨타임 셋팅
void MungGuGame::setCoolTime(){
    
    //위치 참고//
    //mungBtn->setPosition(Point(winSize.width * 19 / 60, 56 * sizeRate));
    //    whangGuBtn->setPosition(Point(mungBtn->getPositionX() + (30 * sizeRate), mungBtn->getPositionY() + 36));

    
    //SpriteFrameCache Practice
    //cooltime.plist를 읽어 각각의 이미지들, 즉 cooltime_0,1,2,3////을 캐시에 넣는다.
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("coolTime2.plist");
    //coolTime1 -> 2 변경
    
    //최초로 화면에 찍힐 스프라이트를 만들어 준다.
    Rect firstBtnRect = mungBtn->getBoundingBox();
    coolTime1 = Sprite::create("cooltime_0.png");//검은 원 배치
    coolTime1->setAnchorPoint(Point(0.5,0.5));
    coolTime1->setPosition(Point(firstBtnRect.getMidX(),firstBtnRect.getMidY()));
    coolTime1->setVisible(false);//일단 가려둠.
    coolTime1->setScale(sizeRate);
    this->addChild(coolTime1,45);
    
    Rect secondBtnRect = whangGuBtn->getBoundingBox();
    coolTime2 = Sprite::create("cooltime_0.png");//검은 원 배치
    coolTime2->setAnchorPoint(Point(0.5,0.5));
    coolTime2->setPosition(Point(secondBtnRect.getMidX(),secondBtnRect.getMidY()));
    coolTime2->setVisible(false);//일단 가려둠.
    coolTime2->setScale(sizeRate);
    this->addChild(coolTime2,45);
    
    Rect thirdBtnRect = mungBallBtn->getBoundingBox();
    coolTime3 = Sprite::create("cooltime_0.png");//검은 원 배치
    coolTime3->setAnchorPoint(Point(0.5,0.5));
    coolTime3->setPosition(Point(thirdBtnRect.getMidX(),thirdBtnRect.getMidY()));
    coolTime3->setVisible(false);//일단 가려둠.
    coolTime3->setScale(sizeRate);
    this->addChild(coolTime3,45);
    
    Rect fourthBtnRect = mungButterFlyBtn->getBoundingBox();
    coolTime4 = Sprite::create("cooltime_0.png");//검은 원 배치
    coolTime4->setAnchorPoint(Point(0.5,0.5));
    coolTime4->setPosition(Point(fourthBtnRect.getMidX(),fourthBtnRect.getMidY()));
    coolTime4->setVisible(false);//일단 가려둠.
    coolTime4->setScale(sizeRate);
    this->addChild(coolTime4,45);
    
    Rect fifthBtnRect = mungSausageBtn->getBoundingBox();
    coolTime5 = Sprite::create("cooltime_0.png");//검은 원 배치
    coolTime5->setAnchorPoint(Point(0.5,0.5));
    coolTime5->setPosition(Point(fifthBtnRect.getMidX(),fifthBtnRect.getMidY()));
    coolTime5->setVisible(false);//일단 가려둠.
    coolTime5->setScale(sizeRate);
    this->addChild(coolTime5,45);
    
    
    //animation을 만들 각각의 이미지를 담을 공간을 만들어 두자.
    Vector<SpriteFrame*> aniFrames;
    //파일명을 가지고 있을 변수를 하나 만든다.
    char str[20] = {0};
    //캐시 해놓은 이미지를 하나씩 가져와서
    for(int i=0; i<19; i++){
        sprintf(str,"cooltime_%d.png",i);//i 값에 따라 cooltime_0,1,2,.....등이 된다.
        //만들어진 파일명의 이미지를 캐시에서 가져와
        SpriteFrame* frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        //aniFrames에다가 넣는다.
        aniFrames.pushBack(frame);
    }
    //이렇게 사용할 이미지들이 준비된다.
    //Animation이랑 Animate가 이름이 비슷하면서 역할이 헷갈리는 경우가 있다.
    //Animation은 설정이라고 생각하고 움직이도록 하는 액션은 Animate라고 생각하면 될 듯 싶다.
    //준비된 이미지 프레임들을 0.1초 마다 바꿔 보여주도록 설정해서 animation을 만든다.
    
    bool m1 = UserDefault::getInstance()->getBoolForKey("m1");
    bool m2 = UserDefault::getInstance()->getBoolForKey("m2");
    bool m3 = UserDefault::getInstance()->getBoolForKey("m3");
    bool m4 = UserDefault::getInstance()->getBoolForKey("m4");
    bool m5 = UserDefault::getInstance()->getBoolForKey("m5");
    bool m6 = UserDefault::getInstance()->getBoolForKey("m6");
    bool m7 = UserDefault::getInstance()->getBoolForKey("m7");
    
    coolTimeFastValue = 0;
    if(m1==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m2==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m3==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m4==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m5==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m6==true){
        coolTimeFastValue+=0.02;
    }
    
    if(m7==true){
        coolTimeFastValue+=0.03;
    }
    
    //시작 시의 쿨타임 (화면 전환 감안)
    Animation *animation_mungf = Animation::createWithSpriteFrames(aniFrames,0.15f - 0.15f*coolTimeFastValue);
    Animation *animation_whangf = Animation::createWithSpriteFrames(aniFrames,0.19f - 0.19f*coolTimeFastValue);
    Animation *animation_mungBallf = Animation::createWithSpriteFrames(aniFrames,0.225f - 0.225f*coolTimeFastValue);
    Animation *animation_mungButf = Animation::createWithSpriteFrames(aniFrames,0.4f - 0.4f*coolTimeFastValue);
    Animation *animation_mungSausagef = Animation::createWithSpriteFrames(aniFrames,0.5f - 0.5f*coolTimeFastValue);
    
    Animation *animation_mung = Animation::createWithSpriteFrames(aniFrames,0.10f);
    Animation *animation_whang = Animation::createWithSpriteFrames(aniFrames,0.145f);
    Animation *animation_mungBall = Animation::createWithSpriteFrames(aniFrames,0.16f);
    Animation *animation_mungBut = Animation::createWithSpriteFrames(aniFrames,0.35f);
    Animation *animation_mungSausage = Animation::createWithSpriteFrames(aniFrames,0.53f);
    //animation설정을 이용하여 Animate 액션을 만든다.
    
    coolTimeAnimatef = Animate::create(animation_mungf); //이걸이제 사용하면 된다.
    coolTime2Animatef = Animate::create(animation_whangf); //이걸이제 사용하면 된다.
    coolTime3Animatef = Animate::create(animation_mungBallf); //이걸이제 사용하면 된다.
    coolTime4Animatef = Animate::create(animation_mungButf); //이걸이제 사용하면 된다.
    coolTime5Animatef = Animate::create(animation_mungSausagef); //이걸이제 사용하면 된다.
    
    
    coolTimeAnimate = Animate::create(animation_mung); //이걸이제 사용하면 된다.
    coolTime2Animate = Animate::create(animation_whang); //이걸이제 사용하면 된다.
    coolTime3Animate = Animate::create(animation_mungBall); //이걸이제 사용하면 된다.
    coolTime4Animate = Animate::create(animation_mungBut); //이걸이제 사용하면 된다.
    coolTime5Animate = Animate::create(animation_mungSausage); //이걸이제 사용하면 된다.
    
//    coolTime6Animate = Animate::create(animation_mung); //이걸이제 사용하면 된다.
//    coolTime7Animate = Animate::create(animation_mung); //이걸이제 사용하면 된다.
//    coolTime8Animate = Animate::create(animation_mung); //이걸이제 사용하면 된다.
//    coolTime9Animate = Animate::create(animation_mung); //이걸이제 사용하면 된다.
//    coolTime10Animate = Animate::create(animation_mung); //이걸이제 사용하면 된다.

    coolTimeAnimate->retain();
    coolTime5Animate->retain();
    coolTime2Animate->retain();
    coolTime3Animate->retain();
    coolTime4Animate->retain();//이걸 해야 된다...
//
    
    auto coolTimeAction1 = Sequence::create(coolTimeAnimatef,CallFunc::create(this,callfunc_selector(MungGuGame::firstBtnCoolTimeFinished)),NULL);
    auto coolTimeAction2 = Sequence::create(coolTime2Animatef,CallFunc::create(this,callfunc_selector(MungGuGame::btn2ndCoolTimeFinished)),NULL);
    auto coolTimeAction3 = Sequence::create(coolTime3Animatef,CallFunc::create(this,callfunc_selector(MungGuGame::btn3rdCoolTimeFinished)),NULL);
    auto coolTimeAction4 = Sequence::create(coolTime4Animatef,CallFunc::create(this,callfunc_selector(MungGuGame::btn4thCoolTimeFinished)),NULL);
    auto coolTimeAction5 = Sequence::create(coolTime5Animatef,CallFunc::create(this,callfunc_selector(MungGuGame::btn5thCoolTimeFinished)),NULL);
   
    coolTime1->setVisible(true);
    coolTime1->runAction(coolTimeAction1);
   
    //여기에 쿨타임 애니메이션 + 콜백함수
    coolTime2->setVisible(true);
    coolTime2->runAction(coolTimeAction2);
        //여기에 쿨타임 애니메이션 + 콜백함수
    coolTime3->setVisible(true);
    coolTime3->runAction(coolTimeAction3);

    //여기에 쿨타임 애니메이션 + 콜백함수
    coolTime4->setVisible(true);
    coolTime4->runAction(coolTimeAction4);

    //여기에 쿨타임 애니메이션 + 콜백함수
    coolTime5->setVisible(true);
    coolTime5->runAction(coolTimeAction5);
    
    
//    coolTime6Animate->retain();
//    coolTime7Animate->retain();
//    coolTime8Animate->retain();
//    coolTime9Animate->retain();
//    coolTime10Animate->retain();
    //계속 작동 시키고자 한다면 무한 반복을 수행 할 수도 있다.
   // auto actionCool = RepeatForever::create(animate);
   // coolTime->runAction(coolTimeAnimate);
}

//쿨타임 콜백함수
void MungGuGame::firstBtnCoolTimeFinished(){
    //쿨타임이 끝나면
    isFirstBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
    coolTime1->setVisible(false);
}
void MungGuGame::btn2ndCoolTimeFinished(){
    //쿨타임이 끝나면
    is2ndBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
    coolTime2->setVisible(false);
}
void MungGuGame::btn3rdCoolTimeFinished(){
    //쿨타임이 끝나면
    is3rdBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
    coolTime3->setVisible(false);
}
void MungGuGame::btn4thCoolTimeFinished(){
    //쿨타임이 끝나면
    is4thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
    coolTime4->setVisible(false);
}
void MungGuGame::btn5thCoolTimeFinished(){
    //쿨타임이 끝나면
    is5thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
    coolTime5->setVisible(false);
}
void MungGuGame::btn6thCoolTimeFinished(){
    //쿨타임이 끝나면 //
    is6thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
}
void MungGuGame::btn7thCoolTimeFinished(){
    //쿨타임이 끝나면 //
    is7thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
}
void MungGuGame::btn8thCoolTimeFinished(){
    //쿨타임이 끝나면 //
    is8thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
}
void MungGuGame::btn9thCoolTimeFinished(){
    //쿨타임이 끝나면 //
    is9thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
}
void MungGuGame::btn10thCoolTimeFinished(){
    //쿨타임이 끝나면 //
    is10thBtnCoolTimeFinished = true;//이러면 다시 재소환 가능
}

/////


void MungGuGame::setSongPlayedBtn(){

	//음악 옵션 버튼
	Point songBtnPos = Point(goHomeBtn->getPositionX(), goHomeBtn->getPositionY() + 100);
	isSongBtn = Sprite::create("isSongPlayedBtn.png");
	isSongBtn_ = Sprite::create("isSongPlayedBtn_.png");
	isNotSongBtn = Sprite::create("isNotSongPlayedBtn.png");
	isNotSongBtn_ = Sprite::create("isNotSongPlayedBtn_.png");

	isSongBtn->setPosition(songBtnPos);
	isSongBtn_->setPosition(songBtnPos);
	isNotSongBtn->setPosition(songBtnPos);
	isNotSongBtn_->setPosition(songBtnPos);

	isSongBtn->setAnchorPoint(Point(0, 0));
	isSongBtn_->setAnchorPoint(Point(0, 0));
	isNotSongBtn->setAnchorPoint(Point(0, 0));
	isNotSongBtn_->setAnchorPoint(Point(0, 0));

    isSongBtnRect = isSongBtn->getBoundingBox();

	this->addChild(isSongBtn, 310);
	this->addChild(isSongBtn_, 320);
	this->addChild(isNotSongBtn, 310);
	this->addChild(isNotSongBtn_, 320);

    
	isSongBtn->setVisible(false);
	isSongBtn_->setVisible(false);
	isNotSongBtn->setVisible(false);
	isNotSongBtn_->setVisible(false);

}

void MungGuGame::setBG()
{
	auto node = ParallaxNode::create();
	this->addChild(node);

	auto action_0 = MoveBy::create(36.0, Point(-winSize.width, 0));//이동시킨 후,
	auto action_1 = Place::create(Point::ZERO);//원상 복귀 시킴
	auto action_2 = Sequence::create(action_0, action_1, NULL);//이를 같이 묶어
	auto action_3 = RepeatForever::create(action_2); //무한반복한다.
	node->runAction(action_3);
	//원리 이해하자.
    if(isStage1==true){
	auto spr_1 = Sprite::create("bg1.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
	spr_1->setAnchorPoint(Point::ZERO);
	auto spr_0 = Sprite::create("bg1.png", Rect(0, 0, winSize.width, winSize.height));
	spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
	
    }else if(isStage2==true){
        auto spr_1 = Sprite::create("bg2.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg2.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage3==true){
        auto spr_1 = Sprite::create("bg3.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg3.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
    
    }else if(isStage4==true){
        auto spr_1 = Sprite::create("bg4.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg4.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage5==true){
        auto spr_1 = Sprite::create("bg5.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg5.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage6==true){
        auto spr_1 = Sprite::create("bg6.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg6.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage7==true){
        auto spr_1 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage8==true){
        auto spr_1 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage9==true){
        auto spr_1 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage10==true){
        auto spr_1 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage11==true){
        auto spr_1 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage12==true){
        auto spr_1 = Sprite::create("bg13.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg13.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage13==true){
        auto spr_1 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage14==true){
        auto spr_1 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage15==true){
        auto spr_1 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage16==true){
        auto spr_1 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage17==true){
        auto spr_1 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage18==true){
        auto spr_1 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage19==true){
        auto spr_1 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage20==true){
        auto spr_1 = Sprite::create("bg6.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg6.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage21==true){
        auto spr_1 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage22==true){
        auto spr_1 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg9.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage23==true){
        auto spr_1 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg10.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage24==true){
        auto spr_1 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg11.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage25==true){
        auto spr_1 = Sprite::create("bg13.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg13.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage26==true){
        auto spr_1 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage27==true){
        auto spr_1 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg7.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage28==true){
        auto spr_1 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg8.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage29==true){
        auto spr_1 = Sprite::create("bg2.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg2.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else if(isStage30==true){
        auto spr_1 = Sprite::create("bg3.png", Rect(0, 0, winSize.width, winSize.height));
        Rect spr_1Rect = spr_1->getBoundingBox();
        spr_1->setScale(winSize.width/spr_1Rect.size.width,1);
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg3.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        spr_0->setScale(winSize.width/spr_1Rect.size.width,1);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
        
    }else{
        auto spr_1 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        spr_1->setAnchorPoint(Point::ZERO);
        auto spr_0 = Sprite::create("bg12.png", Rect(0, 0, winSize.width, winSize.height));
        spr_0->setAnchorPoint(Point::ZERO);
        node->addChild(spr_1, 0, Point(1, 0), Point(winSize.width, 0));
        node->addChild(spr_0, 1, Point(1, 0), Point::ZERO);
    }
    
	whiteDot = Sprite::create("whiteDot.png");
	this->addChild(whiteDot, 100);
	whiteDot->setOpacity(160);
	whiteDot->setColor(Color3B::RED);
	Rect WhiteDotRect = whiteDot->getBoundingBox();
	whiteDot->setScale(winSize.width / WhiteDotRect.size.width, winSize.height / WhiteDotRect.size.height);
	whiteDot->setAnchorPoint(Point(0.5, 0.5));
	whiteDot->setPosition(Point(winSize.width / 2, winSize.height / 2));
	whiteDot->setVisible(false);

}

void MungGuGame::initAttackEffect(Monster* monster, EnemyMonster* enemyMonster){//아군의 공격 이펙트
    //적 공격 시 공격효과 위치가 상이(INU Monster의 경우 그렇다.)
	if ((isFirstStageLoser == false) && (isFirstStageClear == false)){
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");

		attackEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
		Rect catSiteRect = catSite->getBoundingBox();

		Rect mungRect = monster->getBoundingBox();
		//  attackEffect->setPosition(Point(catSiteRect.getMinX()+30+rand()%50,catSiteRect.size.height+rand()%30));
		Rect sprCatRect = enemyMonster->getBoundingBox();

		int attackEffectPosX = sprCatRect.getMinX() + enemyMonster->enemySizeDecreaseRate + rand() % (int)((sprCatRect.getMaxX() - sprCatRect.getMinX() - enemyMonster->enemySizeDecreaseRate));
		int attackEffectPosY = sprCatRect.getMinY() + rand() % (int)((sprCatRect.getMidY() - sprCatRect.getMinY()));

		attackEffect->setPosition
			(Point(attackEffectPosX, attackEffectPosY));

		attackEffect->setAnchorPoint(Point(0.5, 0.5));
		//attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
		this->addChild(attackEffect, 50);

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.06);

		for (int i = 0; i<6; i++) {
			auto attackEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));

			animation->addSpriteFrame(attackEffect);
		}


		auto attackEffectAnimate = Animate::create(animation);
		attackEffect->setScale(1.0);

		attackEffect->runAction(attackEffectAnimate);
	}
}


void MungGuGame::initEnemyAttackEffect(Monster* monster, EnemyMonster* enemyMonster){//적군의 공격 이펙트
	if ((isFirstStageLoser == false) && (isFirstStageClear == false)){
		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");
		attackEnemyEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
		// Rect catRect = enemyMonster->getBoundingBox();
		//  attackEffect->setPosition(Point(catSiteRect.getMinX()+30+rand()%50,catSiteRect.size.height+rand()%30));
		Rect sprMungRect = monster->getBoundingBox();

		int attackEffectPosX = sprMungRect.getMinX()-monster->mySizeDecreaseRate + rand() % (int)((sprMungRect.getMaxX() - sprMungRect.getMinX()-monster->mySizeDecreaseRate));
		int attackEffectPosY = sprMungRect.getMinY() + rand() % (int)((sprMungRect.getMidY() - sprMungRect.getMinY()));

		attackEnemyEffect->setPosition
			(Point(attackEffectPosX, attackEffectPosY));

		attackEnemyEffect->setAnchorPoint(Point(0.5, 0.5));////? 앵커포인트 어케 조절?
		this->addChild(attackEnemyEffect, 50);

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.06);

		for (int i = 0; i<6; i++) {
			auto attackEnemyEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
			animation->addSpriteFrame(attackEnemyEffect);
		}

		auto attackEffectAnimate = Animate::create(animation);
		attackEnemyEffect->setScale(1.0*winSize.width/1200);

		attackEnemyEffect->runAction(attackEffectAnimate);
	}
}


void MungGuGame::initFireEffect(){
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");

	attackEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");

	attackEffect->setPosition(Point(dogSite->getPositionX() + 60, dogSite->getPositionY() + 130));

	attackEffect->setAnchorPoint(Point(0.5, 0.5));
	//attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
	this->addChild(attackEffect, 5);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.08);

	for (int i = 0; i<6; i++) {
		auto attackEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
		animation->addSpriteFrame(attackEffect);
	}
	auto effectUp = MoveBy::create(0.6, Point(-13, 10));
	auto attackEffectAnimate = Animate::create(animation);
	//폭발하면서 약간 위로 뜸.
	FiniteTimeAction* dogSiteFireAction = Spawn::create(effectUp, attackEffectAnimate, attackEffectAnimate, NULL);//동시에 액션
	attackEffect->setScale(1.5*winSize.width/1200);
	attackEffect->runAction(dogSiteFireAction);

	//여기에 미사일 발사 함수까지 넣는다.
	//  void initMungFireMissile();

}

void MungGuGame::setMungFireMissile(){
	mungGuMissile = Sprite::create("mungGuMissile.png");//멍구 미사일
	mungGuMissile->setPosition(Point(dogSite->getPositionX() + 60, dogSite->getPositionY() + 110*(winSize.width/1200)));
	mungGuMissile->setAnchorPoint(Point(0, 0));
	mungGuMissile->setRotation(-20);//회전 셋팅
	mungGuMissile->setScale(1.2*winSize.width/1200);
	this->addChild(mungGuMissile, 10);
    mungGuMissile->setScale(dogSiteScaleRate);
	mungGuMissile->setVisible(false);
}

void MungGuGame::initMungFireMissile(){
	ccBezierConfig missileMove; //액션 테스트

	missileMove.controlPoint_1 = Point(missileGroundPos - winSize.height / 30, dogSite->getPositionY() + 200);
	missileMove.controlPoint_2 = Point(missileGroundPos - winSize.height / 30, dogSite->getPositionY() + 130);
	missileMove.endPosition = Point(missileGroundPos, ground->getPositionY() + 50);//50은 임의로 정한 값

	auto missileRotateAction0 = RotateTo::create(0.8, 95);
	auto missileMoveAction0 = BezierTo::create(0.8, missileMove);
	auto missileRotateAction = EaseIn::create(missileRotateAction0, 2.0);
	auto missileMoveAction = EaseIn::create(missileMoveAction0, 1.05);
	//    auto missileRotateAni = Animate::create(missileRotateAction);
	//    auto missileMoveAni = Animate::create(missileMoveAction);
	FiniteTimeAction* missileAction0 = Spawn::create(missileMoveAction, missileRotateAction, NULL);
	FiniteTimeAction* missileAction = Sequence::create(missileAction0, CallFunc::create(this, callfunc_selector(MungGuGame::initMissileEffect)), NULL);
	//,CallFunc::create(this,callfunc_selector(MungGuGame::initMissileAttackEffect))
	mungGuMissile->setVisible(true);
	mungGuMissile->runAction(missileAction);

}

void MungGuGame::initMissileEffect(){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
	mungGuMissile->setVisible(false);
	if (isSong == true){//폭발음
	//	int mungFireExplosionSound =
			SimpleAudioEngine::getInstance()->playEffect("mungFireExplosionSound.wav");
	}
	initMissileAttackEffect();

	setMungFireMissile();

}

void MungGuGame::initDogSite_fireReady(){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("dogSite_fire.plist");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	dogSite_fire =
		Sprite::createWithSpriteFrameName("dogSite_fire_0.png");
	for (int i = 0; i<5; i++){

		auto dogSite_fire = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("dogSite_fire_%d.png", i));

		animation->addSpriteFrame(dogSite_fire);
	}

	if ((isSong == true) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
		mungFireReadySound =
			SimpleAudioEngine::getInstance()->playEffect("mungFireReady.wav");
	}

	//멍구포 장전
	auto dogSite_fireAnimate = Animate::create(animation);
	dogSite->runAction(dogSite_fireAnimate);


}


void MungGuGame::initDogSite_fireCancel(){
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("dogSite_fire.plist");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	dogSite_fire =
		Sprite::createWithSpriteFrameName("dogSite_fire_0.png");
	for (int i = 0; i<5; i++){

		auto dogSite_fire = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("dogSite_fire_%d.png", i));

		animation->addSpriteFrame(dogSite_fire);
	}
	//멍구포 장전
	auto dogSite_fireAnimate = Animate::create(animation);
	auto dogSite_fireCancel = dogSite_fireAnimate->reverse();

	auto dogSite_fireCanCelAni = Sequence::create(dogSite_fireCancel, CallFunc::create(this, callfunc_selector(MungGuGame::mungFireFinished)), NULL);//취소시, 취소하는 동안 true 끝나면 false

	dogSite->runAction(dogSite_fireCanCelAni);


}

void MungGuGame::initDogSite_fire(){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("dogSite_fire.plist");
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.1);

	dogSite_fire =
		Sprite::createWithSpriteFrameName("dogSite_fire_0.png");

	auto animation1 = Animation::create();
	animation1->setDelayPerUnit(0.13);

	auto animation2 = Animation::create();
	animation2->setDelayPerUnit(0.13);

	auto dogSite_fire = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("dogSite_fire_%d.png", 5));
	animation1->addSpriteFrame(dogSite_fire);

	for (int i = 6; i<12; i++){

		auto dogSite_fire = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("dogSite_fire_%d.png", i));

		animation2->addSpriteFrame(dogSite_fire);
	}
	auto dogSite_fireAnimate2 = Animate::create(animation2);
	auto dogSite_fireAnimate1 = Animate::create(animation1);

	//중간에 발사 효과도 포함.
	FiniteTimeAction* dogSite_fireAni = Sequence::create(dogSite_fireAnimate1, CallFunc::create(this, callfunc_selector(MungGuGame::initFireEffect)), dogSite_fireAnimate2, CallFunc::create(this, callfunc_selector(MungGuGame::mungFireFinished)), NULL);//콜백함수를 처음으로 직접 써봤다.

	//멍구포 발사
	if (isSong == true){
	//	int mungFireSound =
			SimpleAudioEngine::getInstance()->playEffect("mungFireSound.wav");
	}

	dogSite->runAction(dogSite_fireAni);
}

bool MungGuGame::isAllMonsterDie(){
    for(EnemyMonster* sprCat : enemyMonsters){
        if(sprCat->now_hp > 0){
            return false;
        }
    }
    return true;
    
}

bool MungGuGame::isAllMungguDie(){
    for (Monster* sprMung : myMonsters) {
        if(sprMung->now_hp > 0){
            return false;
        }
        
    }
    return true;
}

//발사액션이 모두 끝나면 그때서야 다시 장전이 가능하다.
void MungGuGame::mungFireFinished(){
	isMungFire = false;
}

//적 초기화 함수/

//void MungGuGame::resetEnemyMonster(Ref *sender){
//	auto enemyMonster = (EnemyMonster*)sender;
//	enemyMonsters.eraseObject(enemyMonster);
	//this->addChild(enemyMonster);
//}
//void MungGuGame::resetMyMonster(Ref *sender){
//	auto myMonster = (Monster*)sender;
//	myMonsters.eraseObject(myMonster);
	//this->addChild(myMonster);
//}

int MungGuGame::getNearCatPos(){
    
    Rect catSiteRect = catSite->getBoundingBox();
    nearCatPos = catSitePos;
    if(isAllMonsterDie() == false){//적 몬스터가 있을때,
       
        
        for(EnemyMonster *sprCat : enemyMonsters){
            if(sprCat->now_hp > 0){
            Rect catRect = sprCat->getBoundingBox();//고양이 박스 생성
            int imsiCatPos = catRect.getMinX()+sprCat->enemySizeDecreaseRate;
            if(nearCatPos >= imsiCatPos){//만약 고양이의 위치가 고양이 기지보다 더 앞에 있으면,
                nearCatPos = imsiCatPos; //가장 가까운 적의 위치를 갱신한다.
            }
            }
            
        }
        return nearCatPos;
    }else{//적 몬스터 없을때,
     return nearCatPos;//적 기지가 가장 가까운 적의 위치
}
}

int MungGuGame::getNearMungPos(){
    Rect dogSiteRect = dogSite->getBoundingBox();
    nearMungPos = dogSitePos;
    if(isAllMungguDie() == false){//멍구가 있을때,
       
        
        for(Monster *sprMung : myMonsters){
            if(sprMung->now_hp > 0){
            Rect mungRect = sprMung->getBoundingBox();//멍구 박스 생성
            int imsiMungPos = mungRect.getMaxX()-sprMung->mySizeDecreaseRate;
            if(nearMungPos <= imsiMungPos){//만약 고양이의 위치가 고양이 기지보다 더 앞에 있으면,
                nearMungPos = imsiMungPos; //가장 가까운 적의 위치를 갱신한다.
            }
            }
        }
        return nearMungPos;
        
    }else{//적 몬스터 없을때,
      
        return nearMungPos;//적 기지가 가장 가까운 적의 위치
    }
}


//몬스터 충돌 알고리즘 구현 "18.07."
void MungGuGame::enemyInfrontConfirm(){//적 몬스터가 있는지 없는지를 확인하고 여부를 알려줌.
    
    //위치는 초기 적 기지 앞
    
    /////Munggu
    //if)적 몬스터가 있을때,
    //if)적 몬스터가 앞에없으면, => 이동한다. else)적 몬스터의 앞에 가게 되면, => 공격한다.
    
    //else if)적 몬스터가 없을떄,
    //if)적기지가 앞에 없으면 => 이동한다. else)적 기지 앞에 가게 되면, => 공격한다.
    Rect catSiteRect = catSite->getBoundingBox();
    for(Monster *sprMung : myMonsters){
        Rect mungRect = sprMung->getBoundingBox();
        
        int nearCatPos = getNearCatPos();//현재 가장 가까운 적 위치를 구한 뒤,
        if(mungRect.getMaxX()+sprMung->attackRangeValue < nearCatPos){//적이 없으면
            
            sprMung->monsterAction(ACTION_MOVE);//이동하고
            
        }else{//적이 있으면
            
            sprMung->monsterAction(ACTION_ATTACK);//공격한다.
            
            if(sprMung->isFinishAttackAction == true){
                sprMung->monsterAction(ACTION_MOVE);//이동하고
            }
            
        }
        //  catSiteHitted(sprMung);
        //  }
    }
}
    
void MungGuGame::mungguInfrontConfirm(){//멍구 몬스터가 있는지 없는지를 확인하고 여부를 알려줌.
    for(EnemyMonster *sprCat : enemyMonsters){
        Rect catRect = sprCat->getBoundingBox();
        int nearMungPos = getNearMungPos();//현재 가장 가까운 적 위치를 구한 뒤,
        if(catRect.getMinX()-sprCat->attackRangeValue > nearMungPos){//적이 없으면
            
            sprCat->monsterAction(ACTION_MOVE);//이동하고
            // }
        }else{//적이 있으면
            
            sprCat->monsterAction(ACTION_ATTACK);//공격한다.
            
            if(sprCat->isFinishAttackAction == true){
                sprCat->monsterAction(ACTION_MOVE);//이동하고
            }
        }
    }
}


void MungGuGame::update(float delta){

    
   
  

	if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
		srand((unsigned int)time(NULL));
    }else{
        //게임 끝날 경우, 타이머 다 안보이게 함
        for(Monster* sprMung : myMonsters){
            sprMung->mungEnergyTimer->setVisible(false);
        }
        for(EnemyMonster *sprCat : enemyMonsters){
            sprCat->catEnergyTimer->setVisible(false);
        }
    }
    
	Rect dogSiteRect = dogSite->getBoundingBox();
	Rect catSiteRect = catSite->getBoundingBox();

	catSiteRandX = rand() % (int)(catSiteRect.getMaxX() - 50 - (int)(catSiteRect.getMinX()) + 30) + (int)(catSiteRect.getMinX() + 30);
	catSiteRandY = rand() % (int)(catSiteRect.getMaxY() - 50 - (int)(catSiteRect.getMinY())) + (int)(catSiteRect.getMinY());

	dogSiteRandX = rand() % (int)(dogSiteRect.getMaxX() - 50 - (int)(dogSiteRect.getMinX()) + 30) + (int)(dogSiteRect.getMinX() + 30);
	dogSiteRandY = rand() % (int)(dogSiteRect.getMaxY() - 50 - (int)(dogSiteRect.getMinY())) + (int)(dogSiteRect.getMinY());
    
    
    enemyInfrontConfirm();//적이 앞에있는지 확인하는 알고리즘 함수 구현 (Ver 18.07.30)
    mungguInfrontConfirm();//멍구가 앞에 있는지 확인하는 알고리즘 함수 구현
    
    


	for (Monster* sprMung : myMonsters) {
		
	if ((isFirstStageLoser == true) || (sprMung->now_hp == 0)){
	//processing
	
	//myMonsters.popBack();
	
	
	sprMung->monsterAction(ACTION_DIE);
	myMonsters.eraseObject(sprMung); //..6
//
//    nearMungPos = dogSiteRect.getMaxX()-10;
	}
	break;
	}

	for (EnemyMonster* sprCat : enemyMonsters) {
	if (isEnemyMonsterAngry == true){//모두가 화난 상태이면,
	if (sprCat->isEnemyAngryed == false){//적들은 각자 분개함.
	sprCat->isEnemyAngryed = true;

	//고양이들이 화나면서 일어나는 효과
	sprCat->monsterAction(ACTION_ANGRY);
	}
	}

	if ((isFirstStageClear == true) || (sprCat->now_hp == 0)){

	//enemyMonsters.popBack();
   
	sprCat->monsterAction(ACTION_DIE);
	enemyMonsters.eraseObject(sprCat);
        
//    nearCatPos = catSiteRect.getMinX();

	}
	break;
	}



	/*
	 ///android
	//음악 중지
	//android
	if ((isNotSongBtnTouched == true) && (isSongBtnTouched == false)){
		if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
			if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == true)
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();

			if (audioCount>0){
				myMoney -= increasingMoney;
				Director::getInstance()->pause();
				goto EscapeFromUpdate;
			}
		}
	}
	//음악 재시작
	//android
	if ((isNotSongBtnTouched == false) && (isSongBtnTouched == false)){
		if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
			//audioEngine = SimpleAudioEngine::getInstance();
			if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == false)
				//SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
				if (::isSongPlayed == true)
					SimpleAudioEngine::getInstance()->playBackgroundMusic
					("background2.mp3", true);
			//미리 로딩해두니 음악 재색속도가 빨라졌다.

			if (audioCount>0){
				myMoney -= increasingMoney;
				Director::getInstance()->pause();
				goto EscapeFromUpdate;
			}
		}
	}
	*/

	if (isMungGuFireBtnTouched == true){
		if (isExploreRangeAction == false){
			isExploreRangeAction = true;
			initExploreMileStoneAction();//터치중 즉, 장전중일때 범위 지표가 움직임.
		}
	}
	else{
		if (isExploreRangeAction == true){
			isExploreRangeAction = false;
			setExploreMileStone();
		}
	}

	//배경음악 일시정지
	//SimpleAudioEngine::getInstance()->pauseBackGroundMusic();

	//배경음악 재시작 ->resumeBackGroundMusic();
	//배경음악 정지 ->stopBackgroundMusic();
	//배경음원 메모리 해제 SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);


	//버튼 효과
    if(whangLv==0){
        whangGuBtn->setVisible(false);
        whangGuBtn_->setVisible(true);
    }else{
	if (myMoney<whangCost||(is2ndBtnCoolTimeFinished==false)){
		//whangGuBtn_->setPosition(whangGuBtn->getPositionX(), whangGuBtn->getPositionY());
        
		whangGuBtn->setVisible(false);
		whangGuBtn_->setVisible(true);
	}else{
		if ((isWhangGuBtnTouched == false)){
			whangGuBtn->setVisible(true);
			whangGuBtn_->setVisible(false);
		}
	}
    }
    
    ////33333
    if(mungBallLv==0){
        mungBallBtn->setVisible(false);
        mungBallBtn_->setVisible(true);
    }else{
	if (myMoney<mungBallCost||(is3rdBtnCoolTimeFinished==false)){
		//버튼몬
        if(mungBallLv==0){
            mungBallBtn->setVisible(false);
            mungBallBtn_->setVisible(true);
        }else{
		mungBallBtn->setVisible(false);
		mungBallBtn_->setVisible(true);
        }
	}
	else{
		if (isMungBallBtnTouched == false){
			mungBallBtn->setVisible(true);
			mungBallBtn_->setVisible(false);
		}
	}
    }
    
    ////11111
	if ((myMoney<mungCost)||(isFirstBtnCoolTimeFinished==false)){
		//버튼몬
		mungBtn->setVisible(false);
		mungBtn_->setVisible(true);
	}
	else{
		if (isMungBtnTouched == false){
			mungBtn->setVisible(true);
			mungBtn_->setVisible(false);
		}
	}
    
    //44444
    if(mungButLv==0){
        mungButterFlyBtn->setVisible(false);
        mungButterFlyBtn_->setVisible(true);
    }else{
	if ((myMoney<mungButCost)||(is4thBtnCoolTimeFinished==false)){
		//버튼몬
        if(mungButLv==0){
            mungButterFlyBtn->setVisible(false);
            mungButterFlyBtn_->setVisible(true);
        }else{
		mungButterFlyBtn->setVisible(false);
		mungButterFlyBtn_->setVisible(true);
        }
	}
	else{
		if (isMungButBtnTouched == false){
			mungButterFlyBtn->setVisible(true);
			mungButterFlyBtn_->setVisible(false);
		}
	}
    }
    
    //55555
    if(mungSausageLv==0){
        mungSausageBtn->setVisible(false);
        mungSausageBtn_->setVisible(true);
    }else{
	if (myMoney<mungSausageCost||(is5thBtnCoolTimeFinished==false)){//600
		//버튼몬
        if(mungSausageLv==0){
            mungSausageBtn->setVisible(false);
            mungSausageBtn_->setVisible(true);
        }else{
		mungSausageBtn->setVisible(false);
		mungSausageBtn_->setVisible(true);
        }
	}
	else{
		if (isMungSausageBtnTouched == false){
			mungSausageBtn->setVisible(true);
			mungSausageBtn_->setVisible(false);
		}
	}
    }


  





	if ((catSiteNowHp <= 0) && (isFirstStageClear == false)){//고양이 체력이 0이고, 클리어상태가 아니면
		if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
			if (isSong == true){
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		//		stageClearSound =
					SimpleAudioEngine::getInstance()->playEffect("stageClear.mp3");
			}

			catSiteDestroyed();
			for (EnemyMonster* sprCat : enemyMonsters) {
				sprCat->now_hp = 0;
				enemyMonsterNum = 0;
				sprCat->monsterAction(ACTION_DIE);//적 진영 패배시 전 자동 전멸
				nearCatPos = dogSiteRect.getMaxX();
			}
			enemyMonsters.clear();
            if(isStage18==true){//함정 이벤트
                
            }else{
			this->schedule(schedule_selector(MungGuGame::catSiteDestroyedEffect), 0.01);
            }
			if (isFirstStageLoser == false)
				initGameClearEvent();//클리어 창이 생김.
			gold_Label->setString(StringUtils::format("%d", goldForStage));//클리어시 받는 골드 체크

		}

	}
	if ((dogSiteNowHp <= 0) && (isFirstStageLoser == false)){//아군 기지 체력이 0이고, 클리어상태가 아니면
		if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
			if (isSong == true){
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();
			//	stageLoserSound =
					SimpleAudioEngine::getInstance()->playEffect("stageLoser.mp3");
			}
            if(isStage18==true){
                sinBtn->setVisible(false);
                sinBtn_->setVisible(false);
                ///게임 오버 되면 바뀜. 역시태
                youWin->setVisible(false);
                gold_Label->setVisible(false);
                homeBackBtn->setVisible(false);
            }
			dogSiteDestroyed();
			for (Monster* sprDog : myMonsters) {
				sprDog->now_hp = 0;
				myMonsterNum = 0;
				sprDog->monsterAction(ACTION_DIE);//적 진영 패배시 전 자동 전멸
			//	nearMungPos = dogSiteRect.getMaxX();
			}
			myMonsters.clear();
			this->schedule(schedule_selector(MungGuGame::dogSiteDestroyedEffect), 0.02);
			if (isFirstStageClear == false)
				initGameLoserEvent();//클리어 창이 생김.
		}
	}
	//*인자의 순서 = 주기적으로 호출할 함수/ 호출주기 / 반복횟수 / 호출 시작시간
	//addMonster(MONSTER_MUNGGU,Point(dogSite->getPositionX(),dogSite->getPositionY()-20-rand()%10));
	//Cat_boss
	if ((isFirstStageClear == false) && (isFirstStageLoser == false) &&(isTutorialFinished == true)){ //적기지와 아군 기지의 체력을 체크 상태를 변화, 적 생성 수 설정
//        bool isStage1 = UserDefault::getInstance()->getBoolForKey("isStage1");
//        bool isStage2 = UserDefault::getInstance()->getBoolForKey("isStage2");
//        bool isStage3 = UserDefault::getInstance()->getBoolForKey("isStage3");
		//*scheduler의 다양한 기능
		//unschedule(schedule_selector(호출한 메소드명)):특정 스케쥴만 중지 시킬때
		//unscheduleAllSeletors():호출한 모든 스케줄을 중지할 때
		//unscheduleUpdate() : update()스케줄만 중지할 때
        
        //2/9일 문제 없음
        if(isStage6 == true){
            /// 스테이지6 ///
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 120, 3, 300);//20
		if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
            if(isFirstGenFinished==false){
                isFirstGenFinished=true;
			catSiteHp_label->setColor(Color3B(20, 100, 20));
			this->schedule(schedule_selector
				(MungGuGame::addCatBabyMonster), rand() % 2 + 5, 30, 6);//6
			this->schedule(schedule_selector
				(MungGuGame::addCatMonster), rand() % 3 + 10, 1, 20);//20
            }
           
		}
		else if (catSiteNowHp >= catSiteMaxHp / 4){
            
            if(isSecondGenFinished==false){
                isSecondGenFinished=true;
			catSiteHp_label->setColor(Color3B(100, 100, 20));
			// unscheduleUpdate();
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 2);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 0, 5);//20
            }
		}
		else{
            if(isThirdGenFinished==false){
                isThirdGenFinished=true;
			if ((isEnemyMonsterAngry == false) && (enemyMonsterAngryCheck == false)){
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();

				auto act = Blink::create(1, 13);
				whiteDot->runAction(act);
				////
				auto act0 = DelayTime::create(1.0);
				auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
				runAction(action);
				//분노 이벤트
				enemyMonsterAngryCheck = true;
				for (Monster* sprMung : myMonsters){ //적의 분노모드
					sprMung->now_hp = 0;
					sprMung->monsterAction(ACTION_DIE);	
					
				}
                initStageTalk();
				nearMungPos = dogSiteRect.getMaxX()-10;
				myMonsters.clear();

            
			}
       
			catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 4, 100, 1);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 13, 4, 3);//20
            }
		  }
        }else if(isStage1==true){
            
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 600);//20
            /// 스테이지1 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 12 + 13, 5, 6);//6
                }
//                this->schedule(schedule_selector
//                               (MungGuGame::addCatJoe), rand() % 2 + 50, 2, 1);//6
//            this->schedule(schedule_selector
//                           (MungGuGame::addCatNamGu), rand() % 2 + 50, 2, 1);//6
//        
                //여여기기
                
                
            }else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
//                    //물러나게 하기 이벤트
//                    auto act = Blink::create(1, 13);
//                    whiteDot->setColor(Color3B(200,230,230));
//                    whiteDot->runAction(act);
//                    ////
//                    auto act0 = DelayTime::create(1.0);
//                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
//                    ///여기몬
//                    
//                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
//                    if(isSong == true){//song 켰나 안켯나 확인
//                        int disabledSong =
//                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
//                    }
//                    runAction(action);
//                    for (Monster* sprMung : myMonsters) {
//                        sprMung->monsterAction(ACTION_HITTED);
//                    }
//                    /////////////////////
//                    this->schedule(schedule_selector
//                                   (MungGuGame::addCatInuMonster), rand() % 1+2, 5, 0.5);//6
                   
                    
                catSiteHp_label->setColor(Color3B(100, 100, 20));

                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 15, 6, 2);//6
                }
                
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    this->unschedule(schedule_selector(MungGuGame::addCatBabyMonster));
                   
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 5, 3, 3);//6
                }
            }
            
        }else if(isStage2==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            /// 스테이지2 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 6 + 13, 6, 6);//6
                    
                }
                
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 13, 10, 5);//6
                }
                
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 12, 16, 1.5);//6
                }
            }
            
        }else if(isStage3==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            /// 스테이지3 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 10, 6);//6
                  
                }
                
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 13, 20, 0);//6
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 16, 100, 0.8);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 0, 0.5);//20
                }
            }
            
        }else if(isStage4==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            /// 스테이지3 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 13, 100, 6);//6
                }
                
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 12, 100, 0);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 0, 6);//20
                }
        
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 12, 100, 0);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 0, 1);//20
                }
            }
            
        }else if(isStage5==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            /// 스테이지3 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 12, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 1, 26);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 5 + 8, 100, 1);//6
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 10, 100, 1);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 1, 0, 5);//20
                }
            }
            
        }else if(isStage7==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20


            /// 스테이지7 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 0, 0, 50);//7
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 10, 100, 3);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 20, 3, 10);//20
                }
                
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 8, 100, 1);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 3 + 12, 1, 1);//20
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 8, 100, 1);//6
                }
            }
            
        }else if(isStage8==true){
            
          
            
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
            
            
            /// 스테이지8 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                
   
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 7, 100, 4);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 16, 3, 15);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 7, 100, 1);//6
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 6, 100, 0);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 8, 15, 5);//20
                    this->schedule(schedule_selector//
                                   (MungGuGame::addCatInuMonster), 0, 0, 1);//6
                }
            }
            
        }else if(isStage9==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
            /// 스테이지3 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 5 + 6, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 8 + 6, 10, 5);//20

                    
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 15, 2, 3);//6

                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 6, 100, 1);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 6 + 10, 2, 1);//20
                }
                
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 0.5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 10, 3, 1);//20
                }
            }
            
        }else if(isStage10==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
          
            /// 스테이지10 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 38, 3, 20);//6
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), 0, 0, 45);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 6, 100, 6);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 20, 2, 20);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5.5, 100, 0.5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 1 + 13, 3, 6);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), 0, 0, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 0, 0, 1);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 5, 100, 0.5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 9, 2, 5);//20
                }
            }
            
        }else if(isStage11==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
            
            /// 스테이지11 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 50, 12, 30);//
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 6);//
                   
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 10, 2, 6);//20
                   
                    
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 50, 12, 0.5);//
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), 0, 0, 1.5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 3 + 4.7, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 15, 1.5);//20
                }
            }
            
        }else if(isStage12==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
            
            /// 스테이지12 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 50, 3, 20);//6
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 1 + 4, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 6 + 5, 20, 6);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 4, 100, 5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 7, 10, 6);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), 0, 0, 1);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 3 + 3, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 8, 15, 5);//20
                }
            }
            
        }else if(isStage13==true){
           
            if(isInitSinTaeDoll==true){
                isInitRedriverMusic = true;
                
                
                if ((isEnemyMonsterAngry == false) && (enemyMonsterAngryCheck == false)){
                    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
                    
                    auto act = Blink::create(1, 13);
                    whiteDot->runAction(act);
                    ////initSinTaeDoll
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0,CallFunc::create(this, callfunc_selector(MungGuGame::initSinTaeDoll)), CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)),CallFunc::create(this, callfunc_selector(MungGuGame::initStageTalk)), NULL);
                    runAction(action);
                    //분노 이벤트
                    enemyMonsterAngryCheck = true;
                    for (Monster* sprMung : myMonsters){ //적의 분노모드
                        sprMung->now_hp = 0;
                        sprMung->monsterAction(ACTION_DIE);	
                        
                    }
                    nearMungPos = dogSiteRect.getMaxX()-10;
                    myMonsters.clear();
                }
            }

            
            /// 스테이지13 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                     catSiteHp_label->setColor(Color3B(20, 100, 20));
                    if(!isInitSinTaeDoll){
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
                   
                    
                    }

                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 20 + 20, 3, 33);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 8, 50, 12);//20
                
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 30, 3);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 10 + 5, 2, 4.5);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 5 + 5, 30, 1);//20
                }
            }
            
        }else if(isStage14==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 230);//20
            
            /// 스테이지14 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                     catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 30, 3, 20);//6
                   
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 12, 2, 9);//20
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 2, 100, 6);//6

                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 20 + 15, 2, 23);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 10, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 12, 6, 6);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 2 + 18, 2, 3);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 2 + 13, 1, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 8, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 8, 10, 3);//20

                }
            }
            
        }else if(isStage15==true){
//            this->schedule(schedule_selector
//                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 200);//20
            
            /// 스테이지15 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), rand()%3+2, 3, 300);//20
                
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 30, 5, 30);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), 20, 6, 15);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 100, 6);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 7, 10, 18);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                            (MungGuGame::addCatBabyMonster), rand() % 1 + 0.5, 100, 1.5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 2 + 7, 10, 1);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 1 + 0.5, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 2 + 6, 10, 2);//20
                }
            }
            
        }else if(isStage16==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 260);//20
            /// 스테이지16 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 25, 5, 20);//20
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 1 + 2, 100, 8);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 2 + 3, 100, 8);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 1 + 4, 100, 2);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 2 + 7, 100, 5);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatNamGu), rand() % 2 + 3, 5, 16);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                 catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 2, 100, 3);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 2 + 3, 100, 2);//20
                }
            }
            
        }else if(isStage17==true){
            
            /// 스테이지17 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), 60, 3, 260);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 6 + 3, 100, 10);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 5 + 8, 100, 17);//20
                   
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 1, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 8 + 5, 100, 2);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatInuMonster), rand() % 20 + 20, 10, 3);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                 catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 6 + 1, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 6 + 4, 100, 2);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu), rand() % 2 + 3, 16, 5);//20
                }
            }
            
        }else if(isStage18==true){
            
            /// 스테이지18 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatSinTaeDollMonster), 60, 3, 240);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 100, 28);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 6 + 23, 13, 5);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 30 + 20, 2, 50);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 15 + 40, 2, 105);//20
                }
                
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu), rand() % 2 + 13, 12, 8);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 1.5, 100, 28);//6
                }
                
            }else{ if(isThirdGenFinished==false){
                isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), rand() % 2+4 ,4, 2);//20
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatInuMonster), rand() % 2+1 ,2, 1);//20
            }
            }
            
            
        }else if(isStage19==true){
            
           
            
            /// 스테이지19 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatSinTaeDollMonster), 60, 3, 240);//20
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 6 + 2, 100, 18);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 5 + 7, 100, 37);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 15 + 24, 6, 10);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 2, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 16 + 14, 100, 12);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 5 + 20, 2, 1);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 1, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu), rand() % 3 + 1, 18, 1.5);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 6 + 5 ,2, 4);//20
                }
            }
            
        }else if(isStage20==true){
            
            /// 스테이지20 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), 100, 1, 300);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatInuMonster), rand() % 25 + 33 ,10, 85);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatNamGu), rand() % 2 + 12, 50, 63);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 10 + 5, 100, 5);//6
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatNamGu), rand() % 3 + 3, 30, 43);//20
                    
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                     catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), 0, 0, 1.5);//20
                }
                
            }
            
        }else if(isStage21==true){
            
            
            
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            
            
            /// 스테이지21 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 5 + 7, 100, 3);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 15, 12, 15);//20
                 
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 5 + 23 ,10, 35);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 5 + 32 ,2, 6);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 1);//6
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 6 + 10 ,2, 3);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 10+6 ,5, 1);//20
                }
            }
            
        }else if(isStage22==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            /// 스테이지3 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 5 + 4, 100, 5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 8 + 6, 10, 5);//20
                    this->schedule(schedule_selector//
                                   (MungGuGame::addCatInuMonster), 1, 2, 30);//6
                    
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 15, 3, 3);//6
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 6 + 6, 1, 1);//20
                }
                
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 3, 4, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu),rand() % 3 + 1.5,13,1.5);//6
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 6, 100, 0.5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 3, 1);//20
                }
            }
            
        }else if(isStage23==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 5 + 4, 100, 5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 8 + 3, 10, 15);//20
                    this->schedule(schedule_selector//
                                   (MungGuGame::addCatNamGu), 1, 4, 30);//6
                    
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 15, 3, 3);//6
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 6 + 6, 1, 1);//20
                }
                
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    
                    this->schedule(schedule_selector//
                                   (MungGuGame::addCatNamGu), rand() % 2 + 6, 13, 1);//6
                    
                    this->schedule(schedule_selector//
                                   (MungGuGame::addCatInuMonster), rand() % 2 + 16, 2, 3);//6

                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 6, 2, 1);//
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 6, 100, 0.5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 3, 1);//20
                }
            }
            
        }else if(isStage24==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            
            /// 스테이지11 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 40 + 30, 3, 20);//
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu), rand() % 30 + 13, 1, 10);//
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 50, 12, 20);//
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 6);//
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 10, 3, 6);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatNamGu), rand() % 2 + 1, 8, 2);//
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 3 + 4, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 15, 3);//20
                }
            }
            
        }else if(isStage25==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            
            /// 스테이지25 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 50, 3, 20);//6
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 1 + 3, 100, 12);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 6 + 5, 20, 16);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 4, 100, 5);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 5, 10, 6);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 3 + 6, 2, 2);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 3 + 2, 100, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 15, 2.5);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 3 + 3, 2, 31);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), rand() % 3 + 8, 1, 1.5);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 3 + 6, 2, 0.5);//20
                }
            }
            
        }else if(isStage26==true){
            
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
//                    if(!isInitSinTaeDoll){
                        this->schedule(schedule_selector
                                       (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
//
//                        
//                    }
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster), rand() % 1 + 1, 1, 35);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 20 + 20, 3, 33);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 7, 50, 23);//20
                    
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 30, 3);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), rand() % 1 + 3, 30, 5);//6
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 5 + 5, 30, 1);//20
                }
            }
            
        }else if(isStage27==true){
            this->schedule(schedule_selector
                           (MungGuGame::addCatSinTaeDollMonster), 60, 3, 300);//20
            
            /// 스테이지27 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 9, 2, 9);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 2, 100, 7);//6
                    
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                   
                    
                    //몸빵 고양이와 죠 남구의 콜라보
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), rand() % 5 + 23, 5, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), rand() % 2 + 5, 6, 2);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), rand() % 2 + 23, 4, 4.5);//6

                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 30, 3);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 11, 16, 6);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 100, 1);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 6, 30, 2);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatJoe), 10, 2, 2);//20
                }
            }
            
        }else if(isStage28==true){ //질문 함정.
          
            /// 스테이지28 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), rand()%3+2, 3, 360);//20
                
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                    catSiteHp_label->setColor(Color3B(20, 100, 20));
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 2 + 3, 100, 6);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 7, 10, 18);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 100, 20));
                    
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addBigCatMonster), 30, 5, 23);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatInuMonster),rand() % 10 + 10, 6, 1);//6
                    
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBabyMonster), rand() % 5 + 0.5, 100, 6);//6
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 3 + 7, 10, 1);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                    catSiteHp_label->setColor(Color3B(100, 20, 20));
                    //물러나게 하기 이벤트
                    auto act = Blink::create(1, 13);
                    whiteDot->setColor(Color3B(200,230,230));
                    whiteDot->runAction(act);
                    ////
                    auto act0 = DelayTime::create(1.0);
                    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                    ///여기몬
                    
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                    }
                    runAction(action);
                    for (Monster* sprMung : myMonsters) {
                        sprMung->monsterAction(ACTION_HITTED);
                    }
                    /////////////////////
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatMonster), rand() % 2 + 6, 10, 2);//20
                    this->schedule(schedule_selector
                                   (MungGuGame::addCatBase), rand() % 5 + 2 ,2, 1.5);//20
                }
            }
            
        }else if(isStage29==true){
           
        
            /// 스테이지29 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), 60, 3, 360);//20
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 25, 5, 40);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), 0, 0, 13);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatNamGu), rand() % 3 + 2, 30, 62);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatJoe), rand() % 5 + 13, 30, 76);//20
            }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                //물러나게 하기 이벤트
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                auto act = Blink::create(1, 13);
                whiteDot->setColor(Color3B(200,230,230));
                whiteDot->runAction(act);
                ////
                auto act0 = DelayTime::create(1.0);
                auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
                ///여기몬
                
                bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                if(isSong == true){//song 켰나 안켯나 확인
                    int disabledSong =
                    SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
                }
                runAction(action);
                for (Monster* sprMung : myMonsters) {
                    sprMung->monsterAction(ACTION_HITTED);
                }
                /////////////////////
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 1 + 4, 100, 2);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 2 + 7, 100, 5);//20
                this->schedule(schedule_selector
                               (MungGuGame::addBigCatMonster), 30, 5, 1);//20
                }
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;

                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 5 + 3, 100, 3);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 1, 100, 2);//20
                }
            }
            
        }else if(isStage30==true){//못깸..
            
            /// 스테이지30 ///
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                this->schedule(schedule_selector
                               (MungGuGame::addCatJoe), rand() % 10 + 16, 23, 20.5);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 6 + 3, 100, 20);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 6 + 5, 100, 32);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                //신태돌이 있는 30스테이지는 클리어가 불가
                this->schedule(schedule_selector
                               (MungGuGame::addCatSinTaeDollMonster), rand() % 20 + 26, 3, 202);
                
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 1, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 8 + 5, 100, 2);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatInuMonster), rand() % 10 + 20, 13, 3);//20
                this->schedule(schedule_selector
                               (MungGuGame::addCatNamGu), rand() % 5 + 1, 38, 3);//20
                }
                
            }else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;

                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 6 + 1, 100, 5);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 6 + 4, 100, 2);//20
                }
            }
            
        }else{
            
          //디폴트 스테이지//
            if (catSiteNowHp >= catSiteMaxHp * 3 / 5){
                if(isFirstGenFinished==false){
                    isFirstGenFinished=true;
                catSiteHp_label->setColor(Color3B(20, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 1, 6);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 10, 10, 20);//20
                }
            }
            else if (catSiteNowHp >= catSiteMaxHp / 4){
                if(isSecondGenFinished==false){
                    isSecondGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 100, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 2 + 5, 1, 6);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 10, 10, 20);//20
                }
            }
            else{
                if(isThirdGenFinished==false){
                    isThirdGenFinished=true;
                catSiteHp_label->setColor(Color3B(100, 20, 20));
                this->schedule(schedule_selector
                               (MungGuGame::addCatBabyMonster), rand() % 3 + 2, 1, 6);//6
                this->schedule(schedule_selector
                               (MungGuGame::addCatMonster), rand() % 3 + 5, 10, 20);//20
                }
            }
            
        }


		if (dogSiteNowHp >= dogSiteMaxHp * 3 / 5){
			dogSiteHp_label->setColor(Color3B(20, 100, 20));
		}
		else if (dogSiteNowHp >= dogSiteMaxHp / 5){
			dogSiteHp_label->setColor(Color3B(100, 100, 20));
		}
		else{
			dogSiteHp_label->setColor(Color3B(100, 20, 20));
            
		}
	}
	else{
		//클리어되면, 스케쥴러 중지
        if(isStage18==true){
            this->unschedule(schedule_selector(MungGuGame::addCatBabyMonster));
            this->unschedule(schedule_selector(MungGuGame::addCatMonster));
            this->unschedule(schedule_selector(MungGuGame::addCatSinTaeDollMonster));
            this->unschedule(schedule_selector(MungGuGame::addBigCatMonster));
            this->unschedule(schedule_selector(MungGuGame::addCatInuMonster));
            this->unschedule(schedule_selector(MungGuGame::addCatNamGu));
        }else{
		this->unschedule(schedule_selector(MungGuGame::addCatBabyMonster));
		this->unschedule(schedule_selector(MungGuGame::addCatMonster));
        this->unschedule(schedule_selector(MungGuGame::addCatSinTaeDollMonster));
        this->unschedule(schedule_selector(MungGuGame::addBigCatMonster));
        this->unschedule(schedule_selector(MungGuGame::addCatInuMonster));
        this->unschedule(schedule_selector(MungGuGame::addCatNamGu));
        this->unschedule(schedule_selector(MungGuGame::addCatJoe));
        }

	}



	if (isInitMissile == true){//미사일이 생길때,
		missileGroundPos = (exploreMileStone2->getPositionX() + exploreMileStone->getPositionX()) / 2; //gound 미사일 투하 위치를 알아내고
		isInitMissile == false;//그 상태를 유지함.
		if (isEnemyMonsterHitted == true){
			//   isEnemyMonsterHitted=false;

		}
	}
	else{
		if (isMungFire == false){///? 왜 될까 나중ㅇ ㅔ 생 각
			isInitMissile = true;
			missileGroundPos = (exploreMileStone2->getPositionX() + exploreMileStone->getPositionX()) / 2;
		}
	}

	if (isEnemyMonsterHitted == true){
		isEnemyMonsterHitted = false;
        //기지 공격의 경우
       
        if ((catSiteRect.getMaxX()-30 >= (nowMissileGroundPos - exploreRange / 2)) && (catSiteRect.getMinX()+30 <= (nowMissileGroundPos + exploreRange* 7 / 10))){
            
            decreasedCatSiteHp(missileDamage);
        }
        
		for (EnemyMonster* sprCat : enemyMonsters) {

			//nowMissileGroundPos = missileGroundPos;
            ///미 사 일 공 격 범 위///
            
             Rect sprCatRect = sprCat->getBoundingBox();
			if ((sprCatRect.getMaxX() >= (nowMissileGroundPos - exploreRange / 2)) && (sprCatRect.getMinX()+sprCat->enemySizeDecreaseRate <= (nowMissileGroundPos + exploreRange* 7 / 10))){

				if (sprCat->now_hp>missileDamage){
					sprCat->now_hp -= missileDamage;
					sprCat->monsterAction(ACTION_HITTED);
                    //    nearCatPos = catSiteRect.getMinX();
				}
				else{
					sprCat->now_hp = 0;
                   // nearCatPos = catSiteRect.getMinX();
					//추가추가

				}
            }
        }
	}


	if ((isFirstStageLoser == false) && (isFirstStageClear == false)){
        if(isTutorialFinished==true){
		changeMyMoney();///돈이 올라가는 부분, 시간에 정확하게 맞춰 올라야 한다...
        }
	}
	else{
		catSiteHp_label->setVisible(false);
		dogSiteHp_label->setVisible(false);
	}

        
	changeCatSiteHp();
	changeDogSiteHp();
	changeStatusBar();
	changeStatusCost();


EscapeFromUpdate:
	{
		audioCount = 0;
		//음악 설정후 나머지 건너뜀
	}


}


void MungGuGame::nextMusicStart(){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){//song 켰나 안켯나 확인
	SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
    }
}

void MungGuGame::setMissileAttackEffect(){

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");
	missileEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
	// missileEffect->setAnchorPoint(Point(0.5,0.5));
	missileEffect->setScale(2.0*winSize.width/1200);
	//attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
	missileEffect->setVisible(false);
	this->addChild(missileEffect, 20);

}

void MungGuGame::initMissileAttackEffect(){//미사일 공격 이펙트
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");
	missileEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
	missileEffect->setAnchorPoint(Point(0.5, 0.6));
	missileEffect->setScale(2.1*winSize.width/1200);
	//attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
	missileEffect->setVisible(false);
	this->addChild(missileEffect, 20);
    
    
    float effectSizeRate = UserDefault::getInstance()->getIntegerForKey("mungGuDogSitePoLv");
    missileEffect->setScale(1 + 0.03*effectSizeRate);

	missileEffect->setPosition(mungGuMissile->getPositionX(), ground->getPositionY()-6);
	missileEffect->setVisible(true);
	auto animation = Animation::create();
	animation->setDelayPerUnit(0.07);

	for (int i = 0; i<6; i++) {
		auto missileEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
		animation->addSpriteFrame(missileEffect);
	}
	auto effectUp = MoveBy::create(0.3, Point(-10, 30));
	auto missileEffectAnimate0 = Animate::create(animation);
	FiniteTimeAction* missileEffectAnimate = Spawn::create(missileEffectAnimate0, effectUp, NULL);

	isEnemyMonsterHitted = true; //범위 내의 적은 맞아 날부라짐

	nowMissileGroundPos = mungGuMissile->getPositionX();
	missileEffect->runAction(missileEffectAnimate);

}


void MungGuGame::sizeCheck(){

	if (winWidth <= 960){//아이폰4는 640의 높이, 960의 너비를 가짐/ 아이폰5는 1136의 너비를 가짐
		sizeRate = 0.8;
	}
	else{
		sizeRate = 0.9;
	}
	//정지 버튼

}


void MungGuGame::setFireBtn(){
	mungCoFireBtn = Sprite::create("mungFireBtn.png");
	mungCoFireBtn->setPosition(Point(0, 0));
	mungCoFireBtn->setAnchorPoint((Point(0, 0)));
    mungCoFireBtn->setVisible(false);
	this->addChild(mungCoFireBtn, 2);
    
    mungFireCoolTime = Sprite::create("mungFireCoolTime.png");
    mungFireCoolTime->setPosition(Point(0, 0));
    mungFireCoolTime->setAnchorPoint((Point(0, 0)));
    
    //this->addChild(mungFireCoolTime, 3);
    
    mungFireTimer = ProgressTimer::create(mungFireCoolTime);
    mungFireTimer->setType(ProgressTimer::Type::BAR);
    
    mungFireTimer->setMidpoint(Point(1,0));
    mungFireTimer->setBarChangeRate(Point(1,0));
    mungFireTimer->setPosition(Point(0, 0));
    mungFireTimer->setAnchorPoint((Point(0, 0)));
    this->addChild(mungFireTimer,3);

    //쿨타임 액션
    auto to1 = ProgressTo::create(5,100);
    auto timerAct = ReverseTime::create(to1);
    timerAction = Sequence::create(timerAct,CallFunc::create(this,callfunc_selector(MungGuGame::mungFireCoolTimeFinish)),NULL);
    mungFireTimer->runAction(timerAction);
    
    
	mungCoFireBtn_ = Sprite::create("mungFireBtn_.png");
	mungCoFireBtn_->setPosition(Point(0, 0));
	mungCoFireBtn_->setAnchorPoint((Point(0, 0)));
	// mungCoFireBtn->setScale(sizeRate);
	//mungCoFireBtn_->setTag(TAG_MUNGGUFIREBTN_);
	this->addChild(mungCoFireBtn_, 2);
	mungCoFireBtn_->setVisible(true);
    
    //멍포비용 라벨
    Rect mungCoFireBtnRect = mungCoFireBtn->getBoundingBox();
    statusCost_mungPo = Label::createWithTTF //상태버튼 power
    (StringUtils::format("%d", mungPoCost), "NanumBarunGothicBold.otf", 26);
    statusCost_mungPo->setAnchorPoint(Point(1, 0.5));
    statusCost_mungPo->setColor(Color3B(20,20,20));
    statusCost_mungPo->setPosition(Point(mungCoFireBtnRect.getMaxX()-10, 20));
    statusCost_mungPo->setColor(Color3B::BLACK);
    this->addChild(statusCost_mungPo, 4);

}


void MungGuGame::mungFireCoolTimeFinish(){
    mungFireCoolTimeFinished = true;
    mungCoFireBtn->setVisible(true);
    mungCoFireBtn_->setVisible(false);
}


void MungGuGame::changeStatusBar(){//StatusBar에서 수시로 변화하는 이미지들 Update함수에 넣고 씀

	if (nowNeededMoneyForMaxMoney <= myMoney){
		statusPushBar_maxMoney->setVisible(false);
	}
	else{
		statusPushBar_maxMoney->setVisible(true);
	}
	if (maxMoneyLV == 7){
		statusPushBar_maxMoney->setVisible(false);
		statusCost_maxMoney->setVisible(false);
		statusCost_maxMoneyMax->setVisible(true);
	}

	if (nowNeededMoneyForSpeed <= myMoney){
		statusPushBar_speed->setVisible(false);
	}
	else{
		statusPushBar_speed->setVisible(true);
	}

	if (speedLV == 7){
		statusPushBar_speed->setVisible(false);
		statusCost_speed->setVisible(false);
		statusCost_speedMax->setVisible(true);
	}

	if (nowNeededMoneyForPower <= myMoney){
		statusPushBar_power->setVisible(false);
	}
	else{
		statusPushBar_power->setVisible(true);
	}

	if (powerLV == 7){
		statusPushBar_power->setVisible(false);
		statusCost_power->setVisible(false);
		statusCost_powerMax->setVisible(true);
	}





}

void MungGuGame::resetGameScene(){
	//터치이벤트를 계속 초기화 시켜줌
	Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
	myMonsters.clear();
	enemyMonsters.clear();
	auto scene = TransitionFade::create(3, MungGuGame::createScene());
	Director::getInstance()->replaceScene(scene);
	// 이 후에 터치가 불가
}

void MungGuGame::changeStatusCost(){//
	statusCost_maxMoney->setString(StringUtils::format("%d", nowNeededMoneyForMaxMoney));
	statusCost_power->setString(StringUtils::format("%d", nowNeededMoneyForPower));
	statusCost_speed->setString(StringUtils::format("%d", nowNeededMoneyForSpeed));
}
void MungGuGame::setStatusBar(){//고정해서 쓸 StatusBar 이미지

	maxMoneyLV = 1;
	powerLV = 1;
	speedLV = 1;

	//이미지는 폰트로 바꿔야 함..
	statusBar = Sprite::create("mungCoStatusBar.png");
	statusBar->setPosition(Point(winSize.width, 0));
	statusBar->setAnchorPoint(Point(1, 0));
	this->addChild(statusBar, 3);


	statusPushBar_maxMoney = Sprite::create("statusBar_.png");
	statusPushBar_maxMoney->setPosition(Point(winSize.width - 192, 65));
	statusPushBar_maxMoney->setAnchorPoint(Point(0.5, 0.5));
	//statusPushBar_maxMoney->setTag(TAG_STATUSBAR_MAXMONEY);
	this->addChild(statusPushBar_maxMoney, 4);

	statusPushBar_power = Sprite::create("statusBar_.png");
	statusPushBar_power->setPosition(Point(winSize.width - 114, 65));
	statusPushBar_power->setAnchorPoint(Point(0.5, 0.5));
	//statusPushBar_power->setTag(TAG_STATUSBAR_POWER);
	this->addChild(statusPushBar_power, 4);

	statusPushBar_speed = Sprite::create("statusBar_.png");
	statusPushBar_speed->setPosition(Point(winSize.width - 38, 65));
	statusPushBar_speed->setAnchorPoint(Point(0.5, 0.5));
//	statusPushBar_speed->setTag(TAG_STATUSBAR_SPEED);
	this->addChild(statusPushBar_speed, 4);

	nowNeededMoneyForMaxMoney = 300; //초기 필요한 머니 값을 셋팅
	nowNeededMoneyForPower = 600;
	nowNeededMoneyForSpeed = 500;
    
    //mungPoCost

	statusCost_maxMoney = Label::createWithTTF //상태버튼 maxMoney
		(StringUtils::format("%d", nowNeededMoneyForMaxMoney), "NanumBarunGothicBold.otf", 20);
	statusCost_maxMoney->setAnchorPoint(Point(0.5, 0.5));
	statusCost_maxMoney->setPosition(Point(winSize.width - 192, 16));
	statusCost_maxMoney->setColor(Color3B::BLACK);
	this->addChild(statusCost_maxMoney, 4);
	statusCost_maxMoneyMax = Label::createWithTTF //상태버튼 maxMoney
		(StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 25);
	statusCost_maxMoneyMax->setAnchorPoint(Point(0.5, 0.5));
	statusCost_maxMoneyMax->setPosition(Point(winSize.width - 192, 16));
	statusCost_maxMoneyMax->setColor(Color3B::BLACK);
	statusCost_maxMoneyMax->setVisible(false);
	this->addChild(statusCost_maxMoneyMax, 4);

    
	statusCost_power = Label::createWithTTF //상태버튼 power
		(StringUtils::format("%d", nowNeededMoneyForPower), "NanumBarunGothicBold.otf", 20);
	statusCost_power->setAnchorPoint(Point(0.5, 0.5));
	statusCost_power->setPosition(Point(winSize.width - 114, 16));
	statusCost_power->setColor(Color3B::BLACK);
	this->addChild(statusCost_power, 4);
	statusCost_powerMax = Label::createWithTTF //상태버튼 maxMoney
		(StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 25);
	statusCost_powerMax->setAnchorPoint(Point(0.5, 0.5));
	statusCost_powerMax->setPosition(Point(winSize.width - 114, 16));
	statusCost_powerMax->setColor(Color3B::BLACK);
	statusCost_powerMax->setVisible(false);
	this->addChild(statusCost_powerMax, 4);

	statusCost_speed = Label::createWithTTF //상태버튼 speed
		(StringUtils::format("%d", nowNeededMoneyForSpeed), "NanumBarunGothicBold.otf", 20);
	statusCost_speed->setAnchorPoint(Point(0.5, 0.5));
	statusCost_speed->setPosition(Point(winSize.width - 38, 16));
	statusCost_speed->setColor(Color3B::BLACK);
	this->addChild(statusCost_speed, 4);
	statusCost_speedMax = Label::createWithTTF //상태버튼 maxMoney
		(StringUtils::format("MAX"), "NanumBarunGothicBold.otf", 25);
	statusCost_speedMax->setAnchorPoint(Point(0.5, 0.5));
	statusCost_speedMax->setPosition(Point(winSize.width - 38, 16));
	statusCost_speedMax->setColor(Color3B::BLACK);
	statusCost_speedMax->setVisible(false);
	this->addChild(statusCost_speedMax, 4);
}



void MungGuGame::setGameClearEvent(){
	//승리 문구

	youWin = Sprite::create("youWin.png");
	youWin->setAnchorPoint(Point(0.5, 1));
	youWin->setPosition(Point(winSize.width / 2, winSize.height * 3 / 4));
	youWin->setVisible(false);
	youWin->setScale(2.5*winSize.width/1200);
	this->addChild(youWin, 50);

	gold_Label = Label::createWithTTF //상태버튼 maxMoney
		(StringUtils::format("%d", goldForStage), "NanumBarunGothicBold.otf", 16);
	gold_Label->setAnchorPoint(Point(0, 0));
	gold_Label->setPosition(Point(90, 10));
	gold_Label->setColor(Color3B::BLACK);
	gold_Label->setVisible(false);
	youWin->addChild(gold_Label, 50);


	homeBackBtn = Sprite::create("homeBackBtn.png");
	homeBackBtn->setAnchorPoint(Point(0.5, 1));
	homeBackBtn->setPosition(Point(winSize.width / 2, winSize.height * 2 / 5));
	homeBackBtn->setVisible(false);
	homeBackBtn->setTag(TAG_SPRITE_HOMEBACKBTN);
    homeBackBtnRect = homeBackBtn->getBoundingBox();

	homeBackBtn_ = Sprite::create("homeBackBtn_.png");
	homeBackBtn_->setAnchorPoint(Point(0.5, 1));
	homeBackBtn_->setPosition(Point(winSize.width / 2, winSize.height * 2 / 5));
	homeBackBtn_->setVisible(false);
	this->addChild(homeBackBtn, 50);
	this->addChild(homeBackBtn_, 50);
    
    sinBtn = Sprite::create("sinTaeDollBtn.png");
    sinBtn->setAnchorPoint(Point(0.5,0.5));
    sinBtn->setPosition(Point(homeBackBtnRect.getMidX(),homeBackBtnRect.getMidY()));
    sinBtn_ = Sprite::create("sinTaeDollBtn_.png");
    sinBtn_->setAnchorPoint(Point(0.5,0.5));
    sinBtn_->setPosition(Point(homeBackBtnRect.getMidX(),homeBackBtnRect.getMidY()));
    sinBtn->setVisible(false);
    sinBtn_->setVisible(false);
    this->addChild(sinBtn,51);
    this->addChild(sinBtn_,51);
}

void MungGuGame::setGameLoserEvent(){
	//패배 문구

    //시도횟수 표시
    attemptValue = UserDefault::getInstance()->getIntegerForKey("attemptValue");
    UserDefault::getInstance()->setIntegerForKey("attemptValue",attemptValue+1);
    attemptValue = UserDefault::getInstance()->getIntegerForKey("attemptValue");
    
    
	youLoser = Sprite::create("youLoser.png");
	youLoser->setAnchorPoint(Point(0.5, 1));
	youLoser->setPosition(Point(winSize.width / 2, winSize.height * 3 / 4));
	youLoser->setVisible(false);
	youLoser->setScale(2.6);
	this->addChild(youLoser, 50);

	Rect youLoserRect = youLoser->getBoundingBox();
    
    
    
    
    attempt_label = Label::createWithTTF(StringUtils::format("Attempt"),"NanumBarunGothic.otf",23);
    attempt_label->setColor(Color3B(205,80,80));
    attempt_label->setAnchorPoint(Point(0,0));
    attempt_label->setPosition(Point(youLoserRect.getMaxX(),youLoserRect.getMaxY()));
    Rect attempt_labelRect = attempt_label->getBoundingBox();
    attemptValue_label = Label::createWithTTF(StringUtils::format(" %d",attemptValue),"NanumBarunGothicBold.otf",36);
    attemptValue_label->setColor(Color3B(230,150,150));
    attemptValue_label->setAnchorPoint(Point(0.3,0.3));
    attemptValue_label->setPosition(Point(attempt_labelRect.getMaxX(),attempt_labelRect.getMaxY()));
    
    this->addChild(attempt_label,50);
    this->addChild(attemptValue_label,50);
    attempt_label->setVisible(false);
    attemptValue_label->setVisible(false);

	regameBtn = Sprite::create("regameBtn.png");

	regameBtn->setVisible(false);
	regameBtn->setAnchorPoint(Point(0, 1));
	regameBtn->setScale(1.6);
	this->addChild(regameBtn, 50);
    regameBtn->setTag(TAG_SPRITE_REGAMEBTN);
    regameBtnRect = regameBtn->getBoundingBox();
    
	regameBtn_ = Sprite::create("regameBtn_.png");

	regameBtn_->setVisible(false);
	regameBtn_->setAnchorPoint(Point(0, 1));
	regameBtn_->setScale(1.6);
	this->addChild(regameBtn_, 50);
	regameBtn_->setTag(TAG_SPRITE_REGAMEBTN_);
}


void MungGuGame::initGameClearEvent(){
	//승리 문구

    //m16 클리어 이벤트
    bool isM16Clear = UserDefault::getInstance()->getBoolForKey("m16");
    //아군 건물 체력 100이하로 승리하면 힘겨운 승리 미션 달성
    if((isM16Clear==false)&&(dogSiteNowHp<=100)){
        
//            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
//            if(isSong == true){//song 켰나 안켯나 확인
//                int disabledSong =
//                SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
//            }
            
            UserDefault::getInstance()->setBoolForKey("m16",true);//8미션 클리어
            
            auto m16Clear = Label::createWithTTF(StringUtils::format("mission 16 Clear~!!!\n-> Hard Victory"), "NanumBarunGothicBold.otf", 20);
            m16Clear->setAnchorPoint(Point(0.5,1));
            m16Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m16Clear->setColor(Color3B::RED);
            m16Clear->setVisible(false);
            this->addChild(m16Clear,10);
            if(initByEnglish==false){
                m16Clear->setString(StringUtils::format("미션 16 클리어~!!!\n -> 힘겨운 승리"));
            }
            auto action = Blink::create(3,10);
            m16Clear->runAction(action);
    }
    
    if(isStage1 == true){
        
    int stage1_clearCount = UserDefault::getInstance()->getIntegerForKey("stage1_revangeStartClearCount");
UserDefault::getInstance()->setIntegerForKey("stage1_revangeStartClearCount", stage1_clearCount+1);
        
        ///mission1 clear/// 첫 스테이지 클리어
        bool isM1Clear = UserDefault::getInstance()->getBoolForKey("m1");
        
        if(isM1Clear==false){
        UserDefault::getInstance()->setBoolForKey("m1", true);
        auto m1Clear = Label::createWithTTF(StringUtils::format("mission 1 Clear~!!!\n-> 1 stage clear"), "NanumBarunGothicBold.otf", 20);
            m1Clear->setColor(Color3B::RED);
        m1Clear->setAnchorPoint(Point(0.5,1));
        m1Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m1Clear->setColor(Color3B::BLACK);
            m1Clear->setVisible(false);
        this->addChild(m1Clear);
        auto action = Blink::create(2,10);
            
            if(initByEnglish==false){
                m1Clear->setString(StringUtils::format("미션 1 클리어~!!!\n -> 첫 판 클리어"));
            }
            
        m1Clear->runAction(action);
                
        
        ////////////////
        Rect m1Clear1Rect = m1Clear->getBoundingBox();
        ///mission1 clear///
            
        }
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
           int clearNum = UserDefault::getInstance()->getIntegerForKey("stage1_revangeStartClearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
            
            //	UserDefault::getInstance()->flush(); //실제 저장소에 저장하는 것 
            
        }
    }else if(isStage2 == true){
        
    int stage2_clearCount = UserDefault::getInstance()->getIntegerForKey("stage2_clearCount");
    UserDefault::getInstance()->setIntegerForKey("stage2_clearCount", stage2_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage2_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
            
            //	UserDefault::getInstance()->flush(); //실제 저장소에 저장하는 것
            
        }
    }else if(isStage3 == true){
        
        int stage3_clearCount = UserDefault::getInstance()->getIntegerForKey("stage3_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage3_clearCount", stage3_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage3_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }

        }
    }else if(isStage4 == true){
        
        int stage4_clearCount = UserDefault::getInstance()->getIntegerForKey("stage4_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage4_clearCount", stage4_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage4_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage5 == true){
        
        ///스테이지 미션 클리어///
        bool isM2Clear = UserDefault::getInstance()->getBoolForKey("m2");
        
        if(isM2Clear==false){
            UserDefault::getInstance()->setBoolForKey("m2", true);
            auto m2Clear = Label::createWithTTF(StringUtils::format("mission 2 Clear~!!!\n-> 5 stage clear"), "NanumBarunGothicBold.otf", 20);
            m2Clear->setColor(Color3B::RED);
            m2Clear->setAnchorPoint(Point(0.5,1));
            m2Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m2Clear->setColor(Color3B::BLACK);
            m2Clear->setVisible(false);
            this->addChild(m2Clear);
            
            if(initByEnglish==false){
                m2Clear->setString(StringUtils::format("미션 2 클리어~!!!\n -> 5스테이지 클리어"));
            }
            auto action = Blink::create(2,10);
            m2Clear->runAction(action);
        }
        ///////////
            
            
        int stage5_clearCount = UserDefault::getInstance()->getIntegerForKey("stage5_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage5_clearCount", stage5_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage5_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage6 == true){
        
        int stage6_clearCount = UserDefault::getInstance()->getIntegerForKey("stage6_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage6_clearCount", stage6_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage6_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage7 == true){
        
        int stage7_clearCount = UserDefault::getInstance()->getIntegerForKey("stage7_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage7_clearCount", stage7_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage7_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage8 == true){
        
        int stage8_clearCount = UserDefault::getInstance()->getIntegerForKey("stage8_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage8_clearCount", stage8_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage8_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage9 == true){
        
        int stage9_clearCount = UserDefault::getInstance()->getIntegerForKey("stage9_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage9_clearCount", stage9_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage9_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage10 == true){
        
        
        ///스테이지 미션 클리어///
        bool isM3Clear = UserDefault::getInstance()->getBoolForKey("m3");
        
        if(isM3Clear==false){
            UserDefault::getInstance()->setBoolForKey("m3", true);
            auto m3Clear = Label::createWithTTF(StringUtils::format("mission 3 Clear~!!!\n-> 10 stage clear"), "NanumBarunGothicBold.otf", 20);
            m3Clear->setColor(Color3B::RED);
            m3Clear->setAnchorPoint(Point(0.5,1));
            m3Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m3Clear->setColor(Color3B::BLACK);
            m3Clear->setVisible(false);
            this->addChild(m3Clear);
            if(initByEnglish==false){
                m3Clear->setString(StringUtils::format("미션 3 클리어~!!!\n -> 10스테이지 클리어"));
            }
            
            auto action = Blink::create(2,10);
            m3Clear->runAction(action);
            ///////////
            
        }
        
        int stage10_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage10_clearCount");
    UserDefault::getInstance()->setIntegerForKey("stage10_clearCount", stage10_clearCount+1);
        
       
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage10_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage11 == true){
        
        int stage11_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage11_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage11_clearCount", stage11_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage11_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage12 == true){
        
        int stage12_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage12_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage12_clearCount", stage12_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage12_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage13 == true){//클리어 버튼 함정
        
        int stage13_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage13_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage13_clearCount", stage13_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage13_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage14 == true){
        
        int stage14_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage14_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage14_clearCount", stage14_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage14_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage15 == true){
        
        
        ///스테이지 미션 클리어///
        bool isM4Clear = UserDefault::getInstance()->getBoolForKey("m4");
        
        if(isM4Clear==false){
            UserDefault::getInstance()->setBoolForKey("m4", true);
            auto m4Clear = Label::createWithTTF(StringUtils::format("mission 4 Clear~!!!\n->15 stage clear"), "NanumBarunGothicBold.otf", 20);
            m4Clear->setColor(Color3B::RED);
            m4Clear->setAnchorPoint(Point(0.5,1));
            m4Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m4Clear->setColor(Color3B::BLACK);
            m4Clear->setVisible(false);
            this->addChild(m4Clear);
            
            if(initByEnglish==false){
                m4Clear->setString(StringUtils::format("미션 4 클리어~!!!\n -> 15스테이지 클리어"));
            }
            
            auto action = Blink::create(2,10);
            m4Clear->runAction(action);
            ///////////
        }
        
            
            
        int stage15_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage15_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage15_clearCount", stage15_clearCount+1);
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage15_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage16 == true){
        
        int stage16_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage16_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage16_clearCount", stage16_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage16_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage17 == true){
        
        int stage17_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage17_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage17_clearCount", stage17_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage17_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage18 == true){
        
        isStage18_trap=true;
        ///홈으로 돌아가야 보상을 얻음
    }else if(isStage19 == true){
        
        int stage19_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage19_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage19_clearCount", stage19_clearCount+1);
        
        
        
        if (isGoldCalc == false){
            isGoldCalc = true;
            
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage19_clearCount");
            
            
            
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            
        }
    }else if(isStage20 == true){
        if (isGoldCalc == false){
            isGoldCalc = true;
            UserDefault::getInstance()->setBoolForKey("isStage20_played",true);
//        int stage20_clearCount =
//        UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
//        UserDefault::getInstance()->setIntegerForKey("stage20_clearCount", stage20_clearCount+1);//엔딩을 다 봐야 클리어가 됨!
        }
       
    }else if(isStage21 == true){
        int stage21_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage21_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage21_clearCount", stage21_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage21_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage22 == true){
        int stage22_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage22_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage22_clearCount", stage22_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage22_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage23 == true){
        int stage23_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage23_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage23_clearCount", stage23_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage23_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage24 == true){
        int stage24_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage24_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage24_clearCount", stage24_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage24_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage25 == true){
        
        ///스테이지 미션 클리어///
        bool isM6Clear = UserDefault::getInstance()->getBoolForKey("m6");
        
        if(isM6Clear==false){
            UserDefault::getInstance()->setBoolForKey("m6", true);
            auto m6Clear = Label::createWithTTF(StringUtils::format("mission 6 Clear~!!!\n->25 stage clear"), "NanumBarunGothicBold.otf", 20);
            m6Clear->setColor(Color3B::RED);
            m6Clear->setAnchorPoint(Point(0.5,1));
            m6Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m6Clear->setColor(Color3B::BLACK);
            m6Clear->setVisible(false);
            this->addChild(m6Clear);
            auto action = Blink::create(2,10);
            m6Clear->runAction(action);
            ///////////
        }

        
        
        int stage25_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage25_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage25_clearCount", stage25_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage25_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage26 == true){
        int stage26_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage26_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage26_clearCount", stage26_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage26_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage27 == true){
        int stage27_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage27_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage27_clearCount", stage27_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage27_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage28 == true){
        int stage28_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage28_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage28_clearCount", stage28_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage28_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage29 == true){
        int stage29_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage29_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage29_clearCount", stage29_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage29_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }else if(isStage30 == true){
        
        ///스테이지 미션7 클리어///
        bool isM7Clear = UserDefault::getInstance()->getBoolForKey("m7");
        
        if(isM7Clear==false){
            UserDefault::getInstance()->setBoolForKey("m7", true);
            auto m7Clear = Label::createWithTTF(StringUtils::format("mission 7 Clear~!!!\n-> 30 stage clear"), "NanumBarunGothicBold.otf", 20);
            m7Clear->setColor(Color3B::RED);
            m7Clear->setAnchorPoint(Point(0.5,1));
            m7Clear->setPosition(Point(winSize.width/2,winSize.height-20));
            m7Clear->setColor(Color3B::BLACK);
            m7Clear->setVisible(false);
            this->addChild(m7Clear);
            auto action = Blink::create(3,10);
            if(initByEnglish==false){
                m7Clear->setString(StringUtils::format("미션 7 클리어~!!!\n -> 30스테이지 클리어"));
            }
            m7Clear->runAction(action);
            ///////////
        }
        
        
        int stage30_clearCount =
        UserDefault::getInstance()->getIntegerForKey("stage30_clearCount");
        UserDefault::getInstance()->setIntegerForKey("stage30_clearCount", stage30_clearCount+1);
        if (isGoldCalc == false){
            isGoldCalc = true;
            int clearNum = UserDefault::getInstance()->getIntegerForKey("stage30_clearCount");
            if (clearNum != 1){
                UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
            else{
                UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
            }
        }
    }
    
    
    
    
	isFirstStageClear = true;//클리어
	//myMonsters.clear();
	//enemyMonsters.clear();
	Rect youWinRect = youWin->getBoundingBox();

	

	youWin->setVisible(true);

	gold_Label->setVisible(true);

	homeBackBtn->setVisible(true);
    if(isStage18==true){
    sinBtn->setVisible(true);
        
        
    }

}

void MungGuGame::initGameLoserEvent(){
    
    //m17 클리어 이벤트
    bool isM17Clear = UserDefault::getInstance()->getBoolForKey("m17");
    //아군 건물 체력 100이하로 승리하면 힘겨운 승리 미션 달성
    if((isM17Clear==false)&&(catSiteNowHp<=100)){
        
        //            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        //            if(isSong == true){//song 켰나 안켯나 확인
        //                int disabledSong =
        //                SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
        //            }
        
        UserDefault::getInstance()->setBoolForKey("m17",true);//8미션 클리어
        
        auto m17Clear = Label::createWithTTF(StringUtils::format("mission 17 Clear~!!!\n-> Hard Defeat"), "NanumBarunGothicBold.otf", 20);
        m17Clear->setAnchorPoint(Point(0.5,1));
        m17Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m17Clear->setColor(Color3B::RED);
        m17Clear->setVisible(false);
        this->addChild(m17Clear,10);
        if(initByEnglish==false){
            m17Clear->setString(StringUtils::format("미션 17 클리어~!!!\n -> 힘겨운 패배"));
        }
        auto action = Blink::create(3,10);
        m17Clear->runAction(action);
    }
    
    auto deadDot = Sprite::create("whiteDot.png");
    
    deadDot->setOpacity(180);
    deadDot->setColor(Color3B(30,10,10));
    this->addChild(deadDot,40);
    deadDot->setVisible(false);
    Rect WhiteDotRect = deadDot->getBoundingBox();
    deadDot->setScale(winSize.width / WhiteDotRect.size.width, winSize.height / WhiteDotRect.size.height);
    deadDot->setAnchorPoint(Point(0.5, 0.5));
    deadDot->setPosition(Point(winSize.width / 2, winSize.height / 2));
    //  whiteDot->setColor(Color3B::BLACK);
    deadDot->setVisible(true);
    
    
	Rect youLoserRect = youLoser->getBoundingBox();
	isFirstStageLoser = true; //실패로...// ?????
	//myMonsters.clear();
	//enemyMonsters.clear();
//쪼개기몬


    
	///패배 위치 조정중
	regameBtn->setPosition(Point(youLoserRect.getMidX() + 30, youLoserRect.getMinY() - 50));
	regameBtn_->setPosition(Point(youLoserRect.getMidX() + 30, youLoserRect.getMinY() - 50));


	homeBackBtn->setPosition(Point(youLoserRect.getMidX() - 80, youLoserRect.getMinY() - 50));
	homeBackBtn_->setPosition(Point(youLoserRect.getMidX() - 80, youLoserRect.getMinY() - 50));

	youLoser->setVisible(true);
	homeBackBtn->setVisible(true);
    homeBackBtn_->setVisible(false);
    
	regameBtn->setVisible(true);
    attempt_label->setVisible(true);
    attemptValue_label->setVisible(true);
    
}

void MungGuGame::setExploreMileStone(){
	//폭바범위를 보여주는 지표의 설정-> 멍포 장전중 나타남.
    
    int mungGuDogSiteRangeLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteRangeLv");
    
	exploreRange = winSize.width / 8;//폭발 범위
	minFireRange = dogSiteRect.getMinX() + winSize.width/8;
    maxFireRange = minFireRange + winSize.width/6 + mungGuDogSiteRangeLv*(winSize.width/72)-winSize.width/50;//1/6 + 2/6

	exploreMileStone = Sprite::create("exploreMileStone.png");
	exploreMileStone->setPosition(Point(minFireRange, ground->getPositionY()));
	exploreMileStone->setVisible(false);
	exploreMileStone->setAnchorPoint(Point(0.5, 0.5));
	exploreMileStone->setOpacity(87);
	this->addChild(exploreMileStone, 50);

	exploreMileStone2 = Sprite::create("exploreMileStone.png");
	exploreMileStone2
		->setPosition(Point(exploreMileStone->getPositionX() + exploreRange, ground->getPositionY()));
	exploreMileStone2->setVisible(false);
	exploreMileStone2->setAnchorPoint(Point(0.5, 0.5));
	exploreMileStone2->setOpacity(87);
	this->addChild(exploreMileStone2, 50);
}

void MungGuGame::initExploreMileStoneAction(){
	exploreMileStone->setVisible(true);
	exploreMileStone2->setVisible(true);
	if (exploreMileStone->getPositionX() <= (minFireRange + maxFireRange)){
		auto Action0 = MoveBy::create(0.6, Point(maxFireRange - minFireRange, 0));
		auto Action = EaseIn::create(Action0, 1.6);
		auto Action00 = MoveBy::create(0.6, Point(maxFireRange - minFireRange, 0));
		auto Action2 = EaseIn::create(Action00, 1.3);
		exploreMileStone->runAction(Action);
		exploreMileStone2->runAction(Action2);
	}
	else{
		exploreMileStone->setVisible(false);
		exploreMileStone2->setVisible(false);
	}
}



void MungGuGame::setDogSite(){
	dogSite = Sprite::create("DogSite.png");
	dogSite->setPosition(Point(winSize.width / 10+catDogDistance, groundPosY - 25));
	dogSite->setAnchorPoint(Point(0.5, 0));
    
    dogSite->setScale(dogSiteScaleRate);
	this->addChild(dogSite, 2);
    
    

}
//2/9 문제 없는 듯
void MungGuGame::setCatSite(){
    
       //적 기지
    //적 기지
    if(isStage1 == true){
        catSite = Sprite::create("CatSite_1.png");
        catSite->setPosition(Point(winSize.width * 9 / 10 - catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        //    catSite->setTag(TAG_SPRITE_CATSITE);
    }else if(isStage2 == true){
        catSite = Sprite::create("CatSite_2.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
    }else if(isStage3 == true) {
        catSite = Sprite::create("CatSite1.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
    }else if(isStage4 == true) {
        catSite = Sprite::create("CatSite.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage5 == true) {
        catSite = Sprite::create("CatSite_5.png");
        catSite->setPosition(Point(winSize.width * 9 / 10 - catDogDistance, groundPosY - 33));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
        
        
    }else if(isStage6 == true) {
        catSite = Sprite::create("CatSite_6.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 30));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage7 == true) {
        catSite = Sprite::create("CatSite_7.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage8 == true) {
        catSite = Sprite::create("CatSite_8.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage9 == true) {
        catSite = Sprite::create("CatSite_9.png");
        catSite->setPosition(Point(winSize.width * 17 / 20- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
        Rect catSiteRect = catSite->getBoundingBox();
        Rect groundRect = ground->getBoundingBox();
        gameOverBtn = Sprite::create("gameOverBtn.png");
        gameOverBtn_ = Sprite::create("gameOverBtn_.png");
        gameOverBtn->setPosition(Point(catSiteRect.getMaxX()+20,groundRect.getMaxY()-20));
        gameOverBtn_->setPosition(Point(catSiteRect.getMaxX()+20,groundRect.getMaxY()-20));
        gameOverBtn->setAnchorPoint(Point(0,0));
        gameOverBtn_->setAnchorPoint(Point(0,0));
        gameOverBtn_->setVisible(false);
        this->addChild(gameOverBtn,1);
        this->addChild(gameOverBtn_,1);
        
    }else if(isStage10 == true) {
        catSite = Sprite::create("CatSite_10.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage11 == true) {
        catSite = Sprite::create("CatSite_11.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage12 == true) {
        catSite = Sprite::create("CatSite_12.png");
        catSite->setPosition(Point(winSize.width * 9 / 10 - catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage13 == true) {
        catSite = Sprite::create("catSite_13.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
        catSite_Angryed_13 = Sprite::create("catSite_angry_13.png");
        catSite_Angryed_13->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite_Angryed_13->setAnchorPoint(Point(0.5, 0));
        catSite_Angryed_13->setVisible(false);
        catSite_Angryed_13->setScale(catSiteScaleRate+0.05);
        this->addChild(catSite_Angryed_13, 2);
        
        
    }else if(isStage14 == true) {
        catSite = Sprite::create("CatSite_14.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage15 == true) {
        catSite = Sprite::create("CatSite_15.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage16 == true) {
        catSite = Sprite::create("catSite_16.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage17 == true) {
        catSite = Sprite::create("CatSite_18.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage18 == true) {
        catSite = Sprite::create("CatSite_17.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage19 == true) {
        catSite = Sprite::create("CatSite_20.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage20 == true) {
        catSite = Sprite::create("CatSite_19.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage21 == true) {
        catSite = Sprite::create("CatSite_21.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage22 == true) {
        catSite = Sprite::create("CatSite_22.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 20));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage23 == true) {
        catSite = Sprite::create("CatSite_23.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 29));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage24 == true) {
        catSite = Sprite::create("CatSite_24.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 27));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage25 == true) {
        catSite = Sprite::create("CatSite_25.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 20));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage26 == true) {
        catSite = Sprite::create("CatSite_28.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 21));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage27 == true) {
        catSite = Sprite::create("CatSite_27.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage28 == true) {
        catSite = Sprite::create("CatSite_28.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 30));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage29 == true) {
        catSite = Sprite::create("CatSite_26.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 20));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else if(isStage30 == true) {
        catSite = Sprite::create("CatSite_26.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 22));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        
    }else{
        catSite = Sprite::create("CatSite.png");
        catSite->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        catSite->setAnchorPoint(Point(0.5, 0));
        this->addChild(catSite, 2);
        //    catSite->setTag(TAG_SPRITE_CATSITE);
    }
    catSiteRect = catSite->getBoundingBox();
    catSite->setScale(catSiteScaleRate);
    
    //기타
    if(isStage4 == true){
        Rect catSiteRect = catSite->getBoundingBox();
        isCatSiteShild = true; //고양이 기지 실드가 존재 무적.
        catSiteShield = cocos2d::Sprite::create("catSiteShild.png");
        catSiteShield->setPosition(Point(catSiteRect.getMidX(),catSiteRect.getMinY()+5));
        catSiteShield->setAnchorPoint(Point(0.5,0));
        //   catSiteShield->retain();
        catSiteShield->setScale(catSiteScaleRate);
        this->addChild(catSiteShield,3);
        catSiteShildRect = catSiteShield->getBoundingBox();
        
    }
    
    stage13_message = Label::createWithTTF(StringUtils::format("Why did you touch me-!!"), "NanumBarunGothic.otf", 16);//폰트적용 O(나눔고딕 볼드체)
    Rect catSiteRect = catSite->getBoundingBox();
    stage13_message->setColor(Color3B::BLACK);
    stage13_message->setPosition(Point(catSiteRect.getMinX()+16,catSiteRect.getMaxY()));
    stage13_message->setAnchorPoint(Point(1,0));
    this->addChild(stage13_message,30);
    stage13_message->setVisible(false);

}

void MungGuGame::catSiteDestroyedEffect(float delta){
	//이곳저곳이 팡팡

	SpriteFrameCache::getInstance()
		->addSpriteFramesWithFile("attackEffect.plist");

	catSiteCrashEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
	catSiteCrashEffect->setAnchorPoint(Point(0.5, 0.5));
	catSiteCrashEffect->setPosition(Point(catSiteRandX, catSiteRandY));
    catSiteCrashEffect->setScale(1*winSize.width/1200);
	this->addChild(catSiteCrashEffect, 50);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.05);
	catSiteCrashEffect->setScale(1.2*winSize.width/1200);

	for (int i = 0; i<6; i++) {
		auto catSiteCrashEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
		animation->addSpriteFrame(catSiteCrashEffect);
	}

	auto attackEffectAnimate = Animate::create(animation);

	catSiteCrashEffect->runAction(attackEffectAnimate);
}

//2/9 문제 없음
void MungGuGame::initSinTaeDoll(){
    this->unschedule(schedule_selector(MungGuGame::addCatSinTaeDollMonster));
    
    this->schedule(schedule_selector
                   (MungGuGame::addCatSinTaeDollMonster), 60, 3, 0.5);
    if((isInitSinTaeDoll==true)||(isStage9==true)||(isStage18==true) ||(isStage28==true)){
       
        if(isStage9==true) {
            Rect catSiteRect = catSite->getBoundingBox();
            stage13_message->setPosition(Point(catSiteRect.getMinX()+30,catSiteRect.getMaxY()-30));
            auto messageAction = Blink::create(2,1);
            auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
            stage13_message->setString(StringUtils::format("Bye Bye-"));
            stage13_message->setColor(Color3B::RED);
            stage13_message->runAction(action);
        }else if(isStage18==true){
            SimpleAudioEngine::getInstance()->stopBackgroundMusic();
            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
            auto messageAction = Blink::create(2,6);
             auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
            stage13_message->setString(StringUtils::format("Hello~ "));
            stage13_message->setColor(Color3B::RED);
            stage13_message->runAction(action);
            
        }else if(isStage28==true){
            SimpleAudioEngine::getInstance()->stopBackgroundMusic();
            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
            auto messageAction = Blink::create(2,6);
            auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
            stage13_message->setString(StringUtils::format("Have a good time \^-^/ "));
            stage13_message->setColor(Color3B::RED);
            stage13_message->runAction(action);
        }
    }else{
        if(isStage13==true){
    Rect catSiteRect = catSite_Angryed_13->getBoundingBox();
    stage13_message->setPosition(Point(catSiteRect.getMinX()+30,catSiteRect.getMaxY()-30));
    auto messageAction = Blink::create(3,12);
    stage13_message->setString(StringUtils::format("I will kill you"));
    stage13_message->setColor(Color3B::RED);
    stage13_message->runAction(messageAction);
        }
        
        
    
    isInitSinTaeDoll = true;
    }

    
   
}

void MungGuGame::catSiteDestroyed(){

    
    catSite->setVisible(false);
    if(isStage1 == true){
	catSiteCrash = Sprite::create("CatSite_1_crash.png");
	catSiteCrash->setAnchorPoint(Point(0.5, 0));
	catSiteCrash->setPosition(Point(winSize.width * 9 / 10 - catDogDistance, groundPosY - 25));
	this->addChild(catSiteCrash, 2);
    }else if(isStage2 == true){
        catSiteCrash = Sprite::create("CatSite_2_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage3 == true){
        catSiteCrash = Sprite::create("CatSiteCrash1.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage4 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage5 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10 - catDogDistance, groundPosY - 33));
        this->addChild(catSiteCrash, 2);
    }else if(isStage6 == true){
        catSiteCrash = Sprite::create("CatSite_6_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 30));
        

        this->addChild(catSiteCrash, 2);
    }else if(isStage7 == true){
        catSiteCrash = Sprite::create("CatSite_7_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY - 25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage8 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage9 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage10 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage11 == true){
        catSiteCrash = Sprite::create("CatSite_11_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage12 == true){
        catSiteCrash = Sprite::create("CatSite_crash_12.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage13 == true){
        catSiteCrash = Sprite::create("catSite_crash_13.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage14 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage15 == true){
        catSiteCrash = Sprite::create("CatSite_crash_15.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage16 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage17 == true){
        catSiteCrash = Sprite::create("CatSite_crash_18.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage18 == true){
        catSiteCrash = Sprite::create("CatSite_crash_17.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage19 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage20 == true){
        catSiteCrash = Sprite::create("CatSite_19_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage21 == true){
        catSiteCrash = Sprite::create("CatSite_21_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage22 == true){
        catSiteCrash = Sprite::create("CatSite_22_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-20));
        this->addChild(catSiteCrash, 2);
    }else if(isStage23 == true){
        catSiteCrash = Sprite::create("CatSite_23_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-29));
        this->addChild(catSiteCrash, 2);
    }else if(isStage24 == true){
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-27));
        this->addChild(catSiteCrash, 2);
    }else if(isStage25 == true){
        catSiteCrash = Sprite::create("CatSite_25_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-20));
        this->addChild(catSiteCrash, 2);
    }else if(isStage26 == true){
        catSiteCrash = Sprite::create("CatSite_28_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-21));
        this->addChild(catSiteCrash, 2);
    }else if(isStage27 == true){
        catSiteCrash = Sprite::create("CatSite_27_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }else if(isStage28 == true){
        catSiteCrash = Sprite::create("CatSite_28_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-30));
        this->addChild(catSiteCrash, 2);
    }else if(isStage29 == true){
        catSiteCrash = Sprite::create("CatSite_26_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-20));
        this->addChild(catSiteCrash, 2);
    }else if(isStage30 == true){
        catSiteCrash = Sprite::create("CatSite_26_crash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-22));
        this->addChild(catSiteCrash, 2);
    }else{
        //default
        catSiteCrash = Sprite::create("CatSiteCrash.png");
        catSiteCrash->setAnchorPoint(Point(0.5, 0));
        catSiteCrash->setPosition(Point(winSize.width * 9 / 10- catDogDistance, groundPosY-25));
        this->addChild(catSiteCrash, 2);
    }
    catSiteCrash->setScale(catSiteScaleRate);
	//건물이 흔들흔들
	auto action = MoveBy::create((0.03), Point(1.0, 0));
	auto action1 = MoveBy::create((0.03), Point(-1.0, 0));
	auto action2 = MoveBy::create((0.03), Point(-1.0, 0));
	auto action3 = MoveBy::create((0.03), Point(1.0, 0));
	auto action4 = MoveBy::create((0.03), Point(0.8, 0));
	auto action5 = MoveBy::create((0.03), Point(-0.8, 0));
	auto action6 = MoveBy::create((0.03), Point(-0.8, 0));
	auto action7 = MoveBy::create((0.03), Point(0.8, 0));
	auto catSiteDestroyedAction = Sequence::create(action, action1, action2, action3, action4, action5, action6, action7, NULL);
	auto catSiteDestroyedActionRepeat = RepeatForever::create(catSiteDestroyedAction);
    
    if(isStage13){
        catSite_Angryed_13->setVisible(false);
    }
    
	catSiteCrash->runAction(catSiteDestroyedActionRepeat);

}


void MungGuGame::dogSiteDestroyedEffect(float delta){
	//이곳저곳이 팡팡

	SpriteFrameCache::getInstance()
		->addSpriteFramesWithFile("attackEffect.plist");

	dogSiteCrashEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
	dogSiteCrashEffect->setAnchorPoint(Point(0.5, 0.5));
	dogSiteCrashEffect->setPosition(Point(dogSiteRandX, dogSiteRandY));

	dogSiteCrashEffect->setAnchorPoint(Point(0.5, 0.5));
	this->addChild(dogSiteCrashEffect, 50);

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.05);
	dogSiteCrashEffect->setScale(1.2*winSize.width/1200);

	for (int i = 0; i<6; i++) {
		auto dogSiteCrashEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));
		animation->addSpriteFrame(dogSiteCrashEffect);
	}

	auto attackEffectAnimate = Animate::create(animation);

	dogSiteCrashEffect->runAction(attackEffectAnimate);

}


void MungGuGame::dogSiteDestroyed(){

	dogSite->setVisible(false);
	dogSiteCrash = Sprite::create("dogSiteCrash.png");//dogSiteCrash 들어가야
	dogSiteCrash->setAnchorPoint(Point(0.5, 0));
	dogSiteCrash->setPosition(Point(dogSite->getPositionX(), dogSite->getPositionY()));
    dogSiteCrash->setScale(dogSiteScaleRate);
	this->addChild(dogSiteCrash, 2);
	//건물이 흔들흔들
	auto action = MoveBy::create((0.03), Point(-1.0, 0));
	auto action1 = MoveBy::create((0.03), Point(1.0, 0));
	auto action2 = MoveBy::create((0.03), Point(1.0, 0));
	auto action3 = MoveBy::create((0.03), Point(-1.0, 0));
	auto action4 = MoveBy::create((0.03), Point(-0.8, 0));
	auto action5 = MoveBy::create((0.03), Point(0.8, 0));
	auto action6 = MoveBy::create((0.03), Point(0.8, 0));
	auto action7 = MoveBy::create((0.03), Point(-0.8, 0));
	auto dogSiteDestroyedAction = Sequence::create(action, action1, action2, action3, action4, action5, action6, action7, NULL);
	auto dogSiteDestroyedActionRepeat = RepeatForever::create(dogSiteDestroyedAction);
	dogSiteCrash->runAction(dogSiteDestroyedActionRepeat);

}




void MungGuGame::setStageName(){//스테이지 명
    
    if(isStage1 == true){
	stageName = Label::createWithTTF(StringUtils::format("Hello World"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage2 == true) {
     stageName = Label::createWithTTF(StringUtils::format("Keep Going"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage3 == true) {
        stageName = Label::createWithTTF(StringUtils::format("3rd"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage4 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Never Die"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage5 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Oh"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage6 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Angry Cats"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage7 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Lucky"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage8 == true) {
        stageName = Label::createWithTTF(StringUtils::format("I And You"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage9 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Gu"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage10 == true) {
        stageName = Label::createWithTTF(StringUtils::format("SSip"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage11 == true) {
        stageName = Label::createWithTTF(StringUtils::format("One of One"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage12 == true) {
        stageName = Label::createWithTTF(StringUtils::format("12th"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage13 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Omatt"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage14 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Making"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage15 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Stage"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage16 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Namis"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage17 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Difficult"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage18 == true) {
        stageName = Label::createWithTTF(StringUtils::format("18th"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage19 == true) {
        stageName = Label::createWithTTF(StringUtils::format("you Sorry"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage20 == true) {
        stageName = Label::createWithTTF(StringUtils::format("ending"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage21 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Continuously"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage22 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Give"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage23 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Mee"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage24 == true) {
        stageName = Label::createWithTTF(StringUtils::format("YourDog"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage25 == true) {
        stageName = Label::createWithTTF(StringUtils::format("I wanna"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage26 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Have"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage27 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Variety"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage28 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Dogs"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage29 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Thanks"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else if(isStage30 == true) {
        stageName = Label::createWithTTF(StringUtils::format("Bye-"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }else{
        stageName = Label::createWithTTF(StringUtils::format("Default"), "NanumBarunGothicBold.otf", 26);//폰트적용 O(나눔고딕 볼드체)
    }
	stageName->setPosition(Point(winSize.width / 10, winSize.height * 9 / 10));
	stageName->setAnchorPoint(Point(0, 0.5));
	stageName->setColor(Color3B::BLACK);
	this->addChild(stageName, 4);
}


//저장소 사용하여 현재 머니현황 표시
void MungGuGame::setMyMoney()
{
	maxMoney = 2000;
	myMoney = UserDefault::getInstance()->
		getIntegerForKey("MyMoney");//최고점수 값에대해 myMoney 라는 값으로 키값이 지정
	UserDefault::getInstance()->
		setIntegerForKey("MyMoney", myMoney);
	// myMoney++;
	//   UserDefault::getInstance()->flush();
	myMoneyCalc = myMoney; //초기화

	myMoney_label = Label::createWithTTF //최고점수 표시할 라벨 선언
		(StringUtils::format("%d / %d", (int)myMoney, maxMoney), "NanumBarunGothicBold.otf", 23);
	myMoney_label->setAnchorPoint(Point(0, 1));
	myMoney_label->setPosition(Point(winSize.width * 17 / 20, winSize.height - 20));
	myMoney_label->setTag(1);
	myMoney_label->setColor(Color3B::BLACK);
	this->addChild(myMoney_label, 4);
}

void MungGuGame::changeMyMoney(){

	if ((int)(myMoney + 1 * moneyIncreaseRate) <= maxMoney){//올린다.
		myMoney += 1 * moneyIncreaseRate;

	}
	else{
		myMoney = maxMoney;
	}

	if ((isFirstStageLoser == false) && isFirstStageClear == false){
		myMoney_label->setString(StringUtils::format("%d / %d", (int)myMoney, maxMoney));

	}
}

void MungGuGame::missionClearEvent(){
    
    //m11 클리어 이벤트
    bool isM11Clear = UserDefault::getInstance()->getBoolForKey("m11");
    if((isM11Clear==false)&&(isStage4==true)){
        
        //            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        //            if(isSong == true){//song 켰나 안켯나 확인
        //                int disabledSong =
        //                SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
        //            }
        
        UserDefault::getInstance()->setBoolForKey("m11",true);//8미션 클리어
        
        auto m11Clear = Label::createWithTTF(StringUtils::format("mission 11 Clear~!!!\n-> Shield Breaker"), "NanumBarunGothicBold.otf", 20);
        m11Clear->setAnchorPoint(Point(0.5,1));
        m11Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m11Clear->setColor(Color3B::BLACK);
        m11Clear->setVisible(false);
        this->addChild(m11Clear,10);
        if(initByEnglish==false){
            m11Clear->setString(StringUtils::format("미션 11 클리어~!!!\n -> 쉴드 브레이커"));
        }
        auto action = Blink::create(3,10);
        m11Clear->runAction(action);
    }
    
    //m14 클리어 이벤트
    bool isM14Clear = UserDefault::getInstance()->getBoolForKey("m14");
    if((isM11Clear==false)&&(isStage13==true)){
        
        //            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
        //            if(isSong == true){//song 켰나 안켯나 확인
        //                int disabledSong =
        //                SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
        //            }
        
        UserDefault::getInstance()->setBoolForKey("m14",true);//8미션 클리어
        
        auto m14Clear = Label::createWithTTF(StringUtils::format("mission 14 Clear~!!!\n-> Don't touch me"), "NanumBarunGothicBold.otf", 20);
        m14Clear->setAnchorPoint(Point(0.5,1));
        m14Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m14Clear->setColor(Color3B::BLACK);
        m14Clear->setVisible(false);
        this->addChild(m14Clear,10);
        if(initByEnglish==false){
            m14Clear->setString(StringUtils::format("미션 14 클리어~!!!\n -> 날 건드리지마"));
        }
        auto action = Blink::create(3,10);
        m14Clear->runAction(action);
    }
}

void MungGuGame::changeCatSiteHp(){
	catSiteHp_label->setString(StringUtils::format("%d / %d", catSiteNowHp, catSiteMaxHp));
}

void MungGuGame::changeDogSiteHp(){
	dogSiteHp_label->setString(StringUtils::format("%d / %d", dogSiteNowHp, dogSiteMaxHp));
}

void MungGuGame::setCatSiteHp(){
	Rect catSiteRect = catSite->getBoundingBox();
	catSiteMaxHp = setCatSiteMaxHp;
	catSiteNowHp = catSiteMaxHp;
	catSiteHp_label = Label::createWithTTF(StringUtils::format("%d / %d", catSiteNowHp, catSiteMaxHp), "NanumBarunGothic.otf", 13);
	//catSite->addChild(catSiteHp_label);
	catSiteHp_label->setAnchorPoint(Point(0.5, 0));
	catSiteHp_label->setPosition(Point(catSiteRect.getMidX(), catSiteRect.getMaxY()));
	catSiteHp_label->setColor(Color3B::BLACK);
	this->addChild(catSiteHp_label, 4);
}

void MungGuGame::decreasedCatSiteHp(int damageValue){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    
    if ((isSong == true) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
        //		int breakSound =
        SimpleAudioEngine::getInstance()->playEffect("BreakSound.wav");
    }
    
	if (damageValue >= 50){//일정이상의 데미지를 받으면 살짝 흔들리는 건물M
		//건물이 흔들흔들
	

		auto action = MoveBy::create((0.05), Point(0.8, 0));
		auto action1 = MoveBy::create((0.05), Point(-0.8, 0));
		auto action2 = MoveBy::create((0.05), Point(-0.8, 0));
		auto action3 = MoveBy::create((0.05), Point(0.8, 0));

		auto catSiteDestroyedAction = Sequence::create(action, action1, action2, action3, NULL);
   
        if(isCatSiteShild == true){
            catSiteShield->runAction(catSiteDestroyedAction);
        }else{
        catSite->runAction(catSiteDestroyedAction);
        }
        
      //  }

    }else{

        auto action = MoveBy::create((0.05), Point(0.4, 0));
        auto action1 = MoveBy::create((0.05), Point(-0.4, 0));
        auto action2 = MoveBy::create((0.05), Point(-0.4, 0));
        auto action3 = MoveBy::create((0.05), Point(0.4, 0));
        
        auto catSiteDestroyedAction = Sequence::create(action, action1, action2, action3, NULL);
        
        if(isCatSiteShild == true){
           
        catSiteShield->runAction(catSiteDestroyedAction);
        }else{
             catSite->runAction(catSiteDestroyedAction);
        }
}
    if(isCatSiteShild==true){
        shildAttackCount++;
        if(shildAttackCount >= 10){//ㅠㅠ
            if(shildAttackCount == 10){
                //무적에 대한 힌트
                if(initByEnglish==true){
                stage4_message = Label::createWithTTF(StringUtils::format("I have a deathless shild. ^오^\n You can't defeat me before strip my Shield!!"), "NanumBarunGothic.otf", 16);//폰트적용 O(나눔고딕 볼드체)
               
                }else{
                    stage4_message = Label::createWithTTF(StringUtils::format("난 무적 갑옷을 입고 있지!\n 벗기기 전엔 힘들걸? ^오^"), "NanumBarunGothic.otf", 16);//폰트적용 O(나눔고딕 볼드체)
                }
                stage4_message->setColor(Color3B::BLUE);
                stage4_message->setPosition(Point(catSiteShildRect.getMinX()+16,catSiteShildRect.getMaxY()));
                stage4_message->setAnchorPoint(Point(1,0));
                this->addChild(stage4_message);
                stage4_message->setVisible(false);
                auto messageAction = Blink::create(6,3); //6초간 3번 깜빡
                auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
                stage4_message->runAction(action);

            }
        }
    }
    
    if (damageValue<catSiteNowHp){
        if ((isFirstStageClear == false) && (isFirstStageLoser == false))
            //구현중
            catSiteAttackEffect();
        if(isCatSiteShild==false){//쉴드 있으면 체력 안 닳음
            catSiteNowHp -= damageValue;
            if(isStage9==true){
                damageValueSum += damageValue;
                
                if(catSiteNowHp<2500){
                    //일정 이상 밀리면 자동으로 꺼짐.
                    
                    auto delayAction = DelayTime::create(1);
                    auto gameOverAction = Sequence::create(CallFunc::create(this,callfunc_selector(MungGuGame::gameOverMessage)),CallFunc::create(this,callfunc_selector(MungGuGame::initSinTaeDoll)),delayAction,NULL);//꺼져
                    Rect catSiteRect = catSite->getBoundingBox();
                    Rect gameOverBtnRect = gameOverBtn->getBoundingBox();
                    if((isStopFinger==false)&&
                       (gameOverBtnRect.getMinX() <= catSiteRect.getMaxX()-13*(winSize.width/1300))){
                        //스위치 눌리는 소리
                        bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                        
                        if (isSong == true){
                            SimpleAudioEngine::getInstance()->playEffect("switch.wav");
                        }
                    if(isGameOverMessage==false){
                        isGameOverMessage=true;
                    gameOverBtn->setVisible(false);
                    gameOverBtn_->setVisible(true);
                    runAction(gameOverAction);
                        }
                    }
                   
                }else{
                    if(isStopFinger==false){
                    if(damageValueSum >= 150){
                        damageValueSum-=150;
                        auto catSiteMoveAction = MoveBy::create(0, Point(2.3,0));
                        catSite->runAction(catSiteMoveAction);
                    }
                    }//사이에 터치가 없으면, 뒤로 밀려 게임오버됨..
                }
            }
        }
    }
    else{
        catSiteAttackEffect();
        catSiteNowHp = 0;
    }
}
void MungGuGame::gameOverMessage(){
    
    //물러나게 하기 이벤트
    auto act = Blink::create(1, 13);
    whiteDot->setColor(Color3B(200,230,230));
    whiteDot->runAction(act);
    ////
    auto act0 = DelayTime::create(1.0);
    auto action = Sequence::create(act0, CallFunc::create(this, callfunc_selector(MungGuGame::nextMusicStart)), NULL);
    ///여기몬
    
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
    if(isSong == true){//song 켰나 안켯나 확인
        int disabledSong =
        SimpleAudioEngine::getInstance()->playEffect("Bell1.wav");
    }
    runAction(action);
    for (Monster* sprMung : myMonsters) {
        sprMung->monsterAction(ACTION_HITTED);
    }
    /////////////////////
    
    Rect gameOverBtnRect = gameOverBtn->getBoundingBox();
    if(initByEnglish==true){
    auto message = Label::createWithTTF(StringUtils::format("I got it~!!"), "NanumBarunGothic.otf", 16);
    message->setAnchorPoint(Point(0.5,0));
    message->setPosition(Point(gameOverBtnRect.getMidX()+5,gameOverBtnRect.getMinY()-30));
    message->setColor(Color3B::RED);
    this->addChild(message,1);
    }else{
        auto message = Label::createWithTTF(StringUtils::format("땡큐! ^-^"), "NanumBarunGothic.otf", 16);
        message->setAnchorPoint(Point(0.5,0));
        message->setPosition(Point(gameOverBtnRect.getMidX()+5,gameOverBtnRect.getMinY()-30));
        message->setColor(Color3B::BLACK);
        this->addChild(message,1);
    }
}
void MungGuGame::gameTurnOff(){
     Director::getInstance()->end();
}
void MungGuGame::dogSiteAttackEffect(){
	{

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");

		attackEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
		Rect dogSiteRect = dogSite->getBoundingBox();

		int attackEffectPosX = dogSiteRect.getMinX() + rand() % (int)((dogSiteRect.getMaxX() - dogSiteRect.getMidX())*0.8);
		int attackEffectPosY = dogSiteRect.getMinY() + rand() % (int)((dogSiteRect.getMaxY() - dogSiteRect.getMidY())*0.8);

		attackEffect->setPosition
			(Point(attackEffectPosX, attackEffectPosY));

		attackEffect->setAnchorPoint(Point(0, 0.5));
		attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
		this->addChild(attackEffect, 10);//여기여기

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.06);

		for (int i = 0; i<6; i++) {
			auto attackEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));

			animation->addSpriteFrame(attackEffect);
		}


		auto attackEffectAnimate = Animate::create(animation);
		attackEffect->setScale(1.2*winSize.width/1200);

		attackEffect->runAction(attackEffectAnimate);
	}
}

void MungGuGame::catSiteAttackEffect(){
	{

		SpriteFrameCache::getInstance()->addSpriteFramesWithFile("attackEffect.plist");

		attackEffect = Sprite::createWithSpriteFrameName("attackEffect_0.png");
		Rect catSiteRect = catSite->getBoundingBox();

		int attackEffectPosX = catSiteRect.getMinX() + rand() % (int)((catSiteRect.getMaxX() - catSiteRect.getMidX())*0.8);
		int attackEffectPosY = catSiteRect.getMinY() + rand() % (int)((catSiteRect.getMaxY() - catSiteRect.getMidY())*0.8);

		attackEffect->setPosition
			(Point(attackEffectPosX, attackEffectPosY));

		attackEffect->setAnchorPoint(Point(0, 0.5));
		//attackEffect->setTag(TAG_SPRITE_ATTACKEFFECT);
		this->addChild(attackEffect, 10);

		auto animation = Animation::create();
		animation->setDelayPerUnit(0.06);

		for (int i = 0; i<6; i++) {
			auto attackEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("attackEffect_%d.png", i));

			animation->addSpriteFrame(attackEffect);
		}


		auto attackEffectAnimate = Animate::create(animation);
		attackEffect->setScale(1.2*winSize.width/1200);

		attackEffect->runAction(attackEffectAnimate);
	}
}

void MungGuGame::decreasedDogSiteHp(int damageValue){
    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
	if (damageValue >= 50){//일정이상의 데미지를 받으면 살짝 흔들리는 건물M
		//건물이 흔들흔들
		//고양이사운드
		if ((isSong == true) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
	//		int breakSound =
				SimpleAudioEngine::getInstance()->playEffect("BreakSound.wav");
		}

		auto action = MoveBy::create((0.05), Point(-0.8, 0));
		auto action1 = MoveBy::create((0.05), Point(0.8, 0));
		auto action2 = MoveBy::create((0.05), Point(0.8, 0));
		auto action3 = MoveBy::create((0.05), Point(-0.8, 0));

		auto dogSiteDestroyedAction = Sequence::create(action, action1, action2, action3, NULL);
		dogSite->runAction(dogSiteDestroyedAction);

    }else{
        if ((isSong == true) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
      //      int breakSound =
            SimpleAudioEngine::getInstance()->playEffect("BreakSound.wav");
        }
        
        auto action = MoveBy::create((0.05), Point(-0.4, 0));
        auto action1 = MoveBy::create((0.05), Point(0.4, 0));
        auto action2 = MoveBy::create((0.05), Point(0.4, 0));
        auto action3 = MoveBy::create((0.05), Point(-0.4, 0));
        
        auto dogSiteDestroyedAction = Sequence::create(action, action1, action2, action3, NULL);
        dogSite->runAction(dogSiteDestroyedAction);
    }
	if (damageValue<dogSiteNowHp){
		if ((isFirstStageClear == false) && (isFirstStageLoser == false))
			dogSiteAttackEffect();
		dogSiteNowHp -= damageValue;
	}
	else{
		dogSiteAttackEffect();
		dogSiteNowHp = 0;
	}

}

void MungGuGame::UpperToneDecreaseCatHp(Monster *sprMung, EnemyMonster *sprCat){
    
}

void MungGuGame::UpperToneDecreaseMungguHp(Monster *sprMung, EnemyMonster *sprCat){
    if(sprCat->isStrongAboutBig==true){//적이 큰적에게 세다면,
        if(sprMung->unitSize >= 2){
            //중형 혹은 큰 적이면,
            if (sprMung->now_hp >= 1.5*(sprCat->damageValue)){
                sprMung->now_hp -= 1.5*(sprCat->damageValue);//2배의 데미지를 줌
            }else{
                initEnemyAttackEffect(sprMung,sprCat);
                sprMung->now_hp = 0;//
                sprMung->monsterAction(ACTION_DIE);
                //nearMungPos = dogSiteRect.getMaxX()-30; ///D I E///
            }
        }else{
            //아니라면, 2배 약함..
            if (sprMung->now_hp >= (sprCat->damageValue)/3){
                sprMung->now_hp -= (sprCat->damageValue)/3;
            }else{
                sprMung->now_hp = 0;//
                sprMung->monsterAction(ACTION_DIE);
                //nearMungPos = dogSiteRect.getMaxX()-30; ///D I E///
            }
            
        }
        
    }else if(sprCat->isStrongAboutSmall==true){//적이 작은 적에게 세다면,
        if(sprMung->unitSize == 1){//작은 적일 떄,
            if (sprMung->now_hp >= 1.5*(sprCat->damageValue)){
                sprMung->now_hp -= 1.5*(sprCat->damageValue);//3배의 데미지를 줌
            }else{
                sprMung->now_hp = 0;//죽을때 이벤트는 나중에 함수로 --구현 완료--
                sprMung->monsterAction(ACTION_DIE);
                //nearMungPos = dogSiteRect.getMaxX()-30; ///D I E///
            }
        }else{
            //아니라면, 2배 약함..
            if (sprMung->now_hp >= (sprCat->damageValue)/1.5){
                sprMung->now_hp -= (sprCat->damageValue)/1.5;
            }else{
                sprMung->now_hp = 0;//죽을때 이벤트는 나중에 함수로 --구현 완료--
                sprMung->monsterAction(ACTION_DIE);
                //nearMungPos = dogSiteRect.getMaxX()-30; ///D I E///
            }
        }
    }else{
        if (sprMung->now_hp >= (sprCat->damageValue)){
            sprMung->now_hp -= (sprCat->damageValue); //이도 저도 아님 기본공격.
        }else{
            sprMung->now_hp = 0;//죽을때 이벤트는 나중에 함수로 --구현 완료--
            sprMung->monsterAction(ACTION_DIE);
            //nearMungPos = dogSiteRect.getMaxX()-30; ///D I E///
        }
        
    }
}

void MungGuGame::dogSiteHitted(EnemyMonster* enemyMonster)
{
    
    
    if ((isFirstStageLoser == false) && (isFirstStageClear == false)){
        
        
        Rect catRect = enemyMonster->getBoundingBox();
        int nearMungPos = getNearMungPos();
        if ((isAllMungguDie()==true)){//모든 멍구가 죽어 있으면,
            
            if(catRect.getMinX()-enemyMonster->attackRangeValue <= dogSitePos){
                decreasedDogSiteHp(enemyMonster->damageValue*damageValueIncreaseRate);//멍구 기지를 공격한다.
            }
            
        }else{//멍구가 한마리라도 살아있을 경우
            
            //적 유닛의 체력을 감소시킨다.
            Rect catSiteRect = catSite->getBoundingBox();
            //int catPos = catRect.getMaxX()-enemyMonster->enemySizeDecreaseRate;
            
            //////////////범 위 공 격////////////////
            for (Monster* sprMung : myMonsters) {
                if(sprMung->now_hp > 0){
                    //만약 지금 유닛의 앞에 적 유닛이 있다면 체력을 감소
                    Rect rectMung = sprMung->getBoundingBox();
                    
                    
                    int mungPos = rectMung.getMaxX() - sprMung->mySizeDecreaseRate;
                    
                    //진행중
                    
                    /////////////범 위 공 격///////////////
                    if(enemyMonster->isMultiAttack==true){//범위공격이 가능한 놈이면,
                        
                        if(catRect.getMinX()-(enemyMonster->attackRangeValue) <= dogSitePos){
                            decreasedDogSiteHp(enemyMonster->damageValue*damageValueIncreaseRate);//적 기지의 공격
                        }
                        
                        if((catRect.getMinX()-(enemyMonster->attackRangeValue)) < mungPos){//공격범위에 도달하면
                            if (sprMung->now_hp > (enemyMonster->damageValue*damageValueIncreaseRate)){//멍구의 체력을 달게한다.
                                initEnemyAttackEffect(sprMung, enemyMonster);
                                sprMung->now_hp -= enemyMonster->
                                damageValue*damageValueIncreaseRate;
                            }
                            else{
                                //if (sprCat->isEnemyDie == false){//체력이 다달면 죽게 만든다.
                                initEnemyAttackEffect(sprMung, enemyMonster);
                                sprMung->now_hp = 0;
                                sprMung->monsterAction(ACTION_DIE);
                                
                                
                            }
                        }
                    }
                    
                    
                    
                }
            }
            
            /////////////단 일 공 격///////////////
            if(enemyMonster->isMultiAttack==false){//단일공격만 가능한 놈이라면,
                Monster *sprMung;
                sprMung = getInfrontMunggu();
                Rect mungRect = sprMung->getBoundingBox();
                Rect catRect = enemyMonster->getBoundingBox();
                int mungPos = mungRect.getMaxX() - sprMung->mySizeDecreaseRate;
                
                if(catRect.getMinX()-enemyMonster->attackRangeValue <= dogSitePos){
                    decreasedDogSiteHp(enemyMonster->damageValue*damageValueIncreaseRate);//멍구 기지를 공격한다.
                }else if(catRect.getMinX()-enemyMonster->attackRangeValue <= mungPos){
                    if (sprMung->now_hp > (enemyMonster->damageValue*damageValueIncreaseRate)){//적의 체력을 달게한다.
                        initEnemyAttackEffect(sprMung, enemyMonster);
                        sprMung->now_hp -= enemyMonster->
                        damageValue*damageValueIncreaseRate;
                    }
                    else{//체력이 다 달면 죽는다.
                        //if (sprCat->isEnemyDie == false){
                        
                        initEnemyAttackEffect(sprMung, enemyMonster);
                        sprMung->now_hp = 0;
                        sprMung->monsterAction(ACTION_DIE);
                        //nearCatPos = catSiteRect.getMinX();
                        
                    }
                }
                
                
            }
            
        }
    }
}//여기에 유닛에 대한 체력감소 함수 구현하자. ---구현 완료---

void MungGuGame::catSiteHitted(Monster* monster)
{
    //* 현재 규칙 : 적 건물은 앞에 적 유닛이 없을때만 공격이 가능하다.*//
    //* 현재 규칙 : 적 유닛은 앞에 적 유닛이 있기만 하면 공격이 가능하다.*//
    // if(isFirstStageLoser == false)
    //만약 개의 건물 공격이 아니라면 실행되면 안됨.
    //18.07.30
    Rect rectMung = monster -> getBoundingBox();
    Rect catSiteRect = catSite->getBoundingBox();
    if ((isFirstStageLoser == false) && (isFirstStageClear == false)){
        
        int nearCatPos = getNearCatPos();
        CCLOG("%d",nearCatPos);
        Rect mungRect = monster->getBoundingBox();
        
        if ((isAllMonsterDie()==true)){//적이 아무도 없고 기지만 있으면,
            if(mungRect.getMaxX()+monster->attackRangeValue >= catSitePos){
                decreasedCatSiteHp(monster->damageValue*damageValueIncreaseRate);//적 기지의 공격
            }
            
            
        }else{
            // if ((monster->isEnemyUnitInFront == true)&&(monster->isEnemySiteInFront == false)){
            
            //   if((mungRect.getMaxX()+(monster->attackRangeValue)) > nearCatPos){
            //적 유닛의 체력을 감소시킨다.
            Rect catSiteRect = catSite->getBoundingBox();
            Rect sprMungRect = monster->getBoundingBox();
            //            int mungPos = sprMungRect.getMaxX()-monster->mySizeDecreaseRate;
            
            if(monster->isMultiAttack==true){//만약 멀티공격이 가능한 몬스터라면, 생존해있는 고양이들 상태에 따라 근처에 있으면 전부 공격을 한다.
                
                for (EnemyMonster* sprCat : enemyMonsters) {
                    if(sprCat->now_hp > 0){
                        //만약 지금 유닛의 앞에 적 유닛이 있다면 체력을 감소
                        Rect rectCat = sprCat->getBoundingBox();
                        
                        //                int catPos = rectCat.getMinX()+sprCat->enemySizeDecreaseRate;
                        int catPos = rectCat.getMinX() + sprCat->enemySizeDecreaseRate;
                        //진행중
                        
                        /////////////범 위 공 격///////////////
                        
                        if((sprMungRect.getMaxX()+(monster->attackRangeValue)) >= catPos){//만약 각각의 고양이적들이 근처에 올 경우,
                            
                            if (sprCat->now_hp > (monster->damageValue*damageValueIncreaseRate)){//적의 체력을 달게한다.
                                initAttackEffect(monster, sprCat);//적군 공격 시의 이펙트
                                sprCat->now_hp -= monster->
                                damageValue*damageValueIncreaseRate;
                            }
                            else{
                                //if (sprCat->isEnemyDie == false){
                                
                                initAttackEffect(monster, sprCat);
                                sprCat->now_hp = 0;
                                sprCat->monsterAction(ACTION_DIE);
                                //nearCatPos = catSiteRect.getMinX();
                                
                            }
                        }
                    }
                }
                
                //적들에 대한 공격을 다한 후, 만약 기지까지 공격범위 근처에 있었다면, 기지도 공격
                if(sprMungRect.getMaxX()+(monster->attackRangeValue) >= catSitePos){
                    decreasedCatSiteHp(monster->damageValue*damageValueIncreaseRate);//적 기지의 공격
                }
                
                //그 후 공격 루틴을 마친다.
            }
            
            /////////////단 일 공 격///////////////
            if(monster->isMultiAttack==false){//단일 공격일 경우
                
                EnemyMonster *sprCat;
                sprCat = getInfrontEnemy();
                Rect rectCat = sprCat->getBoundingBox();
                int catPos = rectCat.getMinX() + sprCat->enemySizeDecreaseRate;
                
                
                if(mungRect.getMaxX()+monster->attackRangeValue >= catSitePos){
                    decreasedCatSiteHp(monster->damageValue*damageValueIncreaseRate);//적 기지의 공격
                }else if(mungRect.getMaxX()+monster->attackRangeValue >= catPos){
                    if (sprCat->now_hp > (monster->damageValue*damageValueIncreaseRate)){//적의 체력을 달게한다.
                        initAttackEffect(monster, sprCat);//적군 공격 시의 이펙트
                        sprCat->now_hp -= monster->
                        damageValue*damageValueIncreaseRate;
                    }else{
                        
                        initAttackEffect(monster, sprCat);
                        sprCat->now_hp = 0;
                        sprCat->monsterAction(ACTION_DIE);
                        //nearCatPos = catSiteRect.getMinX();
                        
                    }
                }
                
                
            }
        }
        
    }
    
}

EnemyMonster *MungGuGame::getInfrontEnemy(){
    EnemyMonster *imsiCat = nullptr;
    int tempNum = 9999;
    for (EnemyMonster* sprCat : enemyMonsters) {
        Rect catRect = sprCat->getBoundingBox();
        int catPos = catRect.getMinX()+(sprCat->enemySizeDecreaseRate);
        if(sprCat->now_hp > 0){
            if(tempNum > catPos){//해당 적 위치가 더 앞에 있으면,
                tempNum = catPos;//해당 적 위치값을 저장하고
                imsiCat = sprCat;//가장 앞의 적 현황을 갱신한다.
            }
        }
    }
    return imsiCat;
}

Monster *MungGuGame::getInfrontMunggu(){
    Monster *imsiMung = nullptr;
    int tempNum = 0;
    for (Monster* sprMung : myMonsters) {
        Rect mungRect = sprMung->getBoundingBox();
        int mungPos = mungRect.getMaxX()-(sprMung->mySizeDecreaseRate);
        if(sprMung->now_hp > 0){
            if(tempNum < mungPos){//해당 멍구 위치가 더 앞에 있으면,
                tempNum = mungPos;//해당 멍구 위치값을 저장하고
                imsiMung = sprMung;//가장 앞의 멍구 현황을 갱신한다.
            }
        }
    }
    return imsiMung;
}
               
void MungGuGame::setDogSiteHp(){
	dogSiteMaxHp = setDogSiteMaxHp;
	dogSiteNowHp = dogSiteMaxHp;
	Rect dogSiteRect = dogSite->getBoundingBox();

	dogSiteHp_label = Label::createWithTTF(StringUtils::format("%d / %d", dogSiteNowHp, dogSiteMaxHp), "NanumBarunGothic.otf", 13);
	//dogSite->addChild(dogSiteHp_label);
	dogSiteHp_label->setAnchorPoint(Point(0.5, 0));
	dogSiteHp_label->setPosition(Point(dogSiteRect.getMidX(), dogSiteRect.getMaxY()));//왜 getPositionX()가 안될까
	dogSiteHp_label->setColor(Color3B::BLACK);
	this->addChild(dogSiteHp_label, 4);
}





void MungGuGame::setMungBtn(){
	
    //레벨이 만약 0이면, 희미라게 표시
    mungLv= UserDefault::getInstance()->getIntegerForKey("mungLv");
    whangLv= UserDefault::getInstance()->getIntegerForKey("whangLv");
    mungBallLv= UserDefault::getInstance()->getIntegerForKey("mungBallLv");
    mungButLv= UserDefault::getInstance()->getIntegerForKey("mungButLv");
    mungSausageLv= UserDefault::getInstance()->getIntegerForKey("mungSausageLv");

    
    
    mungBtn = Sprite::create("mungGuBtn.png");
	mungBtn->setPosition(Point(winSize.width * 19 / 60, 56 * sizeRate));
	mungBtn->setScale(sizeRate);

	this->addChild(mungBtn, 40);

	mungBtn_ = Sprite::create("mungGuBtn_.png");
	mungBtn_->setPosition(Point(winSize.width * 19 / 60, 56 * sizeRate));
	mungBtn_->setScale(sizeRate);
	this->addChild(mungBtn_, 40);

	mungBtn_->setVisible(false);

	///

    //2번째
	whangGuBtn = Sprite::create("whangGuBtn.png");
	whangGuBtn->setPosition(Point(mungBtn->getPositionX() + (110 * sizeRate), mungBtn->getPositionY()));
	whangGuBtn->setScale(sizeRate);
	this->addChild(whangGuBtn, 40);

	whangGuBtn_ = Sprite::create("whangGuBtn_.png");
	whangGuBtn_->setPosition(Point(mungBtn->getPositionX() + (110 * sizeRate), mungBtn->getPositionY()));
	whangGuBtn_->setScale(sizeRate);
	this->addChild(whangGuBtn_, 40);
    
    if(whangLv==0){
    whangGuBtn->setVisible(false);
    }else{
	whangGuBtn_->setVisible(false);
    }
    
    mungBallBtn = Sprite::create("mungBallBtn.png");
    mungBallBtn->setPosition(Point(mungBtn->getPositionX() + (220 * sizeRate), mungBtn->getPositionY()));
    mungBallBtn->setScale(sizeRate);
    this->addChild(mungBallBtn, 40);
    
   
    mungBallBtn_ = Sprite::create("mungBallBtn_.png");
    mungBallBtn_->setPosition(Point(mungBtn->getPositionX() + (220 * sizeRate), mungBtn->getPositionY()));
    mungBallBtn_->setScale(sizeRate);
    this->addChild(mungBallBtn_, 40);
    mungBallBtn_->setVisible(false);

    if(whangLv==0){
        mungBallBtn->setVisible(false);
    }else{
        mungBallBtn_->setVisible(false);
    }
    
	mungButterFlyBtn = Sprite::create("mungButterflyBtn.png");
	mungButterFlyBtn->setPosition(Point(mungBtn->getPositionX() + (330 * sizeRate), mungBtn->getPositionY()));
	mungButterFlyBtn->setScale(sizeRate);
	this->addChild(mungButterFlyBtn, 40);

	mungButterFlyBtn_ = Sprite::create("mungButterflyBtn_.png");
	mungButterFlyBtn_->setPosition(Point(mungBtn->getPositionX() + (330 * sizeRate), mungBtn->getPositionY()));

	mungButterFlyBtn_->setVisible(false);
	mungButterFlyBtn_->setScale(sizeRate);
	this->addChild(mungButterFlyBtn_, 40);

    if(mungButLv==0){
        mungButterFlyBtn->setVisible(false);
    }else{
        mungButterFlyBtn_->setVisible(false);
    }
    

	mungSausageBtn = Sprite::create("mungSausageBtn.png");
	mungSausageBtn->setPosition(Point(mungBtn->getPositionX() + (440 * sizeRate), mungBtn->getPositionY()));
	mungSausageBtn->setScale(sizeRate);
	this->addChild(mungSausageBtn, 40);

	mungSausageBtn_ = Sprite::create("mungSausageBtn_.png");
	mungSausageBtn_->setPosition(Point(mungBtn->getPositionX() + (440 * sizeRate), mungBtn->getPositionY()));

	mungSausageBtn_->setScale(sizeRate);
	this->addChild(mungSausageBtn_, 40);
	
    
    if(mungSausageLv==0){
        mungSausageBtn->setVisible(false);
    }else{
       mungSausageBtn_->setVisible(false);
    }

	btnRaiseRate = 13;//2행 버튼 터치시, 버튼의 Y값 증가량
	//2행 1열 버튼
    
    auto nullBtn6_ = Sprite::create("nullBtn.png");
    nullBtn6_->setPosition(Point(mungBtn->getPositionX() + (30 * sizeRate), mungBtn->getPositionY() + 36));
    nullBtn6_->setScale(sizeRate);
    nullBtn6_->setOpacity(50);
    this->addChild(nullBtn6_, 30);

	auto nullBtn2_ = Sprite::create("nullBtn.png");
	nullBtn2_->setPosition(Point(nullBtn6_->getPositionX() + (110 * sizeRate), nullBtn6_->getPositionY()));
	nullBtn2_->setScale(sizeRate);
    nullBtn2_->setOpacity(50);
	this->addChild(nullBtn2_, 30);

	auto nullBtn3_ = Sprite::create("nullBtn.png");
	nullBtn3_->setPosition(Point(nullBtn6_->getPositionX() + (220 * sizeRate), nullBtn6_->getPositionY()));
	nullBtn3_->setScale(sizeRate);
    nullBtn3_->setOpacity(50);
	this->addChild(nullBtn3_, 30);

	auto nullBtn4_ = Sprite::create("nullBtn.png");
	nullBtn4_->setPosition(Point(nullBtn6_->getPositionX() + (330 * sizeRate), nullBtn6_->getPositionY()));
	nullBtn4_->setScale(sizeRate);
    nullBtn4_->setOpacity(50);
	this->addChild(nullBtn4_, 30);

	auto nullBtn5_ = Sprite::create("nullBtn.png");
	nullBtn5_->setPosition(Point(nullBtn6_->getPositionX() + (440 * sizeRate), nullBtn6_->getPositionY()));
	nullBtn5_->setScale(sizeRate);
    nullBtn5_->setOpacity(50);
	this->addChild(nullBtn5_, 30);


    
    if(whangLv==0){
        whangGuBtn_->setOpacity(200);
        whangGuBtn_->setTexture("nullBtn.png");
    }
    if(mungBallLv==0){
        mungBallBtn_->setOpacity(200);
        mungBallBtn_->setTexture("nullBtn.png");
    }
    if(mungButLv==0){
        mungButterFlyBtn_->setOpacity(200);
        mungButterFlyBtn_->setTexture("nullBtn.png");
    }
    if(mungSausageLv==0){
        mungSausageBtn_->setOpacity(200);
        mungSausageBtn_->setTexture("nullBtn.png");
    }

}

void MungGuGame::resetStop(){
	isStop = false;
}

                    /////////////////터 치 비 긴//////////////////

bool MungGuGame::onTouchBegan(Touch *touch, Event *unused_event){
	//터치 시작시의 이벤트
	Point loc = touch->getLocation();
	//initAttackEffect(); //Effect Test
    
    if((isStage28==true)&&(isDevsQuestion==true)){
        if(answerBtn1Rect.containsPoint(loc)){
            answerBtn1->setOpacity(130);
        }
        
        if(answerBtn2Rect.containsPoint(loc)){
            answerBtn2->setOpacity(130);

        }
        
        if(answerBtn3Rect.containsPoint(loc)){
            answerBtn3->setOpacity(130);
        }
    }

    
    
    
    if((isTutorialFinished==false)&&(isStage1==true)){
    if (tutRect.containsPoint(loc)){
            tutExitBtn->setVisible(false);
            tutExitBtn_->setVisible(true);
    }
    }
    
    
    //4스테이지 터치 특수 이벤트
    if((loc.y<=catSiteShildRect.getMinY())&&(loc.y>=catSiteShildRect.getMinY()-50)&&
       (loc.x<=catSiteShildRect.getMaxX())&&(loc.x>=catSiteShildRect.getMinX())&&
       (isStage4==true)&&(isCatSiteShild==true)){
        isReadyToRemoveTheShild = true;//쉴드를 제거할 조건 충족
    }
    
    
    
    
    if(isStage9==true){
        //No problem
    catSiteRect = catSite->getBoundingBox();
    Rect gameOverBtnRect = gameOverBtn->getBoundingBox();
        
    if((loc.x>=catSiteRect.getMaxX()-20)&&(loc.x<=gameOverBtnRect.getMinX())){
        if((loc.y<=catSiteRect.getMaxY()-10)&&(loc.y>=catSiteRect.getMinY())){
            isStopFinger = true;
        }
    }
        
        if((loc.x>=gameOverBtnRect.getMinX())&&(loc.x<=gameOverBtnRect.getMidX())
           &&(loc.y<=gameOverBtnRect.getMaxY()-10)&&(loc.y>=gameOverBtnRect.getMinY())){
            
                bool isSong = UserDefault::getInstance()->getBoolForKey("isSong");
        
                        if (isSong == true){
                            SimpleAudioEngine::getInstance()->playEffect("switch.wav");
                        }
  
            
            
            /////////============================================/////////
            
            ///////////씨벌 2/8 ~ 2/9일 이 코드 부분떄문에 개고생함.////////// => Conclusion. Sequence액션 구현 과정에서 에러 발생.
    
//        auto delayAction = DelayTime::create(1);
//        auto gameOverAction = Squence::create(CallFunc::create(this,callfunc_selector(MungGuGame::gameOverMessage)),delayAction
//                                            ,CallFunc::create(this,callfunc_selector(MungGuGame::initSinTaeDoll)),NULL);//꺼져 대신 신태돌
//            
           
            /////////============================================/////////
            //////No Problem//////
            if(isGameOverMessage==false)
            {
                isGameOverMessage=true;
                gameOverBtn->setVisible(false);
                gameOverBtn_->setVisible(true);
                //////
                gameOverMessage();//해결
                initSinTaeDoll();//해결
                
            }
            
          }
    }
    
    ///////////////////////// Emergency /////////////////////////
    
    //No Problem.
    Rect regameBtnRect = regameBtn->getBoundingBox();
	if (regameBtnRect.containsPoint(loc)){
		if (isFirstStageLoser == true){
			isRegameBtnTouched = true;
			regameBtn->setVisible(false);
			regameBtn_->setVisible(true);

		}
	}

    Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
	if (homeBackBtnRect.containsPoint(loc)){
        
        if(isStage18==true){
            //버튼 함정 이벤트 존재 18스테이지
            Rect sinBtnRect = sinBtn->getBoundingBox();
            if(!sinBtnRect.containsPoint(loc)){
                isHomeBackBtnTouched = true;
                homeBackBtn->setVisible(false);
                homeBackBtn_->setVisible(true);
            }
        }else{
        
		if ((isFirstStageClear == true) || (isFirstStageLoser == true)){
            
			isHomeBackBtnTouched = true;
			homeBackBtn->setVisible(false);
			homeBackBtn_->setVisible(true);

		}
        }
	}
    
    Rect sinBtnRect = sinBtn->getBoundingBox();
    if ((sinBtnRect.containsPoint(loc))&&(catSiteNowHp==0)&&(isStage18==true)){//신태돌버튼에 가리키고,
        if ((isFirstStageClear == true) || (isFirstStageLoser == true)){
                isSinBtnTouched = true;
                sinBtn->setVisible(false);
                sinBtn_->setVisible(true);
        }
    }

	if (resumeBtnRect.containsPoint(loc)){//재개버튼
		if (isPause == true){
			isResumeBtnTouched = true;//ha
			resumeBtn->setVisible(false);
			resumeBtn_->setVisible(true);

		}
	}


	if (goHomeBtnRect.containsPoint(loc)){//홈가기
		if (isPause == true){
			isGoHomeBtnTouched = true;
			goHomeBtn->setVisible(false);
			goHomeBtn_->setVisible(true);
		}
	}




	//소리 설정
	if (isSongBtnRect.containsPoint(loc)){
		if (isNotSongBtnTouched == false){
			if (isPause == true){
				if (isSongBtnTouched == false){

					isSongBtnTouched = true;
					isSongBtn->setVisible(false);
					isSongBtn_->setVisible(true);
					isNotSongBtn->setVisible(false);
					isNotSongBtn_->setVisible(false);
				}
			}
		}
		else{
			if (isPause == true){
				isSongBtnTouched = true;
				isSongBtn->setVisible(false);
				isSongBtn_->setVisible(false);
				isNotSongBtn->setVisible(false);
				isNotSongBtn_->setVisible(true);
			}
		}
	}

	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false) && (isDevsQuestion==false)){
		if (pauseBtnRect.containsPoint(loc)){
			if ((isPause == false)&&(isInitSinTaeDoll==false)&&(isDevsQuestion==false)){
				isPauseBtnTouched = true;
				pauseBtn->setVisible(false);
				pauseBtn_->setVisible(true);
			}
		}
	}

    //첫번쨰 버튼
	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true) && (isDevsQuestion==false)){
		if (mungBtnRect.containsPoint(loc)){//멍구 버튼

            if((myMoney>=mungCost)&&(isFirstBtnCoolTimeFinished==true)){//쿨타임 끝나고 돈이 있으면 눌림
			isMungBtnTouched = true;
			mungBtn->setVisible(false);
			mungBtn_->setVisible(true);
            }
		}
	}


    
    //2번째 황구 버튼
    if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
        //		if (whangGuBtnRect.containsPoint(loc) && (!mungBtnRect.containsPoint(loc) && (!mungBallBtnRect.containsPoint(loc)))){//2행1열 버튼영역이면서 1행1열,1행2열 버튼영역이 아닌 부위를 터치 하면,
        if (whangGuBtnRect.containsPoint(loc)){//지금은 2번째
            //            if(isWhangGuBtnTouched==true){
            //			mungButterFlyBtn->setOpacity(50);//윗 유닛 버튼 터치시 아랫엿의 버튼 투명도 감소
            //			mungBtn->setOpacity(50);
            //			mungBallBtn->setOpacity(50);
            //			mungSausageBtn->setOpacity(50);
            //            mungButterFlyBtn_->setOpacity(50);//윗 유닛 버튼 터치시 아랫엿의 버튼 투명도 감소
            //            mungBtn_->setOpacity(50);
            //            mungBallBtn_->setOpacity(50);
            //            mungSausageBtn_->setOpacity(50);
            //            }
            
            if((myMoney>=whangCost)&&(is2ndBtnCoolTimeFinished==true)&&(isTutorialFinished==true) && (isDevsQuestion==false)){//두번쨰 버튼
                isWhangGuBtnTouched = true;
                whangGuBtn->setVisible(false);
                whangGuBtn_->setVisible(true);
            }
        }
    }
    
    
    
    
    //세번째 버튼
    if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true) && (isDevsQuestion==false)){
        if (mungBallBtnRect.containsPoint(loc)){//멍공 버튼
            
            if((myMoney>=mungBallCost)&&(is3rdBtnCoolTimeFinished==true)){
                isMungBallBtnTouched = true;
                mungBallBtn->setVisible(false);
                mungBallBtn_->setVisible(true);
            }
        }
    }
    
    //네번쨰 버튼
    if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false) &&(isTutorialFinished==true) && (isDevsQuestion==false)){
        if (mungButBtnRect.containsPoint(loc)){//멍나비
            if((myMoney>=mungButCost)&&(is4thBtnCoolTimeFinished==true)){
                isMungButBtnTouched = true;
                mungButterFlyBtn->setVisible(false);
                mungButterFlyBtn_->setVisible(true);
            }
        }
    }
    
    //타섯번째 버튼
    if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true) && (isDevsQuestion==false)){
        if (mungSausageBtnRect.containsPoint(loc)){//멍소세지 버튼
            
            if((myMoney>=mungSausageCost)&&(is5thBtnCoolTimeFinished==true)){//600
                isMungSausageBtnTouched = true;
                mungSausageBtn->setVisible(false);
                mungSausageBtn_->setVisible(true);
            }
        }
    }
    
    
    ////////////

	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false) && (isMungFire == false)&&(isTutorialFinished==true) && (isDevsQuestion==false)){
		if ((mungGuFireBtnRect.containsPoint(loc)&&(mungFireCoolTimeFinished==true))){//멍구발사버튼

			isMungGuFireBtnTouched = true;
			mungCoFireBtn->setVisible(false);
			mungCoFireBtn_->setVisible(true);
			if (isMungFire == false){
				initDogSite_fireReady();
				//initExploreMileStoneAction();
			}
		}
	}






	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true)){
		if (statusBarForMaxMoney_Rect.containsPoint(loc)){//멍공 버튼

			if (myMoney >= nowNeededMoneyForMaxMoney){//소지중인 돈이 더 많을 때,
				isStatusBarForMaxMoneyTouched = true;//터치를 인식

			}
		}
	}

	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true)){
		if (statusBarForPower_Rect.containsPoint(loc)){//멍공 버튼

			if (myMoney >= nowNeededMoneyForPower){//소지중인 돈이 더 많을 때,
				isStatusBarForPowerTouched = true;//터치를 인식

			}
		}
	}

	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)&&(isTutorialFinished==true)){
		if (statusBarForSpeed_Rect.containsPoint(loc)){//멍공 버튼

			if (myMoney >= nowNeededMoneyForSpeed){//소지중인 돈이 더 많을 때,
				isStatusBarForSpeedTouched = true;//터치를 인식

			}
		}
	}
    
	return true;
}

void MungGuGame::onTouchMoved(Touch *touch, Event *unused_event){
	//터치 드래그시의 이벤트
	Point loc = touch->getLocation();
    
    // 신태돌 버튼은 네모 바깥으로 드래그 되야 이동됨.
    
    ///stage4 이벤트
    if(isReadyToRemoveTheShild == true){
        if((loc.y>=catSiteShildRect.getMaxY())&&
           (loc.x<=catSiteShildRect.getMaxX()&&(loc.x>=catSiteShildRect.getMinX()))){
            //   auto moveShild = MoveBy::create(0.1,Point(0,5));
            auto moveShild2 =
            MoveTo::create(2,Point(catSiteShildRect.getMidX(),winSize.height+100));
            auto moveShild3 =
            EaseOut::create(moveShild2,2);
            Rect groundRect = ground->getBoundingBox();
            catSiteShildRect = catSiteShield->getBoundingBox();
            //  if(catSiteShildRect.getMinY()>=groundRect.getMaxY()){
            catSiteShield->setOpacity(160);
            catSiteShield->runAction(moveShild3);
            isCatSiteShild = false;
            isReadyToRemoveTheShild = false;
            //    }
            if( isStage4_message == false){
                isStage4_message = true;
                //
                auto stage4_message = Label::createWithTTF(StringUtils::format("-,. -;;"), "NanumBarunGothic.otf", 30);//폰트적용 O(나눔고딕 볼드체)
                stage4_message->setColor(Color3B::BLACK);
                stage4_message->setPosition(Point(catSiteShildRect.getMinX()+15,catSiteShildRect.getMaxY()));
                stage4_message->setAnchorPoint(Point(1,0));
                this->addChild(stage4_message);
                stage4_message->setVisible(false);
                auto messageAction = Blink::create(3,1);
                auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::missionClearEvent)),CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
                stage4_message->runAction(messageAction);
            }
        }
        
    }
    
    if(isSinBtnTouched==true){
        Rect sinBtnRect = sinBtn->getBoundingBox();
        homeBackBtn->setVisible(false);
        homeBackBtn_->setVisible(true);
        
        if (homeBackBtnRect.containsPoint(loc)){
            //네모영역안에서는 이동 없음
            
        }else{
            //네모 바깥을 나가면, 이동이 됨.
            sinBtn->setPosition(Point(loc.x,loc.y));
            sinBtn_->setPosition(Point(loc.x,loc.y));
        }
    }
    
    
    
    //13스테이지 이벤트
    if((isStage13==true)&&(isCatSiteAngryed==false)){
        
        Rect catSiteRect = catSite->getBoundingBox();
        if(((loc.y<=catSiteRect.getMaxY()-30)&&(loc.y>=catSiteRect.getMinY()))&&
           ((loc.x<=catSiteRect.getMaxX()-30)&&(loc.x>=catSiteRect.getMinX()+30))){
            isCatSiteAngryed=true;
            //어맛!
            catSite->setVisible(false);
            catSite_Angryed_13->setVisible(true);
            if(initByEnglish==true){
                stage13_message -> setString(StringUtils::format("Don't touch me!!"));
                stage13_message->setColor(Color3B::BLACK);
                
            }else{
                stage13_message -> setString(StringUtils::format("나좀 건드리지 마!"));//폰트적용 O(나눔고딕 볼드체)
                 stage13_message->setColor(Color3B::BLACK);
                //ssss
            }
            
            auto messageAction = Blink::create(3,5);
            auto action = Sequence::create(messageAction,CallFunc::create(this,callfunc_selector(MungGuGame::initSinTaeDoll)),NULL);
            auto action2 = Sequence::create(action,CallFunc::create(this,callfunc_selector(MungGuGame::missionClearEvent)),CallFunc::create(this,callfunc_selector(MungGuGame::initStageTalk)),NULL);
            
            stage13_message->runAction(action2);
   
        
        }
        
        
    }
    
    
 
    
    
    if(isSinBtnTouched==true){
        Rect sinBtnRect = sinBtn->getBoundingBox();
        
        if (sinBtnRect.containsPoint(loc)){
            homeBackBtn->setVisible(false);
            homeBackBtn_->setVisible(true);
            
        }
    }
    
    
if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
   
	if (isHomeBackBtnTouched == true){
         Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
		if (homeBackBtnRect.containsPoint(loc)){
			homeBackBtn->setVisible(false);
			homeBackBtn_->setVisible(true);
		}
		else{
			homeBackBtn->setVisible(true);
			homeBackBtn_->setVisible(false);
		}
	}
    
   
	if (isRegameBtnTouched == true){
          Rect regameBtnRect = regameBtn->getBoundingBox();
		if (regameBtnRect.containsPoint(loc)){
			regameBtn->setVisible(false);
			regameBtn_->setVisible(true);
		}else{
			regameBtn->setVisible(true);
			regameBtn_->setVisible(false);
		}
	}


	if ((isMungButBtnTouched == true)&&(mungButLv!=0)){
		if (mungButBtnRect.containsPoint(loc)){
			mungButterFlyBtn->setVisible(false);
			mungButterFlyBtn_->setVisible(true);
		}
		else{
			mungButterFlyBtn->setVisible(true);
			mungButterFlyBtn_->setVisible(false);
		}
	}


	if (isGoHomeBtnTouched == true){
		if (isPause == true){
			if (goHomeBtnRect.containsPoint(loc)){
				goHomeBtn->setVisible(false);
				goHomeBtn_->setVisible(true);
			}
			else{
				goHomeBtn->setVisible(true);
				goHomeBtn_->setVisible(false);
			}
		}
	}

	//소리 설정
	if ((isPause == true) && (isSongBtnTouched == true)){

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
		}
		else{
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

	if (isPause == true){
		if (isResumeBtnTouched == true){//ha

			if (resumeBtnRect.containsPoint(loc)){//재개버튼
				resumeBtn->setVisible(false);
				resumeBtn_->setVisible(true);
			}
			else{
				resumeBtn->setVisible(true);
				resumeBtn_->setVisible(false);
			}
		}
	}

	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
		if (isPauseBtnTouched == true){

			if (pauseBtnRect.containsPoint(loc)){
				pauseBtn->setVisible(false);
				pauseBtn_->setVisible(true);
			}
			else{
				pauseBtn->setVisible(true);
				pauseBtn_->setVisible(false);
			}
		}
	}


	//isMungBallBtnTouched
	if (isMungGuFireBtnTouched == true){
		// isMungFire = true;
		if (mungGuFireBtnRect.containsPoint(loc)){
			mungCoFireBtn->setVisible(false);
			mungCoFireBtn_->setVisible(true);
		}
		else{
			mungCoFireBtn->setVisible(true);
			mungCoFireBtn_->setVisible(false);
		}
	}

	if (isMungBtnTouched == true){
		if (mungBtnRect.containsPoint(loc)){
			mungBtn->setVisible(false);
			mungBtn_->setVisible(true);
		}
		else{
			mungBtn->setVisible(true);
			mungBtn_->setVisible(false);
		}
	}

	if ((isWhangGuBtnTouched == true)&&(whangLv!=0)){
		//if ((whangGuBtnRect.containsPoint(loc)) && (!mungBtnRect.containsPoint(loc))){
        if ((whangGuBtnRect.containsPoint(loc))){
//            mungButterFlyBtn->setOpacity(50);//윗 유닛 버튼 터치시 아랫엿의 버튼 투명도 감소
//            mungBtn->setOpacity(50);
//            mungBallBtn->setOpacity(50);
//            mungSausageBtn->setOpacity(50);
//            mungButterFlyBtn_->setOpacity(50);//윗 유닛 버튼 터치시 아랫엿의 버튼 투명도 감소
//            mungBtn_->setOpacity(50);
//            mungBallBtn_->setOpacity(50);
//            mungSausageBtn_->setOpacity(50);
          //  nullBtn_->setOpacity(50);

			whangGuBtn->setVisible(false);
			whangGuBtn_->setVisible(true);
		}
		else{
			whangGuBtn->setVisible(true);
			whangGuBtn_->setVisible(false);
		}
	}


	//isMungBallBtnTouched
	if ((isMungBallBtnTouched == true)&&(mungBallLv!=0)){
		if (mungBallBtnRect.containsPoint(loc)){
			mungBallBtn->setVisible(false);
			mungBallBtn_->setVisible(true);
		}
		else{
			mungBallBtn->setVisible(true);
			mungBallBtn_->setVisible(false);
		}
	}


	if ((isMungSausageBtnTouched == true)&&(mungSausageLv!=0)){
		if (mungSausageBtnRect.containsPoint(loc)){
			mungSausageBtn->setVisible(false);
			mungSausageBtn_->setVisible(true);
		}
		else{
			mungSausageBtn->setVisible(true);
			mungSausageBtn_->setVisible(false);
		}
	}




	//maxMoney에서 움직일때
	if (isStatusBarForMaxMoneyTouched == true){//터치 인식중일때,
		//  if(myMoney >= nowNeededMoneyForMaxMoney){//소지한돈이 여전히 많으면,
		if (statusBarForMaxMoney_Rect.containsPoint(loc)){//영역안에 터치가 있을때
			
			isStatusBarForMaxMoneyTouched = true;
			statusPushBar_maxMoney->setVisible(true);
		}
		// }
	}

	//power
	if (isStatusBarForPowerTouched == true){//터치 인식중일때,
		if (statusBarForPower_Rect.containsPoint(loc)){//영역안에 터치가 있을때
			
			isStatusBarForPowerTouched = true;
			statusPushBar_power->setVisible(true);
		}
	}

	//speed
	if (isStatusBarForSpeedTouched == true){//터치 인식중일때,
		if (statusBarForSpeed_Rect.containsPoint(loc)){//영역안에 터치가 있을때
			
			isStatusBarForSpeedTouched = true;
			statusPushBar_speed->setVisible(true);
		}
	}
}
}

void MungGuGame::onTouchEnded(Touch *touch, Event *unused_event){
	//터치 끝날시의 이벤트
	Point loc = touch->getLocation();

    if((isStage4==true)&&(isReadyToRemoveTheShild == true)){//4스테이지 용
        isReadyToRemoveTheShild = false;
    }
    
    if((isStage28==true)&&(isDevsQuestion==true)){
          answerBtn1->setOpacity(230);
        answerBtn2->setOpacity(230);
        answerBtn3->setOpacity(230);

        
        
        if(answerBtn1Rect.containsPoint(loc)){
            
          ////미션미션몬
            isDevsQuestion=false;
            //미션 10 클리어
            //m12 클리어 이벤트 멍포 100번 발사 하면 클리어
            bool isM10Clear = UserDefault::getInstance()->getBoolForKey("m10");
           
            
            if(isM10Clear==false){
                
                 stage13_message->setVisible(false);
                
                Director::getInstance()->resume();
                UserDefault::getInstance()->setBoolForKey("m10",true);//8미션 클리어
                
                auto m10Clear = Label::createWithTTF(StringUtils::format("mission 10 Clear~!!!\n-> Thank you ^*^"), "NanumBarunGothicBold.otf", 20);
                m10Clear->setAnchorPoint(Point(0.5,1));
                m10Clear->setPosition(Point(winSize.width/2,winSize.height-20));
                m10Clear->setColor(Color3B::BLACK);
                m10Clear->setVisible(false);
                this->addChild(m10Clear,10);
                if(initByEnglish==false){
                    m10Clear->setString(StringUtils::format("미션 10 클리어~!!!\n -> 이해 감사 ^*^"));
                }
                auto action = Blink::create(3,10);
                m10Clear->runAction(action);
                
                answerBtn1_label->setVisible(false);
                answerBtn1->setVisible(false);
                answerBtn2->setVisible(false);
                answerBtn2_label->setVisible(false);
                answerBtn3->setVisible(false);
                    answerBtn3_label->setVisible(false);
                stageTalk_label->setVisible(false);
            }else{
                Director::getInstance()->resume();
                stage13_message->setColor(Color3B::BLACK);
                stage13_message->setScale(1.7*winSize.width/1200);
                 stage13_message->setString(StringUtils::format("^*^"));
                answerBtn1_label->setVisible(false);
                answerBtn1->setVisible(false);
                answerBtn2->setVisible(false);
                answerBtn2_label->setVisible(false);
                answerBtn3->setVisible(false);
                answerBtn3_label->setVisible(false);
                stageTalk_label->setVisible(false);
            }
            
            
        }
        
        if(answerBtn2Rect.containsPoint(loc)){
            isDevsQuestion=false;
            Director::getInstance()->resume();
            initSinTaeDoll();
            stage13_message->setString(StringUtils::format("You don't need to know ^^"));
            answerBtn1_label->setVisible(false);
            answerBtn1->setVisible(false);
            answerBtn2->setVisible(false);
            answerBtn2_label->setVisible(false);
            answerBtn3->setVisible(false);
            answerBtn3_label->setVisible(false);
             stageTalk_label->setVisible(false);
        }
        
        if(answerBtn3Rect.containsPoint(loc)){
            isDevsQuestion=false;
            Director::getInstance()->resume();
            initSinTaeDoll();
             stage13_message->setString(StringUtils::format("Me-too.  Bye. ^^"));
            answerBtn1_label->setVisible(false);
            answerBtn1->setVisible(false);
            answerBtn2->setVisible(false);
            answerBtn2_label->setVisible(false);
            answerBtn3->setVisible(false);
            answerBtn3_label->setVisible(false);
             stageTalk_label->setVisible(false);
        }
    }
    
    
    if(isSinBtnTouched==true){
       
        catSiteNowHp=1;
        isSinBtnTouched = false;
        
        Rect sinBtnRect = sinBtn->getBoundingBox();
        if(homeBackBtnRect.containsPoint(loc)){
             isFirstStageClear=false;
        SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
        //크라스
        
        youWin->setVisible(false);
        gold_Label->setVisible(false);
            initSinTaeDoll();
        }else{
            homeBackBtn->setVisible(true);
            homeBackBtn_->setVisible(false);
        }
    }
    
    if((isTutorialFinished==false)&&(isStage1==true)){
    if (tutRect.containsPoint(loc)){
        tutExitBtn->setVisible(false);
        tutExitBtn_->setVisible(false);
        isTutorialFinished = true;
        tutorialWindow->setVisible(false);
        
        
        auto blinkAction = Blink::create(2, 2);
        auto delayAction = DelayTime::create(0.5);
        auto talkAction = Sequence::create(delayAction,blinkAction,NULL);
        
        stageTalk_label->runAction(talkAction);//첫 스테이지 아군 대화 "Let's go-!"
    }else{
        tutExitBtn->setVisible(true);
        tutExitBtn_->setVisible(false);
    }
        }
    
    if(isStage5==true){
        isStopFinger=false;
    }
	//멍구발사버튼 터치하면,
	if (isMungGuFireBtnTouched == true){

		mungCoFireBtn->setVisible(true);
		mungCoFireBtn_->setVisible(false);
		isMungGuFireBtnTouched = false;
		exploreMileStone->setVisible(false);
		exploreMileStone2->setVisible(false);

		if ((isFirstStageClear == false) && (isFirstStageLoser == false)){
			if ((mungGuFireBtnRect.containsPoint(loc))){
                if(myMoney >= mungPoCost){
                    
                    //m12 클리어 이벤트 멍포 100번 발사 하면 클리어
                    bool isM12Clear = UserDefault::getInstance()->getBoolForKey("m12");

                    int mungPoCount = UserDefault::getInstance()->getIntegerForKey("mungPoCount",0);
                    UserDefault::getInstance()->setIntegerForKey("mungPoCount", mungPoCount+1);
                    if((isM12Clear==false)&&(mungPoCount==100)){
                        
               
                        UserDefault::getInstance()->setBoolForKey("m12",true);//8미션 클리어
                        
                        auto m12Clear = Label::createWithTTF(StringUtils::format("mission 12 Clear~!!!\n-> mungPo King"), "NanumBarunGothicBold.otf", 20);
                        m12Clear->setAnchorPoint(Point(0.5,1));
                        m12Clear->setPosition(Point(winSize.width/2,winSize.height-20));
                        m12Clear->setColor(Color3B::BLACK);
                        m12Clear->setVisible(false);
                        this->addChild(m12Clear,10);
                        if(initByEnglish==false){
                            m12Clear->setString(StringUtils::format("미션 12 클리어~!!!\n -> 멍포 왕"));
                        }
                        auto action = Blink::create(3,10);
                        m12Clear->runAction(action);
                    }

                    
                    
                myMoney -= mungPoCost;//300 150멍포 발사 비용(준비액션 포함 100x)
                    
                    mungFireCoolTimeFinished = false;
                    mungCoFireBtn->setVisible(false);
                    mungCoFireBtn_->setVisible(true);
                    //쿨타임 액션
                    auto to1 = ProgressTo::create(6,100);
                    auto timerAct = ReverseTime::create(to1);
                    timerAction = Sequence::create(timerAct,CallFunc::create(this,callfunc_selector(MungGuGame::mungFireCoolTimeFinish)),NULL);
                    mungFireTimer->runAction(timerAction);
                    
                    //멍포 장전음을 멈춤
				SimpleAudioEngine::getInstance()
					->stopEffect(mungFireReadySound);
				//애니매이션 수행중임을 표시
				//mungGuFireBtn의 액션 작동 예정.///
				if (isMungFire == false){
					isInitMissile = true; //미사일 투하위치 아는 용도
					isMungFire = true;

					initDogSite_fire();
					initMungFireMissile();//미사일을 발사
				}
                }else{
                    //라라
                    Rect dogSiteRect = dogSite->getBoundingBox();
                    auto message = Label::createWithTTF //상태버튼 speed
                    (StringUtils::format("you have no fuel ㅜ"), "NanumBarunGothic.otf", 15);
                    if(initByEnglish==false){
                        message->setString(StringUtils::format("연료부족.. ㅜ"));
                    }
                    message->setVisible(false);
                    message->setPosition(Point(dogSiteRect.getMaxX()-20,dogSiteRect.getMaxY()-50));
                    message->setAnchorPoint(Point(0,0.5));
                    message->setColor(Color3B::BLACK);
                    this->addChild(message,20);
                    auto blinkAction = Blink::create(0.6,2);
                    message->runAction(blinkAction);
                    
                    initDogSite_fireCancel();
                }
			}
			else{
				if (isMungFire == false){
					isMungFire = true;


					initDogSite_fireCancel();
				}
			}
		}
	}
	if (isPause == true){//pauseWindow
		if (isGoHomeBtnTouched == true){
			goHomeBtn->setVisible(true);
			goHomeBtn_->setVisible(false);
			isGoHomeBtnTouched = false;
			//정지상태일때
			//홈으로 이동
          
			if ((goHomeBtnRect.containsPoint(loc))){//일시정지 버튼위에 있고, 정지 안되있으면,


				audioCount = 0;//음악 옵션에 사용됨

				Director::getInstance()->getEventDispatcher()->removeAllEventListeners();

				isPause = false;
                isFirstStageLoser = true;

				if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == true)
					SimpleAudioEngine::getInstance()->stopBackgroundMusic();
				SimpleAudioEngine::getInstance()->stopAllEffects();
				myMonsters.clear();
				enemyMonsters.clear();
                setStageSelect();
				auto scene = TransitionFade::create(1.5, MungGuGameMenuScene::createScene());
				Director::getInstance()->replaceScene(scene);

			}

		}
	}

	if (((isFirstStageClear == true) || (isFirstStageLoser == true))||(isStage18==true)){
		if (isHomeBackBtnTouched == true){
			homeBackBtn->setVisible(true);
			homeBackBtn_->setVisible(false);
			isHomeBackBtnTouched = false;

			//홈으로 이동
            Rect homeBackBtnRect = homeBackBtn->getBoundingBox();
			if ((homeBackBtnRect.containsPoint(loc))){//일시정지 버튼위에 있고, 정지 안되있으면,
			
				Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
				// SimpleAudioEngine::getInstance()->stopBackgroundMusic();//음악 정지

				isPause = false;
//				isFirstStageClear = false;
//				isFirstStageLoser = false;
//                isFirstStageLoser = true;
				//음악 메모리 해제
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();
				SimpleAudioEngine::getInstance()->stopAllEffects();
				myMonsters.clear();
				enemyMonsters.clear();
                setStageSelect();
                //z클리어 후, 이동하는 곳
                 int stage20_clearCount =
                UserDefault::getInstance()->getIntegerForKey("stage20_clearCount");
                
                if(isStage20==false){
                    
                    ////////18스테이지 클리어 조건/////////////
                    Rect sinBtnRect = sinBtn->getBoundingBox();//18스테이지
                    if(isStage18==true){
                        if(!sinBtnRect.containsPoint(loc)){//홈으로 돌아갈 수 있게되면 보상과 클리어 이벤트
                            
                            
                            int stage18_clearCount =
                            UserDefault::getInstance()->getIntegerForKey("stage18_clearCount");
                            UserDefault::getInstance()->setIntegerForKey("stage18_clearCount", stage18_clearCount+1);
                            if (isGoldCalc == false){
                                isGoldCalc = true;
                                
                                int clearNum = UserDefault::getInstance()->getIntegerForKey("stage18_clearCount");
                                
                                
                                
                                if (clearNum != 1){
                                    UserDefault::getInstance()->setIntegerForKey("goldForStage", goldForStage / clearNum + goldForStage / clearNum);
                                    goldForStage = UserDefault::getInstance()->getIntegerForKey("goldForStage");
                                    UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
                                }
                                else{
                                    UserDefault::getInstance()->setIntegerForKey("myGold", myGold += goldForStage);
                                }
                                
                            }
                        }/////////////////////////
                        auto scene = TransitionFade::create(1.5, MungGuGameMenuScene::createScene());
                        Director::getInstance()->replaceScene(scene);
                        
                        }else{
				auto scene = TransitionFade::create(1.5, MungGuGameMenuScene::createScene());
				Director::getInstance()->replaceScene(scene);
                    }
                }else{
                    //20 스테이지 클리어 시, 엔딩으로 이동
                    //체키럽
                    if( isFirstStageClear == true){
                    auto scene = TransitionFade::create(3, Epilogue::createScene());
                    Director::getInstance()->replaceScene(scene);
                    }else{
                        auto scene = TransitionFade::create(1.5, MungGuGameMenuScene::createScene());
                        Director::getInstance()->replaceScene(scene);
                    }
                }

			}

		}
	}


	if (isFirstStageLoser == true){
		if (isRegameBtnTouched == true){
			regameBtn->setVisible(true);
			regameBtn_->setVisible(false);
			isRegameBtnTouched = false;

			//홈으로 이동
            Rect regameBtnRect = regameBtn->getBoundingBox();
			if ((regameBtnRect.containsPoint(loc))){//일시정지 버튼위에 있고, 정지 안되있으면,

                if(dogSiteNowHp==0){
                    for (EnemyMonster* sprCat : enemyMonsters) {
                        sprCat->damageValue=0;//씬 바뀔때 문제 방지용
                    }
                }

                if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying() == true)
                    SimpleAudioEngine::getInstance()->stopBackgroundMusic();
                SimpleAudioEngine::getInstance()->stopAllEffects();
                myMonsters.clear();
                enemyMonsters.clear();
                
            mungGuDogSiteHpLv = UserDefault::getInstance()->getIntegerForKey("mungGuDogSiteHpLv");
            setDogSiteMaxHp = 2000+mungGuDogSiteHpLv*400-400;//멍구기지 체력
                dogSiteNowHp = dogSiteMaxHp;
                resetGameScene();//다시하기... 씬을 초기화 그런데 제대로 작동 안하는중
			}///problem..

		}
	}


	if ((isPause == false) && (isFirstStageClear == false) && (isFirstStageLoser == false)){
		if (isPauseBtnTouched == true){
			pauseBtn->setVisible(true);
			pauseBtn_->setVisible(false);
			isPauseBtnTouched = false;
			if (isPause == false){
				if ((pauseBtnRect.containsPoint(loc))){//일시정지 버튼위에 있고, 정지 안되있으면,


					isPause = true;

					setPauseWindow();
					initPauseWindow();
					if (myMoney>100){
						myMoney -= 100;
					}
					else{
						myMoney = 0;
					}
					Director::getInstance()->pause(); // 누르면 일시중지.

				}
			}
		}
	}


	if (isPause == true){
		if (isResumeBtnTouched == true){//ha
			isResumeBtnTouched = false;

			if (resumeBtnRect.containsPoint(loc)){//재개버튼
				//닫을 때 일어나는 이벤트 발생
				audioCount = 0;//음악 옵션에 사용됨
			    resumeBtn_->setVisible(false);
				removePauseWindow();
				isPause = false;
				Director::getInstance()->resume();//소리 적용때까지만 resume


			}


		}
	}

	//소리 설정
	if ((isPause == true) && (isSongBtnTouched == true)){
		if (isSongBtnRect.containsPoint(loc)){
			audioCount++;
			Director::getInstance()->resume();
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
				Director::getInstance()->pause();

			}
			else{
				//음악 켜진다.
				isSongBtn->setVisible(true);
				isSongBtn_->setVisible(false);
				isNotSongBtn->setVisible(false);
				isNotSongBtn_->setVisible(false);
				isNotSongBtnTouched = false;
                
                UserDefault::getInstance()->setBoolForKey("isSong", true);
                ////////스 테 이 지 별 음 악 넣 는 부 분///////////
                bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                
                if(isStage1 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage2 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage3 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage4 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage5 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage6 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage7 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage8 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage9 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("song.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage10 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage11 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage12 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("goodSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage13 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage14 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage15 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage16 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage17 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage18 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage19 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage20 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage21 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage22 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("goodSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage23 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("funnySong.wav", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage24 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage25 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage26 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage27 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("goodSong.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage28 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background2.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage29 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else if(isStage30 == true){
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("redriver.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }else{
                    if(isSong == true){//song 켰나 안켯나 확인
                        SimpleAudioEngine::getInstance();
                        if ((false == SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())){
                            SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true); //미리 로딩해두니 음악 재색속도가 빨라졌다.
                        }
                    }
                }
                 ////////스 테 이 지 별 음 악 넣 는 부 분///////////
                
                
                Director::getInstance()->pause();
                
                

			}
		}
	}

    //////첫번쨰 멍구 버튼
    if (isMungBtnTouched == true){
        
        mungBtn->setVisible(true);
        mungBtn_->setVisible(false);
        isMungBtnTouched = false;
        
        if (mungBtnRect.containsPoint(loc)){
            
            if (myMoney >= mungCost) {//100
                myMoney -= mungCost;
                Rect dogSiteRect = dogSite->getBoundingBox();
                
                addMonster(MONSTER_MUNGGU, Point(dogSiteRect.getMidX(), dogSite->getPositionY() - 5 -rand() % 18));
                
                //쿨타임 이벤트///
                isFirstBtnCoolTimeFinished = false;//쿨타임 실행
                coolTime1->setVisible(true);
                 auto coolTimeAction = Sequence::create(coolTimeAnimate,CallFunc::create(this,callfunc_selector(MungGuGame::firstBtnCoolTimeFinished)),NULL);
            
                coolTime1->runAction(coolTimeAction);
                
                coolTimeAnimate->retain();
                
                
            }
        }
        
    }//
    


	if ((isWhangGuBtnTouched == true)&&(whangLv!=0)){

		whangGuBtn->setVisible(true);
		whangGuBtn_->setVisible(false);
		isWhangGuBtnTouched = false;

        //2번쨰 버튼
        if ((whangGuBtnRect.containsPoint(loc))){
            
            if (myMoney >= whangCost) {//160
                myMoney -= whangCost;
                
                
                Rect dogSiteRect = dogSite->getBoundingBox();
                
                addMonster(MONSTER_WHANGGU, Point(dogSiteRect.getMidX(), dogSite->getPositionY() - 5 - rand() % 20));
                
                //쿨타임 이벤트//
                 is2ndBtnCoolTimeFinished=false; //쿨타임 진행
                coolTime2->setVisible(true);
                 auto coolTimeAction2 = Sequence::create(coolTime2Animate,CallFunc::create(this,callfunc_selector(MungGuGame::btn2ndCoolTimeFinished)),NULL);
               
                //여기에 쿨타임 애니메이션 + 콜백함수

                coolTime2->runAction(coolTimeAction2);
                
                coolTime2Animate->retain();
               
                
            }
        }
        
    }//
    
    //3번쟤
	if ((isMungBallBtnTouched == true)&&(mungBallLv!=0)){

		CCLOG("mungBall");
		mungBallBtn->setVisible(true);
		mungBallBtn_->setVisible(false);
		isMungBallBtnTouched = false;

		if (mungBallBtnRect.containsPoint(loc)){

			Rect dogSiteRect = dogSite->getBoundingBox();

			if (myMoney >= mungBallCost) {
				myMoney -= mungBallCost;//150
                
                
                //쿨타임 이벤트//
                is3rdBtnCoolTimeFinished=false; //쿨타임 진행
                coolTime3->setVisible(true);
                addMonster(MONSTER_MUNGBALL, Point(dogSiteRect.getMidX(), dogSite->getPositionY() - 6 - rand() % 20));
                auto coolTimeAction3 = Sequence::create(coolTime3Animate,CallFunc::create(this,callfunc_selector(MungGuGame::btn3rdCoolTimeFinished)),NULL);

                //여기에 쿨타임 애니메이션 + 콜백함수
                
                coolTime3->runAction(coolTimeAction3);
            
                coolTime3Animate->retain();
         
			}
		}

    }

	if ((isMungButBtnTouched == true)&&(mungButLv!=0)){

//		CCLOG("mungBut");
		mungButterFlyBtn->setVisible(true);
		mungButterFlyBtn_->setVisible(false);
		isMungButBtnTouched = false;

		if (mungButBtnRect.containsPoint(loc)){

			Rect dogSiteRect = dogSite->getBoundingBox();
			if (myMoney >= mungButCost) {
				myMoney -= mungButCost;//300 150
				addMonster(MONSTER_MUNGBUT, Point(dogSiteRect.getMidX()+35, dogSite->getPositionY() - 10- rand() % 13));
                
                //쿨타임 이벤트//
                is4thBtnCoolTimeFinished=false; //쿨타임 진행
                coolTime4->setVisible(true);
                 auto coolTimeAction4 = Sequence::create(coolTime4Animate,CallFunc::create(this,callfunc_selector(MungGuGame::btn4thCoolTimeFinished)),NULL);
                
                
                //여기에 쿨타임 애니메이션 + 콜백함수
                if(mungButLv!=0){
                coolTime4->runAction(coolTimeAction4);
                }
             
                coolTime4Animate->retain();
			}
		}

	}


	if ((isMungSausageBtnTouched == true)&&(mungSausageLv!=0)){

		CCLOG("mungSausage");
		mungSausageBtn->setVisible(true);
		mungSausageBtn_->setVisible(false);
		isMungSausageBtnTouched = false;

		if (mungSausageBtnRect.containsPoint(loc)){

			Rect dogSiteRect = dogSite->getBoundingBox();
			if (myMoney >= mungSausageCost) {
				myMoney -= mungSausageCost;//600
				addMonster(MONSTER_MUNGSAUSAGE, Point(dogSiteRect.getMidX(), dogSite->getPositionY() -5 - rand() % 10));
                
                //쿨타임 이벤트//
                is5thBtnCoolTimeFinished=false; //쿨타임 진행
                 coolTime5->setVisible(true);
                 auto coolTimeAction5 = Sequence::create(coolTime5Animate,CallFunc::create(this,callfunc_selector(MungGuGame::btn5thCoolTimeFinished)),NULL);
                
                //여기에 쿨타임 애니메이션 + 콜백함수
               if(mungSausageLv!=0){
                coolTime5->runAction(coolTimeAction5);
               }
                coolTime5Animate->retain();
			}
		}

	}



	//MaxMoney버튼이 터치될 때
	if (isStatusBarForMaxMoneyTouched == true){

		if (statusBarForMaxMoney_Rect.containsPoint(loc)){

            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
		
			if (maxMoneyLV < 7){
				if (myMoney >= nowNeededMoneyForMaxMoney){
					if (isSong == true){
			//			int chimeSound =
							SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
					}
					myMoney -= nowNeededMoneyForMaxMoney;

					maxMoneyLV++;
					//여기에 레벨업 이펙트 구현 머니속도 증가
					SpriteFrameCache::getInstance()->addSpriteFramesWithFile("LvUpEffect.plist");
					lvUpEffect = Sprite::createWithSpriteFrameName("LvUpEffect_0.png");

					lvUpEffect->setPosition(Point(winSize.width - 192, 65));
					lvUpEffect->setAnchorPoint(Point(0.5, 0.5));
					this->addChild(lvUpEffect, 5);

					auto animation = Animation::create();
					animation->setDelayPerUnit(0.06);

					for (int i = 0; i<4; i++) {
						auto LvUpEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("LvUpEffect_%d.png", i));
						animation->addSpriteFrame(LvUpEffect);
					}

					auto LvUpEffectAnimate = Animate::create(animation);
					lvUpEffect->runAction(LvUpEffectAnimate);

					maxMoney += 500; nowNeededMoneyForMaxMoney += (nowNeededMoneyForMaxMoney / maxMoneyLV);
					maxMoneyGage = Sprite::create("maxMoneyGage.png");
					maxMoneyGage->setAnchorPoint(Point(0.5, 0));
					int imsiPosY = 8 + 10 * maxMoneyLV;
					maxMoneyGage->setPosition(Point(winSize.width - 192, imsiPosY));
					this->addChild(maxMoneyGage, 1);
				}

				isStatusBarForMaxMoneyTouched = false;
				if (myMoney >= nowNeededMoneyForMaxMoney){
					statusPushBar_maxMoney->setVisible(false);
				}
				else{
					statusPushBar_maxMoney->setVisible(true);
				}
			}
		}


	}


	//power
	if (isStatusBarForPowerTouched == true){

		if (statusBarForPower_Rect.containsPoint(loc)){

            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
		
			if (powerLV < 7){
				if (myMoney >= nowNeededMoneyForPower){
					if (isSong == true){
				//		int chimeSound =
							SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
					}
					myMoney -= nowNeededMoneyForPower;

					powerLV++;
					//여기에 레벨업 이펙트 구현 완료
					damageValueIncreaseRate = damageValueIncreaseRate + 0.07;
					//데미지 점차 증가
					//여기에 능력치 향상되는 걸 기입
					SpriteFrameCache::getInstance()->addSpriteFramesWithFile("LvUpEffect.plist");
					lvUpEffect = Sprite::createWithSpriteFrameName("LvUpEffect_0.png");
					lvUpEffect->setPosition(Point(winSize.width - 114, 65));
					lvUpEffect->setAnchorPoint(Point(0.5, 0.5));
					//lvUpEffect->setTag(TAG_LVUPEFFECT);
					this->addChild(lvUpEffect, 5);

					auto animation = Animation::create();
					animation->setDelayPerUnit(0.06);

					for (int i = 0; i<4; i++) {
						auto LvUpEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("LvUpEffect_%d.png", i));
						animation->addSpriteFrame(LvUpEffect);
					}

					auto LvUpEffectAnimate = Animate::create(animation);
					lvUpEffect->runAction(LvUpEffectAnimate);

					nowNeededMoneyForPower += (nowNeededMoneyForPower / powerLV);
					powerGage = Sprite::create("powerGage.png");
					powerGage->setAnchorPoint(Point(0.5, 0));
					int imsiPosY = 8 + 10 * powerLV;
					powerGage->setPosition(Point(winSize.width - 114, imsiPosY));
					this->addChild(powerGage, 1);
				}

				isStatusBarForPowerTouched = false;
				if (myMoney >= nowNeededMoneyForPower){
					statusPushBar_power->setVisible(false);
				}
				else{
					statusPushBar_power->setVisible(true);
				}
			}
		}


	}


	//speed
	if (isStatusBarForSpeedTouched == true){

		if (statusBarForSpeed_Rect.containsPoint(loc)){

            bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
			
			if (speedLV < 7){
				if (myMoney >= nowNeededMoneyForSpeed){
					if (isSong == true){
				//		int chimeSound =
							SimpleAudioEngine::getInstance()->playEffect("ChimeSound.wav");
					}
					myMoney -= nowNeededMoneyForSpeed;

					speedLV++;
					SpriteFrameCache::getInstance()->addSpriteFramesWithFile("LvUpEffect.plist");
					lvUpEffect = Sprite::createWithSpriteFrameName("LvUpEffect_0.png");

					lvUpEffect->setPosition(Point(winSize.width - 36, 65));
					lvUpEffect->setAnchorPoint(Point(0.5, 0.5));
					//lvUpEffect->setTag(TAG_LVUPEFFECT);
					this->addChild(lvUpEffect, 5);

					auto animation = Animation::create();
					animation->setDelayPerUnit(0.06);

					for (int i = 0; i<4; i++) {
						auto LvUpEffect = SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("LvUpEffect_%d.png", i));
						animation->addSpriteFrame(LvUpEffect);
					}

					auto LvUpEffectAnimate = Animate::create(animation);
					lvUpEffect->runAction(LvUpEffectAnimate);

					//여기에 레벨업 이펙트 구현, 상승 능력치 구현 완료.
					moneyIncreaseRate = moneyIncreaseRate + 0.3;
					nowNeededMoneyForSpeed += (nowNeededMoneyForSpeed / speedLV);
					speedGage = Sprite::create("speedGage.png");
					speedGage->setAnchorPoint(Point(0.5, 0));
					int imsiPosY = 8 + 10 * speedLV;
					speedGage->setPosition(Point(winSize.width - 36, imsiPosY));
					this->addChild(speedGage, 1);
				}

				isStatusBarForSpeedTouched = false;
				if (myMoney >= nowNeededMoneyForSpeed){
					statusPushBar_speed->setVisible(false);
				}
				else{
					statusPushBar_speed->setVisible(true);
				}
			}
		}


	}



}





//setLvUpEffect
void MungGuGame::initLvUpEffect(){
	/////안씀..//////

}

//아군 생성
void MungGuGame::addMonster(int monsterNumber, Point position)
{

	Monster *monster = Monster::create(monsterNumber);
	monster->setAnchorPoint(Point(0.5, 0));
	monster->setPosition(position);
	this->addChild(monster, ((ground->getPositionY()) - (monster->getPositionY())) / 5);
	myMonsters.pushBack(monster);

}
//신태돌 생성
void MungGuGame::addCatSinTaeDollMonster(float delta){

    isInitSinTaeDoll=true;
    pauseBtn->setVisible(false);
    pauseBtn_->setVisible(true);
    //신태돌이 나오면 일시정지가 불가
    
    
    
    
    //m13 클리어 이벤트
    bool isM13Clear = UserDefault::getInstance()->getBoolForKey("m13");
    if(isM13Clear==false){
        
                    bool isSong = UserDefault::getInstance()-> getBoolForKey("isSong");
                    if(isSong == true){//song 켰나 안켯나 확인
                        int disabledSong =
                        SimpleAudioEngine::getInstance()->playEffect("disabled.wav");
                    }
        
        UserDefault::getInstance()->setBoolForKey("m13",true);//8미션 클리어
        
        auto m13Clear = Label::createWithTTF(StringUtils::format("mission 13 Clear~!!!\n-> Watch Out!!"), "NanumBarunGothicBold.otf", 20);
        m13Clear->setAnchorPoint(Point(0.5,1));
        m13Clear->setPosition(Point(winSize.width/2,winSize.height-20));
        m13Clear->setColor(Color3B::RED);
        m13Clear->setVisible(false);
        this->addChild(m13Clear,10);
        if(initByEnglish==false){
            m13Clear->setString(StringUtils::format("미션 13 클리어~!!!\n -> 조심해!!"));
        }
        auto action = Blink::create(3,10);
        m13Clear->runAction(action);
    }

    
    Rect catSiteRect = catSite->getBoundingBox();
    Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - 20 - rand() % 5);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATSINTAEDOLL);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    
    enemyMonsters.pushBack(enemyMonster);
    
        }



///준보스 고양이 생성
void MungGuGame::addCatMonster(float delta){
	Rect catSiteRect = catSite->getBoundingBox();
	Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - 8 - rand() % 16);
	EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CAT);
	enemyMonster->setAnchorPoint(Point(0.5, 0));
	enemyMonster->setPosition(position);
	this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
	enemyMonsters.pushBack(enemyMonster);
}



//작은 고양이 생성
void MungGuGame::addCatBabyMonster(float delta){
	Rect catSiteRect = catSite->getBoundingBox();
	Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - 8 - rand() % 15);
	EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATBABY);
	enemyMonster->setAnchorPoint(Point(0.5, 0));
	enemyMonster->setPosition(position);
	this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
	enemyMonsters.pushBack(enemyMonster);
}

//고양이 죠
void MungGuGame::addCatJoe(float delta){
    Rect catSiteRect = catSite->getBoundingBox();
    Point position =
    Point(catSiteRect.getMidX()-10, catSite->getPositionY() - 10 - rand() % 16);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATJOE);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    enemyMonsters.pushBack(enemyMonster);
}

void MungGuGame::addCatNamGu(float delta){
    Rect catSiteRect = catSite->getBoundingBox();
    Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - 6 - rand() % 18);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATNAMGU);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    enemyMonsters.pushBack(enemyMonster);
}

//
void MungGuGame::addCatInuMonster(float delta){
    Rect catSiteRect = catSite->getBoundingBox();
Point position = Point(catSiteRect.getMidX()-40, catSite->getPositionY() - 5 - rand() % 13);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATINU);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    enemyMonsters.pushBack(enemyMonster);
}

void MungGuGame::addBigCatMonster(float delta){
    Rect catSiteRect = catSite->getBoundingBox();
    Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - rand() % 10);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_BIGCAT);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    enemyMonsters.pushBack(enemyMonster);
}

void MungGuGame::addCatBase(float delta) {
    Rect catSiteRect = catSite->getBoundingBox();
    Point position = Point(catSiteRect.getMidX(), catSite->getPositionY() - 10 - rand() % 10);
    EnemyMonster *enemyMonster = EnemyMonster::create(MONSTER_CATBASE);
    enemyMonster->setAnchorPoint(Point(0.5, 0));
    enemyMonster->setPosition(position);
    this->addChild(enemyMonster, ((ground->getPositionY()) - (enemyMonster->getPositionY())) / 5);
    enemyMonsters.pushBack(enemyMonster);
}

void MungGuGame::gameEnded(){
	isFirstStageClear = false;
	isStageEnded = true;
}



