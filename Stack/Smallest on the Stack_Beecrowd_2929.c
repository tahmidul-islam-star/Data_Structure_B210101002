#include<stdio.h>
#include<stdlib.h>


struct stack
{
    int size;

    int top;

    int * arra;
};
int isEmpty(struct stack* ptr)
{
    if(ptr->top== -1) return 1;

    return 0;
}
void Push(struct stack* ptr,int value)
{
    if(ptr->top== ptr->size-1) return;

    else{

        ptr->top++;

        ptr->arra[ptr->top]=value;
    }
}
int Pop(struct stack* ptr)
{
    if(isEmpty(ptr)) {return INT_MIN;}

    else{

        int random= ptr->arra[ptr->top];

        ptr->top--;

        return random;
    }
}
int Top(struct stack* ptr)
{
    if(isEmpty(ptr)) return INT_MIN;

    return ptr->arra[ptr->top];
}
int main()
{
    int n;scanf("%d",&n);

    struct stack* arra1= (struct stack*) malloc(sizeof(struct stack));

    struct stack* arra2=(struct stack*) malloc(sizeof(struct stack));

    arra1->size=n; arra1->top=-1;

    arra2->size= n; arra2->top=-1;

    arra1->arra=(int *) malloc(n*sizeof(int));

    arra2->arra=(int *) malloc(n*sizeof(int));

    char string[5];int value;

    while(n--)
    {
        scanf("%s",&string);

        if(strcmp(string,"PUSH")==0){

            scanf("%d",&value);

            Push(arra1,value);

            if(isEmpty(arra2) || value<= Top(arra2)){

                Push(arra2,value);
            }
        }
        else if(strcmp(string,"POP")==0){

            if(isEmpty(arra1)) printf("EMPTY\n");

            else{

                int temp=Pop(arra1);

                if(temp==Top(arra2)){

                    Pop(arra2);
                }
            }
        }
        else if(strcmp(string,"MIN")==0)
        {
            if(isEmpty(arra2)) printf("EMPTY\n");

            else{

                printf("%d\n",Top(arra2));
            }
        }
    }
    free(arra1->arra); free(arra2->arra);free(arra1);free(arra2);

    return 0;
}
