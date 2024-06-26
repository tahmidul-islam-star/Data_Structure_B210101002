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
void Delete_After_loc_Node(struct Node* position)
{
    struct Node* temp = position->next;

    position->next= temp->next;

    free(temp);

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

    if(loc == NULL ){

        cout<<"This node is not present in this link list"<<endl;
    }
    else if(loc->next == NULL) {

        cout << "No node exist After the given node." << endl;

    }
    else{

    Delete_After_loc_Node(loc);

    cout<<"Deleting after "<<loc<<" node : "<<endl;

    Traverse();

    }

    return 0;
}
