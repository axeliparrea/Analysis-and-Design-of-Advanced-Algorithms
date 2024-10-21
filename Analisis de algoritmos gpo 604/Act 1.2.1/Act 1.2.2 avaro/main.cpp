//Axel Eduardo Iparrea Ramos A00836682
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//algoritmo avaro
vector<int> cambioAvaro(int P, int Q, const vector<int>& monedas) {
    int cambio = Q - P;
    int n = monedas.size();
    vector<int> resultado(n, 0);
    
    for (int i = 0; i < n; ++i) {
        if (monedas[i] <= cambio) {
            resultado[i] = cambio / monedas[i];
            cambio %= monedas[i];
        }
    }
    
    return resultado;
}

int main() {
    int N;
    cout << "Ingrese el número de denominaciones de monedas: ";
    cin >> N;
    
    vector<int> monedas(N);
    cout << "Ingrese las denominaciones de las monedas, una por línea:\n";
    for (int i = 0; i < N; ++i) {
        cin >> monedas[i];
    }
    
    sort(monedas.rbegin(), monedas.rend()); 
    
    int P, Q;
    cout << "Ingrese el precio del producto: ";
    cin >> P;
    cout << "Ingrese la cantidad pagada: ";
    cin >> Q;
    
    if (Q < P) {
        cout << "Falta dinero para pagar ese producto\n";
        return 0;
    }
    
    if (Q == P) {
        cout << "No hay cambio por dar\n";
        return 0;
    }

    cout << "\nSolución usando algoritmo avaro:\n";
    vector<int> resultadoAvaro = cambioAvaro(P, Q, monedas);
    for (int i = 0; i < N; ++i) {
        cout << resultadoAvaro[i] << " moneda(s) de " << monedas[i] << endl;
    }
    
    return 0;
}
