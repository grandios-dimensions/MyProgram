#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "playing.h"
#include "eating.h"

#define loopNum 10

void sleeping();
//*****:機能ごとの境界, -----:関数ごとの境界, .....関数内での境界+インデックスを増やしていく
//上の例、a(ここが増える)  ,a_a(ここが増える), a_a_a(ここが増える)

//*****寝る機能について(起きる時間を計算してくれる)a*****

void sleeping(){

	//時間を扱うために[timer]を作成
	//地方時間に変換するために[tm]のポインタ[local]を作成
	time_t timer;
	struct tm *local;

	//.....現在時刻をここからa_a.....

	//現在時刻を取得
	timer = time(NULL);

	//地方時間に変換
	local = localtime(&timer);

	//現在時刻を表示
	printf("現在時刻は [%2d:%2d] です\n", local->tm_hour,local->tm_min);

	//.....a_a.....

	//h:何時間寝たいか(hour) ,m:何分寝たいか(min) ,check:寝る時間のパターン分岐用
	int h=0, m=0, check;

	//寝る時間を尋ねる
	printf("どのぐらい寝ますか? 1:n時間,2:m分,3:n時間m分\n");
	scanf("%1d", &check);

	switch(check){
		case 1:
		printf("何時間?");
		scanf("%2d", &h);
		break;

		case 2:
		printf("何分間?");
		scanf("%2d", &m);
		break;

		case 3:
		printf("何時間?");
		scanf("%2d", &h);
		printf("何分間?");
		scanf("%2d", &m);
		break;

		default:
		printf("値が不正のため,計算できません\n");
		return;
	}

	//起きる時間を表示する
	if(local->tm_min+m > 60){
		m -= 60;
		h++;
	}

	if((local->tm_hour)+h > 24){
		h -= 24;
	}

	//起床時間を提案する
	printf("起きる時間はは [%2d:%2d] です\n", (local->tm_hour)+h,local->tm_min+m);
	printf("Let's sleep!!\n");
}

//*****a*****


//*****食べる機能について(適切なご飯を提案してくれる)b*****

//-----foodListに値を設定するb_a-----
void setFoodList(foodList *foods, char *name, char *type, char MDE){
	strcpy(foods->name, name);
	strcpy(foods->type, type);
	foods->MDE = MDE;
}
//-----b_a-----

//-----foodListの構造体を新たに作成する(1つ分)b_b-----
void makeFoodList(foodList *foods){

	char name[50] = "";
	char type[10] = "";
	char MDE;

	printf("Please enter new food\n");
	printf("name:");
	scanf("%49s", name);
	printf("type:");
	scanf("%9s", type);
	printf("MDE:");
	scanf("%*c%1c",&MDE);

	setFoodList(foods, name, type, MDE);
}
//-----b_b-----

//-----提案する料理を構造体menuに入れる関数b_c-----
void makeMenu(foodList *timesFoodList, int size, char MDE, menu *foodMenu){

	//i:カウンタ, Q1,Q2:質問の答え, sFood:0(無し) 1(あり)
	int i = 0;
	int sFood = 0, Q1 = 0, Q2 = 0;

	//朝ごはんの場合
	if(MDE == 'M'){
		//2つの質問 Q1:パンorご飯, Q2:ガッツリor少なめ
		//Q1 パン:1, ご飯:2
		printf("パンかご飯どっちがいいですか? パン:1, ご飯:2\n");
		scanf("%d", &Q1);
		//Q2 ガッツリ:1, 少なめ:2
		printf("ガッツリか少なめどっちがいいですか? ガッツリ:1, 少なめ:2\n");
		scanf("%d", &Q2);

		//test
		//食べ物,飲み物の選定
		//パン
		if(Q1 == 1){

			if(Q2 == 1){

			}else if(Q2 == 2){
			}


		//ご飯
		}else if(Q1 == 2){

			if(Q2 == 1){

			}else if(Q2 == 2){
			}

		}


	}

	//昼ごはんの場合
	if(MDE == 'D'){
		//2つの質問 Q1:高いor安い, Q2:ガッツリorあっさり
		//Q1 高い:1, 安い:2
		printf("高いか安いどっちがいいですか? 高い:1, 安い:2\n");
		scanf("%d", &Q1);
		//Q2 ガッツリ:1, あっさり:2
		printf("ガッツリかあっさりどっちがいいですか? ガッツリ:1, あっさり:2\n");
		scanf("%d", &Q2);


		//食べ物,飲み物の選定

		//高い
		if(Q1 == 1){

			if(Q2 == 1){

			}else if(Q2 == 2){

			}

		//安い
		}else if(Q1 == 2){

			if(Q2 == 1){

			}else if(Q2 == 2){

			}

		}

	}


	//夜ごはんの場合
	if(MDE == 'E'){
		//2つの質問 Q1:肉or魚, Q2:ガッツリorあっさり
		//Q1 肉:1, 魚:2
		printf("肉か魚どっちがいいですか? 肉:1, 魚:2\n");
		scanf("%d", &Q1);
		//Q2 ガッツリ:1, あっさり:2
		printf("ガッツリかあっさりどっちがいいですか? ガッツリ:1, あっさり:2\n");
		scanf("%d", &Q2);


		//食べ物,飲み物の選定

		//肉
		if(Q1 == 1){

			if(Q2 == 1){

			}else if(Q2 == 2){

			}

		//魚
		}else if(Q1 == 2){

			if(Q2 == 1){

			}else if(Q2 == 2){

			}

		}


	}


	//値の代入****************
	strcpy(foodMenu->staple_food, timesFoodList[i].name);
	strcpy(foodMenu->main_dish, timesFoodList[i].name);
	strcpy(foodMenu->drink, timesFoodList[i].name);


	//.....ご飯の提案.....
	printf("ご提案のご飯は ↓ になります\n");
	if(sFood == 0){
		printf("main_dish = [%s], drink = [%s]\n", foodMenu->main_dish, foodMenu->drink);
	}else if(sFood == 1){
		printf("staple_food = [%s], main_dish = [%s], drink = [%s]\n", foodMenu->staple_food, foodMenu->main_dish, foodMenu->drink);
	}

}
//-----b_c-----

