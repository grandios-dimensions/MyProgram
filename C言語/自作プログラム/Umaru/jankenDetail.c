#include <stdio.h>
#include "playing.h"
//じゃんけんの詳細な機能
//-----機械の手を決める関数関数c_a-----
int decideCpNum(int randNum){
  //randNum:乱数が0~9で渡され,それを元に手を決める
  //mHnum : machine hand number
  int mHnum;

  if(randNum < 4){
    mHnum = 0;
  }else if(randNum < 8){
    mHnum = 2;
  }else{
    mHnum = 5;
  }

  return mHnum;

}
//-----c_a-----

//-----出した手を表示する関数c_b-----
void checkHand(int hand){

  if(hand == 0){
    printf("グー\n");
  }else if(hand == 2){
    printf("チョキ\n");
  }else if(hand == 5){
    printf("パー\n");
  }else{
    printf("入力がおかしいですよ\n");
  }
}
//-----c_b-----

//-----じゃんけんの勝敗を決める関数c_c-----
void checkWinOrLose(int hHnum, int mHnum){

  int judge;

  //hHmun-mHnumで,人視点で計算する
  //勝ち:1, 負け:2, あいこ:0
  judge = hHnum-mHnum;

  //人:0 → 機械 0 (0) 2 (-2) 5 (-5)
  //人:2 → 機械 0 (2) 2 (0) 5 (-3)
  //人:5 → 機械 0 (5) 2 (2) 5 (0)

  //手の確認
  printf("あなたの手は,");
  checkHand(hHnum);
  printf("機械の手は,");
  checkHand(mHnum);

  //あいこ
  if(judge == 0){
    printf("あいこ！\n");
  }
  //勝ち
  else if(judge == -2 ||judge == -3 ||judge == 5){
    printf("勝ち！\n");
  }
  //負け
  else{
    printf("負け！\n");
  }

  //return;

}
//-----c_c-----
