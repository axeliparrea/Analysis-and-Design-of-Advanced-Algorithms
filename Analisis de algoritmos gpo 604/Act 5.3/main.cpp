#include <iostream>
#include <vector>

using namespace std;

bool esSeguro(vector<vector<int>>& tablero, int fila, int columna, int N) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i][columna] == 1) {
            return false;
        }
    }

    for (int i = fila, j = columna; i >= 0 && j >= 0; i--, j--) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    for (int i = fila, j = columna; i >= 0 && j < N; i--, j++) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool resolverNReinas(vector<vector<int>>& tablero, int fila, int N) {
    if (fila >= N) {
        return true;
    }

    for (int col = 0; col < N; col++) {
        if (esSeguro(tablero, fila, col, N)) {
            tablero[fila][col] = 1;

            if (resolverNReinas(tablero, fila + 1, N)) {
                return true;
            }

            tablero[fila][col] = 0;
        }
    }

    return false;
}

void nQueens(int N) {
    vector<vector<int>> tablero(N, vector<int>(N, 0));

    if (resolverNReinas(tablero, 0, N)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No hay solución para N = " << N << endl;
    }
}

int main() {
    int N;
    cout << "Ingrese el valor de N (4 u 8): ";
    cin >> N;

    if (N == 4 || N == 8) {
        nQueens(N);
    } else {
        cout << "Por favor, ingrese un valor válido (4 u 8)." << endl;
    }

    return 0;
}
