// Given an array of positive and negative integers. You have to make the array beautiful. An array is beautiful if two adjacent integers, arr[i] and arr[i+1] have the same sign. And you can do the following operation any number of times until the array becomes beautiful.

// If two adjacent integers have different signs, remove them.
// Return the beautiful array after performing the above operation.

// Note: An empty array is also a beautiful array. There can be many adjacent integers with different signs. So remove adjacent integers with different signs from left to right.

// Example 1:

// Input: 4 2 -2 1
// Output: 4 1
// Explanation: As at indices 1 and 2 , 2 and -2 have
// different sign, they are removed. And the  the final
// array is: 4 1.
// Example 2:

// Input: 2 -2 1 -1
// Output: []
// Explanation: As at indices 0 and 1, 2 and -2 have
// different sign, so they are removed. Now the array
// is 1 -1.Now 1 and -1 are also removed as they have
// different sign. So the final array is empty.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function makeBeautiful() which takes an array as an input parameter and returns an array.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(N)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void makebeautiful(int *array[], int n)
{
    int i = 0, *temp[n];
    for (i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            temp[k] = &array[k];
        }

        if ((temp[i] > 0) && (temp[i + 1] < 0))
        {

            array = (int *)realloc(array, (n - 2) * sizeof(int));
            for (int j = 0; j < i; j++)
            {
                array[j] = temp[j];
            }
            for (int j = i; j < (n - 2); j++)
            {
                array[j] = temp[j + 2];
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d ", *array[j]);
    }
}
int main()
{
    int n, *array;
    printf("enter the number of elements you want the array of : ");
    scanf("%d", &n);
    array = (int *)malloc(n * sizeof(int));
    printf("Enter the elements in the array :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d = ", i);
        scanf("%d", &array[i]);
    }
    makebeautiful(array, n);

    return 0;
}
//outpit failed program failed