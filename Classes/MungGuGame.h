#ifndef __MungGuGame_SCENE_H__
#define __MungGuGame_SCENE_H__

#include "Common.h"
#include "EnemyMonster.h"
#include "Monster.h"

#define TAG_ATTACK_EFFECT 200
#define TAG_SPRITE_ATTACKEFFECT 28

#define TAG_SPRITE_HOMEBACKBTN  129
#define TAG_SPRITE_HOMEBACKBTN_ 130

#define TAG_SPRITE_REGAMEBTN  131
#define TAG_SPRITE_REGAMEBTN_ 132

class MungGuGame : public LayerColor
{   
	int mungRangeValue;
	int missileDamage;
    int winHeight,winWidth;
public:
    
    Size winSize;
    Point point;

    
    static MungGuGame *instance;
    static MungGuGame *getInstance();
    MungGuGame();
   
//    void setHpBar(); 
    
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    virtual bool init();
    	void initData();
    
    CREATE_FUNC(MungGuGame);
    
    
    int getNearCatPos();
    int getNearMungPos();
    
    int coolTimeFastValue;
    
    bool isAllMonsterDie();
    bool isAllMungguDie();
    
    bool isSongBtnTouched;
    
    bool isHomeBackBtnTouched;
    bool isInitMissile;
    bool isEnemyMonsterHitted;
    bool isExploreRangeAction;
    bool isMung;
    bool isMungButBtnTouched;
    bool isWhangGuBtnTouched;
    bool isMungFire;
    bool isMungBtnTouched;
    bool isMungBallBtnTouched;
    bool isMungSausageBtnTouched;
    bool isStatusBarForMaxMoneyTouched;
    bool isStatusBarForSpeedTouched;
    bool isStatusBarForPowerTouched;
    bool isMungGuFireBtnTouched;
    bool isSinBtnTouched;
    bool isStage18_trap;
    
    bool enemyMonsterAngryCheck;
    bool isEnemyMonsterAngry;
    bool isStopAction;
    bool isFinishActionAttack;
    bool isPauseBtnTouched;
    bool isPause;
    bool isResumeBtnTouched;
    bool isInfoCancelBtnTouched;
    bool isGoHomeBtnTouched;
    bool isGameOverMessage;
    bool isRegameBtnTouched;
    bool isStageEnded;
    
    bool isFirstGenFinished,isSecondGenFinished,isThirdGenFinished;
    bool initByEnglish;
    
    bool isStage13_message2;
    bool isStopFinger;
    
    bool isReadyToRemoveTheShild;
    bool isStage4_message;
    bool isStage1,isStage2,isStage3,isStage4,isStage5,isStage6,isStage7,isStage8,isStage9,isStage10,isStage11,isStage12,isStage13,isStage14,isStage15,isStage16,isStage17,isStage18,isStage19,isStage20,isStage21,isStage22,isStage23,isStage24,isStage25,
    isStage26,isStage27,isStage28,isStage29,isStage30;
    
    bool isGoldCalc;
    bool isNotSongBtnTouched;
    bool isInitSinTaeDoll;
    bool isFirstStageClear;
    bool isFirstStageLoser;
    bool isCatSiteShild;
    bool isInitRedriverMusic;
    bool isCatSiteAngryed;
    
    bool isFirstBtnCoolTimeFinished;
    bool is2ndBtnCoolTimeFinished;
    bool is3rdBtnCoolTimeFinished;
    bool is4thBtnCoolTimeFinished;
    bool is5thBtnCoolTimeFinished;
    bool is6thBtnCoolTimeFinished;
    bool is7thBtnCoolTimeFinished;
    bool is8thBtnCoolTimeFinished;
    bool is9thBtnCoolTimeFinished;
    bool is10thBtnCoolTimeFinished;
    bool isNotWhangGu,isNotMungBall,isNotMungSausage,IsNotMungButterfly;
    
     bool isTutorialFinished;

    Rect catSiteRect;
    Rect dogSiteRect;
    int dogSitePos, catSitePos;
    
