// You are given an array of integers of size n where n being even.. You have to calculate the number of dominate pairs (i,j) . Where a pair is called dominant if ( 0<=i<n/2, n/2<=j<n, arr[i]>=5*arr[j] ) these relation are fulfilled.  For example  in arr=[10,3,3,1] index i=0, j=3 form a dominating pair

// Note : 0 based indexing is used  and n is even
#include <stdio.h>
int dominantpair()
{
    int n, count = 0;
start:
    printf("Enter the even number of elements in array: ");
    scanf("%d", &n);
    if (n % 2 == 1)
    {
        printf("Try again\nYou may have entered wrong input\n");
        goto start;
    }
    int array[n];
    printf("ENter the elements of array\n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = n / 2; j < n; j++)
        {
            if (array[i] >= 5 * array[j])
            {
                count++;
            }
        }
    }
    printf("the number of dominant pairs in array %d",count);
}
int main()
{
    dominantpair();
    return 0;
}