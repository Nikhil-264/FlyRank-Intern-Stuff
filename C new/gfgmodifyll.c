// 1. Modify the value of the first half nodes such that 1st node's new value is equal to the value of the last node minus the first node's current value, 2nd node's new value is equal to the second last nodes value minus 2nd nodes current value, likewise for first half nodes.
// 2. Replace the second half of nodes with the initial values of the first half nodes(values before modifying the nodes).
// 3. If N is odd then the value of the middle node remains unchanged.

// Example 1:

// Input:
// N = 5
// linked list = 10 -> 4 -> 5 -> 3 -> 6
// Output:
// -4 -1 5 4 10
// Explanation:
// For first half nodes modified list will be:
// -4 -> -1 -> 5 -> 3 -> 6
// For second half nodes modified list will be:
// -4 -> -1 -> 5 -> 4 -> 10

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int index;
    struct node *next;
} mll;

mll *createnode(int data)
{
    static int index = 1;
    mll *newnode = (mll *)malloc(sizeof(mll));
    newnode->data = data;
    newnode->index = index;
    newnode->next = NULL;
    index++;
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

mll *modify(mll *head, int n)
{
    mll *temp = head;
    mll *temp2 = head;
    mll *temp3 = head;
    int half = n / 2;

    for (int i = 1; i <= half; i++)
    {
        // temp = head;
        int data1 = temp->data;
        // int indextemp = temp->index;
        for (int j = 1; j <= n - i; j++)
            temp2 = temp2->next;
        temp->data = temp2->data - temp->data;
        temp2->data = data1;
        temp = temp->next;
        temp2 = head;
    }
    head = temp3;
    return head;
}

int main()
{
    int n;
    printf("Enter size of list : ");
    scanf("%d", &n);
    mll *head = createlist(n);
    mll *temp = head;
    head = modify(head, n);
    while (temp != NULL)
    {
        printf("Node %d : %d \n", temp->index, temp->data);
        temp = temp->next;
    }
    return 0;
}