    Rect isSongBtnRect;
    Rect catSiteShildRect;
    Rect tutRect;
    
    Rect homeBackBtnRect;
    Rect regameBtnRect;
    Rect goHomeBtnRect;
    Rect resumeBtnRect;
    Rect pauseBtnRect;
    Rect mungGuFireBtnRect;
    
    Rect whangGuBtnRect;
    Rect mungButBtnRect;
    Rect mungBtnRect;
    Rect mungBallBtnRect;
    Rect mungSausageBtnRect;
    
    Rect statusBarForMaxMoney_Rect;
    Rect statusBarForPower_Rect;
    Rect statusBarForSpeed_Rect;
    
    Label *myMoney_label;
    Label *dogSiteHp_label;
    Label *catSiteHp_label;
    
    Label* stage4_message;
    Label* stage13_message;
    Label* stage13_message2;
    Label* stageTalk_label;
    
    Label *statusCost_speed;
    Label *statusCost_speedMax;
    Label *statusCost_maxMoney;
    Label *statusCost_maxMoneyMax;
    Label *statusCost_power;
    Label *statusCost_powerMax;
    Label *stageName;
    Label *devsMessage;
    
    //적과 아군 데이터 관리 벡터
    Vector <Monster *> myMonsters;
    Vector <EnemyMonster *> enemyMonsters;
	
    float dogSiteScaleRate, catSiteScaleRate;
	int mungFireReadySound;
	int nearMungPos, nearCatPos;
	static int initMungPos, initCatPos;
    int audioCount;
    int increasingMoney;
    int messageCount;
    bool isDevsQuestion;
    Sprite* answerBtn1;
    Sprite* answerBtn2;
    Sprite* answerBtn3;
    Label* answerBtn1_label;
    Label* answerBtn2_label;
    Label* answerBtn3_label;
    Label* attempt_label;
    Label* attemptValue_label;
    Rect answerBtn1Rect;
    Rect answerBtn2Rect;
    Rect answerBtn3Rect;
    
    int catDogDistance;
    int btnRaiseRate;
    int count;
    int myMonsterNum, enemyMonsterNum;//현재 아군, 적 몬스터의 수
    int nowMissileGroundPos;
    int missileGroundPos;
    int mungGuDogSiteHpLv;
    
    int goldForStage;
    
    int nowNeededMoneyForMungPo,mungGuDogSitePoLv;
    int  mungLv,whangLv,mungBallLv,mungButLv,mungSausageLv;
    int catSiteRandX, catSiteRandY;
    int dogSiteRandX, dogSiteRandY;
    int shildAttackCount;
    
    int maxMoneyLV, speedLV, powerLV;
    double myMoney;
    double myImsiMoney;
    int maxMoney;
    double myMoneyCalc;
    double moneyIncreaseRate, damageValueIncreaseRate;
    
    int catNum, mungNum; //각 진영 몬스터의 수를 판단
    int catSiteMaxHp, dogSiteMaxHp, setCatSiteMaxHp, setDogSiteMaxHp;
    int catSiteNowHp;
    int dogSiteNowHp;
    int groundPosY;
	
    Sequence* timerAction;
    Sequence* timerAction2;

    ProgressTimer* mungFireTimer;
    bool mungFireCoolTimeFinished;
    void mungFireCoolTimeFinish();
    Sprite* mungFireCoolTime;
	Sprite* isSongBtn;
	Sprite* isSongBtn_;
	Sprite* isNotSongBtn;
	Sprite* isNotSongBtn_;
	Sprite* mungBallBtn;
	Sprite* mungBallBtn_;
	Sprite* mungButterFlyBtn;
	Sprite* mungButterFlyBtn_;
	Sprite* mungSausageBtn;
	Sprite* mungSausageBtn_;
	Sprite* whiteDot;
    Sprite* tutorialWindow;
    Sprite* tutExitBtn;
    Sprite* tutExitBtn_;
    
