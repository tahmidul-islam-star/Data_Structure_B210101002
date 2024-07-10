#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{

    int data;

    struct Node* next;
};
struct Queue{

    Node* front;

    Node* rear;
};
struct Queue* createQueue() {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    q->front = q->rear=NULL;

    return q;
}
void Display(struct Queue* q) {

    struct Node* ptr = q->front;

    while (ptr != NULL) {

        cout << ptr->data << " ";

        ptr = ptr->next;
    }
    cout << endl;
}
void enqueue(struct Queue* q, int data) {

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    newnode->data = data;

    newnode->next = NULL;

    if (q->rear == NULL) {

        q->front =q->rear= newnode;

    } else {

        q->rear->next = newnode;

        q->rear = newnode;
    }
}
void dequeue(struct Queue* q)
{
    if(q->front==NULL) {

        cout<<"Empty "<<endl;

        return;
    }
    struct Node* temp= q->front;

    q->front = q->front->next;

    if(q->front==NULL)
    {
        q->rear=NULL;
    }
    free(temp);
}
int main() {

    Queue* q = createQueue();

    int n;cin >> n;

    while (n--) {

        int random; cin >> random;

        enqueue(q, random);
    }
    Display(q);

    dequeue(q);

    Display(q);

    return 0;
}
