#include <iostream>
#include <vector>
using namespace std;

int encontrarNumeroFaltante(const vector<int>& nums) {
    int n = nums.size();
    int suma_esperada = n * (n + 1) / 2;
    int suma_actual = 0;

    for (int num : nums) {
        suma_actual += num;
    }

    return suma_esperada - suma_actual;
}

int main() {
    int n;
    cout << "tamaño matriz: ";
    cin >> n;

    vector<int> nums(n);
    cout << "elementos de la matriz separados ejemplo: 3 0 1: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int numero_faltante = encontrarNumeroFaltante(nums);
    cout << "número faltante es: " << numero_faltante << endl;

    return 0;
}
