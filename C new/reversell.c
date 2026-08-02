#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createnode(int data)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

Node *createlist(int n)
{
    if (n == 0)
        return NULL;
    Node *head = NULL;
    Node *temp = NULL;

    int data;
    printf("Enter date for node 1 : ");
    scanf("%d", &data);
    head = createnode(data);
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        printf("Enter date for node %d : ", i);
        scanf("%d", &data);
        temp->next = createnode(data);
        temp = temp->next;
    }
    return head;
}

void swap(Node *a1, Node *a2)
{
    int temp = a1->data;
    a1->data = a2->data;
    a2->data = temp;
}

void Traversal(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

Node *ReverseLL(Node *head)
{
    Node *last = head;
    Node *temp = head;
    Node *Templast = head;
    while (last->next != NULL)
        last = last->next;
    // head = last;

    return head;
}

int main()
{
    int n;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    Node *head = createlist(n);
    // Traversal(head);
    head = ReverseLL(head);
    printf("%d", head->data);
    return 0;
}