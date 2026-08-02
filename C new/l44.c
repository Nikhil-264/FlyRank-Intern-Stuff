#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct driver
{
    char name[110];
    int license;
    char route[100];
    int kms;
} sdr;
int main()
{
    int n;
    printf("Enter number of drivers entries\n");
    scanf("%d", &n);
    sdr *array = (sdr *)malloc(n * sizeof(sdr));
    // sdr array[n];
    for (int i = 0; i < n; i++)
    {
        printf("Write all the details of yourself\n");
        printf("Name : ");
        getchar();
        scanf("%s", &array[i].name);
        printf("License no : ");
        scanf("%d", &array[i].license);
        printf("Route : ");
        scanf("%s", &array[i].route);
        printf("Experience in kms : ");
        scanf("%d", &array[i].kms);
    }
    printf("information of all drivers is :\n\n");
    for (int i = 0; i < n; i++)
    {

        printf("driver %d :\n Name        : %s \n License no. : %d \n Route       : %s \n Experience  : %d\n\n", i + 1, array[i].name, array[i].license, array[i].route, array[i].kms);
    }

    return 0;
}