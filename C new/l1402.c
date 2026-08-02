//same as 1401 but with using do while
#include<stdio.h>
int main()
{
    int a;
    printf("enter a\n"),
    scanf("%d",&a);
    do
    {
        printf("%d\n", a);
        a=a-1;
    } while (a>0);
    
    return 0;
}
