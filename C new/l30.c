// Exercise 4 star pattern
#include <stdio.h>
int main()
{

    int n, a;
    printf("Enter the number for pattern : ");
    scanf("%d", &n);
    printf("Enter 0 to obtain triangular pattern \nEnter 1 to obtain reverse triangular pattern :");
    scanf("%d", &a);
    switch (a)
    {
    case 0:
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf("%c", '*');
            }
            printf("\n");
        }
        break;

    case 1:
        for (int i = n; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                printf("%c", '*');
            }
            printf("\n");
        }
        break;
    }
    return 0;
}
