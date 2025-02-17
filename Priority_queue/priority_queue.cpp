#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue<int> pq;

    int n;cin >> n;

    while (n--) {

        int random;

        cin >> random;

        pq.push(random);
    }
    while (!pq.empty()) {

        cout << pq.top() << " ";

        pq.pop();
    }

    cout << endl;

    return 0;
}

