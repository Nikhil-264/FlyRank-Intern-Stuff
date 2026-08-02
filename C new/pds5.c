// //  Suppose the digits 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 are mapped to the lowercase letters a, b, c, d, e, f, g, h, i, j
// // respectively. Read in a single digit integer as a character (using %c in scanf) and print its
// // corresponding lowercase letter. Do this both using switch and without using switch (two programs).
// // Do not use any ascii code value directly
// //with switch case
// #include <stdio.h>

// int main() {
//     char ch;
//     printf("Enter a single digit integer as a character: ");
//     scanf("%c", &ch);

//     switch(ch) {
//         case '0':
//             printf("a\n");
//             break;
//         case '1':
//             printf("b\n");
//             break;
//         case '2':
//             printf("c\n");
//             break;
//         case '3':
//             printf("d\n");
//             break;
//         case '4':
//             printf("e\n");
//             break;
//         case '5':
//             printf("f\n");
//             break;
//         case '6':
//             printf("g\n");
//             break;
//         case '7':
//             printf("h\n");
//             break;
//         case '8':
//             printf("i\n");
//             break;
//         case '9':
//             printf("j\n");
//             break;
//         default:
//             printf("Invalid input!\n");
//     }

//     return 0;
// }
// //without switch case
// #include <stdio.h>

// int main() {
//     char ch;
//     printf("Enter a single digit integer as a character: ");
//     scanf("%c", &ch);

//     if(ch == '0') {
//         printf("a\n");
//     }
//     else if(ch == '1') {
//         printf("b\n");
//     }
//     else if(ch == '2') {
//         printf("c\n");
//     }
//     else if(ch == '3') {
//         printf("d\n");
//     }
//     else if(ch == '4') {
//         printf("e\n");
//     }
//     else if(ch == '5') {
//         printf("f\n");
//     }
//     else if(ch == '6') {
//         printf("g\n");
//     }
//     else if(ch == '7') {
//         printf("h\n");
//     }
//     else if(ch == '8') {
//         printf("i\n");
//     }
//     else if(ch == '9') {
//         printf("j\n");
//     }
//     else {
//         printf("Invalid input!\n");
//     }

//     return 0;
// }
//  Suppose that you have to print the grades of a student, with >= 90 marks getting EX, 80-89 getting A,
// 70-79 getting B, 60-69 getting C, 50-59 getting D, 35-49 getting P and <30 getting F. Read in the marks
// of a student and print his/her grade.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter your marks : ");
    scanf("%d", &n);
    if (n > 90)
    {
        printf("Your grade is EX\n");
    }
    else if (n > 80)
    {
        printf("Your grade is A\n");
    }
    else if (n > 70)
    {
        printf("Your grade is B\n");
    }
    else if (n > 60)
    {
        printf("Your grade is C \n");
    }
    else if (n > 50)
    {
        printf("Your grade is D \n");
    }
    else if (n >= 35)
    {
        printf("Your grade is P\n");
    }
    else if (n < 35)
    {
        printf("Your grade is F\n");
    }
}
