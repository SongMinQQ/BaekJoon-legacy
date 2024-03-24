#include<stdio.h>
#include<ctype.h>

void main(){
char a[50];
scanf("%s", &a);
for (int i = 0; i < (int)strlen(a); ++i)
    {
        if (islower(a[i]) != 0)
        {
            printf("%c", a[i]);
        }
    }
printf("??!");
//printf("%s??!", a);
exit(0);
};