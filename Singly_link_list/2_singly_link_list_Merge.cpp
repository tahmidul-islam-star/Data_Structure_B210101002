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

struct Node* Merge_lists(struct Node* head1, struct Node* head2) {

    if (head1 == NULL) return head2;

    if (head2 == NULL) return head1;

    struct Node* mergeHead = NULL;

    struct Node* mergeTail = NULL;

    if (head1->data <= head2->data) {

        mergeHead = head1;

        head1 = head1->next;

    } else {

        mergeHead = head2;

        head2 = head2->next;
    }
    mergeTail = mergeHead;

    while (head1 != NULL && head2 != NULL) {

        struct Node* temp = NULL;

        if (head1->data <= head2->data) {

            temp = head1;

            head1 = head1->next;

        } else {

            temp = head2;

            head2 = head2->next;
        }
        mergeTail->next = temp;

        mergeTail = temp;
    }
    if (head1 != NULL) {

        mergeTail->next = head1;

    } else {

        mergeTail->next = head2;
    }
    return mergeHead;
}

int main() {

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

    cout << "Before Merge :" << endl;

    cout << "First Link List :" << endl;

    Traverse(Head1);

    cout << "Second Link List" << endl;

    Traverse(Head2);

    Sort_Link_list(Head1);

    Sort_Link_list(Head2);

    cout << "After Sorting :" << endl;

    cout << "First Link List :" << endl;

    Traverse(Head1);

    cout << "Second Link List" << endl;

    Traverse(Head2);

    struct Node* MergeHead = Merge_lists(Head1, Head2);

    cout << "After Merge :" << endl;

    Traverse(MergeHead);

    return 0;
}
