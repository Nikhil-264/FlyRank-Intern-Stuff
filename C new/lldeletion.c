#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} snd;
void traversal(snd *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
snd *deletefirst(snd *head)
{
    snd *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

snd *deleteatindex(snd *head, int index)
{
    int i = 0;
    snd *ptr = head;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    snd *next = ptr->next;
    ptr->next = next->next;
    free(next);
    return head;
}

snd *deletelast(snd *head)
{
    snd *p = head;
    snd *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

snd *deletebyvalue(snd *head, int value)
{
    snd *p = head;
    snd *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    snd *head;
    snd *second;
    snd *third;
    snd *forth;

    // memory alloaction for each pointer
    head = (snd *)malloc(sizeof(snd));
    second = (snd *)malloc(sizeof(snd));
    forth = (snd *)malloc(sizeof(snd));
    third = (snd *)malloc(sizeof(snd));

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

    // traversal(head);
    // head = deletefirst(head);
    // traversal(head);
    // head = deleteatindex(head, 3);
    // traversal(head);
    // head = deletelast(head);
    // traversal(head);
    head = deletebyvalue(head, 34);
    traversal(head);

    return 0;
}