// Axel Iparrea
// Knapsack problem

#include <iostream>
#include <vector>
using namespace std;


int knapsack(int W, const vector<int>& values, const vector<int>& weights, int N) {
    // DP table to store the maximum value for each weight
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i-1] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + values[i-1]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[N][W];
}

int main() {
    cout << "Enter your data" << endl;
    int N; 
    cin >> N;

    vector<int> values(N);  
    vector<int> weights(N); 

    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    int W; 
    cin >> W;

    int maxProfit = knapsack(W, values, weights, N);

    cout << "Output" << endl;
    cout << maxProfit << endl;

    return 0;
}
