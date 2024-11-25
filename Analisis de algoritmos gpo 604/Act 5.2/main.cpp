#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int MAX_HATS = 100;

vector<int> hatOwners[MAX_HATS + 1];
int n;
vector<vector<int>> solutions;

int countArrangements(int hat, int mask, vector<int>& current) {
    if (mask == (1 << n) - 1) {
        solutions.push_back(current);
        return 1;
    }
    if (hat > MAX_HATS) return 0;

    int ways = countArrangements(hat + 1, mask, current);

    for (int person : hatOwners[hat]) {
        if (!(mask & (1 << person))) {
            current[person] = hat;
            ways += countArrangements(hat + 1, mask | (1 << person), current);
            current[person] = 0;
        }
    }

    return ways;
}

int main() {
    cout << "Enter the number of people: ";
    cin >> n;
    cin.ignore();

    cout << "Enter the hat collections for each person:" << endl;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int hat;
        while (iss >> hat) {
            hatOwners[hat].push_back(i);
        }
    }

    vector<int> current(n, 0);
    int totalArrangements = countArrangements(1, 0, current);

    cout << "Total unique arrangements: " << totalArrangements << endl;

    for (const auto& solution : solutions) {
        cout << "(";
        for (int i = 0; i < solution.size(); i++) {
            cout << solution[i];
            if (i != solution.size() - 1) cout << ", ";
        }
        cout << ")" << endl;
    }

    return 0;
}
