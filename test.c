#include<stdio.h>

int main(void){
    int a[6] = {1,1,2,2,2,8};
    int b[6];
    for(int i = 0; i < 6; i++)
        scanf("%d",&b[i]);

    for(int i = 0; i < 6; i++){
        int result = a[i] - b[i];
        if(result >= 0){
            printf("%d ",result);
        }
        else
            printf("%d ",-(b[i]-a[i]));
    }
    
    return 0;
};