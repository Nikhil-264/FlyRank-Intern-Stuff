#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;
void display(node *head)
{
    node *current = head;
    while (current != NULL)
    {
        printf("Element = %d\n ", current->data);
        current = current->next;
    }
    printf("\n");
}

node *insert_at_beginning(node *head, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head;
    new_node->prev = NULL;
    head->prev = new_node;
    return new_node;
}
void insert_at_end(node **head, int data);
void insert_at_index(node **head, int data, int index);
void delete_at_beginning(node **head);
void delete_at_end(node **head);
void delete_at_index(node **head, int index);
void reverse_list(node **head)
{ 
}

int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    node *tail;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));

    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = tail;
    tail->prev = fourth;
    tail->next = NULL;
    head->data = 2;
    second->data = 1;
    third->data = 3;
    fourth->data = 4;
    tail->data = 5;

    head = insert_at_beginning(head, 6);
    display(head);

    return 0;
}