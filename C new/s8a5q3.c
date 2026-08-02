#include <stdio.h>
#include <stdlib.h>
void droptiles(int n, int k, int tiles[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tiles[0][j] == k)
            {
                tiles[0][j] = 69;
            }

            if (tiles[i][j] == k)
            {
                for (int l = i; l > 0; l--)
                {
                    tiles[l][j] = tiles[l - 1][j];
                }
                tiles[0][j] = 69;
            }
        }
    }
}
int main()
{
    int n, k;
    printf("Enter array dimention :");
    scanf("%d", &n);
    int tiles[n][n];
    printf("Enter tiles except 69 \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tiles[i][j]);
        }
    }
    printf("Enter element to removed : ");
    scanf("%d", &k);
    droptiles(n, k, tiles);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tiles[i][j] == 69)
                printf("   ");
            else
            printf("%d ", tiles[i][j]);
        }
        printf("\n");
    }

    return 0;
}
