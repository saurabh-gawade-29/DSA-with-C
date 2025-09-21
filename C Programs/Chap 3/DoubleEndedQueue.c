#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() { return (rear == MAX - 1 && front == 0); }
int isEmpty() { return (front == -1); }

void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        printf("Cannot insert at rear\n");
        return;
    }
    else
        rear++;
    deque[rear] = value;
    printf("%d inserted at rear\n", value);
}

void insertFront(int value)
{
    if (isFull() || front == 0)
    {
        printf("Cannot insert at front\n");
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
    }
    else
        front--;
    deque[front] = value;
    printf("%d inserted at front\n", value);
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("%d deleted from front\n", deque[front]);
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Underflow\n");
        return;
    }
    printf("%d deleted from rear\n", deque[rear]);
    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    deleteRear();
    deleteFront();
    return 0;
}