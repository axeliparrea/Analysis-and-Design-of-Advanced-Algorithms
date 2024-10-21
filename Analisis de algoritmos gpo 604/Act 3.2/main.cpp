//Axel Eduardo Iparrea Ramos A00836682

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(int src, int n, const vector<vector<int>>& adjMatrix) {
    vector<int> dist(n, INF);
    dist[src] = 0; 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; 

        for (int v = 0; v < n; v++) {
            if (adjMatrix[u][v] != -1) { 
                int newDist = dist[u] + adjMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != src) {
            cout << "node " << src + 1 << " to node " << i + 1 << " : " << dist[i] << endl;
        }
    }
}

void floydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "Floyd :" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adjMatrix(n, vector<int>(n)); 
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            if (i == j) dist[i][j] = 0;
            else if (adjMatrix[i][j] != -1) dist[i][j] = adjMatrix[i][j]; 
        }
    }

    cout << "Dijkstra :" << endl;
    for (int i = 0; i < n; i++) {
        dijkstra(i, n, adjMatrix);
    }

    floydWarshall(n, dist);

    return 0;
}
