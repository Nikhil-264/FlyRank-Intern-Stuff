// goto statement
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b = 1, c = 1;
    printf("ENTER THE NUMBER\n");
    scanf("%d", &a);
    do
    {
        goto end;
        printf("%d\nenter c\n", a * b);
        b = b + 1;
        scanf("%d", &c);
        if (c > 18)
        {
            continue;
        }
        printf("%d\n", b * c);

    } while ((b < 11));
end:
    return 0;
}
