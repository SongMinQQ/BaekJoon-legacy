#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int a = 3, b = 4;
    printf("%p", &a);
    swap(&a, &b);

    printf("%d %d\n", a, b);
    return 0;
}
