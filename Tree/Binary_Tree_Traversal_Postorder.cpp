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
    struct node* temp= (struct node*)malloc(sizeof(struct node));

    temp->data= info;

    temp->left= NULL;

    temp->right= NULL;
};
void postorder_traverse(struct node* root)
{
    if(root != NULL)
    {
        postorder_traverse(root->left);

        postorder_traverse(root->right);

        cout<<root->data<<" ";
    }
}
int main()
{
    struct node* n1,*n2,*n3,*n4,*n5;

    n1 = getnode(4);

    n2 = getnode(1);

    n3 = getnode(6);

    n4 = getnode(5);

    n5 = getnode(2);

    n1->left = n2, n1->right = n3;

    n2->left = n4, n2->right = n5;

    postorder_traverse(n1);

    return 0;
}

