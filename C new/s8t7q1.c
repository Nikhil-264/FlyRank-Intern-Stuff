// Identity. You are given an array a[] of N distinct integers (positive or negative) in ascending order. Write
// a C function, identity(), with suitable arguments that returns an index i such that a[i] = i if such
// an index exists, and -1 otherwise. You must use binary search for this purpose.
// In the main(), read N, then read the N integers into a dynamically allocated array a[], then sort and print
// them in ascending order using any algorithm, and then call the function, identity(), and print its return
// value.
#include <stdio.h>
#include <stdlib.h>

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

int binarysearch(int arr[], int size, int element)
{
    // time comlexity if O(log n) more efficient
    // while time complexity of linear search is O(n)
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

void identity(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = binarysearch(arr, n, i);
        if (index == -1)
            printf("%d is not in the array\n", i);
        else if (i == index)
            printf("%d at %d\n", i, index);
    }
}
int main()
{
    int n;
    printf("ENter number : ");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Enter a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    bubblesort(a, n);
    printf("after sorting we get the following result\n");
    identity(a, n);

    return 0;
}