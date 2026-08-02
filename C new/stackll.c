// creating stack using linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

struct stack
{
    int top;
    node *head;
};

int is_empty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}


node *createnode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

node *push(struct stack *s, int data)
{
    node *newnode = createnode(data);
    if (s->head == NULL)
    {
        s->head = newnode;
        s->top = 0;
        return newnode;
    }
    else
    {
        s->top++;
        newnode->next = s->head;
        s->head = newnode;
        return newnode;
    }
}

node *pop(struct stack *s)
{
    if (is_empty(s))

    {
        printf("Stack is empty\n");
        return NULL;
    }
    else
    {
        node *temp = s->head;
        s->head = s->head->next;
        s->top--;
        return temp;
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

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->head = NULL;
    node *k = push(s, 4);
    k = push(s, 5);
    k = push(s, 6);
    k = pop(s);
    k = pop(s);
    k = pop(s);
    printf("%d  \n", is_empty(s));
    traversal(s->head);

    return 0;
}