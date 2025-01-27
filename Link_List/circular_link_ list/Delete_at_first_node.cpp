#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {

    int data;

    struct Node* next;
};
Node* Head = NULL;

void Traverse() {

     Node* ptr = Head;

    do {

        cout << ptr->data << " -> ";

        ptr = ptr->next;

    } while (ptr != Head);

    cout<<ptr->data<<endl;
}
void Insert_at_end(int data) {

    struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));

    if (Newnode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    Newnode->data = data;

    Newnode->next = NULL;

    if (Head == NULL) {

        Head = Newnode;

        Newnode->next = Head;

        return;
    }
    struct Node* temp = Head;

    while (temp->next != Head) {

        temp = temp->next;
    }
    temp->next = Newnode;

    Newnode->next = Head;
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
    struct Node* temp = Head;

    struct Node* last = Head;

    while (last->next != Head) {

        last = last->next;
    }
    Head = Head->next;

    last->next = Head;

    free(temp);
}
int main() {

    int n; cin >> n;

    int random;

    while (n--) {

        cin >> random;

        Insert_at_end(random);
    }
    Traverse();

    Delete_at_First();

    cout << "after deleting first node:" << endl;

    Traverse();

    return 0;
}

