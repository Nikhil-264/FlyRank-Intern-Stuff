// tic tac toe game
#include <stdio.h>
#include <stdlib.h>

void drawboard(char board[][3])
{
    printf("-------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int IfWin(char board[][3], char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[2][0] == player && board[1][1] == player && board[0][2] == player)
        return 1;
    else
        return 0;
}
int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    char currentPlayer = 'X';
    int x, y;
    int moves = 0;
    drawboard(board);
    while (1)
    {
        printf("Player %c Turn", currentPlayer);

        printf("Enter co-ordinates you want (0 <= x , y <= 2 ): ");
        scanf("%d %d", &x, &y);
        moves++;
        if (board[x][y] == ' ')
            board[x][y] = currentPlayer;
        else
        {
            printf("Wrong input slot already used! ");
            continue;
        }
        drawboard(board);

        // IfWin(board, currentPlayer);
        if (IfWin(board, currentPlayer))
        {
            printf("Player %c Wins", currentPlayer);
            break;
        }
        if (moves == 9)
        {
            printf("Game is Tie !");
            break;
        }

        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
    }
    return 0;
}