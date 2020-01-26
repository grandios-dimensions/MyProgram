#include <stdio.h>

int main(void){

    int num[10], i;

    //入力部
    printf("enter num: ");
    for(i=0; i<10; i++){
        scanf("%d", &num[i]);
    }

    //入力値に2をかけて出力
    for(i=0; i<10; i++){
        printf("%d ", 2*(num[i]));
    }

    //最後に改行
    printf("\n");
    return 0;
}