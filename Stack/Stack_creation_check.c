#include<stdio.h>
#include<stdlib.h>


struct stack
{
    int size;

    int top;

    int *arra;
};
int isEmpty(struct stack *ptr)
{
    if(ptr->top==-1) {

        return 1;
    }
    else {

        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));

    s->size=80;

    s->top=-1;

    s->arra=(int *)malloc(s->size*sizeof(int));

    s->arra[0]=7;

    s->top++;

    if(isEmpty(s)) {printf("The stack is empty\n");}

    else {printf("The stack is not empty\n");}


    free(s->arra);
    free(s);

    return 0;

}
