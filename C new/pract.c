#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} ll;

ll *createnode(int data)
{
    ll *newnode = (ll *)malloc(sizeof(ll));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

ll *createlist(int n)
{
    if (n == 0)
        return NULL;
    ll *head = NULL;
    ll *temp = NULL;
    int data;
    printf("ENter data for node 1: ");
    scanf("%d", &data);
    head = createnode(data);
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        printf("ENter data for node %d: ", i);
        scanf("%d", &data);
        temp->next = createnode(data);
        temp = temp->next;
    }
    return head;
}

void printlist(ll *head)
{
    if (head == NULL)
        return;
    ll *temp = head;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    ll *head = createlist(n);
    printlist(head);
    return 0;
}
