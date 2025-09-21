#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isFull()
{
    return ((rear + 1) % MAX == front);
}

int isEmpty()
{
    return (front == -1);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d enqueued\n", value);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Circular Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(50);
    enqueue(60);
    display();
    return 0;
}