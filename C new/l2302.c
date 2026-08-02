// arrays
#include <stdio.h>
int main()
{
    int n;
    
    printf("enter the number of elements in array\n");
    scanf("%d", &n);
    printf("print elements in array\n");
    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("element %d :", i);
        scanf("%d", &array[i]);
    }
    printf("elements in given order are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }
    printf("elements in reverse order are:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}