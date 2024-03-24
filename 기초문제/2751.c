#include<stdio.h>
#include<stdlib.h>

//백준 2751 수 정렬하기 2
int sortArr[1000000];

void mergeSort(int arr[], int first, int mid, int last){
    int mid2 = mid + 1;
    int i;
    int first2 = first;
    int first3 = first;
    
    while ((first2 <= mid) && (mid2 <= last))
    {
        if(arr[first2] <= arr[mid2]){
            sortArr[first3++] = arr[first2++];
        }
        else{
            sortArr[first3++] = arr[mid2++];
        }
    }

    if(first2 > mid){
        for(i= mid2; i<=last; i++)
            sortArr[first3++] = arr[i];
        }

    else{
        for(i=first2; i<=mid; i++)
            sortArr[first3++] = arr[i];
        }

    for(i=first; i<=last; i++){
        arr[i] = sortArr[i];
    }
}

void merge(int arr[], int first, int last){
    int mid;
    if(first < last){
        mid = (first + last) / 2;
        merge(arr, first, mid);
        merge(arr, mid + 1, last);
        mergeSort(arr, first,mid,last);
    }
};

int main(void){
    int n, a, box;

    scanf("%d",&n);

    if((n > 1000000)){
        return 0;
    }

    int *arr = (int*)malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d",&a);
        arr[i] = a;
    }

    merge(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d\n",arr[i]);
    }

    return 0;
};
