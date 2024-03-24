#include<stdio.h>

int main(void){
    int i, a = 0,c = 3, check = 0;
    scanf("%d", &i);

    while(i >= 0){
        if(i % 5 == 0){
            a = i / 5;
            printf("%d", a + check);
            return 0;
        }
        i = i - c;
        check++;
    }
    printf("-1");
    return 0;
};