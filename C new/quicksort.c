#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int *A, int lb, int ub)
{
    int pivot = A[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (A[start] <= pivot && start < ub)
            start++;
        while (A[end] > pivot)
            end--;
        if (start < end)
            swap(&A[start], &A[end]);
    }
    swap(&A[lb], &A[end]);
    return end;
}

void Quicksort(int *A, int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(A, lb, ub);
        Quicksort(A, lb, loc - 1);
        Quicksort(A, loc + 1, ub);
    }
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("Before sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    Quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}