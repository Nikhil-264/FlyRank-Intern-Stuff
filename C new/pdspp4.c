// // practice problem 1 lecturem 4  Read in an integer N. Then print the sum of the squares of the first N natural numbers
// #include <stdio.h>
// int main()
// {
//     int n;
//     scanf("%d",&n);
//     for (int i = 1; i <= n; i++)
//     {
//         printf("%d\n",i*i);
//     }

//     return 0 ;
// }
// // practice problem 2 lecturem 4 Read in an integer N. Then read in N numbers and print their maximum and second maximum (do not use
// // arrays even if you know it)

// #include <stdio.h>
// int main()
// {
//     float next, max, smax;
//     printf("Enter the number >0 and <=0 to exit the program\n ");
//     scanf("%f", &next);
//     while (next > 0)
//     {
//         if (next > max)
//         {
//             smax = max;
//             max = next;
//         }
//         scanf("%f", &next);
//     }
//     printf("the maximum number is %f\n", max);
//     printf("The second highest number is %f\n", smax);

//     return 0;
// }
// // Read in an integer N. Then read in N numbers and print the number of integers between 0 and 10 (including
// // both), between 11 and 20, and > 20. (do not use arrays even if you know it)
// #include <stdio.h>
// int main()
// {
//     int N, num, count1 = 0, count2 = 0;
//     scanf("%d", &N);
//     printf("Enter %d numbers below : \n", N);
//     for (int i = 0; i < N; i++)
//     {

//         scanf("%d", &num);
//         if (num >= 0 && num <= 10)
//         {
//             count1++;
//         }
//         if (num >= 11 && num <= 20)
//         {
//             count2++;
//         }
//     }
//     printf("Number sbetween 1 and 10 are %d\n", count1);
//     printf("Number sbetween 10 and 20 are %d\n", count2);

//     return 0;
// }
// 4. Repeat 3, but this time print the average of the numbers in each range.
// #include <stdio.h>
// int main()
// {
//     int N, num, count1 = 0, count2 = 0, sum1 = 0, sum2 = 0;
//     printf("Enter number of inputs u want :");
//     scanf("%d", &N);
//     printf("Enter %d numbers below : \n", N);
//     for (int i = 0; i < N; i++)
//     {

//         scanf("%d", &num);
//         if (num >= 0 && num <= 10)
//         {
//             count1++;
//             sum1 = sum1 + num;
//         }
//         if (num >= 11 && num <= 20)
//         {
//             count2++;
//             sum2 = sum2 + num;
//         }
//     }
//     printf("Number sbetween 1 and 10 are %d\n", count1);
//     printf("Number sbetween 10 and 20 are %d\n", count2);
//     printf("Average of range 1 is %f\n", (float)(sum1) / count1);
//     printf("Average of range 2 is %f\n", (float)(sum2) / count2);

//     return 0;
// }
// // Read in a positive integer N. If the user enters a negative integer or 0, print a message asking the user to enter
// // the integer again. When the user enters a positive integer N finally, find the sum of the logarithmic series
// // (loge(1+x)) upto the first N terms
// #include <stdio.h>
// #include <math.h>
// int main()
// {
//     int N, x;
//     float sum = 0;
//     printf("Enter the number : ");
//     scanf("%d", &N);
//     while (N <= 0)
//     {
//         printf("Enter the number again : ");
//         scanf("%d", &N);
//     }
//     printf("Enter the value of x for log evaluation :");
//     scanf("%d", &x);
//     for (int i = 0; i < N; i++)
//     {
//         sum = sum + pow(-1, i) * ((pow(x, i + 1)) / (i + 1));
//     }

//     printf("The sum of %d terms of logarithmic series log(1+x) for x = %d is %f", N, x, sum);

//     return 0;
// }