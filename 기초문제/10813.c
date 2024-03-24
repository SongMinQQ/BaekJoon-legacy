#include<stdio.h>
#include<stdlib.h>
//백준 10813 공 바꾸기
int main(void){
    int n, m, q, w, box;

    scanf("%d %d",&n, &m);

    if((n >= 100)&&(m >= 100)){
        return 0;
    }

    int *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }

    for(int i = 0; i < m ; i++){
        scanf("%d %d",&q,&w);
        if((q > w) && (w > m)){
            return 0;
        }
        box = arr[q-1];
        arr[q-1] = arr[w-1];
        arr[w-1] = box;
    }

    for(int i = 0; i < n ; i++){
        printf("%d ",arr[i]);
    }
    return 0;
};
