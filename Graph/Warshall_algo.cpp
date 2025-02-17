#include <iostream>
using namespace std;

#define V 4

#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[ ][V]) {

    int i, j, k;

    for (k = 0; k < V; k++) {

        for (i = 0; i < V; i++) {

            for (j = 0; j < V; j++) {

                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][V]) {

    cout << "shortest distances between every pair of vertices \n";

    for (int i = 0; i < V; i++) {

        for (int j = 0; j < V; j++) {

                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}
int main() {

    int graph[V][V] = { { 0, 5, 2, 10 },
                        { 7, 0, 3, 6 },
                        { 1, 2, 0, 1 },
                        { 3, 7, 9, 0 } };

    floydWarshall(graph);

    return 0;
}
