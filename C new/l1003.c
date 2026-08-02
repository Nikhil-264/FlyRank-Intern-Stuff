// finding greater number between 3 different numbers
#include<stdio.h>
int main()
{
    int a , b , c ;
    printf("enter three numbers\n");
    scanf("%d%d%d" , &a ,&b ,&c);
    if ((a>b)&&(a>c))
    {
        printf("%d is larger", a);
    }
     else if ((b>a)&&(b>c))
    {
        printf("%d is larger", b);
    }
    else if((c>a)&&(c>b))
    {
        printf("%d is larger", c);
    }
    return 0;
}