//-----料理の提案をする関数b_d-----
void eating(){

	//カウンタ
	int i = 0, j = 0;

	//eatingで使うfoodListをsetFoodListを用いて作成しておく
	//setFoodListに初めから入れるものを全部書いておく

	//.....初期データ作成 b_d_a.....
	foodList foods[50];

	//朝飯
	setFoodList(&foods[0], "sandwich", "food", 'M');
	setFoodList(&foods[1], "piza_toast", "food", 'M');
	setFoodList(&foods[2], "toast", "food", 'M');
	setFoodList(&foods[3], "Anko_margarine_toast", "food", 'M');
	setFoodList(&foods[4], "rice", "food", 'M');
	setFoodList(&foods[5], "rice_ball", "food", 'M');
	setFoodList(&foods[6], "ochazuke", "food", 'M');
	setFoodList(&foods[7], "salmon", "food", 'M');
	setFoodList(&foods[8], "Fried_egg", "food", 'M');
	setFoodList(&foods[9], "miso_soup", "drink", 'M');
	setFoodList(&foods[10], "juice", "drink", 'M');
	setFoodList(&foods[11], "green_tea", "drink", 'M');
	setFoodList(&foods[12], "barley_tea", "drink", 'M');

	//昼飯
	setFoodList(&foods[13], "hamburger", "food", 'D');
	setFoodList(&foods[14], "ramen", "food", 'D');
	setFoodList(&foods[15], "steak", "food", 'D');
	setFoodList(&foods[16], "sushi", "food", 'D');
	setFoodList(&foods[17], "pasta", "food", 'D');
	setFoodList(&foods[18], "curry", "food", 'D');
	setFoodList(&foods[19], "side_dish", "food", 'D');
	setFoodList(&foods[20], "lunch_box", "food", 'D');
	setFoodList(&foods[21], "bread", "food", 'D');
	setFoodList(&foods[22], "udon", "food", 'D');
	setFoodList(&foods[23], "coffee", "drink", 'D');
	setFoodList(&foods[24], "green_tea", "drink", 'D');
	setFoodList(&foods[25], "barley_tea", "drink", 'D');

	//晩飯
	setFoodList(&foods[26], "hamburger_steak", "food", 'E');
	setFoodList(&foods[27], "fried_chicken", "food", 'E');
	setFoodList(&foods[28], "grilled_meat", "food", 'E');
	setFoodList(&foods[29], "shabu_shabu", "food", 'E');
	setFoodList(&foods[30], "Pork roses and Chinese cabbage", "food", 'E');
	setFoodList(&foods[31], "gyoza", "food", 'E');
	setFoodList(&foods[32], "grilled_fish", "food", 'E');
	setFoodList(&foods[33], "shushi", "food", 'E');
	setFoodList(&foods[34], "sashimi", "food", 'E');
	setFoodList(&foods[35], "boiled", "food", 'E');
	setFoodList(&foods[36], "green_tea", "drink", 'E');
	setFoodList(&foods[37], "barley_tea", "drink", 'E');

	//.....b_d_a.....

	//.....追加で食品を足したい場合 b_d_b.....
	/*
	int add = 0, addNum = 0;
	printf("do you want to add menu? 1:yes, 2:no");
	scanf("%1d", &add);
	//新しくメニューをNewfoods構造体を用意して作成。後々可変長+for分で指定回数足せるようにする
	if(add == 1){

		foodList Newfoods;
		printf("how many menu do you want add? 1~12まで可能\n");
		scanf("%d", &addNum);

		for(i = 0; i < addNum; i++){
			makeFoodList(&Newfoods);
			foods[eveningFin+i+1] = Newfoods;
		}

	}
	printf("food = [%s], type = [%s], MDE = [%c],",foods[eveningFin+i+1].name, foods[eveningFin+i+1].type, foods[eveningFin+i+1].MDE);
	*/
	//.....b_d_b.....

	printf("Let's eat!!\n");

	//.....朝、昼、夜の判定をする為に現在時刻を取得するb_d_c.....

	//朝:0~8:food ,9~12:drink
	//昼:13~22:food, 23~24:drink
	//晩:25~26:food

	//時間ごとのフードリストを作成する (例:朝なら朝食専用リストが作成される)
	foodList timesFoodList[40];
	//提案するメニューを入れる構造体
	menu foodMenu;

	//時間を扱うために[timer]を作成
	//地方時間に変換するために[tm]のポインタ[local]を作成
	time_t timer;
	struct tm *local;
	//現在時刻を取得
	timer = time(NULL);
	//地方時間に変換
	local = localtime(&timer);

	//.....b_d_c.....

	//.....時間を元に朝昼夜の判定を行い、メニューを提案するb_d_d.....
	if(local->tm_hour <= 10){
		//~10時まで
		printf("今は%d時ですので朝ごはんです\n",local->tm_hour);

		//朝:0~8:food ,9~12:drink
		j=morningStart;

		for(i = 0; i <= morningFin-morningStart; i++){

			timesFoodList[i] = foods[j];
			printf("[%d] food = [%s], type = [%s], MDE = [%c]\n",i, timesFoodList[i].name, timesFoodList[i].type, timesFoodList[i].MDE);
			j++;
		}

		makeMenu(&timesFoodList[0], morningFin-morningStart, timesFoodList[0].MDE, &foodMenu);

	}
	else if(local->tm_hour >= 12 && local->tm_hour <= 14){
		//11~14時
		printf("今は%d時ですので昼ごはんです\n",local->tm_hour);

		//昼:13~22:food, 23~24:drink
		j=DayStart;

		for(i = 0; i <= DayFin-DayStart; i++){

			timesFoodList[i] = foods[j];
			printf("[%d] food = [%s], type = [%s], MDE = [%c]\n",i, timesFoodList[i].name, timesFoodList[i].type, timesFoodList[i].MDE);
			j++;
		}

		makeMenu(&timesFoodList[0], DayFin-DayStart, timesFoodList[0].MDE, &foodMenu);

	}
	else if(local->tm_hour >= 17 && local->tm_hour <= 22){
		//17~22時
		printf("今は%d時ですので晩ごはんです\n",local->tm_hour);

		//晩:25~26:food
		j=eveningStart;

		for(i = 0; i <= eveningFin-eveningStart; i++){

			timesFoodList[i] = foods[j];
			printf("[%d] food = [%s], type = [%s], MDE = [%c]\n",i, timesFoodList[i].name, timesFoodList[i].type, timesFoodList[i].MDE);
			j++;
		}

		makeMenu(&timesFoodList[0], eveningFin-eveningStart, timesFoodList[0].MDE, &foodMenu);

	}
	else{
		//その他の時間の場合
		printf("今は%d時ですのでおやつにしてください (@_@)\n",local->tm_hour);
	}
	//.....b_d_d.....
}
//-----b_d-----