    Sprite* sinBtn;
    Sprite* sinBtn_;
    
    Sprite* mungGuMissile;
    Sprite* attackEffect;
    Sprite* attackEnemyEffect;
    Sprite* catSiteCrashEffect;
    Sprite* catSiteCrash;
    Sprite* coolTime1;
    Sprite* coolTime2;
    Sprite* coolTime3;
    Sprite* coolTime4;
    Sprite* coolTime5;
    Sprite* coolTime6;
    Sprite* coolTime7;
    Sprite* coolTime8;
    Sprite* coolTime9;
    Sprite* coolTime10;
    
    Sprite* dogSiteCrashEffect;
    Sprite* dogSiteCrash;
    Sprite* maxMoneyGage;
    Sprite* speedGage;
    Sprite* powerGage;
    Sprite* ground;
   
	void nextMusicStart();
	
	Sprite* missileEffect;
   Sprite* dogSite_fire;
	
	//void nowMissileGroundPosSetting();
	
    float mungSausageCool;//쿨타임
    float mungCool;
    float mungButCool;
    float whangCool;
    float mungBallCool;
    FiniteTimeAction* coolTimeAction;
    
    Animate* coolTimeAnimatef;
    Animate* coolTime2Animatef;
    Animate* coolTime3Animatef;
    Animate* coolTime4Animatef;
    Animate* coolTime5Animatef;
    Animate* coolTime6Animatef;
    Animate* coolTime7Animatef;
    Animate* coolTime8Animatef;
    Animate* coolTime9Animatef;
    Animate* coolTime10Animatef;
    Animate* coolTimeAnimate;
    Animate* coolTime2Animate;
    Animate* coolTime3Animate;
    Animate* coolTime4Animate;
    Animate* coolTime5Animate;
    Animate* coolTime6Animate;
    Animate* coolTime7Animate;
    Animate* coolTime8Animate;
    Animate* coolTime9Animate;
    Animate* coolTime10Animate;
    
    void firstBtnCoolTimeFinished();
    void btn2ndCoolTimeFinished();
    void btn3rdCoolTimeFinished();
    void btn4thCoolTimeFinished();
     void btn5thCoolTimeFinished();
     void btn6thCoolTimeFinished();
     void btn7thCoolTimeFinished();
     void btn8thCoolTimeFinished();
     void btn9thCoolTimeFinished();
     void btn10thCoolTimeFinished();

    void missionClearEvent();
    
    int mungSausageCost;
    int mungButCost;
    int mungBallCost;
    int whangCost;
    int mungCost;
    int mungPoCost;
    float sizeRate;
    int nowNeededMoneyForSpeed, nowNeededMoneyForMaxMoney, nowNeededMoneyForPower;
    int nextNeededMoney_speed, nextNeededMoney_maxMoney, nextNeededMoney_power;
    int minFireRange;
    int maxFireRange;
    int exploreRange;
    int maxMoneyValue;
    int attemptValue;
    
    
    
    bool isStop;

    ////함수////
	
	void setStageName();
	void setFireBtn();
	void changeCatSiteHp();
	void changeDogSiteHp();
	void setMyMoney();
	void setCatSiteHp();
	void setDogSiteHp();
	void resetGameScene();
    
    
    void setStatusBar();
    void changeStatusCost();
    void update(float delta);
    void setMungBtn();
    void setExploreMileStone();
    
	
	void changeMyMoney();
	void changeStatusBar();
	
	void setCatSite();
	void setDogSite();
	void setBG();
	
    Sprite* exploreMileStone;
    Sprite* exploreMileStone2;
	Sprite* whangGuBtn;
	Sprite* whangGuBtn_;
	Sprite* mungBtn;
	Sprite* mungBtn_;
	Sprite* nullBtn_;
	Sprite* statusBar;
	
