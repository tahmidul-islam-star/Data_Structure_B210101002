#include<iostream>
#include<cstdlib>


using namespace std;

struct Node
{
    int data;

    struct Node* next;
};
struct Node* Head= NULL;

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
void Create_linklist(int item)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL) {

    cout<<"Memory Allocation Failed"<<endl;

    return;
    }
    newnode->data=item;

    newnode->next=NULL;

    if(Head==NULL)
    {
        Head=newnode;

        return;
    }
    struct Node* temp=Head;

    while(temp->next !=NULL)
    {
        temp= temp->next;
    }

    temp->next= newnode;

}
void Reverse_Linklist()
{
    struct Node* prevNode,*currentNode,*nextNode;

    prevNode=NULL;

    currentNode= nextNode= Head;

    while(nextNode !=NULL)
    {
        nextNode= nextNode->next;

        currentNode->next= prevNode;

        prevNode=currentNode;

        currentNode=nextNode;
    }
    Head=prevNode;
}
int main()
{
    int num=7;

    while(num--)
    {
        int random;cin>>random;

        Create_linklist(random);
    }
    cout<<"Original Link List : "<<endl;

    Traverse();

    cout<<"After Reverse Link List : "<<endl;

    Reverse_Linklist();

    Traverse();

    return 0;

}
