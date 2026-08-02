#include <iostream>
#include <vector>

#define N 9

using namespace std;

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if a number can be placed in a given cell
bool isSafe(const vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    bool isEmpty = true;

    // Find an empty cell
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // No empty cell left, puzzle is solved
    if (isEmpty) {
        return true;
    }

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0; // Undo & try again
        }
    }

    return false;
}

int main() {
    // Example Sudoku grid with empty cells marked as 0
    // vector<vector<int>> grid = {
    //     {4, 0, 0, 0, 0, 0, 8, 7, 0},
    //     {0, 0, 0, 1, 5, 0, 0, 0, 0},
    //     {0, 0, 6, 0, 7, 8, 0, 0, 0},
    //     {0, 0, 0, 8, 0, 3, 0, 6, 0},
    //     {2, 9, 5, 6, 4, 0, 0, 0, 3},
    //     {0, 0, 0, 0, 0, 0, 0, 0, 0},
    //     {7, 0, 0, 4, 0, 0, 0, 0, 0},
    //     {0, 4, 8, 0, 3, 0, 6, 0, 9},
    //     {0, 6, 0, 0, 8, 0, 7, 5, 0}
    // };

    vector<vector<int>> grid = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};


    // vector<vector<int>> grid(9, vector<int> (9, 0));
    // grid[0][0] = 1;

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
