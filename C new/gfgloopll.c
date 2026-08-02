// //removing loop in  ll
// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|
// A loop is present. If you remove it
// successfully, the answer will be 1.

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not
// contains any loop.

// Example 3:

// Input:
// N = 4
// value[] = {1,2,3,4}
// X = 1
// Output: 1
// Explanation: The link list looks like
// 1 -> 2 -> 3 -> 4
// ^              |
// |______________|
// A loop is present.
// If you remove it successfully,
// the answer will be 1.

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
// Note: The generated output will be 1 if your submitted code is correct.

// Expected time complexity: O(N)
// Expected auxiliary space: O(1)

// Constraints:
// 1 ≤ N ≤ 10^4

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

snode *createlist(int n, int *arr, int x)
{
    if (n == 0)
        return NULL;
    snode *head = NULL;
    snode *temp = NULL;
    snode *temp1 = NULL;

    int data;
    data = arr[0];
    head = createnode(data);
    temp = head;
    if (x == 0)
        printf("No loop in list\n");
    if (x == 1)
        temp1 = head;

    for (int i = 2; i <= n; i++)
    {
        if (x == i)
            temp1 = temp;
        data = arr[i - 1];
        temp->next = createnode(data);
        temp = temp->next;
    }
    temp->next = temp1;
    return head;
}
void traversal(struct node *ptr)
{
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
    int x;
    printf("Enter the index where to be linked the last : ");
    scanf("%d", &x);
    snode *head = createlist(n, arr, x);
    printf("List : \n");
    traversal(head);
    return 0;
}