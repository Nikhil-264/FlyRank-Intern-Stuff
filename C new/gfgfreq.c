// Given an array A of size N. The elements of the array consist of positive integers. You have to find the largest element with minimum frequency
#include <stdio.h>
#include <stdlib.h>

void LargButMinFreq(int *A, int n)
{
    int freq[n];
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (A[i] == A[j])
                freq[i]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", freq[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    LargButMinFreq(A, n);
    return 0;
}
//incomplete 