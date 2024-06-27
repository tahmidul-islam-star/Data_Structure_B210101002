#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;

    struct Node* next;
};
struct Node * top =NULL;

void link(struct Node* ptr)
{
    while(ptr !=NULL)
    {
        printf("Element : %d\n",ptr->data);

        ptr= ptr->next;
    }
}

int isEmpty(struct Node* ptr)
{
    if(ptr==NULL) return 1;

    return 0;
}
int isFull(struct Node* ptr)
{
    struct Node* n= (struct Node*)malloc(sizeof(struct Node));

    if(n==NULL) return 1;

    return 0;
}
struct Node* push(struct Node* p,int x)
{
     if(isFull(p)) printf("Stack overflow\n");

     else
     {
         struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));

         ptr->data=x;

         ptr->next=p;

         p=ptr;

         return ptr;
     }
}
int pop(struct Node* ptr)
{
    if(isEmpty(ptr)) printf("stack Underflow\n");

    else
    {
        struct Node *n= ptr;

        int x=n->data;

        top= ptr->next;

        free(n);

        return x;
    }
}
int peek(int pos)
{
    struct Node* ptr= top;

    for(int i=0;(i<pos-1 && ptr!= NULL) ; i++)
    {
        ptr= ptr->next;
    }
    if(ptr !=NULL)
    {
        return ptr->data;
    }
    else return -1;
}
int Top()
{
    return top->data;
}
int Bottom(struct Node *ptr)
{
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    top= push(top,20);

    top=push(top,30);

    top=push(top,40);

    top=push(top,50);

    link(top);

   printf("Value at position at %d is %d\n",0,peek(0));


    return 0;
}
