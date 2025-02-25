#include <iostream>
using namespace std;

const int N = 6;
const int movesX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int movesY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] < 10 ? " " : "") << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y, int board[N][N]) {
    return x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1;
}

bool solveKnightTour(int x, int y, int moveCount, int board[N][N]) {
    if (moveCount == N * N) return true;

    for (int i = 0; i < 8; i++) {
        int newX = x + movesX[i];
        int newY = y + movesY[i];

        if (isValid(newX, newY, board)) {
            board[newX][newY] = moveCount;
            if (solveKnightTour(newX, newY, moveCount + 1, board)) {
                return true;
            }
            board[newX][newY] = -1; 
        }
    }
    return false;
}

int main() {
    setlocale(LC_ALL, "");
    int startX, startY;
    cout << "Введите координаты начальной клетки (от 0 до 5) через пробел: ";
    cin >> startX >> startY;

    int board[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = -1;
        }
    }
    board[startX][startY] = 0;

    if (solveKnightTour(startX, startY, 1, board)) {
        cout << "Решение найдено:\n";
        printBoard(board);
    }
    else {
        cout << "Решение не найдено." << endl;
    }
    return 0;
}

