#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    /* data */
    char subj[55], grade[20];
    float score;
}student;

int main(void){
    struct student s[20];
    
    float scSum = 0, sum = 0;
    float score2;
    for(int i = 0; i < 20; i++){
        scanf("%s %f %s",&s[i].subj,&s[i].score,&s[i].grade);
        if(strlen(s[i].subj) > 50){
            return 0;
        }
        if(strcmp(s[i].grade, "A+") == 0)
            score2 = 4.5;
        if(strcmp(s[i].grade, "A0") == 0)
            score2 = 4.0;
        if(strcmp(s[i].grade, "B+") == 0)
            score2 = 3.5;
        if(strcmp(s[i].grade, "B0") == 0)
            score2 = 3.0;
        if(strcmp(s[i].grade, "C+") == 0)
            score2 = 2.5;
        if(strcmp(s[i].grade, "C0") == 0)
            score2 = 2.0;
        if(strcmp(s[i].grade, "D+") == 0)
            score2 = 1.5;
        if(strcmp(s[i].grade, "D0") == 0)
            score2 = 1.0;
        if(strcmp(s[i].grade, "F") == 0)
            score2 = 0.0;
        if(strcmp(s[i].grade, "P") == 0){
            score2 = 0.0;
            s[i].score = 0.0;
        }
        sum = sum + (s[i].score * score2);
        scSum = scSum + s[i].score;
    }
    
    float result;
    result = sum / scSum;
    printf("%f",result);
    return 0;
};