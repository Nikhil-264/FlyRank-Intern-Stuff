// mirroring character array 2D
#include <stdio.h>
#include <stdlib.h>
void mirror(int n, int grid[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = grid[i][j];
            grid[i][j] = grid[i][n - j - 1];
            grid[i][n - j - 1] = temp;
        }
    }
}
int main()
{
    int n;
    printf("Enter array dimention :");
    scanf("%d", &n);
    int grid[n][n];
    printf("Enter grid elements : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
    mirror(n, grid);
    printf("Mirrored grid : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}