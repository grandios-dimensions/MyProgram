#include <stdio.h>
#define num 10

int main(void)
{
    int i, high[num];

    printf("登ります!\n");
    for(i=0; i<num; i++){
        printf("%d合目の標高は?:", i);
        scanf("%d", &high[i]);
        printf("\n");
    }

    printf("下ります!\n");
    for(i; i>=0; i--){
        printf("%d合目 : %d\n", i, high[i]);
    }
    
    if(i==0){
        printf("無事下山しました!\n");
    }

    return 0;
}