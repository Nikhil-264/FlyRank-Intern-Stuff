// Name : Nikhil Mahindrakar
// Roll no. : 22CH10036
// Section : 6
// Description : Assignment no 3
// Date : 31 March 2023
#include <stdio.h>
#include <math.h>
int is_prime(int n)
{
    if (n < 2)
    {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    unsigned long int num, n;
    int count = 0, digit, choice, iteration = 0, i = 2;
    printf("Enter the positive number : ");
    scanf("%ld", &num);
    n = num;
    while (n > 1)
    {
        n = n / 10;
        count++;
    }
    printf("Number of digits in the number are %d\n", count);
    while (1)
    {

        printf("Enter 1 to PRINT FIRST DECOMPOSITION OF %ld\n", num);
        printf("Enter 2 to PRINT DIGITS OF %ld\n", num);
        printf("Enter 3 to PRINT SQUARE ROOT OF %ld\n", num);
        printf("Enter 4 to CHECK PRIMALITY OF %ld\n", num);
        printf("Enter 5 to VERIFY GOLDBECH CONJECTURE\n");
        printf("Enter 6 to EXIT THE PROGRAM\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            n = num;
            printf("First Decomposition of the number is : ");
            printf("%ld ", n);
            for (int i = 0; i < count - 1; i++)
            {
                n = n / 10;
                printf("%ld  ", n);
            }

            break;
        case 2:
            n = num;
            printf("The digits of the number are : ");
            for (int i = 0; i < count; i++)
            {
                digit = n % 10;
                n = n / 10;
                printf("%d  ", digit);
            }
            break;
        case 3:
            // square root
            n = num;
            for (int i = 1; i * i; i++)
            {

                if ((double)n / i == i)
                {
                    printf("The number is perfect square \nSquare root of the number is %d\n", i);
                    break;
                }
                else if (i * i > n)
                {
                    printf("The number is not perfect square and\nSquare root lies between %d and %d\n", i - 1, i);
                    break;
                }
            }

            break;
        case 4:
            // prime number
            n = num;
            if (is_prime(n))
            {
                printf("The number is prime number\n");
                break;
            }
            printf("The number is not prime\n");

        case 5:
            n = num;
            for (int p = 2; p <= n / 2; p++)
            {
                if (is_prime(p) && is_prime(2 * n - p))
                {
                    printf("2 x %d = %d + %d\n", n, p, 2 * n - p);
                    return 0;
                }
            }
            printf("No such primes p and q exist.\n");

            break;
        case 6:
            printf("Goodbye !\n");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
// #include <stdio.h>
// #include <math.h>

// int is_prime(int n) {
//     if (n < 2) {
//         return 0;
//     }
//     for (int i = 2; i <= sqrt(n); i++) {
//         if (n % i == 0) {
//             return 0;
//         }
//     }
//     return 1;
// }

// int main() {
//     int n;
//     printf("Enter the value of n: ");
//     scanf("%d", &n);
//     for (int p = 2; p <= n/2; p++) {
//         if (is_prime(p) && is_prime(2*n - p)) {
//             printf("%d = %d + %d\n", n, p, 2*n - p);
//             return 0;
//         }
//     }
//     printf("No such primes p and q exist.\n");
//     return 0;
// }
