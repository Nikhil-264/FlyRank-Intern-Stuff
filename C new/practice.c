// // // // #include <stdio.h>
// // // // #include <stdlib.h>
// // // // char *firstuppar(char s[])
// // // // {
// // // //     while (*s)
// // // //         if ((*s >= 'A') && (*s <= 'Z'))
// // // //             return s;
// // // //         else
// // // //             ++s;
// // // //     return NULL;
// // // // }
// // // // int main()
// // // // {
// // // //     char *p, s[100];
// // // //     scanf("%s", s);
// // // //     p = firstuppar(s);
// // // //     if (p)
// // // //         printf("%c", *p);
// // // //     else
// // // //         printf("NO\n");
// // // //     return 0;

// // // // }
// // // #include <stdio.h>
// // // #include <stdlib.h>
// // // #define MAXDIM 100
// // // double (*genvdm(double *A, int n))[MAXDIM]
// // // {
// // //     double(*p)[MAXDIM];
// // //     int i, j;
// // //     p = (double(*)[MAXDIM])malloc(n * MAXDIM * sizeof(double));
// // //     for (i = 0; i < n; i++)
// // //     {
// // //         p[0][i] = 1;
// // //         for (j = 1; j < n; j++)
// // //             p[j][i] = p[j - 1][i] * A[i];
// // //     }
// // //     return p;
// // // }
// // // void prnvdm(double M[][MAXDIM], int n)
// // // {
// // //     for (int i = 0; i < n; i++)
// // //     {
// // //         for (int j = 0; j < n; j++)
// // //         {
// // //             printf("%10.5lf ", M[i][j]);
// // //         }
// // //         printf("\n");
// // //     }
// // // }
// // // int main()
// // // {
// // //     double A[MAXDIM], (*v)[MAXDIM];
// // //     int n;
// // //     printf("Enter the number of variables: ");
// // //     scanf("%d", &n);
// // //     printf("Enter the variables: ");
// // //     for (int i = 0; i < n; i++)
// // //     {
// // //         scanf("%lf", &A[i]);
// // //     }
// // //     v = genvdm(A, n);
// // //     prnvdm(v, n);

// // //     exit(0);

// // //     // return 0;
// // //     // return 0;
// // // }
// // #include <stdio.h>
// // #include <stdlib.h>
// // int bin(int x[], int size, int key)
// // {
// //     int L, R, mid;
// //     L = 0;
// //     R = size - 1;
// //     while (L != R)
// //     {
// //         mid = (L + R) / 2;
// //         if (key <= x[mid])
// //             R = mid;
// //         else
// //             L = mid + 1;
// //     }
// //     if (key == x[L])
// //         return L;
// //     return -1;
// // }
// // int bin_iterative2(int x[], int size, int key)
// // {
// //     int L, R, mid;
// //     L = 0;
// //     R = size - 1;
// //     while (L <= R)
// //     {
// //         mid = (L + R) / 2;
// //         if (key == x[mid])
// //             return mid;
// //         if (key < x[mid])
// //             R = mid - 1;
// //         else
// //             L = mid + 1;
// //     }
// //     return -1;
// // }
// // int binrec(int x[], int L, int R, int key)
// // {
// //     int mid;
// //     if (L <= R)
// //     {
// //         mid = (L + R) / 2;
// //         if (key == x[mid])
// //             return mid;
// //         if (key < x[mid])
// //             return binrec(x, L, mid - 1, key);
// //         else
// //             return binrec(x, mid + 1, R, key);
// //     }
// //     return -1;
// // }
// // int main()
// // {
// //     int n;
// //     printf("Enter the number of elements: ");
// //     scanf("%d", &n);
// //     int *x = (int *)malloc(n * sizeof(int));
// //     printf("Enter the elements: ");
// //     for (int i = 0; i < n; i++)
// //     {
// //         scanf("%d", &x[i]);
// //     }
// //     int key;
// //     printf("Enter the key: ");
// //     scanf("%d", &key);
// //     int index = bin(x, n, key);
// //     if (index == -1)
// //         printf("Element not found\n");
// //     else
// //         printf("Element found at index %d\n", index);

// //     index = bin_iterative2(x, n, key);
// //     if (index == -1)
// //         printf("Element not found\n");
// //     else
// //         printf("Element found at index %d\n", index);
// //     index = binrec(x, 0, n - 1, key);
// //     if (index == -1)
// //         printf("Element not found\n");
// //     else
// //         printf("Element found at index %d\n", index);

// //     free(x);

// //     return 0;
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void merge(int *a, int *b, int *c, int m, int n)
// {
//     int i = 0, j = 0, k = 0, p;
//     while (i < m && j < n)
//     {
//         if (a[i] < b[j])
//         {
//             c[k] = a[i];
//             i++;
//         }
//         else
//         {
//             c[k] = b[j];
//             j++;
//         }
//         k++;
//     }
//     if (i == m)
//     {
//         for (p = j; p < n; p++)
//         {
//             c[k] = b[p];
//             k++;
//         }
//     }
//     else
//     {
//         for (p = i; p < m; p++)
//         {
//             c[k] = a[p];
//             k++;
//         }
//     }
// }
// void merge_sort(int *A, int n)
// {
//     int i, j, k, m;
//     int *B, *C;
//     if (n > 1)
//     {
//         k = n / 2;
//         m = n - k;
//         B = (int *)malloc(k * sizeof(int));
//         C = (int *)malloc(m * sizeof(int));
//         for (i = 0; i < k; i++)
//             B[i] = A[i];
//         for (j = k; j < n; j++)
//             C[j - k] = A[j];
//         merge_sort(B, k);
//         merge_sort(C, m);
//         merge(B, C, A, k, m);
//         free(B);
//         free(C);
//     }
// }
// int main()
// {
//     srand(time(NULL));
//     int n;
//     scanf("%d", &n);
//     int *A = (int *)malloc(n * sizeof(int));
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = rand() % 100;
//     }
//     merge_sort(A, n);
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ",A[i]);
//     }
//     printf("\n");
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
int what()
{
    char not ;
    int but;
    if ((not = getchar()) == EOF)
        return 0;
    but = what() + 1;
    putchar(not );
    printf("%d",but);
    return but;
}
int main()
{
    what();
    return 0;
}