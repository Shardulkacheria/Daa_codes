//EXP 10: N-Queen's Problem
#include <iostream>
#include <cmath>
#define MAX 10 // Define a maximum value for N
using namespace std;

int board[MAX]; // to store the position of queens in each row
int N; // Size of the board

// printing the output
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// checking if the placement is safe or not
bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// solving n queens problem
bool solveNQueens(int row) {
    if (row == N) {
        printSolution();  // printing solution
        return true;
    }

    bool foundSolution = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            foundSolution = solveNQueens(row + 1) || foundSolution;
        }
    }
    return foundSolution;
}

int main() {
    cout << "Enter the value of N: ";  // taking input for the board size
    cin >> N;
    if (N >= MAX) {  // value exceeds the MAX value
        cout << "N is too large. Please enter a value less than " << MAX << "." << endl;
        return 0;
    }
    if (!solveNQueens(0)) {   //min value of N is 1
        cout << "No solution exists for N = " << N << endl;
    }

    return 0;
}



