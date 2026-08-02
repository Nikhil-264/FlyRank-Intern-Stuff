#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter arraylenght : ");
    scanf("%d", &n);
    int *a;
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    int find;
    printf("Enter element to be searched : ");
    scanf("%d", &find);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == find)
        {
            printf("Element found\n");
            break;
        }
        else if (a[i] != find && i == n-1)
        {
            printf("Element not found\n");
            break;
        }
    }

    return 0;
}