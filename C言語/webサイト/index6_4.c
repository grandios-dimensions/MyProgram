#include <stdio.h>

int main(void){
    
    int i,bi,num[10],sum=0;

    //入力部
    printf("enter num: ");
    for(i=0; i<10; i++){
        scanf("%d", &num[i]);
        sum += num[i];

        if(sum == 100){
            i++;
            bi = i;
            break;
        }else if(sum > 100){
            bi = i;
            break;
        }else if(i==9){
            bi = 10;
        }
    }

    //表示
    for(i=0; i<bi; i++){
        printf("%d ",num[i]);
    }
    printf("\n");

    return 0;
}