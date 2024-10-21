//Axel Eduardo Iparrea Ramos A00836682
//Act 1.1

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<double> L(n1);
    vector<double> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int N;
    cout << "Ingresa los numeros que vas a teclear: ";
    cin >> N;

    vector<double> values(N);
    cout << "Ingrese " << N << " uno por linea:" << endl;
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    mergeSort(values, 0, N - 1);

    cout << "Valores ordenados de mayor a menor: " << endl;
    for (const auto& value : values) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
