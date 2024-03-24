#include<stdio.h>

void main(){
    int a, b[3];

    scanf("%d",&a);
    for(int i = 0; i<3; i++){
        scanf("%1d",&b[i]);
    };

    int q, w, e;

    q = a * b[2];
    w = a * b[1];
    e = a * b[0];

    printf("%d\n",a * b[2]);
    printf("%d\n",a * b[1]);
    printf("%d\n",a * b[0]);
    printf("%d\n",q + (w * 10) + (e * 100));
    exit(0);
};