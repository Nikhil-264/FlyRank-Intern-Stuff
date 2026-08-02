// Evaluating SGPA
#include <stdio.h>
#include <string.h>
typedef struct student
{
    char MA;
    char CE;
    char PDS;
    char ME;
    char PDSL;
    char ED;
    char CL;
} sst;

int avrg();

int main()
{
    int n;
    printf("Number of students: ");
    scanf("%d",&n);
    sst array[n];
    int ma, ce, pds, me, pdsl, ed, cl;
    float SGPA;
    for (int i = 0; i < n; i++)
    {
        printf("WRITE YOUR GRADES :\n");
        printf("Maths : ");
        getchar();
        scanf("%c", &array[i].MA);
        printf("Chemistry : ");
        getchar();
        scanf("%c", &array[i].CE);
        printf("PDS : ");
        getchar();
        scanf("%c", &array[i].PDS);
        printf("Mechanics : ");
        getchar();
        scanf("%c", &array[i].ME);
        printf("PDS lab : ");
        getchar();
        scanf("%c", &array[i].PDSL);
        printf("Engg. Drawing : ");
        getchar();
        scanf("%c", &array[i].ED);
        printf("Chemistry Lab : ");
        getchar();
        scanf("%c", &array[i].CL);
        switch (array[i].MA)
        {
        case 'X':
            ma = 10;
            break;
        case 'A':
            ma = 9;
            break;
        case 'B':
            ma = 8;
            break;
        case 'C':
            ma = 7;
            break;
        case 'D':
            ma = 6;
            break;
        case 'P':
            ma = 5;
            break;
        case 'F':
            ma = 0;
            break;

        default:
            break;
        }
        switch (array[i].CE)
        {
        case 'X':
            ce = 10;
            break;
        case 'A':
            ce = 9;
            break;
        case 'B':
            ce = 8;
            break;
        case 'C':
            ce = 7;
            break;
        case 'D':
            ce = 6;
            break;
        case 'P':
            ce = 5;
            break;
        case 'F':
            ce = 0;
            break;

        default:
            break;
        }
        switch (array[i].PDS)
        {
        case 'X':
            pds = 10;
            break;
        case 'A':
            pds = 9;
            break;
        case 'B':
            pds = 8;
            break;
        case 'C':
            pds = 7;
            break;
        case 'D':
            pds = 6;
            break;
        case 'P':
            pds = 5;
            break;
        case 'F':
            pds = 0;
            break;

        default:
            break;
        }
        switch (array[i].ME)
        {
        case 'X':
            me = 10;
            break;
        case 'A':
            me = 9;
            break;
        case 'B':
            me = 8;
            break;
        case 'C':
            me = 7;
            break;
        case 'D':
            me = 6;
            break;
        case 'P':
            me = 5;
            break;
        case 'F':
            me = 0;
            break;

        default:
            break;
        }
        switch (array[i].PDSL)
        {
        case 'X':
            pdsl = 10;
            break;
        case 'A':
            pdsl = 9;
            break;
        case 'B':
            pdsl = 8;
            break;
        case 'C':
            pdsl = 7;
            break;
        case 'D':
            pdsl = 6;
            break;
        case 'P':
            pdsl = 5;
            break;
        case 'F':
            pdsl = 0;
            break;

        default:
            break;
        }
        switch (array[i].ED)
        {
        case 'X':
            ed = 10;
            break;
        case 'A':
            ed = 9;
            break;
        case 'B':
            ed = 8;
            break;
        case 'C':
            ed = 7;
            break;
        case 'D':
            ed = 6;
            break;
        case 'P':
            ed = 5;
            break;
        case 'F':
            ed = 0;
            break;

        default:
            break;
        }
        switch (array[i].CL)
        {
        case 'X':
            cl = 10;
            break;
        case 'A':
            cl = 9;
            break;
        case 'B':
            cl = 8;
            break;
        case 'C':
            cl = 7;
            break;
        case 'D':
            cl = 6;
            break;
        case 'P':
            cl = 5;
            break;
        case 'F':
            cl = 0;
            break;

        default:
            break;
        }

        SGPA = (float)(4 * ma + 4 * ce + 4 * pds + 4 * me + 2 * pdsl + 3 * ed + 2 * cl) / 23;
        printf("Your SGPA is : %f ", SGPA);
    }
    

    return 0;
}