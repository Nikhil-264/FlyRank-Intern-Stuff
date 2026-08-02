#include <stdio.h>

int main()
{
    int n, temp;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr1[n];
    printf("\nEnter elements of array: ");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Your elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr1[i];
        arr1[i] = arr1[n - 1 - i];
        arr1[n - 1 - i] = temp;
    }

    printf("\nReverse array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}
