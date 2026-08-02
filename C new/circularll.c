#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertfirst(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    struct node *p = head->next;
    while (p->next != head)
        p = p->next;
    newnode->next = head;
    p->next = newnode;
    head = newnode;
    return head;
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
    forth->next = head; // last pointer pointing to first head

    // travesing function

    // traversal(head);
    head = insertfirst(head, 54);
    head = insertfirst(head, 69);
    head = insertfirst(head, 73);
    traversal(head);

    return 0;
}