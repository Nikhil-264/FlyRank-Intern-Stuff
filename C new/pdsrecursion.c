#include <stdio.h>
void tranfer(int n, char from, char to, char temp)
{
    if (n > 0)
    {
        tranfer(n - 1, from, temp, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        tranfer(n - 1, temp, to, from);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    tranfer(n, 'L', 'R', 'C');

    return 0;
}