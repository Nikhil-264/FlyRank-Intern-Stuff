// Given a singly linked list of N nodes.
// The task is to find the middle of the linked list. For example, if the linked list is
// 1-> 2->3->4->5, then the middle node of the list is 3.
// If there are two middle nodes(in case, when N is even), print the second middle element.
// For example, if the linked list given is 1->2->3->4->5->6, then the middle node of the list is 4.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5
// Output: 3
// Explanation:
// Middle of linked list is 3.
// Example 2:

// Input:
// LinkedList: 2->4->6->7->5->1
// Output: 7
// Explanation:
// Middle of linked list is 7.
// Your Task:
// The task is to complete the function getMiddle() which takes a head reference as the only argument and should return the data at the middle node of the linked list.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 5000

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
    temp =head;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter date for node %d : ", i);
        scanf("%d", &data);
        temp->next = createnode(data);
        temp = temp->next;
    }
    return head;
}
// blackbox written
mll *getMiddle(mll *head)
{
    mll *fast = head;
    mll *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// mine
mll *middleget(mll *head, int n)
{
    mll *point = head;
    int k = 0;
    while (k < n / 2)
    {
        point = point->next;
        k++;
    }
    return point;
}

int main()
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    mll *head = createlist(n);
    mll *middle1 = getMiddle(head);
    printf("Middle node is %d\n", middle1->data);
    mll *middle2 = middleget(head, n);
    printf("Middle node is %d\n", middle2->data);
    return 0;
}
//learn the logic