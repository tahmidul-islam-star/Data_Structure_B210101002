#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {

    int data;

    struct Node* next;

    struct Node* prev;
};
Node* Head = NULL;

void Traverse() {

    if (Head == NULL) {

        cout << "List is empty." << endl;

        return;
    }
    struct Node* ptr = Head;

    do {

        cout << ptr->data << " <-> ";

        ptr = ptr->next;

    } while (ptr != Head);

    cout << "(Back to Head: " << Head->data << ")" << endl;
}
void Insert_at_end(int data) {

    struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));

    if (Newnode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    Newnode->data = data;

    if (Head == NULL) {

        Newnode->next = Newnode;

        Newnode->prev = Newnode;

        Head = Newnode;

        return;
    }
    struct Node* tail = Head->prev;

    tail->next = Newnode;

    Newnode->prev = tail;

    Newnode->next = Head;

    Head->prev = Newnode;
}
int main() {

    int n; cin >> n;

    int random;

    while (n--) {

        cin >> random;

        Insert_at_end(random);
    }
    Traverse();

    return 0;
}
/*
  5
1 2 3 4 5
1 <-> 2 <-> 3 <-> 4 <-> 5 <-> (Back to Head: 1)

Process returned 0 (0x0)   execution time : 14.557 s
Press any key to continue.



*/
