#include <iostream>
#include <climits>

using namespace std;

#define V 4
#define INF INT_MAX

void dijkstra(int graph[V][V], int src) {

    int dist[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++) {

        dist[i] = INF;

        sptSet[i] = false;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {

        int min = INF, u;

        for (int v = 0; v < V; v++) {

            if (!sptSet[v] && dist[v] <= min) {

                min = dist[v];
                u = v;
            }
        }

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {

            if (!sptSet[v] && graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";

    for (int i = 0; i < V; i++) {

    cout << i << "\t" << dist[i] << "\n";
    }
}
int main() {

    int graph[V][V] = { { 0, 5, 2, 10 },
                        { 7, 0, 3, 6 },
                        { 1, 2, 0, 1 },
                        { 3, 7, 9, 0 } };

    int src = 0;

    dijkstra(graph, src);

    return 0;
}

