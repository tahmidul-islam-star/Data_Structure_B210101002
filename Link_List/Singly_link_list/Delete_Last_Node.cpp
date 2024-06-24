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
    struct Node* Newnode=(struct Node*)malloc(sizeof(struct Node));

    if(Newnode==NULL)    
    {
        cout<<"Memory Allocation Failed"<<endl;

        return;
    }
    Newnode->data=data;

    Newnode->next=NULL;

    if(Head==NULL){

        Head= Newnode;

        return;
    }
    struct Node* temp= Head;

    while(temp->next !=NULL)
    {
        temp =temp->next;
    }
    temp->next=Newnode;

}
void Delete_Last_Node()
{
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));   
    
    if (Head == NULL) { 

        printf("List is already empty\n");

        return;
    }
     // Only one node in the list
    
    else if (Head->next == NULL) { 

        free(Head);

        Head = NULL;

        return;
    }
    else{

    ptr= Head;

    // Traverse to the second last node

    while(ptr->next->next !=NULL)
    {

        ptr= ptr->next;
    }

    free(ptr->next);

    ptr->next=NULL;

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
    
    Delete_Last_Node();

    cout<<"After Deleting : "<<endl;

    Traverse();
    
    return 0;
}