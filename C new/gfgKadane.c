// this is so wrong
//Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum
#include <stdio.h>
#include <stdlib.h>
int maxsubarraysum(int array[], int n)
{
    int max_idx = 0, sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (array[i] > array[max_idx])
        {
            max_idx = i;
        }
    }
    if (array[max_idx] < 0)
    {
        return array[max_idx];
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] >= 0)
            {
                sum += array[i];
            }
        }
        return sum;
    }
}
int main()
{
    int n;
    printf("Enter the number of elements in array :");
    scanf("%d", &n);
    printf("Enter the members of array\n");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
    }
    printf("The max sum of the subarray is %d", maxsubarraysum(array, n));
    return 0;
}
