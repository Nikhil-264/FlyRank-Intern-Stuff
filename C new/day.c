// finding day for any date
#include <stdio.h>
int main()
{
    int date, year, month, y, m, c, l; // y= year code,m= month code, c = century code
    printf("Write the date in the form : DD MM YYYY \n");
    scanf("%d%d%d", &date, &month, &year);
    y = ((year % 100) + ((year % 100) / 4));
    switch (month)
    {
    case 3:
        m = 3;
        break;
    case 2:
        m = 3;
        break;
    case 11:
        m = 3;
        break;
    case 1:
        m = 0;
        break;
    case 10:
        m = 0;
        break;
    case 4:
        m = 6;
        break;
    case 7:
        m = 6;
        break;
    case 9:
        m = 5;
        break;
    case 12:
        m = 5;
        break;
    case 5:
        m = 1;
        break;
    case 6:
        m = 4;
        break;
    case 8:
        m = 2;
        break;

    default:
        break;
    }
    switch ((year / 100) % 4)
    {
    case 1:
        c = 4;
        break;
    case 2:
        c = 2;
        break;
    case 3:
        c = 0;
        break;
    case 0:
        c = 6;
        break;

    default:
        break;
    }
    if ((year % 4 == 0) || (year % 400 == 0))
    {
        if ((month == 1) || (month == 2))
            l = -1;
        else
            l = 0;
    }
    else
    {
        l = 0;
    }
    switch ((date + y + m + c + l) % 7)
    {
    case 0:
        printf("The day on the given date is SUNDAY");
        break;
    case 1:
        printf("The day on the given date is MONDAY");
        break;
    case 2:
        printf("The day on the given date is TUESDAY");
        break;
    case 3:
        printf("The day on the given date is WEDNESDAY");
        break;
    case 4:
        printf("The day on the given date is THURSDAY");
        break;
    case 5:
        printf("The day on the given date is FRIDAY");
        break;
    case 6:
        printf("The day on the given date is SATURDAY");
        break;

    default:
        break;
    }
}
