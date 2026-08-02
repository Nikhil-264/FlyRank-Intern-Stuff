// You are given an array A of N integers and an integer K, and your task is to find the total number of totalcuts that you can make such that for each cut these two conditions are satisfied
// 1. A cut divides an array into two parts equal or unequal length (non-zero).
// 2. Sum of the largest element in the left part and the smallest element in the right part is greater than or equal to K.

// Example 1:

// Input:
// N=3
// K=3
// A[]={1,2,3}
// Output:
// 2
// Explanation:
// Two ways in which array is divided to satisfy above conditions are:
// {1} and {2,3} -> 1+2>=3(satisfies the condition)
// {1,2} and {3} -> 2+3>=3(satisfies the condition)
// Example 2:

// Input:
// N=5
// K=5
// A[]={1,2,3,4,5}
// Output:
// 3
// Explanation:
// {1,2} and {3,4,5} -> 2+3>=5
// {1,2,3} and {4,5} -> 3+4>=5
// {1,2,3,4} and {5} -> 4+5>=5
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function totalCuts() which takes two integers N, K, and an array A of size N as input parameters, and returns an integer representing the total number of totalcuts that satisfy both conditions.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= N <= 10^6
// 0 <= K <= 10^6
// 0 <= A[i] <= 10^6
#include <stdio.h>
#include <stdlib.h>
int leastinarray(int array[], int n)
{
    int min = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] < min)
            min = array[i];
    }
    return min;
}
int biginarray(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
int totalcuts(int n, int k, int array[])
{
    int count = 0;
    int leftary[n];
    int rightary[n];

    return count;
}
int total_cuts(int set[], int n, int k)
{
    int count = 0;
    int leftary[n];
    int rightary[n];
    for (int i = 0; i < (1 << n); i++)
    {
        int l=0;
        // printf("{ ");
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                leftary[l] = set[j];
                l++;
                // printf("%d ", set[j]);
            }
        }
        
        
        // printf("}\n");
    }
    return count ;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k;
    scanf("%d", &k);
    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter the elements in array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("%d", totalcuts(n, array, k));
    return 0;
}
//not getting