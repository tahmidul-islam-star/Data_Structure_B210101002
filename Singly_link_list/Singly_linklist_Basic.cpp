#include<iostream>
#include<cstdlib>

using namespace std;

struct Node
{
    int data;

    struct Node* next;
};
void Traverse(struct Node* ptr)
{
    ptr = ptr->next;// To point first node

    while(ptr !=NULL)
    {
        cout<<ptr->data<<" -> ";

        ptr= ptr->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    struct Node* Head,*first,*second,*third;

    Head= (struct Node*)malloc(sizeof(struct Node));

    first=(struct Node*)malloc(sizeof(struct Node));

    second=(struct Node*)malloc(sizeof(struct Node));

    third=(struct Node*)malloc(sizeof(struct Node));


    Head->next= first;

    first->data=5;

    first->next=second;

    second->data=6;

    second->next=third;

    third->data=7;

    third->next=NULL;

    Traverse(Head);
    
    return 0;
}