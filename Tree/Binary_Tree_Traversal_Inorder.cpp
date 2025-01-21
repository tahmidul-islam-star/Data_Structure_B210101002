#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;

    struct node* left,*right;
};
struct node* root;

struct node* getnode(int info)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    temp->data = info;

    temp->left = NULL; temp->right = NULL;
};
void Create_Tree()
{
     struct node *c1,*c2,*c3,*c4;

    root = getnode(4); c1 = getnode(1);

    c2 = getnode(6); c3 = getnode(5);

    c4 = getnode(2);

    root->left = c1, root->right = c2;

    c1->left = c3, c1->right = c4;
}
void Inorder_traverse(struct node* root)
{
    if(root != NULL)
    {
        Inorder_traverse(root->left);

        cout<<root->data<<" ";

        Inorder_traverse(root->right);
    }
}
int main()
{
    Create_Tree();

    Inorder_traverse(root);

    return 0;
}


