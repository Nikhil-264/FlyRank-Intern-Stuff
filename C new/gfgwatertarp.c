// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.

// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10
// Explanation:

// Example 2:

// Input:
// N = 4
// arr[] = {7,4,0,9}
// Output:
// 10
// Explanation:
// Water trapped by above
// block of height 4 is 3 units and above
// block of height 0 is 7 units. So, the
// total unit of water trapped is 10 units.
// Example 3:

// Input:
// N = 3
// arr[] = {6,9,9}
// Output:
// 0
// Explanation:
// No water will be trapped.

// Your Task:
// You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.
#include <stdio.h>
#include <stdlib.h>
void trippingwater(int arr[], int n)
{
    int smaxi = 0, maxi = 0, sum = 0;
    int max = arr[0], secmax = arr[1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            secmax = max;
            max = arr[i];
            maxi = i;
        }
        if (arr[i] > secmax && arr[i] < max)
        {
            secmax = arr[i];
            smaxi = i;
        }
    }
    if (smaxi > maxi)
    {
        for (int i = maxi + 1; i < smaxi; i++)
        {
            sum += (secmax - arr[i]);
        }
    }
    if (maxi > smaxi)
    {
        for (int i = smaxi + 1; i < maxi; i++)
        {
            sum += (secmax - arr[i]);
        }
    }
    printf("Water trapped is %d", sum);
}
int main()
{
    int n;
    printf("Enter the number of columns : ");
    scanf("%d", &n);
    int *array;
    array = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    trippingwater(array, n);

    return 0;
}