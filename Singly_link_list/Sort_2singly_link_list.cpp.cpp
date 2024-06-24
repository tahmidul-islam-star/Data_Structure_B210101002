#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {

    int data;

    struct Node* next;
};
struct Node* Head1 = NULL;

struct Node* Head2 = NULL;

void Traverse(struct Node* ptr) {

    struct Node* temp = ptr;

    while (temp != NULL) {

        cout << temp->data << " -> ";

        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void Create_Link_list(struct Node*& head, int data) {

    struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));

    if (Newnode == NULL) {

        cout << "Memory Allocation Failed" << endl;

        return;
    }
    Newnode->data = data;

    Newnode->next = NULL;

    if (head == NULL) {

        head = Newnode;

        return;
    }
    struct Node* temp = head;

    while (temp->next != NULL) {

        temp = temp->next;
    }
    temp->next = Newnode;
}
void Sort_Link_list(struct Node*& head) {

    if (head == NULL || head->next == NULL) return;

    struct Node* sorted = NULL;

    struct Node* current = head;

    while (current != NULL) {

        struct Node* next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {

            current->next = sorted;

            sorted = current;

        } else {

            struct Node* temp = sorted;

            while (temp->next != NULL && temp->next->data < current->data) {

                temp = temp->next;
            }
            current->next = temp->next;

            temp->next = current;
        }
        current = next;
    }
    head = sorted;
}
int main(){

int m, n, random;

    cin >> m >> n;

    while (m--) {

        cin >> random;

        Create_Link_list(Head1, random);
    }
    while (n--) {

        cin >> random;

        Create_Link_list(Head2, random);
    }

    cout << "Before Sorting :" << endl;

    cout << "First Link List :" << endl;

    Traverse(Head1);

    cout << "Second Link List" << endl;

    Traverse(Head2);
    
    cout << "After Sorting :" << endl;

    Sort_Link_list(Head1);

    Sort_Link_list(Head2);

    cout << "First Link List :" << endl;

    Traverse(Head1);

    cout << "Second Link List" << endl;

    Traverse(Head2);

    return 0;
}