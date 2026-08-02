// You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].
// Input:
// n = 3
// arr = {1, 2, 3}
// Output:
// 0 1 3
// Explanation:
// For 1, there are no elements lesser than itself.
// For 2, only 1 is lesser than 2.
// And for 3, 1 and 2 are lesser than 3, so the sum is 3
#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[j] < i + 1)
            {
                sum += array[j];
            }
        }
        printf("%d ", sum);
    }

    return 0;
}