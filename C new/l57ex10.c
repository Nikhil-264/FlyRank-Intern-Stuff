#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r1, r2, c1, c2;
    while (1)
    {

        printf("Enter number of rows and number of columns in matrix 1\n");
        scanf("%d %d", &r1, &c1);
        printf("Enter number of rows and number of columns in matrix 2\n");
        scanf("%d %d", &r2, &c2);
        if (r2 == c1)
        {
            break;
        }
        else
        {
            printf("to multiply matrices r1 and c2 should be equal enter again\n");
        }
    }
    int m1[r1][c1];
    int m2[r2][c2];
    printf("Enter the elements from left to right and top to bottom in matrix\n");
    printf("Enter the elements of the matrix 1 \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            scanf("%d", &m1[i][j]);
        }
    }
    printf("Matrix m1 is \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d  ", m1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Enter the elements of the matrix 2 \n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &m2[i][j]);
        }
    }
    printf("Matrix m2 is \n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d  ", m2[i][j]);
        }
        printf("\n");
    }
    int multi[r1][c2];
    printf("multiplication of the given matrices is \n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int sum = 0;
            for (int k = 0; k < c1; k++)
            {
                sum += m1[i][k] * m2[k][j];
            }
            multi[i][j] = sum;
        }
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d  ", multi[i][j]);
        }
        printf("\n");
    }

    return 0;
}