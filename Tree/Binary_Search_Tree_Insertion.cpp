#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;

    struct node* left;

    struct node* right;
};
struct node* getnode(int info)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = info;

    temp->left = NULL;

    temp->right = NULL;

    return temp;
};
void Inorder_traverse(struct node* root)
{
    if(root != NULL)
    {
        Inorder_traverse(root->left);

        cout<<root->data<<" ";

        Inorder_traverse(root->right);
    }
}
void Insertion(struct node* root,int value)
{
    struct node* temp = NULL;

    while(root != NULL)
    {
        temp = root;

        if(value == root->data) return;

        else if(value < root->data) root = root->left;

        else root = root->right;
    }
    struct node* newnode = getnode(value);

    if(value<temp->data)
    {
        temp ->left = newnode;
    }
    else temp->right = newnode;
}
int main()
{
    struct node*root, *c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8;

    root = getnode(8);

    c1= getnode(3); c2 = getnode(10);

    c3 = getnode(1); c4 = getnode(6);

    c5 = getnode(14); c6 = getnode(4);

    c7 = getnode(7); c8 = getnode(13);

    root->left = c1; root->right = c2;

    c1->left = c3; c1->right = c4;

    c4->left = c6; c4->right = c7;

    c2->right = c5; c5->left = c8;

    Inorder_traverse(root); cout<<endl;

    Insertion(root,9);

    cout<<"After Inserting "<<endl;

    Inorder_traverse(root);

    return 0;
}
