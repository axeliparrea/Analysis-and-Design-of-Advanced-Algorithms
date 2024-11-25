/*
Axel Eduardo Iparrea Ramos

Knight's Tour using Backtracking in C++
This program solves the Knight's Tour problem, where a knight must visit every cell on an 
N×N chessboard exactly once following chess movement rules. It uses the backtracking algorithm 
to find and display the order of the knight's moves.
*/


#include <iostream>
#include <vector>
using namespace std;

const int N_MAX = 8;
int board[N_MAX][N_MAX];

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int N) {
    return (x >= 0 && y >= 0 && x < N && y < N && board[x][y] == -1);
}

bool solveKnightTour(int x, int y, int moveCount, int N) {
    if (moveCount == N * N) return true;

    for (int i = 0; i < 8; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValid(nextX, nextY, N)) {
            board[nextX][nextY] = moveCount;
            if (solveKnightTour(nextX, nextY, moveCount + 1, N)) {
                return true;
            }
            board[nextX][nextY] = -1;
        }
    }
    return false;
}

void knightTour(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }

    board[0][0] = 0;

    if (solveKnightTour(0, 0, 1, N)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found for a " << N << "x" << N << " board." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the board size (N): ";
    cin >> N;

    if (N > 1 && N <= N_MAX) {
        knightTour(N);
    } else {
        cout << "The board size must be greater than 1 and less than or equal to " << N_MAX << "." << endl;
    }

    return 0;
}
