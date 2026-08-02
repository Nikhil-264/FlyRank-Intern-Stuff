#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

int push(struct stack *s, int value)
{
    if (is_full(s))
    {
        printf("Stack overflow\n");
        return 0;
    }
    s->top++;
    s->arr[s->top] = value;
    return 1;
}

int pop(struct stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int peek(struct stack *s, int i)
{
    // i is the position of the element in the stack from the top and it is related to the index of the array as i = top - index + 1
    // int index = s->top + 1 - i;
    if (s->top + 1 - i < 0)
    {
        printf("Invalid position\n");
        return -1;
    }
    return *(s->arr + s->top + 1 - i);
}

int stacktop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    else
        return *(s->arr + s->top);
}

int stackbottom(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    else
        return *(s->arr);
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 60;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // pushing element manually
    //  s->top++;
    //  s->arr[s->top] = 7;
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    push(s, 12);
    // push(s, 10);
    // int popped = pop(s);
    // printf("popped: %d\n", popped);
    // popped = pop(s);
    // printf("popped: %d\n", popped);
    // popped = pop(s);
    // printf("popped: %d\n", popped);
    // popped = pop(s);

    // stack empty check
    if (is_empty(s))
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");

    // stack full check
    // if (is_full(s))
    //     printf("Stack is full.\n");
    // else
    //     printf("Stack is not full.\n");
    // printf("%d ", peek(s, 17));
    // printf("%d ", stacktop(s));
    // printf("%d ", stackbottom(s));

    // for (int i = 0; i < s->top; i++)
    // {
    //     printf("%d ", s->arr[i]);
    // }

    return 0;
}