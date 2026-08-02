#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float num1, num2, result;
    num1 = atof(argv[1]);
    num2 = atof(argv[3]);
    char op = (argv[2][0]);
    if (op == '+')
        result = num1 + num2;
    if (op == '-')
        result = num1 - num2;
    if (op == '*')
        result = num1 * num2;
    if (op == '/')
        result = num1 / (num2);
    printf("%.2f\n", result);
    return 0;
}
