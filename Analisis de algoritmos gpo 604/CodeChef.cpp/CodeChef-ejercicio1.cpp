#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void rotateImage(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n;
    cout << "Ingresa el tamaño de la matriz (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Ingresa los elementos de la matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    rotateImage(matrix);

    cout << "Matriz rotada 90 grados en sentido de las agujas del reloj:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}