// You are given a number N. Find the total number of setbits in the numbers from 1 to N.

// Example 1:

// Input: N = 3
// Output: 4
// Explaination:
// 1 -> 01, 2 -> 10 and 3 -> 11.
// So total 4 setbits.
// Example 2:

// Input: N = 4
// Output: 5
// Explaination: 1 -> 01, 2 -> 10, 3 -> 11
// and 4 -> 100. So total 5 setbits.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void setbits1()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int p = 0;
        while (pow(2, p) <= i)
            p++;
        int temp = i;
        for (int j = 0; j < p; j++)
        {
            int binary = temp % 2;
            temp = temp / 2;
            if (binary == 1)
                ans++;
        }
    }
    printf("%d\n", ans);
}

int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
void setbits()
{
    int n;
    printf("Enter number : ");
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += countSetBits(i);
    }
    printf("%d\n", ans);
}

int main()
{
    setbits1(); // timecomplexity is O(nlogn)
    setbits();  // timecomplexity is O(1)
    return 0;
}
//learn thr logic