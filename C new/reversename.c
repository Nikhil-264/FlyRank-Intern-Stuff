// printing name in reverse without using string and using recursion

#include <stdio.h>
void RaP()
{
    char c;
    scanf("%c", &c);
    if (c == '\n')
        return;
    RaP();
    printf("%c", c);
}
int main()
{
    RaP();
    return 0;
}

