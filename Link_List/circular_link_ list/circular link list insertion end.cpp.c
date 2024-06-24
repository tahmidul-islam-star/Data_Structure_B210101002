#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;

    struct Node* next;
};
void LinklistTraversal(struct Node* ptr)
{
    struct Node* p= ptr;

   do{
    printf("Element: %d\n",ptr->data);

    ptr=ptr->next;

   } while(ptr != p);
}
struct Node* insetEnd(struct Node* head,int data)
{
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));

    ptr->data=data;

    struct Node *p=head->next;

    while(p->next != head){

        p= p->next;
    }
    p->next= ptr;

    ptr->next=head;

   return head;
};
int main()
{
    struct Node* head;

    struct Node* second;

    struct Node* third;

    struct Node* fourth;

    head=(struct Node*)malloc(sizeof(struct Node));

    second=(struct Node*)malloc(sizeof(struct Node));

    third=(struct Node*)malloc(sizeof(struct Node));

    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=1;

    head->next=second;

    second->data=2;

    second->next=third;

    third->data=3;

    third->next=fourth;

    fourth->data=4;

    fourth->next=head;

   printf("Before inserting end:  \n");

   LinklistTraversal(head);

   printf("After Insserting at end: \n");

   head=insetEnd(head,5);

  printf("after Inserting end \n");

  LinklistTraversal(head);

  return 0;
}
