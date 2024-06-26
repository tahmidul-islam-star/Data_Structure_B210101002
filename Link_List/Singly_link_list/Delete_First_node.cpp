#include<iostream>
#include<cstdlib>


using namespace std;

struct Node
{
    int data;

    struct Node* next;
};
struct Node* Head=NULL;

void Traverse()
{
    struct Node* temp=Head;

    while(temp !=NULL)
    {
        cout<<temp->data<<" -> ";

        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}
void Create_Link_list(int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL)
    {
        cout<<"Memory Allocation Failed"<<endl;

        return;
    }
    newnode->data=data;

    newnode->next=NULL;

    if(Head==NULL){

        Head= newnode;

        return;
    }
    struct Node* temp= Head;

    while(temp->next !=NULL)
    {
        temp =temp->next;
    }
    temp->next=newnode;

}
void Delete_First_Node()
{
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));

    if (Head == NULL) {

        printf("List is already empty\n");

        return;
    }
    else if (Head->next == NULL) {

        free(Head);

        Head = NULL;

        return;
    }
    else{

    ptr= Head;

    Head= Head->next;

    free(ptr);

    }
}
int main()
{
    int n;cin>>n;

    int random;

    while(n--)
    {
        cin>>random;

        Create_Link_list(random);
    }
    cout<<"Before Deleteing : "<<endl;

    Traverse();

    Delete_First_Node();

    cout<<"After Deleting : "<<endl;

    Traverse();

    return 0;
}
