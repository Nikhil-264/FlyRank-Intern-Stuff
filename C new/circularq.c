#include <stdio.h>
#include <stdlib.h>

struct CircularQueue
{
    int size, f, r;
    int *arr;
};

int isFull(struct CircularQueue *q)
{
    if ((q->r + 1) % (q->size) == q->f)
        return 1;
    return 0;
}

int isEmpty(struct CircularQueue *q)
{
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct CircularQueue *q, int val)
{
    if (isFull(q))
        printf("Queue is full !\n");
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct CircularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
        printf("Queue is empty !\n");
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct CircularQueue
        q;
    q.size = 4;
    q.arr = (int *)malloc(q.size * sizeof(int));
    q.f = q.r = 0;
    enqueue(&q, 12);
    if (isEmpty(&q))
        printf("Queue is empty\n");
    enqueue(&q, 34);
    enqueue(&q, 56);
    enqueue(&q, 78);
    enqueue(&q, 90);
    // enqueue(&q, 102);
    // enqueue(&q, 114);
    // enqueue(&q, 126);
    // enqueue(&q, 138);
    // enqueue(&q, 150);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    if (isFull(&q))
        printf("Queue is full\n");
    // printf("%d\n", dequeue(&q));
    // printf("%d\n", dequeue(&q));

    return 0;
}