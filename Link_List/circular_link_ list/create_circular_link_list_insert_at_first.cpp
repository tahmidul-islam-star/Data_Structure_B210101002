#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {

    int data;

    struct Node* next;
};
struct Node* Head = NULL;

void Traverse() {

    struct Node* ptr = Head;

    do {

        cout << ptr->data << " -> ";

        ptr = ptr->next;

    } while (ptr != Head);

     cout<< ptr->data; // now ptr point at head

    cout<<endl;
}
void Insert_At_First(int value) {

    struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));

    if (Newnode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    Newnode->data = value;

    if (Head == NULL) {

        Newnode->next = Newnode;

        Head = Newnode;

    } else {

        struct Node* ptr = Head;

        while (ptr->next != Head) {

            ptr = ptr->next;
        }

        Newnode->next = Head;

        ptr->next = Newnode;

        Head = Newnode;
    }
}
int main() {

    for (int i = 1; i <= 10; i++) {

        Insert_At_First(i + 5);
    }
    Traverse();

    return 0;
}

