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
   if(ptr->top==-1) return 1;

   return 0;
}
int isFull(struct stack*ptr)
{
    if(ptr->top== ptr->size-1) return 1;

    return 0;
}
void Push(struct stack*ptr,int value)
{
    if(isFull(ptr)) printf("Stack overflow\n");

    else{
         ptr->top++;
         ptr->arra[ptr->top]=value;
    }
}
int Pop(struct stack*ptr){

   if(isEmpty(ptr)) printf("Stack Underflow\n");

   else{

    int temp =ptr->arra[ptr->top];
     ptr-> top--;

     return temp;
   }
}
int peek(struct stack* ptr,int pos){


    if(ptr->top-pos+1<0) printf("Not a valid position\n");

    else{

       return ptr->arra[ptr->top-pos+1];
    }
}
int stakTop(struct stack * ptr){

   return ptr->arra[ptr->top];
}
int stakB(struct stack* ptr){

   return ptr->arra[0];
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
    Push(sp,4);
    Push(sp,5);
    Push(sp,12);

    printf("Top most Element is %d\n",stakTop(sp));

    printf("Bottom most Element is %d\n",stakB(sp));

    return 0;
}


