#include <stdio.h> // HEADER
#define MAX 5      // Maximum size of stack

int stack[MAX]; // STACK [5]
int top = -1;   // Initialize top of stack

// Function to push element
void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot insert %d\n", x);
    }
    else
    {
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}

// Function to pop element
void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! No element to pop\n");
    }
    else
    {
        printf("%d popped from stack\n", stack[top--]);
    }
}

// Function to display top element
void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }
}

// Function to display all elements
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// ENTRY POINT
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    pop();
    pop();
    display();
    return 0;
}