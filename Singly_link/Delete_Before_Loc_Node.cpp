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
        //Traverse second last loacation node

        if(item==temp->next->data){ 

            return temp;
        }
        temp =temp->next;
    }
    return NULL;
}
void Delete_Before_loc_Node(struct Node* position)
{

    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));   
    
    struct Node* temp = Head;

    while (temp != NULL && temp->next != position) {

        temp = temp->next;
    }

    if (temp != NULL) {

        struct Node* p = temp->next;

        temp->next = p->next;

        free(p);

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
    cout<<"Before Deleting Any Node : "<<endl;

    Traverse();

    int value= 2;
    
    struct Node* loc= Searching(value);

    if(loc ==NULL)
    {
        cout<<"This node is not found"<<endl;
    }
    
    else if( loc == Head){

        cout << "No node to exist Before the given node." << endl;
    }
    else{

    Delete_Before_loc_Node(loc);

    cout<<"Deleting Before "<<loc<<" node : "<<endl;

    Traverse();

    }
    return 0;
}