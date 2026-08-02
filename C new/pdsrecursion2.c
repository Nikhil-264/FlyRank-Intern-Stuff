#include <stdio.h>
#include <stdlib.h>
int canchage(int k)
{
    int a;
    if (k == 0)
        return 0;
    if (k == 10 || k == 5 || k == 3)
        return 1;
    if (k < 3)
        return -1;

    a = canchage(k - 10);
    if (a > 0)
        return a + 1;
    a = canchage(k - 5);
    if (a > 0)
        return a + 1;
    a = canchage(k - 3);
    if (a > 0)
        return a + 1;
    return -1;
}
int main()
{
    int k;
    scanf("%d", &k);
    printf("%d",canchage(k));
    return 0;
}