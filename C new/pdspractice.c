#include <stdio.h>
#include <stdlib.h>
// int main()
// {
//     char m[110];
//     int len;
//     char vowels[] = {"aeiou"};
//     char C[5] = {0, 0, 0, 0, 0};
//     scanf("%s",m);//cannot take input with spaces in it
//     for (len = 0; m[len] != '\0'; len++)
//         ;
//     for (int i = 0; i < len; i++)
//     {
//         for (int j = 0; j < 5; j++)
//         {
//             if (m[i] == vowels[j])
//                 C[j]++;
//         }
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%c = %d \n", vowels[i], C[i]);
//     }

//     return 0;
// }
int main()
{
    int *A = (int *)malloc(10 * sizeof(int)), allocsize = 10, n = 0, x;
    printf("Keep on entering + ve integers.Enter 0 or a - ve integer to stop.\n");
    while (1)
    {
        printf("Next integer : ");
        scanf("%d", &x);
        if (x <= 0)
            break;
        ++n;
        if (n > allocsize)
        {
            allocsize += 10;
            A = (int *)realloc(A, allocsize * sizeof(int));
        }
        A[n - 1] = x;
    }
    A = (int *)realloc(A, n * sizeof(int));
    allocsize = n;
    // Process the integers read from the user
    free(A);
    return 0;
}