#include <iostream>
#include <cstdlib>

using namespace std;

struct Queue{

    int front, rear, capacity;

    int* queue;
};
struct Queue* createQueue(int capacity) {

    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

    q->capacity = capacity;

    q->front = q->rear = 0;

    q->queue = (int*)malloc(q->capacity * sizeof(int));

    return q;
}
void Q_Insert(struct Queue* q, int data) {

    if (q->capacity == q->rear) {

        printf("\nQueue is full\n");

        return;
    }
    q->queue[q->rear] = data;

    q->rear++;
}
void Q_Delete(struct Queue* q) {

    if (q->front == q->rear) {

        printf("\nQueue is empty\n");

        return;
    }
    for (int i = 0; i < q->rear - 1; i++) {

        q->queue[i] = q->queue[i + 1];
    }
    q->rear--;
}
void display(struct Queue* q) {

    for (int i = q->front; i < q->rear; i++) {

      cout<<q->queue[i]<<" ";
    }
    cout<<endl;
}
int main() {

    int n; cin>>n;

    struct Queue* q = createQueue(n);

    while(n--){

        int random;cin>>random;

        Q_Insert(q,random);
    }
    display(q);

    Q_Delete(q);

    display(q);

    return 0;
}

