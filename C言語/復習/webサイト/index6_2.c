#include <stdio.h>
int main(void){
    
    int i, num[10];

    //入力部
    printf("enter num: ");
    for(i=0; i<10; i++){
        scanf("%d", &num[i]);
    }

    //表示
    for(i=9; i>=0; i--){
        printf("%d ", num[i]);
    }

    return 0;
}