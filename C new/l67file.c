#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *ptr = NULL;
    ptr = fopen("myfile.txt", "a+");
    // char c = fgetc(ptr);
    // printf("The character read was %c\n", c);
    // c = fgetc(ptr);
    // printf("The character read was %c\n", c);
    // c = fgetc(ptr);
    // printf("The character read was %c\n", c);
    // c = fgetc(ptr);
    // printf("The character read was %c\n", c); // everytime it picks next charcater

    // char str[34];
    // fgets(str,5,ptr);
    // printf("The string is %s\n",str);//gives (5-1)charcters in string as last character is \0

    fputc('o', ptr);
    fputc('\n', ptr); // initiated in write mode it deletes previous data and adds what is writen in fputs
    fputs("This is Nikhil\n", ptr);
    // now r+ mode is started in this previous date in a file is remained intact but new date is added in front of previous data as aaaaa was already in file after running this code data will be (o\nThis is Nikhil\naaaaa)
    // but w+ will remove previous date and add above
    // and a+ will append the date in previous data as is will add data after preivuos
    char c[66] = fgets(c, 6, ptr);
    printf("%s", c);
    fclose(ptr);
    return 0;
}