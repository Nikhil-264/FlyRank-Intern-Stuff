//continue and break statement
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a , b=1,c=1 ;
    printf("ENTER THE NUMBER\n");
    scanf("%d", &a);
    do
    {
        printf("%d\nenter c\n",a*b);
        b=b+1;
        scanf("%d",&c);
        if (c>18)
        {
            continue;
        }
        printf(" lol%d\n", b*c);
        
    } while ((b < 5));
    
    return 0;
}
