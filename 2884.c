#include<stdio.h>
//백준 2884 알람 시계
void main(){
    int h, m;

    scanf("%d %d",&h, &m);

    if((h >= 0) && (h <= 23) && (m >= 0) && (m <= 59)){
        if((m - 45) > 0){
            printf("%d %d",h, m - 45);
        }
        if((m - 45) == 0){
            printf("%d %d",h, m - 45);
        }
        if((m - 45) < 0){
            h = h - 1;
            m = m - 45 + 60;
            if(h >= 0)
                printf("%d %d",h, m);
            else if(h < 0){
                printf("%d %d",h + 24, m);
            }
        }
    }
    exit(0);
};