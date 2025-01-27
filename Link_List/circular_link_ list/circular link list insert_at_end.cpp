#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {

    int data;

    struct Node* next;
};
Node *Head = NULL;

void Traverse() {

    struct Node* ptr = Head;

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
