/*******************************
 * Name : Nikhil Mahindrakar
 * Roll no.: 22CH10036
 * section : 6
 * Assignment : 7
 * description : 2D array,strings,structures.
 * Date : 26 MAY 2023
 *******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    char name[100];
    char surname[100];
    // char interest[100];
    int interest;
    int ID;
} info;

int path(int grid[][100], int n, int m, int k)
{
    int visited[100];
    for (int i = 0; i < 100; i++)
    {
        visited[i] == 0;
    }
    visited[n] == 0;

    if (grid[n][m] == 1)
    {
        printf("path through %d and %d\n", n, m);
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            printf("Path exists throught %d and %d\n", i, m);
            if (grid[i][m] == 1 && visited[i] == 0)
            {
                printf("Neighbour of %d", i);
                path(grid, i, m, k);
                return 1;
            }
        }
    }
}

int main()
{
    info people[100];
    int intrst;
    people[0] = (info){"John", "Nash", 0, 0};
    people[1] = (info){"George", "Bush", 3, 1};
    people[2] = (info){"Barack", "Obama", 3, 2};
    people[3] = (info){"Isaac", "Newton", 0, 3};
    people[4] = (info){"Allan", "Border", 1, 4};
    people[5] = (info){"Sunil", "Gavaskar", 1, 5};
    people[6] = (info){"Marlon", "Brando", 2, 6};
    people[7] = (info){"Leo", "Caprio", 2, 7};

    // printf("%s\n", people[3].name);
    int key;
    int k = 8;
    int grid[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            grid[i][j] = 0;
        }
    }

    for (int i = 8; i < 100; i++)
    {
        printf("Add new person in DB:");
        scanf("%d", &key);
        if (key == 0)
            break;
        if (key == 1)
        {
            printf("Name : ");
            scanf("%s", people[i].name);
            printf("Surname : ");
            scanf("%s", people[i].surname);
            printf("Interest : \n0 for Science\n1 for Sports\n2 for movie\n3 for Politics\n");
            scanf("%d", &people[i].interest);
            people[i].ID = i;
            k++;
        }
    }

    grid[0][3] = 1;
    grid[3][0] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[1][3] = 1;
    grid[3][1] = 1;
    grid[4][5] = 1;
    grid[5][4] = 1;
    grid[0][6] = 1;
    grid[6][0] = 1;
    grid[6][7] = 1;
    grid[7][6] = 1;

    // for (int i = 0; i < k; i++)
    // {
    //     printf("ID %d ", i);
    //     printf("%s ", people[i].name);
    //     printf("%s  -", people[i].surname);
    //     printf("%s\n", people[i].interest);
    // }

    int edges;
    printf("number of edges :");
    scanf("%d", &edges);
    int n, m;
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edges :");
        scanf("%d %d", &n, &m);
        grid[n][m] = grid[m][n] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        printf("ID %d ", i);
        printf("%s ", people[i].name);
        printf("%s  -", people[i].surname);
        if (people[i].interest == 0)
            printf("Science");
        if (people[i].interest == 1)
            printf("Sports");
        if (people[i].interest == 2)
            printf("Movie");
        if (people[i].interest == 3)
            printf("Politics");
        printf("   Neighbours : ");
        for (int j = 0; j < k; j++)
        {
            if (grid[i][j] == 1)
                printf("%d, ", j);
        }
        printf("\n");
    }
    printf("Enter paths to search (0,0 to stop)\n");

    while (1)
    {
        printf("Enter edges : ");
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0)
            return 0;
        else if (grid[n][m] == 1)
            printf("Direct path exists !\n");
        else
            path(grid, n, m, k);
    }

    return 0;
}
