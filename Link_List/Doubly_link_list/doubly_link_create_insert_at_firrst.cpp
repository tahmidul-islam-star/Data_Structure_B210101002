#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {

    int data;

    Node* next;

    Node* prev;
};
Node* Head = NULL;

void Traverse() {

    if (Head == NULL) {

        cout << "List is empty." << endl;

        return;
    }
    Node* ptr = Head;

    do {

        cout << ptr->data << " <-> ";

        ptr = ptr->next;

    } while (ptr != Head);

    cout << "(Back to Head: " << Head->data << ")" << endl;
}
void Insert_At_First(int value) {

    Node* NewNode = (Node*)malloc(sizeof(Node));

    if (NewNode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    NewNode->data = value;

    if (Head == NULL) {

        NewNode->next = NewNode;

        NewNode->prev = NewNode;

        Head = NewNode;

    } else {

        Node* tail = Head->prev;

        NewNode->next = Head;

        NewNode->prev = tail;

        tail->next = NewNode;

        Head->prev = NewNode;

        Head = NewNode;
    }
}
int main() {

    int n;cin>>n;

    for (int i = 0; i <n; i++) {

        int random;cin>>random;

        Insert_At_First(random);
    }
    Traverse();

    return 0;
}
/*
5
 1 2 3 4 5
 5 <-> 4 <-> 3 <-> 2 <-> 1 <-> (Back to Head: 5)

 Process returned 0 (0x0)   execution time : 3.932 s
 Press any key to continue.

*/
