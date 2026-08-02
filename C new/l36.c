// array reversal
#include <stdio.h>

int main()
{
    int n, temp;
    
    printf("Enter number of elements in array : ");
    scanf("%d", &n);
    printf("Enter elements of array\n");
    int arr1[n];

    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i + 1);
        scanf("%d", &arr1[i]);
    }
    printf("Your elements are : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    if ((n % 2) == 0)
    {
        for (int i = 0; i < n/2; i++)
        {
            temp = arr1[i];
            arr1[i] = arr1[n - 1 - i];
            arr1[n - 1 - i] = temp;
        }
    }
    else
    {
        for (int i = 0; i < (n-1)/2; i++)
        {
            temp = arr1[i];
            arr1[i] = arr1[n - 1 - i];
            arr1[n - 1 - i] = temp;
        }
    }
    printf("\nReverse array is : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}