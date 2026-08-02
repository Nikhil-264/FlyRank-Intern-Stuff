// Name : NIkhil Mahindrakar
// Roll no : 22CH10036
// Section   :  6
// Assignment  : class test 2
// File : part 1
// Description   : Question 2
// Date   : 2 June 2023
#include <stdio.h>
#include <stdlib.h>
typedef struct polyunit
{
    int noceff;
    int ndeg;
    struct polyunit *next;
} poly;

poly *createnode(int data1, int data2)
{
    poly *newnode = (poly *)malloc(sizeof(poly));
    newnode->noceff = data1;
    newnode->ndeg = data2;
    newnode->next = NULL;
    return newnode;
}

void Swap(poly *p1, poly *p2)
{
    int t1 = p1->noceff;
    int t2 = p1->ndeg;
    p1->noceff = p2->noceff;
    p1->ndeg = p2->ndeg;
    p2->noceff = t1;
    p2->ndeg = t2;
}

void bubbledescnd(poly *p1)
{
    int swapped;
    poly *temp;
    poly *temp2 = NULL;

    if (p1 == NULL)
        return;
    do
    {
        swapped = 0;
        temp = p1;

        while (temp->next != temp2)
        {
            if (temp->ndeg < temp->next->ndeg)
            {
                Swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        temp2 = temp;
    } while (swapped);
}

void printpoly(poly *p1)
{
    poly *temp = p1;
    while (temp->next != NULL)
    {
        printf("%d %d\n", temp->noceff, temp->ndeg);
        temp = temp->next;
    }
}

int main()
{
    poly *p1 = NULL;
    poly *p2 = NULL;
    printf("Enter first polynomial : ");
    p1 = createnode(0, 0);
    scanf("%d %d", &p1->noceff, &p1->ndeg);
    // p1 = createnode(p1->noceff, p1->ndeg);

    poly *temp1 = NULL;
    temp1 = p1;
    do
    {
        scanf("%d %d", &temp1->noceff, &temp1->ndeg);
        if ((temp1->noceff != -1) && (temp1->ndeg != -1))
        {
            temp1->next = createnode(temp1->noceff, temp1->ndeg);
            temp1 = temp1->next;
        }

    } while ((temp1->noceff != -1) && (temp1->ndeg != -1));
    bubbledescnd(p1);

    printf("Enter second polynomial : ");
    p2= createnode(0, 0);
    scanf("%d %d", &p2->noceff, &p2->ndeg);
    p2 = createnode(p2->noceff, p2->ndeg);

    poly *temp2 = p2;
    do
    {
        scanf("%d %d", &temp2->noceff, &temp2->ndeg);
        if (temp2->noceff != -1 && temp2->ndeg != -1)
        {
            temp2->next = createnode(temp2->noceff, temp2->ndeg);
            temp2 = temp2->next;
        }
    } while (temp2->noceff != -1 && temp2->ndeg != -1);
    bubbledescnd(p2);

    printpoly(p1);
    printf("\n");
    printpoly(p2);

    return 0;
}