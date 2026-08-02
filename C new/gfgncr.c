// Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7
//
#include <stdio.h>
#include <stdlib.h>

int nCr(int n, int r)
{

    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// def nCr(n,r):
//     if r>n:
//         return 0
//     if r==0 or r==n:
//         return 1
//     return nCr(n-1,r-1) + nCr(n-1,r) 

int main()
{
    int n, r;
    printf("Enter the value of N and R: ");
    scanf("%d%d", &n, &r);
    printf("%d", nCr(n, r));
    return 0;
}