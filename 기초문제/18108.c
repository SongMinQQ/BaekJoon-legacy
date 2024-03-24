#include<stdio.h>

void main(){
    int a;

    scanf("%d",&a);
    if((1000 <= a) && (a <= 3000)){
        printf("%d",a-543);
    }

    exit(0);
};