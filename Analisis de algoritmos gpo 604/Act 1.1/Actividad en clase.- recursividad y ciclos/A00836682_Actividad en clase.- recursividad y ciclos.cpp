//Axel Eduardo Iparrea Ramos A00836682

#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

long long combinaciones(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    // Punto 1: Calcular el factorial de un número
    int n;
    cout << "Ingrese un número para calcular su factorial: ";
    cin >> n;

    long long resultadoFactorial = factorial(n);
    cout << "El factorial de " << n << " es " << resultadoFactorial << endl;

    // Punto 2: Calcular las combinaciones de 2 ingredientes de un conjunto de 4
    int totalIngredientes = 4;
    int ingredientesSeleccionados = 2;

    long long formas = combinaciones(totalIngredientes, ingredientesSeleccionados);
    cout << "El chef puede preparar la ensalada de " << formas << " formas usando solo 2 ingredientes." << endl;

    // Listar las combinaciones de ingredientes
    string ingredientes[] = {"tomate", "zanahoria", "papa", "brócoli"};
    
    cout << "\nFormas de preparar la ensalada usando solo 2 ingredientes:\n";
    for (int i = 0; i < totalIngredientes; ++i) {
        for (int j = i + 1; j < totalIngredientes; ++j) {
            cout << ingredientes[i] << " y " << ingredientes[j] << endl;
        }
    }

    return 0;
}
