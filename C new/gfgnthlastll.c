// Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} mll;

mll *createnode(int data)
{
    mll *newnode = (mll *)malloc(sizeof(mll));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

mll *createlist(int n)
{
    if (n == 0)
        return NULL;
    mll *head = NULL;
    mll *temp = NULL;

    int data;
    printf("Enter date for node 1 : ");
    scanf("%d", &data);
    head = createnode(data);
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter date for node %d : ", i);
        scanf("%d", &data);
        temp->next = createnode(data);
        temp = temp->next;
    }
    return head;
}

int getNthFromLast(mll *head, int n)
{
    int k = 0;
    mll *temp = head;
    while (temp != NULL)
    {
        k++;
        temp = temp->next;
    }
    if (n > k)
        return -1;
    temp = head;
    for (int i = 0; i < k - n; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

int main()
{
    mll *head = NULL;
    int n;
    printf("Enter the size of linked list : ");
    scanf("%d", &n);
    head = createlist(n);
    printf("Enter the position : ");
    scanf("%d", &n);
    printf("The nth last node is : %d", getNthFromLast(head, n));

    return 0;
}