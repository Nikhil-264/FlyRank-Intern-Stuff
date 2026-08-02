#include <stdio.h>
#include <stdlib.h>

void tranfer(int n, char from, char to, char temp)
{
    if (n > 0)
    {
        tranfer(n - 1, from, temp, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        tranfer(n - 1, temp, to, from);
    }
    return;
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tranfer(n, 'L', 'C', 'R');

    return 0;
}