/****************************
Name:-Nikhil Mahindrakar
Roll NO :- 22CH10036
Section:-06
Assignment No:- 4
Description:-Forth C Program question 2
Date :-28-April-2023
****************************/
#include <stdio.h>
void printingsubset(int set[], int subset[], int n, int sslength, int i)
{
    if (i == n)
    {
        printf("{ ");
        for (int i = 0; i < sslength; i++)
            printf("%d ", subset[i]);
        printf("} ");
        return;
    }
    subset[sslength] = set[i];
    printingsubset(set, subset, n, sslength + 1, i + 1);
    printingsubset(set, subset, n, sslength, i + 1);
}
// sslengjht=subsetlemgth

int main()
{
    int n;
    printf("Enter the lenght of the set : ");
    scanf("%d", &n);
    int ar[n];
    printf("Enter the numbers : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Subsets are : ");
    int subset[n];
    printingsubset(ar, subset, n, 0, 0);
    printf("\n");
    // bonus
    int m;
    printf("enter number of elemets :");
    scanf("%d", &m);
    int set[m];
    int yes = 0;
    printf("Enter the checking set: ");
    for (int i = 0; i < m; i++)
    {
        int count = 0;
        scanf("%d", &set[i]);
        for (int j = 0; j < n; j++)
        {
            if (set[i] == ar[j])
            {
                
                break;
            }
            if (set[i] != ar[j])
            {
                count++;
                if (count == n)
                {
                    printf("this is not the subset\n");
                    break;
                }
                else
                {
                    printf("this is  the subset\n");
                }

                continue;
            }
        }
    }

    return 0;
}
