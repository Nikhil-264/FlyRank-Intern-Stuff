#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants for game configuration
const int SIZE = 5;    // Size of the board (10x10)
const int MINES = 5;   // Number of mines

// Board representation
vector<vector<char>> board(SIZE, vector<char>(SIZE, '-'));      // Display board
vector<vector<int>> mines(SIZE, vector<int>(SIZE, 0));         // Stores the locations of mines and numbers

// Function to print the board
void printBoard(const vector<vector<char>>& board) {
    cout << "  ";
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to place mines randomly on the board
void placeMines() {
    srand(time(0));
    int count = 0;
    while (count < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (mines[x][y] == 0) {
            mines[x][y] = -1;  // -1 represents a mine
            count++;
        }
    }
}

// Function to calculate numbers around mines
void calculateNumbers() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (mines[i][j] == -1) continue;
            int count = 0;
            for (int di = -1; di <= 1; ++di) {
                for (int dj = -1; dj <= 1; ++dj) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < SIZE && nj >= 0 && nj < SIZE && mines[ni][nj] == -1) {
                        count++;
                    }
                }
            }
            mines[i][j] = count;
        }
    }
}

// Function to uncover a cell
bool uncover(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != '-') {
        return true;
    }

    if (mines[x][y] == -1) {
        return false;  // Hit a mine, game over
    }

    board[x][y] = '0' + mines[x][y];

    // If the cell is empty, uncover adjacent cells
    if (mines[x][y] == 0) {
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                uncover(x + di, y + dj);
            }
        }
    }
    return true;
}

// Function to check if the player has won
bool isWin() {
    int count = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '-' && mines[i][j] != -1) {
                return false;
            }
            if (board[i][j] != '-' && mines[i][j] == -1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    placeMines();
    calculateNumbers();

    int x, y;
    bool alive = true;

    cout << "Welcome to Minesweeper!" << endl;

    while (alive) {
        printBoard(board);
        cout << "Enter coordinates to uncover (row and column): ";
        cin >> x >> y;

        if (!uncover(x, y)) {
            alive = false;
            cout << "Game Over! You hit a mine!" << endl;
        } else if (isWin()) {
            cout << "Congratulations! You won!" << endl;
            break;
        }
    }

    cout << "Final board:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (mines[i][j] == -1) {
                board[i][j] = '*';
            } else {
                board[i][j] = '0' + mines[i][j];
            }
        }
    }
    printBoard(board);
    return 0;
}   
