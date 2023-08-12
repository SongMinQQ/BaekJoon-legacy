#include<stdio.h>
//백준 14681 사분면 판별
void main(){
    int x, y;

    scanf("%d %d",&x, &y);

    if((x * y != 0) && (x >= -1000) && (y >= -1000) && (x <= 1000) && (y <= 1000)){
        if((x > 0) && (y > 0))
            printf("1");
        else if((x < 0) && (y > 0))
            printf("2");
        else if((x < 0) && (y < 0))
            printf("3");
        else if((x > 0) && (y < 0))
            printf("4");
    }
    exit(0);
};