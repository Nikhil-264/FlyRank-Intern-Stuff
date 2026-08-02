#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

// Function to set the cursor position
void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function to hide the cursor
void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

// Function to draw the maze
void drawMaze(char maze[10][10], int playerX, int playerY) {
    setCursorPosition(0, 0);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerY && j == playerX) {
                cout << 'P'; // Player position
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }
}

int main() {
    char maze[10][10] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', ' ', '#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    int playerX = 1, playerY = 1;
    char input;

    hideCursor();
    drawMaze(maze, playerX, playerY);

    while (true) {
        if (_kbhit()) {
            input = _getch();
            int newX = playerX;
            int newY = playerY;

            switch (input) {
                case 'w': newY--; break;
                case 's': newY++; break;
                case 'a': newX--; break;
                case 'd': newX++; break;
            }

            // Check for collisions with walls
            if (maze[newY][newX] != '#') {
                playerX = newX;
                playerY = newY;
            }

            drawMaze(maze, playerX, playerY);
        }
    }

    return 0;
}
