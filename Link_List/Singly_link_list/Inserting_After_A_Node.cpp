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
struct Node* Searching(int item)
{
    struct Node* temp= Head;

    while(temp !=NULL)
    {
        if(item==temp->data){

            return temp;
        }
        temp =temp->next;
    }
    return NULL;
}
void Insert_After_Node(struct Node* prev_node,int item)
{
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));

    if (prev_node == NULL) {

        cout << "The given previous node cannot be nullptr" << endl;

        return;
    }
    
    ptr->data=item;

    ptr->next= prev_node->next;

    prev_node->next= ptr;

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
    cout<<"Before Inserting : "<<endl;

    Traverse();

    int value= 2;

    struct Node* loc= Searching(value);

    Insert_After_Node(loc,100);

    Traverse();
    
    return 0;
}