#include <stdio.h>
#include <stdlib.h>

void merge(int A[], int mid, int low, int high)
{
    int i, j, k;
    int B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (high + low) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

void print_array(int *array, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("element %d = ", i);
        scanf("%d", &array[i]);
    }
    printf("The array is : ");
    print_array(array, n);
    mergesort(array, 0, n - 1);
    printf("The sorted array is : ");
    print_array(array, n);

    return 0;
}