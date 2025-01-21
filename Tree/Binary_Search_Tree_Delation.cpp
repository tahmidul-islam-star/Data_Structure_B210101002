#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;

    struct node* left;

    struct node* right;
};
struct node *root;

struct node* getnode(int info)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = info;

    newnode->left = NULL; newnode->right = NULL;
}
void Create_Tree()
{
    struct node* c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8;

    root = getnode(10);

    c1 = getnode(4); c2 = getnode(12);

    c3 = getnode(2); c4 = getnode(7);

    c5 = getnode(15); c6 = getnode(5);

    c7 = getnode(8); c8 = getnode(14);

    root->left = c1, root->right = c2;

    c1->left = c3, c1->right = c4;

    c2->right = c5 ;

    c4->left = c6, c4->right = c7;

    c5->left = c8;
}
void Inorder_Traverse(struct node* root)
{
    if(root != NULL)
    {
        Inorder_Traverse(root->left);

        cout<<root->data<<" ";

        Inorder_Traverse(root->right);
    }
}
struct node* InorderPredessor(struct node* root)
{
    root = root->left;

    while( root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node* Delete_node(struct node* root,int key)
{
    if(root == NULL) return NULL;

    if(root->right == NULL && root->left== NULL){

    free(root);

    return NULL;
    }
    else if(key<root->data)
    {
        root->left = Delete_node(root->left,key);
    }
    else if(key> root->data)
    {
        root->right = Delete_node(root->right,key);
    }
    else
    {
        struct node* temp = InorderPredessor(root);

        root->data = temp->data;

        root->left = Delete_node(root->left,temp->data);
    }
    return root;
}
int main()
{
    Create_Tree();

    Inorder_Traverse(root); cout<<endl;

    Delete_node(root,10);

    Inorder_Traverse(root);

    return 0;
}
