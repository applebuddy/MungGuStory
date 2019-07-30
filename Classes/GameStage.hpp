//
//  GameStage.hpp
//  mungGuStory
//
//  Created by Min Kyeong Tae on 2018. 8. 2..
//

#ifndef GameStage_hpp
#define GameStage_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class GameStage{
  
public:
    GameStage();
    void setFirstStageData();
    void initStage();
    
    int stageMaxNum = 50;//최대 스테이지 값을 저장
    int stageClearCount[50];//스테이지 클리어횟수를 저장하는 배열 0->1스테이지 클리어횟수 정보를 담는다.
    string clearCountStr = "";
    
    
    
};
#endif /* GameStage_hpp */
