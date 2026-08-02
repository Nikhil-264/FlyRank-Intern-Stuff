// r = 4, c = 4
// matrix[][] = {{1, 2, 3, 4},
//            {5, 6, 7, 8},
//            {9, 10, 11, 12},
//            {13, 14, 15,16}}
// Output:
// 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int box[n][n];
    int m = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            box[i][j] = m;
            m++;
        }
    }
    // spiral travesing in 2D array
    int row_start = 0;
    int row_end = n - 1;
    int col_start = 0;
    int col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end)
    {
        // Traverse right
        for (int i = col_start; i <= col_end; i++)
        {
            printf("%d ", box[row_start][i]);
        }
        row_start++;

        // Traverse down
        for (int i = row_start; i <= row_end; i++)
        {
            printf("%d ", box[i][col_end]);
        }
        col_end--;

        // Traverse left
        if (row_start <= row_end)
        {
            for (int i = col_end; i >= col_start; i--)
            {
                printf("%d ", box[row_end][i]);
            }
            row_end--;
        }

        // Traverse up
        if (col_start <= col_end)
        {
            for (int i = row_end; i >= row_start; i--)
            {
                printf("%d ", box[i][col_start]);
            }
            col_start++;
        }
    }

    return 0;
}