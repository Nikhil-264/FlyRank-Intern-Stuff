// 18. Write a C program to find the Hailstone Sequence of a given number up to 1. Go to the editor
// Test Data :
// Input any number (positive) to start for Hailstone Sequence : 13
// Expected Output :

//  The hailstone sequence starting at 13 is :
//  13  40  20  10  5  16  8  4  2 1
//  The length of the sequence is 10
#include <stdio.h>
#include <stdlib.h>
void hailstone(int n)
{
    if (n == 1)
        return;
    if (n % 2 == 1)
        n = 3 * n + 1;
    else if (n % 2 == 0)
        n = n / 2;
    printf("%d ", n);
    hailstone(n);
}
int main()
{
    int n;
    scanf("%d", &n);
    hailstone(n);
    return 0;
}