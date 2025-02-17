#include <iostream>
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
int main() {

    add_connection(1, 0);

    add_connection(1, 2);

    add_connection(2, 0);

    cout << "Adjacency Matrix Representation:" << endl;

    display_graph();

    return 0;
}

