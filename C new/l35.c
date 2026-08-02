// string functions
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100] = "NIKHIL";
    char str2[100] = "AMRUTA";
    char str3[100];
    printf("Number of characters in str1 are %d \n", strlen(str1));
    printf("Number of characters in str2 are %d \n", strlen(str2));
    printf("Reverse is %s\n", strrev(str1));
    printf("Reverse is %s\n", strrev(str2));
    
    printf("str3 is %s\n", strcpy(str3, strcat(str1, str2)));
    printf("mix is %s\n", strcat(str2,str1));
    printf("reverse is %s \n", strrev(str3));

    return 0;
}
