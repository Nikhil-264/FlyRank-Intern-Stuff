#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, m, k;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= 109; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (arr[j][k] == i)
                    count++;
            }
        }
        if (count >= k)
            printf("%d ", i);
    }

    return 0;
}