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

    temp->data = info;

    temp->left = NULL;

    temp->right = NULL;
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
bool isBst(struct node* root)
{
    if(root == NULL) return 1; // empty tree is BST

    else{

        static struct node* prev= NULL;

        if(!isBst(root->left)) return 0;

        if(prev != NULL && root->data <= prev->data) return 0;

        prev= root;

        return isBst(root->right);
    }
}
int main()
{
    struct node*root,*c1,*c2,*c3,*c4,*c5,*c6,*c7,*c8;

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

    Inorder_traverse(root);

    cout<<endl;

   if(isBst(root)) cout<<"Yes Binary Search Tree"<<endl;

   else cout<<"No "<<endl;

    return 0;
}



