#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Happy()
{
    for (int i = 0; i < 6; i++)
        printf("*");
}

int main()
{
    printf("Hi\n");
    char *greetings = (char *)malloc(10 * sizeof(char));
    scanf("%s", greetings);
    int date, month, year;
    printf("Enter date : ");
    scanf("%d%d%d", &date, &month, &year);
    printf("You wanna know how many days since we met last time ?(YES or NO)\n");
    char *response;
    scanf("%s", response);
    if (strcmp(response, "YES"))
    {
        printf("fine");
    }
    else
        printf("its Ok if no! we met today tahts important");

    return 0;
}