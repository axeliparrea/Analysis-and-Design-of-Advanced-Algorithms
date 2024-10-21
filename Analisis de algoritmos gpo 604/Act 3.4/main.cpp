#include <iostream>
#include <vector>
using namespace std;

bool esSeguro(int v, vector<vector<int>>& grafo, vector<int>& colores, int c) {
    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[v][i] == 1 && colores[i] == c)
            return false;
    }
    return true;
}

bool colorearGrafo(vector<vector<int>>& grafo, int m, vector<int>& colores, int v) {
    if (v == grafo.size())
        return true;

    for (int c = 0; c < m; c++) {
        if (esSeguro(v, grafo, colores, c)) {
            colores[v] = c;
            if (colorearGrafo(grafo, m, colores, v + 1))
                return true;
            colores[v] = -1;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Introduce el número de nodos: ";
    cin >> n;

    vector<vector<int>> grafo(n, vector<int>(n));
    cout << "Introduce la matriz de adyacencias:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grafo[i][j];
        }
    }

    int m = n;
    vector<int> colores(n, -1);

    if (!colorearGrafo(grafo, m, colores, 0)) {
        cout << "No es posible asignar colores a los nodos\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "Node: " << i << ", Assigned Color: " << colores[i] << endl;
        }
    }

    return 0;
}
