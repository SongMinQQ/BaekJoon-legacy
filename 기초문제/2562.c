#include<stdio.h>
//백준 2562 1차원 배열 최댓값 출력
int main(void){
    int a, b[9], max, maxnum;
        for(int i = 0; i < 9; i++){
            scanf("%d", &a);
            if(a > 100)
                return 0;
            b[i] = a;
        }
        max = b[0];
        maxnum = 0;
        for(int i = 1; i <sizeof(b)/sizeof(int) ; i++){
            if(b[maxnum]<b[i]){
                max = b[i];
                maxnum = i;
            }
        }
    printf("%d\n", max);
    printf("%d", maxnum+1);

    return 0;
};
