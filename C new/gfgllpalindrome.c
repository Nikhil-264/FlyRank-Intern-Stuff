// Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

// Example 1:

// Input:
// N = 3
// value[] = {1,2,1}
// Output: 1
// Explanation: The given linked list is
// 1 2 1 , which is a palindrome and
// Hence, the output is 1.
// Example 2:

// Input:
// N = 4
// value[] = {1,2,3,4}
// Output: 0
// Explanation: The given linked list
// is 1 2 3 4 , which is not a palindrome
// and Hence, the output is 0.
// Your Task:
// The task is to complete the function isPalindrome() which takes head as reference as the only parameter and returns true or false if linked list is palindrome or not respectively.

// Expected Time Complexity: O(N)
// Expected Auxialliary Space Usage: O(1)  (ie, you should not use the recursive stack space as well)

// Constraints:
// 1 <= N <= 105

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} mll;

mll *createnode(int data)
{
    mll *newnode = (mll *)malloc(sizeof(mll));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
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
    int i;
    for (i = 2; i <= n; i++)
    {
        printf("Enter date for node %d : ", i);
        scanf("%d", &data);
        temp->next = createnode(data);
        temp->next->prev = temp;
        temp = temp->next;
    }
    return head;
}

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

void is_palindrome(mll *middle1, mll *middle2, int n)
{
    int flag = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (middle1->data != middle2->data)
        {
            printf("This linked list is not the palindrome ! \n");
            return;
        }
        if (middle1->data == middle2->data)
        {
            flag++;
            middle1 = middle1->prev;
            middle2 = middle2->next;
        }
    }
    if (flag == n / 2)
        printf("Yes !, It is palindrome \n");
}

int main()
{
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    mll *head = createlist(n);
    mll *middle1 = getMiddle(head);
    mll *middle2 = middleget(head, n);
    is_palindrome(middle1, middle2, n);
    return 0;
}


// //given by chatGPT
// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// typedef struct node
// {
//     int data;
//     struct node *next;
// } mll;

// mll *createnode(int data)
// {
//     mll *newnode = (mll *)malloc(sizeof(mll));
//     newnode->data = data;
//     newnode->next = NULL;
//     return newnode;
// }

// mll *createlist(int n)
// {
//     if (n == 0)
//         return NULL;
//     mll *head = NULL;
//     mll *temp = NULL;

//     int data;
//     printf("Enter data for node 1: ");
//     scanf("%d", &data);
//     head = createnode(data);
//     temp = head;
//     int i;
//     for (i = 2; i <= n; i++)
//     {
//         printf("Enter data for node %d: ", i);
//         scanf("%d", &data);
//         temp->next = createnode(data);
//         temp = temp->next;
//     }
//     return head;
// }

// mll *reverseList(mll *head)
// {
//     mll *prev = NULL;
//     mll *curr = head;
//     mll *next = NULL;

//     while (curr != NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }

//     return prev;
// }

// bool isPalindrome(mll *head)
// {
//     if (head == NULL || head->next == NULL)
//         return true;

//     mll *slow = head;
//     mll *fast = head;

//     // Find the middle of the linked list
//     while (fast->next != NULL && fast->next->next != NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     // Reverse the second half of the linked list
//     mll *secondHalf = reverseList(slow->next);

//     // Compare the first half and the reversed second half of the linked list
//     mll *p1 = head;
//     mll *p2 = secondHalf;
//     bool isPalindrome = true;

//     while (p2 != NULL)
//     {
//         if (p1->data != p2->data)
//         {
//             isPalindrome = false;
//             break;
//         }
//         p1 = p1->next;
//         p2 = p2->next;
//     }

//     // Restore the original linked list by reversing the second half again
//     slow->next = reverseList(secondHalf);

//     return isPalindrome;
// }

// int main()
// {
//     int n;
//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);
//     mll *head = createlist(n);

//     if (isPalindrome(head))
//         printf("Yes, it is a palindrome.\n");
//     else
//         printf("No, it is not a palindrome.\n");

//     return 0;
// }
