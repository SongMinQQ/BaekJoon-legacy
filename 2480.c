#include<stdio.h>
//백준 2480 주사위 세개

void main(){
    int a, b, c, result;

    scanf("%d %d %d",&a, &b, &c);
    if((a == b) && (b == c))
        result = 10000 + (a * 1000) ;
    else if((a == b) ^ (a == c) ^ (b == c))
        result = 1000 + ((a == b ? a : c) * 100);
    else
        result = ((a > b ? a : b) < c ? c : (a > b ? a : b) ) * 100;
    printf("%d", result);
    exit(0);
};
