#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

node *top = NULL;

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
    free(p);
    return 0;
}

struct node *push(struct node *tp, char x)
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
    return tp;
}

char pop(struct node **tp)
{
    if (is_empty(*tp))
        printf("Stack Underflow\n");
    else
    {
        struct node *p = *tp;
        *tp = (*tp)->next;
        char x = p->data;
        free(p);
        return x;
    }
    return '\0';
}

void traversal(struct node *ptr)
{
    printf("stack : \n");
    while (ptr != NULL)
    {
        printf("Element : %c\n", ptr->data);
        ptr = ptr->next;
    }
}

void checkparenthesis(char *str, int n, node *tp)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
           tp= push(tp, str[i]);
        else if (str[i] == ')')
        {
            if (is_empty(tp))
            {
                printf("Invalid Parenthesis\n");
                return;
            }
            else
                pop(&tp);
        }
    }
    if (is_empty(tp))
        printf("Valid Parenthesis\n");
    else
        printf("Invalid Parenthesis\n");
}

int main()
{
    char *str = (char *)malloc(100 * sizeof(char));
    fgets(str,100,stdin);
    int n = strlen(str);
    checkparenthesis(str, n, top);
    // puts(str);

    return 0;
}