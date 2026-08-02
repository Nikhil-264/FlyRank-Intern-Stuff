// greater number between two numbers
#include<stdio.h>
int main()
{
    int a , b ;
    printf("enter a and b\n");
    scanf("%d%d", &a, &b);
    
    if (a>b)
    {
        printf("%d is larger \n" , a);
    }
    else if(b>a)
    {
        printf("%d is larger\n " , b);
    }
    else 
    {
        printf("both are equal\n" );
    }
    
    return 0;
}
