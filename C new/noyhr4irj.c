#include <stdio.h>
#include <stdlib.h>
int pr(int *arra, int n, int m)
{
    scanf("%d", *(arra++));
}
int main()
{
    int n = 2, m = 3;
    int ara[n][m];
    pr(&ara, n, m);
    pr(&ara, n, m);
    pr(&ara, n, m);
    pr(&ara, n, m);
    pr(&ara, n, m);
    return 0;
}