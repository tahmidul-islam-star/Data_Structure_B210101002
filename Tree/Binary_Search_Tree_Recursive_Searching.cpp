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
void Inorder_traverse(struct node* root)
{
    if(root != NULL)
    {
        Inorder_traverse(root->left);

        cout<<root->data<<" ";

        Inorder_traverse(root->right);
    }
}
struct node* Search(struct node* root ,int key)
{
    if(root == NULL) return NULL;

    if(root->data == key) return root;

    else if(root->data>key) return Search(root->left,key);

    else return Search(root->right,key);
}
int main()
{
   Create_Tree();

    Inorder_traverse(root);

    cout<<endl;

    if(Search(root,12)){

        cout<<"Found "<<endl;
    }
    else cout<<"NOT Found"<<endl;

    return 0;
}




