#include <iostream>
#include <queue>
using namespace std;

const int n = 3;

int graph[n][n] = {0};

void add_connection(int from, int to) {

    graph[from][to] = 1;
}
void display_graph() {

    for (int i = 0; i < n; i++) {

        cout << i << ": ";

        for (int j = 0; j < n; j++) {

            if (graph[i][j]) {

                cout << j << " ";
            }
        }
        cout << endl;
    }
}
void bfs(int start) {

    bool visited[n] = {false};

    queue<int> q;

    visited[start] = true;

    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {

        int node = q.front();

        q.pop();

        cout << node << " ";

        for (int i = 0; i < n; i++) {

            if (graph[node][i] && !visited[i]) {

                visited[i] = true;

                q.push(i);
            }
        }
    }
    cout << endl;
}
int main() {

    add_connection(1, 0);

    add_connection(1, 2);

    add_connection(2, 0);

    cout << "Adjacency Matrix Representation:" << endl;

    display_graph();

    cout << "\nApplying BFS from node 1:" << endl;

    bfs(1);

    return 0;
}

