#include <stdio.h>

int main(void){
    
    int i,num[10];

    //入力部
    printf("enter num: ");
    for(i=0; i<10; i++){
        scanf("%d", &num[i]);
    }

    //偶数
    printf("even: ");
    for(i=0; i<10; i++){
        if(num[i] % 2 == 0){
            printf("%d ", num[i]);
        }
    }
    printf("\n");

    //奇数
    printf("odd: ");
    for(i=0; i<10; i++){
        if(num[i] % 2 != 0){
            printf("%d ", num[i]);
        }
    }
    printf("\n");

    return 0;
}