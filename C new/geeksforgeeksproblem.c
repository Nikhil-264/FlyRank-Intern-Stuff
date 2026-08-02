// You are given an array A of size N. Let us denote S as the sum of all integers present in the array. Among all integers present in the array, find the minimum integer X such that S ≤ N*X
#include <stdio.h>
int arraysum(int *array, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += array[i];
    }
    return sum;
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int main()
{
    int n, sum;
    printf("ENter the number of elemnts in array : ");
    scanf("%d", &n);
    printf("Enter elements of the array\n");
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &ar[i]);
    }
    sum = arraysum(ar,n);
    printf("sum is %d\n", sum);
    bubblesort(ar, n);
    printf("The sorted array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        if (sum <= n * ar[i])
        {
            printf("Smallest member of the array to satisfy given condition is %d", ar[i]);
            break;
        }
    }

    return 0;
}