#include <stdio.h> // header file
#define MAX 5      // max size 5

int queue[MAX];            // empty array
int front = -1, rear = -1; // future: reaer+1 i.e. my value index is zero

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return rear == MAX - 1;
}

// Function to add an element
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;              // rear=0
    queue[rear] = value; // 10 at index 0
    printf("%d enqueued to queue\n", value);
}

// element removal:
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front++;
    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() // main function
{
    enqueue(10); // add 10
    enqueue(20); // add 20
    enqueue(30); // add 30
    display();   // display queue

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); // overflow
    display();

    return 0;
}