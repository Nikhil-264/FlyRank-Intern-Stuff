// Strings in C
#include <stdio.h>
int main()
{
    char str[100]="BNSVUB";
    printf("%s\n", str);//prints name
    printf("Enter your name\n");
    
    gets(str);
    puts(str);//also prints name

    return 0;
}
