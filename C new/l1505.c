//finding factorial by iterative strategy
#include<stdio.h>
int main()
{
    int i,n,c;
    printf("enter n\n");
    scanf("%d",&n);
    c=1;
    for (int i = 1; i <= n; i++)
    {
        c = i*c;
    }
    printf("%d",c);
    return 0;
}