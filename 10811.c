#include<stdio.h>
#include<stdlib.h>

int main(void){
    int n, m, box;
    scanf("%d %d",&n,&m);
    if((n > 100) ||(m > 100)){
        return 0;
    }
    int  *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }

    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d %d",&a,&b);
        int k = 1,j;
        if(a != b){
            j= ((b - a) / 2) + 1;
            for(int i = a ; i < b ; i++){
                box = arr[i-1];
                arr[i-1] = arr[b - k];
                arr[b - k] = box;
                k++;
                if(k>j){
                    break;
                }
            }
        }
        
    }

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
};
