#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
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
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;

    // memory alloaction for each pointer
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    forth = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    // linking to next pointer

    head->data = 21;
    head->next = second;
    second->data = 34;
    second->next = third;
    third->data = 56;
    third->next = forth;
    forth->data = 78;
    forth->next = NULL;

    // travesing function
    
    traversal(head);

    return 0;
}