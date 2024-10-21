#include <iostream>
#include <string>

using namespace std;

long long prhf(const string& S) {
    int n = S.length();
    int p = 31;
    int m = 1000000000 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    
    for (int i = 0; i < n; i++) {
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    
    return valorHash;
}

int main() {
    cout << "Dame la cadena que quieres hashear: ";
    string input;
    getline(cin, input);

    long long hashValue = prhf(input);
    cout << hashValue << endl;

    return 0;
}
