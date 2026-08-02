// Pattern question from section 8 assignment 3 
#include <stdio.h>
int main()
{
    int N;
    printf("Enter the number : ");
    scanf("%d", &N);
    for (int i = 0; i < 4 * N; i++)
    {
        printf("=");
    }
    printf("\n");
    for (int i = 0; i <= (2 * N - 1) / 2; i++)
    {
        printf("|");
        for (int j = 0; j < 2 * (N - i - 1); j++)
        {
            printf(" ");
        }
        printf("<");
        for (int j = 0; j < 4 * i; j++)
        {
            printf("-");
        }
        printf(">");
        for (int j = 0; j < 2 * (N - i - 1); j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    for (int i = (2 * N - 1) / 2 - 1; i >= 0; i--)
    {
        printf("|");
        for (int j = 0; j < 2 * (N - i - 1); j++)
        {
            printf(" ");
        }
        printf("<");
        for (int j = 0; j < 4 * i; j++)
        {
            printf("-");
        }
        printf(">");
        for (int j = 0; j < 2 * (N - i - 1); j++)
        {
            printf(" ");
        }
        printf("|\n");
    }
    for (int i = 0; i < 4 * N; i++)
    {
        printf("=");
    }

    return 0;
}