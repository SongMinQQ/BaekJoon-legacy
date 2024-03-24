#include<stdio.h>
#include<stdlib.h>

int main(void){
    int a, b, num, j;

    scanf("%d %d", &a, &b);

    int *c = (int *)malloc(sizeof(int) *a);

    for(int i = 0; i < a; i++){
        c[i] = i+1;
    }
    printf("<");
    int count = 0;
    int count2 = 0;
    num = b;
    j = 1;
    while(1){
        if(c[j-1] > 0){
            count++;
        }

        if(c[j-1] > 0 && count == b){
            count = 0;
            
            c[j-1] = 0;
            count2++;
            if(count2 == a){
                printf("%d", j);
                break;
            }
            printf("%d, ", j);
        }
        j++;
        if(j > a)
            j = j - a;
    }

    printf(">");
    return 0;
};