// Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.

// Example 1:

// Input:
// N = 4
// value[] = {5,2,2,4}
// Output: 5 2 4
// Explanation:Given linked list elements are
// 5->2->2->4, in which 2 is repeated only.
// So, we will delete the extra repeated
// elements 2 from the linked list and the
// resultant linked list will contain 5->2->4
// Example 2:

// Input:
// N = 5
// value[] = {2,2,2,2,2}
// Output: 2
// Explanation:Given linked list elements are
// 2->2->2->2->2, in which 2 is repeated. So,
// we will delete the extra repeated elements
// 2 from the linked list and the resultant
// linked list will contain only 2.
// Your Task:
// You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(N)

// Constraints:
// 1 <= size of linked lists <= 106
// 0 <= numbers in list <= 104

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newNode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node *createlist(int n)
{
    if (n == 0)
        return NULL;
    struct node *head = NULL;
    struct node *temp = NULL;

    int data;
    printf("Enter node data for node 1 :");
    scanf("%d", &data);
    head = newNode(data);
    temp = head;

    for (int i = 2; i <= n; i++)
    {
        printf("Enter node data for node %d :", i);
        scanf("%d", &data);
        temp->next = newNode(data);
        temp = temp->next;
    }
    return head;
}

// struct node *deletenode(struct node *head)
// {
//     struct node *p = head;
//     head = head->next;
//     free(p);
//     return head;
// }

// struct node *removeduplicates(struct node *head, struct node *head2)
// {
//     struct node *temp1 = head;
//     struct node *temp3 = NULL;
//     temp3 = newNode(temp1->data);
//     struct node *temp4 = temp3;
//     temp1 = temp1->next;

//     while (temp1 != NULL)
//     {
//         temp3 = temp4;
//         while (temp3 != NULL)
//         {
//             if (temp3->data == temp1->data)
//                 break;
//             if (temp3->data != temp1->data)
//             {
//                 temp3->next = newNode(temp1->data);
//                 break;
//             }
//             temp3 = temp3->next;
//         }
// temp1= temp1->next;
//     }
//     head2 = temp4;
//     return head2;
// }

struct node *removeduplicates(struct node *head, struct node *head2)
{
    if (head == NULL)
        return NULL;

    struct node *temp1 = head;
    struct node *temp3 = newNode(temp1->data);
    struct node *temp4 = temp3;
    temp1 = temp1->next;
    while (temp1 != NULL)
    {
        struct node *temp2 = temp4;
        while (temp2 != NULL)
        {
            if (temp2->data == temp1->data)
                break;

            if (temp2->next == NULL)
            {
                temp2->next = newNode(temp1->data);
                break;
            }

            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

    head2 = temp4;
    return head2;
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
    printf("Enter the size of the linked list : ");
    scanf("%d", &n);
    struct node *head = createlist(n);
    struct node *head2 = NULL;
    printf("linked list without the duplicates is : \n");
    head2 = removeduplicates(head, head2);
    traversal(head2);

    return 0;
}