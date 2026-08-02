#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size, f, r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("Queue is full !");
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("Queue is empty !");
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct queue q;
    q.size = 100;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.f = q.r = -1;
    enqueue(&q, 12);
    if (isEmpty(&q))
        printf("Queue is empty\n");
    enqueue(&q, 34);
    if (isFull(&q))
        printf("Queue is full\n");
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));

    return 0;
}