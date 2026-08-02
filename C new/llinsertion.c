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
// inserting at first function
struct node *insertatfirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// inserting ar specific index / insert at between function
struct node *insertatindex(struct node *head, int data, int index)//insert at between
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// inserting at the end
struct node *insertatend(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// insertion at the given node
struct node *insertafternode(struct node *head, struct node *prevnode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
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
    forth->next = NULL;
    // travesing function

    // before inserting element
    // traversal(head);
    // printf("\n");
    // // inserting at first//45 added ar beginning
    // head = insertatfirst(head, 45);
    // traversal(head);
    // printf("\n");
    // // inserting at index

    // head = insertatindex(head, 89, 2);
    // traversal(head);
    // printf("\n");

    // // imserting at end
    // head = insertatend(head, 69);
    // traversal(head);
    // printf("\n");

    // inserting at node
    head = insertafternode(head, second, 33);
    traversal(head);
    printf("\n");

    return 0;
}
