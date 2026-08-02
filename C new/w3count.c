#include <stdio.h>
int main()
{
    int n, count, array[n], counted[n];

    printf("Enter the number of elements in array :");
    scanf("%d", &n);

    printf("Enter the members of array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
        counted[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (counted[i] == 1)
            continue;

        count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (array[i] == array[j])
            {
                count++;
                counted[j] = 1;
            }
        }

        printf("%d appeared %d times\n", array[i], count);
    }

    return 0;
}