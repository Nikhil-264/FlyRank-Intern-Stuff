// making long linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} snd;

snd *stnode;

void createnode(int n)
{
    snd *firstnode, *temp;
    int data;
    stnode = (snd *)malloc(sizeof(snd));
    if (stnode == NULL)
        printf("Memory cant be allocated\n");
    else
    {
        printf("Enter date for node 1 : ");
        scanf("%d", &data);

        stnode->data = data;
        stnode->next = NULL;
        temp = stnode;

        for (int i = 2; i < n; i++)
        {
            firstnode = (snd *)malloc(sizeof(snd));
            if (firstnode == NULL)
            {
                printf("Memory cant be allocated\n");
                break;
            }
            else
            {
                printf("Enter data for node %d : ", i);
                scanf("%d", &data);
                firstnode->data = data;
                firstnode->next = NULL;
                temp->next = firstnode;
                temp = temp->next;
            }
        }
    }
}

int main()
{

    return 0;
}