#include <stdio.h>
#include <stdlib.h>
void adjoint(int n , int matrix[][n])
{
}
int main()
{
    int n;
    printf("Enter array dimention :");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter matrix elements \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}