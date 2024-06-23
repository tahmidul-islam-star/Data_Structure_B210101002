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
int main()
{
    for(int i=10;i>=1;i--){

        Insert_At_First(i);
    }
    Traverse();

    int value= 2;

    struct Node* Loc= Searching(value);

    if(Loc==NULL) cout<<value<<" Not Found"<<endl;

    else cout<<value<<" is found at location : "<<Loc<<endl;

    return 0;

}

