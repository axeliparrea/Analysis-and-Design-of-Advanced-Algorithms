/*
Axel Eduardo Iparrea Ramos
Randomized Binary Search

This program implements the Randomized Binary Search Algorithm using the
Las Vegas Randomized Algorithm method to search for an integer in a given set.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

vector<int> splitToVector(const string &input) {
    vector<int> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ',')) {
        result.push_back(stoi(temp));
    }
    return result;
}

int randomizedBinarySearch(const vector<int> &arr, int target, int low, int high) {
    while (low <= high) {
        int mid = low + rand() % (high - low + 1);

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    cout << "Enter the number to search: ";
    int target;
    cin >> target;

    cout << "Enter the set of numbers separated by commas (e.g., 2,3,4,10,40): ";
    string input;
    cin >> input;

    vector<int> arr = splitToVector(input);

    int index = randomizedBinarySearch(arr, target, 0, arr.size() - 1);

    if (index != -1) {
        cout << "The element is present at index: " << index << endl;
    } else {
        cout << "The element is not present in the array" << endl;
    }

    return 0;
}
