#include <stdio.h>
#include <stdlib.h>
int canchange(int k)
{
    int a;
    if (k == 0)
        return 0;
    if ((k == 3) || (k == 5) || (k == 10))
        return 1;
    if (k < 3)
        return -1;

    a = canchange(k - 10);
    if (a > 0)
        return a + 1;
    a = canchange(k - 5);
    if (a > 0)
        return a + 1;
    a = canchange(k - 3);
    if (a > 0)
        return a + 1;
    return -1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int ans = canchange(n);
    if (ans == -1)
        printf("No Solution");
    else
        printf("%d", ans);
    return 0;
}