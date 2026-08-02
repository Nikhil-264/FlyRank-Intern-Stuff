//sum of n natural numbers iterative appraoch
#include<stdio.h>
int main()
{
    int i,n,c;
    printf("enter n\n");
    scanf("%d",&n);
    c=0;
    for (int i = 0; i <= n; i++)
    {
        c = i+c;
    }
    printf("%d",c);
    return 0;
}