// Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.

// Example 1:

// Input:
// N = 5
// A[] = {1,2,3,5}
// Output: 4
// Example 2:

// Input:
// N = 10
// A[] = {6,1,2,8,3,4,7,10,5}
// Output: 9
// Your Task :
// You don't need to read input or print anything. Complete the function MissingNumber() that takes array and N as input  parameters and returns the value of the missing number.
#include <stdio.h>
void missingnumber()
{
    int n, sum = 0, expected_sum = 0;
    printf("Enter the number : ");
    scanf("%d", &n);
    expected_sum = n * (n + 1) / 2;

    int array[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        printf("element %d : ", i);
        scanf("%d", &array[i]);
        sum += array[i];
    }
    printf("The misssing number is %d", expected_sum - sum);
}

int main()
{
    missingnumber();
    return 0;
}