#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Función para imprimir 
void imprimirResultado(const vector<int>& denominaciones, const vector<int>& cantidad) {
    for (int i = 0; i < denominaciones.size(); ++i) {
        cout << cantidad[i] << " moneda(s) de " << denominaciones[i] << endl;
    }
}

// Función de programación dinámica para encontrar el cambio mínimo
vector<int> cambioDinamico(const vector<int>& denominaciones, int cambio) {
    int N = denominaciones.size();
    vector<int> dp(cambio + 1, INT_MAX);
    vector<int> monedas(cambio + 1, -1);
    dp[0] = 0; // Cero monedas para el cambio 0

    for (int i = 0; i < N; ++i) {
        for (int j = denominaciones[i]; j <= cambio; ++j) {
            if (dp[j - denominaciones[i]] != INT_MAX && dp[j] > dp[j - denominaciones[i]] + 1) {
                dp[j] = dp[j - denominaciones[i]] + 1;
                monedas[j] = i;
            }
        }
    }

    vector<int> resultado(N, 0);
    if (dp[cambio] == INT_MAX) {
        cout << "No es posible dar el cambio con las denominaciones dadas" << endl;
        return resultado;
    }

    int temp = cambio;
    while (temp > 0) {
        int idx = monedas[temp];
        resultado[idx]++;
        temp -= denominaciones[idx];
    }

    return resultado;
}


int main() {
    int N;
    cout << "Ingrese el numero de denominaciones de monedas: ";
    cin >> N;

    vector<int> denominaciones(N);
    cout << "Ingrese las denominaciones de las monedas, una por linea:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> denominaciones[i];
    }

    int P, Q;
    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese la cantidad pagada: ";
    cin >> Q;

    int cambio = Q - P;

    if (cambio < 0) {
        cout << "Falta dinero " << endl;
        return 0;
    } else if (cambio == 0) {
        cout << "No hay cambio por dar" << endl;
        return 0;
    }

    cout << "Usando Programación Dinamica:" << endl;
    vector<int> resultadoDinamico = cambioDinamico(denominaciones, cambio);
    imprimirResultado(denominaciones, resultadoDinamico);


    return 0;
}