	Sprite* statusRate;
	Sprite* statusPushBar_speed;
	Sprite* statusPushBar_maxMoney;
	Sprite* statusPushBar_power;
	Sprite* mungCoFireBtn;
	Sprite* mungCoFireBtn_;
	Sprite* pauseBtn;
	Sprite* pauseBtn_;
	Sprite* pauseWindow;
	Sprite* resumeBtn;
	Sprite* resumeBtn_;
	Sprite* goHomeBtn;
	Sprite* goHomeBtn_;
    Sprite* dogSite;
    Sprite* catSite;
    ///stage 4///
    Sprite* catSiteShield;
    ///
    Sprite* lvUpEffect;
	
	Sprite* youWin;
	Sprite* youLoser;
	Sprite* homeBackBtn;
	Sprite* homeBackBtn_;
	Sprite* regameBtn;
	Sprite* regameBtn_;
   
	Label* gold_Label;
    Label* statusCost_mungPo;
    
    
    //stage5 데미지 합을 담는 변수
    int damageValueSum;
    Sprite* catSite_Angryed_13;
    
    Sprite* gameOverBtn;
    Sprite* gameOverBtn_;
	
 
    void enemyInfrontConfirm();
    void mungguInfrontConfirm();
    
    void setPauseWindow();
    
    void resetEnemyMonster(Ref *sender);
    void resetMyMonster(Ref *sender);
    //아군 진영 공격 받을 때
    void dogSiteDestroyed();
    void dogSiteDestroyedEffect(float delta);
    void dogSiteHitted(EnemyMonster* monster);
    
    //적 진영 공격 받을 때
    Monster *getInfrontMunggu();
    EnemyMonster *getInfrontEnemy();
    void catSiteDestroyed();
    void catSiteDestroyedEffect(float delta);
    void catSiteHitted(Monster* monster);
    void setPauseBtn();
    void resetStop();
    void setStageSelect();
    
    void resetMissileAttack();
    void setMissileAttackEffect();
    void initMissileAttackEffect();
    void setGround();
    void initLvUpEffect();
    void initAttackEffect(Monster* monster, EnemyMonster* enemyMonster);
    void initEnemyAttackEffect(Monster* monster, EnemyMonster* enemyMonster);
    void UpperToneDecreaseCatHp(Monster *sprMung, EnemyMonster *sprCat);
    void UpperToneDecreaseMungguHp(Monster *sprMung, EnemyMonster *sprCat);
    
    void mungFireFinished();
    void initMissileEffect();
    void initDogSite_fire();
    void initDogSite_fireReady();
    void initDogSite_fireCancel();
    void initFireEffect();
    void dogSiteAttackEffect();
    void catSiteAttackEffect();
    void setCoolTime();
    void setSongPlayedBtn();
    void setSong();
    
    void setMungFireMissile();
    void initMungFireMissile();
    void initExploreMileStoneAction();
    
    void gameEnded();
   
    void setGameClearEvent();
    void initGameClearEvent();
    void gameTurnOff();
    void gameOverMessage();
    void setGameLoserEvent();
    void initGameLoserEvent();
    void initSinTaeDoll();
    void initStageTalk();
    void decreasedCatSiteHp(int damageValue);
    void decreasedDogSiteHp(int damageValue);
    void initDevsQuestion();
    
    void myMungHitted(EnemyMonster* enemyMonster);
    void enemyHitted(Monster* monster);
    
    
    void addMonster(int monster, Point position);
    void addCatJoe(float delta);
    void addCatNamGu(float delta);
    void addCatBase(float delta);
    void addEnemyMonster(int monsterNumber, Point Position);
    void addCatSinTaeDollMonster(float delta);
    void addCatMonster(float delta);
    void addCatBabyMonster(float delta);
    void addCatInuMonster(float delta);
    void addBigCatMonster(float delta);
    void enemyVector();
    void initPauseWindow();
    void removePauseWindow();
    
    void sizeCheck();

    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
    void neededToMoveEnabled(){isNeededToMove=true;}
    void neededToMoveDisabled(){isNeededToMove=false;}
private:
    bool isNeededToMove;
};


#endif 
