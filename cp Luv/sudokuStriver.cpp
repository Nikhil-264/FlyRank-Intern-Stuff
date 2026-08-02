#include <bits/stdc++.h>
using namespace std;
#define N 9;

class solutionSudoku{
public:
    bool isSafe(vector<vector<int>> & grid, int row, int col, int num){
        for (int i = 0; i < 9; i++) {
            if(grid[row][i] == num){
                return false;
            }
        }

        for (int i = 0; i < 9; i++) {
            if(grid[i][col] == num){
                return false;
            }
        }

        int minRow = row - row % 3;
        int minCol = col - col % 3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(grid[i + minRow][j + minCol] == num){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool solveSudoku(vector<vector<int>> & grid){
        int row = 0, col = 0;
        bool forBreak = true;
        for(row = 0; row < 9; row++){
            for(col = 0; col < 9; col++){
                if(grid[row][col] == 0){
                    forBreak = false;
                    break;
                }
            }
            if(forBreak == false){
                break;  
            }
        }
        
        if(forBreak) return true;

        for(int num = 1; num <= 9; num++){
            if(isSafe(grid, row, col, num)){
                grid[row][col] = num;
                if(solveSudoku(grid)){
                    return true;
                }
                grid[row][col] = 0;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> grid = {
        {0, 0, 8, 7, 0, 0, 0, 9, 0},
        {9, 5, 0, 0, 0, 6, 0, 0, 8},
        {0, 0, 0, 8, 0, 0, 5, 0, 6},
        {0, 0, 9, 6, 0, 0, 8, 0, 1},
        {0, 8, 0, 4, 1, 0, 0, 0, 0},
        {0, 1, 5, 0, 0, 9, 0, 0, 0},
        {8, 0, 7, 0, 6, 4, 0, 0, 0},
        {0, 9, 4, 1, 2, 3, 0, 8, 7},
        {1, 6, 3, 0, 0, 8, 0, 5, 4}
    };
    solutionSudoku sd;
    if(sd.solveSudoku(grid)){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    else cout << "NOT SOLVABLE \n";

    return 0;
}