//A00836682 Axel Eduardo Iparrea Ramos 

#include <iostream>
#include <vector>
using namespace std;

vector<int> recorrerMatriz(const vector<vector<int>>& matriz) {
    vector<int> salida;
    int numFilas = matriz.size();
    int numColumnas = matriz[0].size();
    int left = 0, right = numColumnas - 1, top = 0, bottom = numFilas - 1;

    while (left <= right && top <= bottom) {
        // izquierda a derecha
        for (int i = left; i <= right; ++i) {
            salida.push_back(matriz[top][i]);
        }
        ++top; 

        // arriba a abajo
        for (int i = top; i <= bottom; ++i) {
            salida.push_back(matriz[i][right]);
        }
        --right;
        if (top <= bottom) {
            // derecha a izquierda
            for (int i = right; i >= left; --i) {
                salida.push_back(matriz[bottom][i]);
            }
            --bottom;
        }
        if (left <= right) {
            // abajo a arriba
            for (int i = bottom; i >= top; --i) {
                salida.push_back(matriz[i][left]);
            }
            ++left;
        }
    }
    return salida;
}

int main() {
    // Ejemplo 1
    vector<vector<int>> matriz1 = {
        {1, 2, 3},
        {4, 5, 6},
        {9, 8, 10}
    };
    vector<int> salida1 = recorrerMatriz(matriz1);
    cout << "Salida Ejemplo 1: ";
    for (int num : salida1) {
        cout << num << " ";
    }
    cout << endl;

    // Ejemplo 2
    vector<vector<int>> matriz2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> salida2 = recorrerMatriz(matriz2);
    cout << "Salida Ejemplo 2: ";
    for (int num : salida2) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}