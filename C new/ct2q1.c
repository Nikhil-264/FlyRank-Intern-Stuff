// Name : NIkhil Mahindrakar
// Roll no : 22CH10036
// Section   :  6
// Assignment  : class test 2
// File : part 1
// Description   : Question 1
// Date   : 2 June 2023
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Node
{
    int Rollno;
    char Name[20];
    int markA;
    int markB;
    int age;
    char Specialization[2];
};

struct Node *CreateFirstTable(struct Node *table, int n)
{
    for (int i = 0; i < n; i++)
    {
        table[i].Rollno = 1000 + rand() % (8999);
        printf("Enter Name of the student %d:", i + 1);
        scanf("%s", &table[i].Name);
    }
    return table;
}

struct Node *PrintFirstTable(struct Node *table, int n)
{
    printf("\nTable 1 :\n");
    for (int i = 0; i < n; i++)
    {
        printf("Roll No %d ", table[i].Rollno);
        printf("Name  %s \n", table[i].Name);
    }
    return table;
}

struct Node *CreateSecondTable(struct Node *table, int n)
{
    for (int i = 0; i < n; i++)
    {
        table[i].markA = 0 + rand() % (100);
        table[i].markB = 0 + rand() % (100);
    }
    return table;
}

struct Node *PrintSecondTable(int n, struct Node *table)
{

    printf("\nTable 2 : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Roll Number : %d ", table[i].Rollno);
        printf("Marks in A %d ", table[i].markA);
        printf("Marks in B %d \n", table[i].markB);
    }
    printf("\n");
    return table;
}

struct Node *CreateThirdTable(struct Node *table, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        table[i].age = 15 + rand() % (10);
        printf("Enter specialization between(CS,EC,PH) :");
        scanf("%s", table[i].Specialization);
    }
    return table;
}

struct Node *PrintThirdTable(struct Node *table, int n)
{
    printf("\nTable 3 \n");
    for (int i = 0; i < n; i++)
    {
        printf("Name %s ", table[i].Name);
        printf("Age  %d ", table[i].age);
        printf("specialization %s \n", table[i].Specialization);
    }
    return table;
}
void SearchByName(struct Node *table, int n)
{
    char *name;
    name = (char *)malloc(20 * sizeof(char));
    printf("Enter Name :");
    scanf("%s", name);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(name, table[i].Name))
        {
            printf("Roll no %d Age %d Specialization %s Marks in A %d Marks in B %d Average marks %f\n", table[i].Rollno, table[i].age, table[i].Specialization, table[i].markA, table[i].markB, (float)(table[i].markA + table[i].markB) / 2);
            return;
        }
        else
        {
            k++;
            if (k == n - 1)
                printf("No name found\n");
        }
    }
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Please enter n : ");
    scanf("%d", &n);
    struct Node *Students = (struct Node *)malloc(n * sizeof(struct Node));
    Students = CreateFirstTable(Students, n);
    Students = PrintFirstTable(Students, n);
    Students = CreateSecondTable(Students, n);
    Students = PrintSecondTable(n, Students);
    Students = CreateThirdTable(Students, n);
    Students = PrintThirdTable(Students, n);
    int k;
    while (1)
    {
        printf("Enter 1 to search by name or 2 to exit : ");
        scanf("%d", &k);
        if (k == 2)
            return 0;
        if (k == 1)
            SearchByName(Students, n);
    }

    return 0;
}
