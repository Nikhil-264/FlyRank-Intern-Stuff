// You are given an integer n, denoting the number of people who needs to be seated, and a list of m integers seats, where 0 represents a vacant seat and 1 represents an already occupied seat.

// Find whether all n people can find a seat, provided that no two people can sit next to each other.
// Example 1:

// Input:
// n = 2
// m = 7
// seats[] = {0, 0, 1, 0, 0, 0, 1}
// Output:
// Yes
// Explanation:
// The two people can sit at index 0 and 4
#include <stdio.h>
#include <stdlib.h>
void is_possible_toget_seat()
{
    int n, m, allowed = 0;
    // n=number of people to be seated
    // m==number if seats
    printf("Enter the number of people to be seated : ");
    scanf("%d", &n);
    printf("Enter the number of seats : ");
    scanf("%d", &m);
    int *ptr;
    ptr = (int *)malloc(m * sizeof(int));
    printf("Enter the seat status :");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &ptr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        // printf("i before = %d\n", i);
        if ((ptr[i] == 1) && (ptr[i + 1] == 0))
        {
            i += 1;
        }
        else if ((ptr[i] == 0) && (ptr[i + 1] == 0))
        {
            allowed++;
            i += 1;
        }
        // printf("i after = %d\n", i);
        // printf("allowed in loop %d\n", allowed);
    }
    printf("allowed out of loop %d\n", allowed);
    if (allowed >= n)
    {
        printf("YES\n");
    }
    else
        printf("NO\n");
}
int main()
{
    is_possible_toget_seat();
    return 0;
}