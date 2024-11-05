#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> s;
    for (int ast : asteroids) {
        if (ast > 0) {
            s.push(ast);
        } else {
            while (!s.empty() && s.top() > 0) {
                if (s.top() < -ast) {
                    s.pop();
                } else if (s.top() == -ast) {
                    s.pop();
                    ast = 0;
                } else {
                    ast = 0;
                    break;
                }
            }
            if (ast != 0) {
                s.push(ast);
            }
        }
    }
    vector<int> result(s.size());
    int i = result.size() - 1;
    while (!s.empty()) {
        result[i--] = s.top();
        s.pop();
    }
    return result;
}

int main() {
    vector<int> asteroids;
    string input;

    cout << "Ingrese los datos separados por espacios ejemplo: 10 2 -5: ";
    getline(cin, input);

    stringstream ss(input);
    int value;
    while (ss >> value) {
        asteroids.push_back(value);
    }
    vector<int> result = asteroidCollision(asteroids);
    cout << "Estado final de los asteroides: ";
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i];
            if (i < result.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
