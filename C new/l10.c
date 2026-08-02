// if else , if , if else if ladder
#include <stdio.h>
int main()
{
    int age;

    printf("enter your age\n");
    scanf("%d", &age);

    printf("yuor age is %d\n", age);
    if (age > 18)
    {
        printf("you can vote");
    }
    else
    {
        printf("you cant vote");
    }

    return 0;
}
