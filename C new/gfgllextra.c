// sorting linked list
// merging two sorted linkd list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void traversal(struct node *ptr)
{
    printf("List : \n");
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// swapping nodes
void swap(struct node *a, struct node *b)
{
    int temp;
    temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void selectionsort(snode *head)
{
    snode *ptr = head;
    while (ptr != NULL)
    {
        snode *min_node = head;
        while (ptr != NULL)
        {
            if (ptr->data < min_node->data)
                min_node = ptr;
            ptr = ptr->next;
        }
        if (min_node != head)
        {
            swap(min_node, head);
        }
        head = head->next;
        ptr = head;
    }
}

snode *mergelists(snode *head1, snode *head2)
{
    snode *ptr = head1;

    // Traverse to the last node of the first list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // Append the second list to the last node of the first list
    ptr->next = head2;

    return head1; // Return the merged list
}

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter the number of nodes for list 1: ");
    scanf("%d", &n);
    int *arr1 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr1[i] = n + rand() % (n * n);
    }
    int m;
    printf("Enter the number of nodes for list 2: ");
    scanf("%d", &m);
    int *arr2 = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        arr2[i] = m + rand() % (m * m);
    }
    snode *head1 = createlist(n, arr1);
    snode *head2 = createlist(m, arr2);

    traversal(head1);
    traversal(head2);
    head1 = mergelists(head1, head2);
    selectionsort(head1);
    traversal(head1);

    return 0;
}