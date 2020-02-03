#define FoodListSize 27
#define morningStart 0
#define morningFin 12
#define DayStart 13
#define DayFin 25
#define eveningStart 26
#define eveningFin 37


//eatingに使う構造体:食べ物のリスト
typedef struct foodList
{
	char name[50]; //食べ物、飲み物の名前
	char type[10]; //食べ物:food、飲み物:drink
	char MDE;	   //M:morning、D:day、E:evening
}foodList;

//利用者に提案するメニューを入れる構造体
typedef struct menu
{
	char staple_food[50]; //主食:パン or ご飯(lunchはこの項目はなし)
	char main_dish[50]; //主菜:ハンバーグなど,lunchはまとめてここに[寿司]とかが入る
	char drink[50]; //飲み物,朝は味噌汁も入る

}menu;

//プロトタイプ宣言
void eating();
int GetRandom(int min,int max);
void setFoodList(foodList *foods, char *name, char *type, char MDE);
void makeFoodList();
void makeMenu(foodList *timesFoodList, int size, char MDE, menu *foodMenu);