#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> suffixArrayNaive(string S) {
    int n = S.length() + 1;
    vector<string> sa;
    vector<int> A(n);
    S = S + "$";
    for (int i = 0; i < n; i++)
        sa.push_back(S.substr(n - i - 1, i + 1));
    sort(sa.begin(), sa.end());
    for (int i = 0; i < n; i++)
        A[i] = n - sa[i].size() + 1;
    return A;
}

int main() {
    string input;
    cout << "Ingrese una cadena: ";
    getline(cin, input);  
    
    vector<int> suffixArray = suffixArrayNaive(input);
    
    cout << "Posiciones originales en el orden de subcadenas ordenadas:" << endl;
    for (int pos : suffixArray) {
        cout << pos << endl;
    }

    return 0;
}
