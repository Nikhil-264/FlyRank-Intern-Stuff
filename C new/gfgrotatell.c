#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} snode;

snode *createnode(int data)
{
    snode *newnode = (snode *)malloc(sizeof(snode));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

snode *createlist(int n, int *arr)
{
    if (n == 0)
        return NULL;
    snode *head = NULL;
    snode *temp = NULL;

    int data;
    data = arr[0];
    head = createnode(data);
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        data = arr[i - 1];
        temp->next = createnode(data);
        temp = temp->next;
    }
    return head;
}


snode *rotate(snode *head)
{

    snode *temp = head;
    int headdata = head->data;

    while (temp->next != NULL)
    {
        temp->data = temp->next->data;
        temp = temp->next;
    }
    temp->data = headdata;
    return head;
}

void traversal(struct node *ptr)
{
    printf("List : \n");
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    int n;
    printf("Enter the size of the list : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("enter list elements :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    int k;
    printf("Enter the rotations : ");
    scanf("%d", &k);
    snode *head = createlist(n, arr);
    traversal(head);
    int i = 1;
    while (i <= k)
    {
        head = rotate(head);
        i++;
    }
    traversal(head);
    return 0;
}