//*****b*****


//*****遊ぶ機能について(じゃんけんが出来る)c*****


//-----じゃんけんを実際にする関数c_d-----
void playing(){
  int hHnum,mHnum, randNum;

  //人が出す手を入力
  //グー 0,　チョキ 1, パー 2
  printf("最初はグー、じゃんけんぽい!\n");
  printf("グー 0,　チョキ 2, パー 5 : ");
  scanf("%1d", &hHnum);

  if(hHnum != 0 && hHnum != 2 && hHnum != 5){
    printf("不正な入力です\n");
    exit(0);
  }

  srand((unsigned int)time(NULL));

  //コンピュータが出す手を計算
  randNum = rand() % 10;

  //乱数を元に、グー：0,チョキ:2,パー:5に変更
  //0~3を0、4~7を2、8と9を5にする
  mHnum = decideCpNum(randNum);

  //じゃんけんの勝敗を決める
  checkWinOrLose(hHnum, mHnum);

}
//-----c_d-----

//*****c*****


//*****ここから 「main」 関数 d*****

int main(void){

	//i:カウンタ, select:利用する機能の選択
	//1.sleeping、2.eating、3.playing、4.bye

	int i, select;

	//後にwhileに変える
	for(i=0; i<loopNum; i++){
		printf("select number : 1.sleep、2.eat、3.play、4.bye\n");
		printf("please enter num :");
		scanf("%1d", &select);

		switch(select){
			case 1:
			sleeping();
			printf("\n");
			break;

			case 2:
			eating();
			printf("\n");
			break;

			case 3:
			playing();
			printf("\n");
			break;

			case 4:
			printf("Thank you for using this application (*^_^*) \n");
			printf("\n");
			exit(1);
			break;

			default:
			printf("your number in wrong!\n");
			printf("\n");
			break;

		}
	}

	return 0;
}

//*****d*****