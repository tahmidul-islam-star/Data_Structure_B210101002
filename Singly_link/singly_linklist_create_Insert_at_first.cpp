#include<iostream>
#include<cstdlib>


using namespace std;

struct Node
{
    int data;

    struct Node* next;
};
struct Node* Head;

void Traverse()
{
    struct Node* ptr= Head;

    while(ptr != NULL)
    {
        cout<<ptr->data<<" -> ";

        ptr= ptr->next;
    }
    cout<<"NULL"<<endl;
}
void Insert_At_First(int value)
{
    struct Node* Newnode= (struct Node*)malloc(sizeof(struct Node));
    
    if(Newnode== NULL) {

        cout<<"Memory Allocation Failed"<<endl;

        return;
    }
    Newnode->data=value;

    Newnode->next=Head;

    Head= Newnode;

}
int main()
{
    for(int i=1;i<=10;i++)
    {
        Insert_At_First(i+5);
    }
    Traverse();

    return 0;
}


