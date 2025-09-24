#include <stdio.h>
#define MAX 5

int queue[MAX];
int n = 0;

void enqueue(int value)
{
    if (n == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }
    int i = n - 1; // 0
    while (i >= 0 && queue[i] < value)
    {
        queue[i + 1] = queue[i];
        i--; //-1
    }
    queue[i + 1] = value;
    n++;
    printf("%d enqueued\n", value);
}

void dequeue()
{
    if (n == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }
    printf("%d dequeued\n", queue[0]);
    for (int i = 1; i < n; i++)
        queue[i - 1] = queue[i];
    n--;
}

void display()
{
    if (n == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(30);
    enqueue(20);
    display();
    dequeue();
    display();
    return 0;
}