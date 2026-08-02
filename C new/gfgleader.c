#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of elements in array :");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i; j < n; j++)
        {
            if (array[i] < array[j])

                break;

            if (array[i] >= array[j])

                flag++;

            if (flag == n - i)
            {
                printf("%d ", array[i]);
            }
        }
    }

    return 0;
}