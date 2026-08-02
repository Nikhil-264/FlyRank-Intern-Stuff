//while loop for reverse order number from n to 1
#include<stdio.h>
int main()
{
    int n;
    printf("enter n\n");
    scanf("%d", &n);
    while (n>0)
    {
        printf("%d\n",n);
        n = n-1;
    }
    
    return 0;
}
