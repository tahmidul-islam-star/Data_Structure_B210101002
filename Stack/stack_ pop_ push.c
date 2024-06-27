#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack
{
    int size;

    int top;

    int *arra;
};

bool isEmpty(struct stack* ptr)
{
    if(ptr->top== -1) return true;

    return false;
}

bool isFull(struct stack* ptr)
{
    if(ptr->top == ptr->size-1) return true;

    return false;
}

void Push(struct stack* ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;

        ptr->arra[ptr->top] = val;
    }
}

int Pop(struct stack* ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");

        return -1;
    }
    else
    {
        int temp = ptr->arra[ptr->top];

        ptr->top--;

        return temp;
    }
}

int main()
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));

    sp->size = 10;

    sp->top = -1;

    sp->arra = (int*)malloc(sp->size * sizeof(int));

    for (int i = 10; i > 0; i--)
    {
        Push(sp, i);
    }

    while (!isEmpty(sp))
    {
        printf("%d is popped \n", Pop(sp));
    }

    return 0;
}
