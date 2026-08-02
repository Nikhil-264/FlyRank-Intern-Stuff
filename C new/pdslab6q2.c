// Name : NIkhil Mahindrakar
// Roll no : 22CH10036
// Section   :  6
// Assignment  : 6
// File : part 2
// Description   : Searching and Sorting
// Date   : 19 May 2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printarray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(array + i));
    }
    printf("\n");
}
void bubblesortascending(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void bubblesortdescending(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j + 1] > array[j])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int *mergeArr(int A[], int B[], int n)
{
    int *C = (int *)malloc(2 * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        C[2 * i + 1] = *(B + i);
        C[2 * i] = *(A + i);
    }
    return C;
}
int *InitArray(int n, int *A, int min, int max)
{
    A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        A[i] = min + rand() % (max);
    }
    return A;
}
void Linearsearch(int key, int C[], int n)
{
    int comparisons = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        if (*(C + i) == key)
        {
            printf("%d is found at index %d\n", key, i);
            break;
        }
        if (*(C + i) != key)
            comparisons++;
    }
    if (comparisons < 2 * n - 1)
        printf("The number of comparisons are %d", comparisons);
    else
        printf("Element not found ...\n");
}
int Smartsearch(int arr[], int size, int element)
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

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int *A = InitArray(n, A, 1, n);
    int *B = InitArray(n, B, n * n, n * n + 2 * n);

    bubblesortascending(A, n);
    bubblesortdescending(B, n);

    int *C = mergeArr(A, B, n);
    // printarray(B, n);
    printarray(C, 2 * n);
    int key;
    printf("Enter key : ");
    scanf("%d", &key);

    int k;
    printf("Type 1 for linear search \nType 2 forsmart search\n");
    scanf("%d", &k);
    int ans;
    switch (k)
    {
    case 1:
        Linearsearch(key, C, 2 * n);
        break;

    case 2:
        ans = Smartsearch(C, 2 * n, key);
        printf("Key found at index %d\n", ans);
        break;
    }

    return 0;
}