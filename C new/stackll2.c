#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

int is_empty(struct node *tp)
{
    if (tp == NULL)
        return 1;
    return 0;
}
int is_full(struct node *tp)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
        return 1;
    return 0;
}
struct node *push(struct node *tp, int x)
{
    if (is_full(tp))
        printf("Stack overflow\n");
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = x;
        p->next = tp;
        tp = p;
        return tp;
    }
}

int pop(struct node *tp)
{
    if (is_empty(tp))
        printf("Stack Underflow\n");
    else
    {
        struct node *p = tp;
        top = (tp)->next;
        int x = p->data;
        free(p);
        return x;
    }
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

int peek(struct node *tp, int position)
{
    struct node *ptr = tp;
    int i = 1;
    while ((i < position) && (ptr != NULL))
    {
        ptr = ptr->next;
        i++;
    }
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int stacktop(struct node *tp)
{
    if (tp != NULL)
        return tp->data;
    else
        return -1;
}

int stackbottom(struct node *tp)
{
    struct node *ptr = tp;
    while (ptr->next != NULL)
        ptr = ptr->next;
    return ptr->data;
}

int main()
{
    top = push(top, 45);
    top = push(top, 56);
    top = push(top, 78);
    top = push(top, 90);
    top = push(top, 99);
    top = push(top, 101);

    int popped = pop(top);
    printf("Popped : %d\n", popped);
    printf("%d ", peek(top, 3));
    printf("%d ", peek(top, 4));
    printf("%d ", peek(top, 6));
    printf("%d ", peek(top, 1));
    printf("%d ", stackbottom(top));
    printf("%d ", stacktop(top));
    traversal(top);

    return 0;
}