// Name : NIkhil Mahindrakar
// Roll no : 22CH10036
// Section   :  6
// Assignment  : 6
// File : part 1
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

void bubblesort(int array[], int n)
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
int mLargest(int array[], int m, int n)
{
    int m_largest;
    bubblesort(array, n);
    m_largest = array[n - m];
    printf("mth largest element is %d \n", m_largest);
}

void distinct(int arra[], int n, int m)
{
    int *counted = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        counted[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arra[j] == arra[i])
            {
                counted[j]++;
            }
        }
    }
    int *B = (int *)malloc(n * sizeof(int));
    int j = 0;
    int multi = 0;
    for (int i = 0; i < n; i++)
    {
        if (counted[i] == 1)
        {
            B[j] = arra[i];
            j++;
        }
        if (counted[i] > 1)
        {
            multi++;
        }
    }
    n = n - multi;
    B = (int *)realloc(B, n * sizeof(int));
    // printarray(B, n);
    bubblesort(B, n);
    mLargest(B, m, n);
}

int main()
{
    int m, n;
    printf("Enter m and n such that m<=n :\n");
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter m : ");
    scanf("%d", &m);
    while (1)
    {
        if (m <= n)
        {
            break;
        }
        else
        {
            printf("Enter n ad m again :");
            printf("Enter n : ");
            scanf("%d", &n);
            printf("Enter m : ");
            scanf("%d", &m);
        }
    }
    int *arr = (int *)malloc(n * (sizeof(int)));
    int i;
    for (i = 0; i < n; i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &arr[i]);
    }
    // printarray(arr, n);
    // bubblesort(arr, n);
    // printarray(arr, n);
    // mLargest(arr, m, n);
    distinct(arr, n, m);

    return 0;
}
