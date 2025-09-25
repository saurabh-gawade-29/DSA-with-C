#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // size of each queue

// Queue structure
struct Queue
{
    int arr[MAX];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if empty
int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

// Check if full
int isFull(struct Queue *q)
{
    return (q->rear == MAX - 1);
}

// Enqueue operation
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->arr[++q->rear] = value;
    printf("%d enqueued\n", value);
}

// Dequeue operation
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1; // reset queue
    }
    else
    {
        q->front++;
    }
    return val;
}

// Display queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q1, q2;
    initQueue(&q1);
    initQueue(&q2);

    // Working with first queue
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    display(&q1);
    printf("Dequeued from q1: %d\n", dequeue(&q1));
    display(&q1);

    // Working with second queue
    enqueue(&q2, 100);
    enqueue(&q2, 200);
    display(&q2);
    printf("Dequeued from q2: %d\n", dequeue(&q2));
    display(&q2);

    return 0;
}