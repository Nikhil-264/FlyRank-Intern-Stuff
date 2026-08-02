// while loop break
#include <stdio.h>
int main()
{
    int n, i = 0;
    int name;
    printf("enter  n\n");
    scanf("%d", &n);
    while (i < n)
    {
        printf("%d\n enter your name to proceed\n", i);
        scanf("%d", &name);
        if (name == 5)
        {
            break;
        }

        i = i + 1;
    }

    return 0;
}
