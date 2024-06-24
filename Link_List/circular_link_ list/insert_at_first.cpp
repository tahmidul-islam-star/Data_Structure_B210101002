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
    struct Node* p= ptr;

    ptr= ptr->next;// first node point now

    do{

        cout<<ptr->data<<" ";

        ptr= ptr->next; //Second node

    } while(ptr != p);
}
int main()
{
    struct Node* head,*first,*second,*third;

    head=(struct Node*)malloc(sizeof(struct Node));

    first=(struct Node*)malloc(sizeof(struct Node));

    second=(struct Node*)malloc(sizeof(struct Node));

    third=(struct Node*)malloc(sizeof(struct Node));

    head->next= first;

    first->data=5;

    first->next= second;

    second->data= 6;

    second->next= third;

    third->data= 7;

    third->next= head;

    Traverse(head);

    return 0;
}

