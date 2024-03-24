#include<stdio.h>
#include<stdlib.h>

int main(void){
    float n, max = 0, sum = 0, result;

    scanf("%f",&n);

    if((n > 1000)){
        return 0;
    }

    int  *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
        if(arr[i]> max){
            max = arr[i];
        }
    }
    
    for(int i = 0; i < n; i++){
        result = (arr[i]/max) * 100;
        sum = sum + result;
    }
    float avg = sum / n;
    printf("%f",avg);
    return 0;
};
