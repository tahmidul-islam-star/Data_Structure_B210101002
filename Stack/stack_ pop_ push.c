#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;

    int top;

    int *arra;
};
int isEmpty(struct stack* ptr)
{
    if(ptr->top== -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else {
        return 0;
    }
}
void Push(struct stack *ptr,int val)
{
    if(isFull(ptr)){

        printf("Stack Overflow");
    }
    else{
        ptr->top++;

        ptr->arra[ptr->top]=val;
    }
}
int Pop(struct stack* ptr)
{
    if(isEmpty(ptr)){

        printf("Stack Underflow\n");
    }
    else{

        int temp= ptr->arra[ptr->top];

        ptr->top=ptr->top-1;

        return temp;
    }
}
int main()
{
    struct stack *sp=(struct stack*)malloc(sizeof(struct stack));

    sp->size=10;

    sp->top=-1;
    sp->arra=(int *)malloc(sp->size*sizeof(int));

    printf("Stack has been created successfully\n");

    Push(sp,1);
    Push(sp,2);
    Push(sp,3);

   printf("%d is popped from the stack\n",Pop(sp));
   printf("%d is popped from the stack\n",Pop(sp));

   return 0;

}
