#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct listNode
{
    /* data */
    element data;
    struct listNode *link;
}listNode;

listNode* insert(listNode *head, element value){
    listNode *p= (listNode *)malloc(sizeof(listNode));
    p->data = value;
    p ->link = head;
    head = p;
    return head;
}



void print_list(listNode *head, int b){
    if(head == NULL){
        return ;
    }
    listNode *removed;
    head -> data == b;
    removed = head;
    head = removed -> link;
    printf("%d ", removed -> data);
    free(removed);
    // for(listNode *p=head;p!=NULL;p=p->link){
    //     printf("%d ", p->data);
    // }
}

int main(void){
    listNode *head = NULL;

    int a, b;

    scanf("%d %d", &a, &b);

    for(int i = a; i > 0; i--){
        head = insert(head, i);
    }
    for(int i = 0; i < a; i++){
        print_list(head, b);
    }
    return 0;
};