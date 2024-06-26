#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;

    struct Node * next;
};
struct Node* top = NULL;

void Traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);

        ptr = ptr->next;
    }
    printf("NULL");
}
int isEmpty(struct Node* top){

    if (top==NULL){

        return 1;
    }
    else{

        return 0;
    }
}
int isFull(struct Node* top){

    struct Node* p = (struct Node*)malloc(sizeof(struct Node));

    if(p==NULL){

        return 1;
    }
    else{

        return 0;
    }
}

struct Node* push(struct Node* top, int x){

    if(isFull(top)){

        printf("Stack Overflow\n");
    }
    else{

        struct Node* n = (struct Node*) malloc(sizeof(struct Node));

        n->data = x;

        n->next = top;

        top = n;

        return top;
    }
}

int pop(struct Node* tp){

    if(isEmpty(tp)){

        printf("Stack Underflow\n");
    }
    else{

        struct Node* n = tp;

        top = (tp)->next;

        int x = n->data;

        free(n);

        return x;
    }
}

int main(){

    top = push(top, 8);

    top = push(top, 71);

    top = push(top, 80);

    Traverse(top);

    int element = pop(top);

    printf("\n%d is popped \n", element);

    Traverse(top);

    return 0;
}
