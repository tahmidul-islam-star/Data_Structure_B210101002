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

    while(temp != NULL)
    {    
        
        if(item==temp->data){ 

            return temp;
        }
        temp =temp->next;
    }
    return NULL;
}
void Delete_In_loc_Node(struct Node* position)
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

    while(ptr->next != NULL &&  ptr->next !=position)
    {

        ptr= ptr->next;

    }
    struct Node* temp= ptr->next;

    ptr->next= temp->next;

    free(temp);

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
    cout<<"Before Deleting : "<<endl;

    Traverse();

    int value= 2;
    
    struct Node* loc= Searching(value);

    Delete_In_loc_Node(loc);

    cout<<"After Deleting : "<<endl;

    Traverse();
    
    return 0;
}