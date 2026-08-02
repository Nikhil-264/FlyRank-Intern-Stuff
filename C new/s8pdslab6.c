#include <stdio.h>
#include <stdlib.h>

int binarySearch(int a[], int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == mid)
            return mid;

        if (a[mid] < mid)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int identity(int a[], int N)
{
    int index = binarySearch(a, 0, N - 1);
    return index;
}

int main()
{
    int N;

    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int *a = (int *)malloc(N * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sort the array (using any sorting algorithm)
    // ... (e.g., using bubble sort)
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Sorted array in ascending order: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int index = identity(a, N);
    printf("Index i such that a[i] = i: %d\n", index);

    free(a);
    return 0;
}
