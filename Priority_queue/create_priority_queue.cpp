#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct PriorityQueue {

    int front, rear, capacity;

    int* queue;

    PriorityQueue(int cap) {

        capacity = cap;

        front = rear = 0;

        queue = (int*)malloc(capacity * sizeof(int));
    }
    void insert(int data) {

        if (rear == capacity) {

            cout << "\nQueue is full\n";

            return;
        }
        queue[rear] = data;

        rear++;

        sort(queue, queue + rear, greater<int>());
    }
    void display() {

        for (int i = front; i < rear; i++) {

            cout << queue[i] << " ";
        }
        cout << endl;
    }
};
int main() {

    int n; cin >> n;

    PriorityQueue pq(n);

    while (n--) {

        int random; cin >> random;

        pq.insert(random);
    }
    pq.display();

    return 0;
}

