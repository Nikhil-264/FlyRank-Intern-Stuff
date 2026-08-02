// if else exercise trial
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a, b;
    printf("enter marks in maths and science\n");
    scanf("%d%d", &a, &b);
    if ((a > 35) && (b > 35))
    {
        printf("congrates you have won 3 prizes\n");
    }
    else if ((a > 35) || (b > 35))
    {
        printf("congrates you have won 1 prize\n");
    }
    else
    {
        printf("sorry better luck next time\n");
    }

    return 0;
}