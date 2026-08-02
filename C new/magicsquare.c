#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d", &n);
    int box[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            box[i][j] = 0;
        }
    }
    int m = 1;
    int i = n - 1, j = n / 2;
    box[i][j] = m;
    int tempi, tempj;
    while (m < n * n)
    {
        m++;
        if (i < n - 1 && j < n - 1)
        {
            // printf("1  %d\n", m);
            tempi = i;
            tempj = j;
            i++;
            j++;
            if (box[i][j] == 0)
                box[i][j] = m;
            else if (tempi != 0)
            {
                i = tempi - 1;
                j = tempj;
                box[i][j] = m;
            }
            else
            {
                i = n - 1;
                j = tempj;
                box[i][j] = m;
            }
            continue;
        }
        if (i == n - 1 && j < n - 1)
        {
            // printf("2  %d\n", m);
            tempi = i;
            tempj = j;
            j++;
            i = 0;
            if (box[i][j] == 0)
                box[i][j] = m;
            else if (tempi != 0)
            {
                i = tempi - 1;
                j = tempj;
                box[i][j] = m;
            }
            else
            {
                i = n - 1;
                j = tempj;
                box[i][j] = m;
            }
            continue;
        }
        if (j == n - 1 && i < n - 1)
        {
            // printf("3  %d\n", m);
            tempi = i;
            tempj = j;
            i++;
            j = 0;
            if (box[i][j] == 0)
                box[i][j] = m;
            else if (tempi != 0)
            {
                i = tempi - 1;
                j = tempj;
                box[i][j] = m;
            }
            else
            {
                i = n - 1;
                j = tempj;
                box[i][j] = m;
            }
            continue;
        }
        if (i == n - 1 && j == n - 1)
        {
            // printf("4  %d\n", m);
            tempi = i;
            tempj = j;
            i = 0;
            j = 0;
            if (box[i][j] == 0)
                box[i][j] = m;
            else if (tempi != 0)
            {
                i = tempi - 1;
                j = tempj;
                box[i][j] = m;
            }
            else
            {
                i = n - 1;
                j = tempj;
                box[i][j] = m;
            }
            continue;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", box[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += box[i][0];
        sum2 += box[i][2];
    }
    printf("%d %d ", sum1, sum2);
    sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += box[0][i];
        sum2 += box[2][i];
    }
    printf("%d %d ", sum1, sum2);
    sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += box[i][i];
    }
    printf("%d ", sum1);
    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--)
    {
        sum2 += box[i][j];
    }
    printf("%d ", sum2);

    return 0;
}