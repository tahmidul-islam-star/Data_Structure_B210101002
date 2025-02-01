#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {

    int data;

    Node* next;

    Node* prev;
};
Node* Head = NULL;

void Traverse() {

    if (Head == NULL) {

        cout << "List is empty" << endl;

        return;
    }
    Node* ptr = Head;

    do {
        cout << ptr->data << " <-> ";

        ptr = ptr->next;

    } while (ptr != Head);

    cout << "(Head)" << endl;
}
void Insert_at_end(int data) {

    Node* Newnode = (Node*)malloc(sizeof(Node));

    if (Newnode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    Newnode->data = data;

    Newnode->next = Newnode->prev = NULL;

    if (Head == NULL) {

        Head = Newnode;

        Head->next = Head;

        Head->prev = Head;

        return;
    }
    Node* last = Head->prev;

    last->next = Newnode;

    Newnode->prev = last;

    Newnode->next = Head;

    Head->prev = Newnode;
}
void Delete_at_First() {

    if (Head == NULL) {

        cout << "List is empty" << endl;

        return;
    }
    if (Head->next == Head) {

        free(Head);

        Head = NULL;

        return;
    }
    Node* temp = Head;

    Node* last = Head->prev;

    Head = Head->next;

    Head->prev = last;

    last->next = Head;

    free(temp);
}
int main() {

    int n;cin >> n;

    int random;

    while (n--) {

        cin >> random;

        Insert_at_end(random);
    }
    cout << "Original List:" << endl;

    Traverse();

    Delete_at_First();

    cout << "After deleting first node:" << endl;

    Traverse();

    return 0;
}
/*
5
1 2 3 4 5
Original List:
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> (Head)
After deleting first node:
2 <-> 3 <-> 4 <-> 5 <-> (Head)

Process returned 0 (0x0)   execution time : 3.917 s
Press any key to continue.

*/
