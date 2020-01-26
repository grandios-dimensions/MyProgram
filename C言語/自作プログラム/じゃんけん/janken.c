#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int changeCpNum(int mHnum);
void checkHand(int hand);
void checkWinOrLose(int hHnum, int mHnum);

int main(void){

  int hHnum,mHnum, randNum;
  
  //人が出す手を入力
  //グー 0,　チョキ 1, パー 2
  printf("最初はグー、じゃんけんぽい!\n");
  printf("グー 0,　チョキ 2, パー 5 : ");
  scanf("%d", &hHnum);

  if(hHnum != 0 && hHnum != 2 && hHnum != 5){
    printf("不正な入力です\n");
    exit(0);
  }
  
  srand((unsigned int)time(NULL));
  
  //コンピュータが出す手を計算
  randNum = rand() % 10;
  
  //乱数を元に、グー：0,チョキ:2,パー:5に変更
  //0~3を0、4~7を2、8と9を5にする
  mHnum = changeCpNum(randNum);

  //じゃんけんの勝敗を決める
  checkWinOrLose(hHnum, mHnum);
  
  return 0;
}

int changeCpNum(int randNum){

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

  printf("終わり。\n");
  exit(1);
}

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
