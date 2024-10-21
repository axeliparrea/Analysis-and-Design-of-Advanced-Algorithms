//Axel Eduardo Iparrea Ramos A00836682

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printMaze(const vector<vector<int>>& maze) {
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool solveMazeBacktracking(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    int M = maze.size();
    int N = maze[0].size();

    if (x < 0 || x >= M || y < 0 || y >= N || maze[x][y] == 0 || solution[x][y] == 1) {
        return false;
    }

    solution[x][y] = 1;

    if (x == M - 1 && y == N - 1) {
        return true;
    }

    if (solveMazeBacktracking(maze, x + 1, y, solution) || 
        solveMazeBacktracking(maze, x, y + 1, solution) ||
        solveMazeBacktracking(maze, x - 1, y, solution) ||
        solveMazeBacktracking(maze, x, y - 1, solution)) {
        return true;
    }

    solution[x][y] = 0;
    return false;
}

bool branchAndBoundHelper(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    int M = maze.size();
    int N = maze[0].size();

    if (x < 0 || x >= M || y < 0 || y >= N || maze[x][y] == 0 || solution[x][y] == 1) {
        return false;
    }

    solution[x][y] = 1;

    if (x == M - 1 && y == N - 1) {
        return true;
    }

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (auto [dx, dy] : directions) {
        int newX = x + dx;
        int newY = y + dy;
        if (branchAndBoundHelper(maze, newX, newY, solution)) {
            return true;
        }
    }

    solution[x][y] = 0;
    return false;
}

bool solveMazeBranchAndBound(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& solution) {
    return branchAndBoundHelper(maze, x, y, solution);
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> maze(M, vector<int>(N));
    vector<vector<int>> solutionBacktracking(M, vector<int>(N, 0));
    vector<vector<int>> solutionBranchAndBound(M, vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }

    if (solveMazeBacktracking(maze, 0, 0, solutionBacktracking)) {
        printMaze(solutionBacktracking);
    } else {
        cout << "No solution found with backtracking" << endl;
    }

    if (solveMazeBranchAndBound(maze, 0, 0, solutionBranchAndBound)) {
        printMaze(solutionBranchAndBound);
    } else {
        cout << "No solution found with branch and bound" << endl;
    }

    return 0;
}
