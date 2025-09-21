#include <stdio.h>
#define MAX 10 // max length of the array

int arr[MAX]; // empty array with fix size of 10
int top1 = -1;  // Stack 1 grows from left to right
int top2 = MAX; // Stack 2 grows from right to left

// Push in Stack 1
void push1(int val)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        arr[++top1] = val; // arr[0]=10
        printf("%d pushed in Stack1.\n", val);
    }
}

// Push in Stack 2
void push2(int val)
{
    if (top1 + 1 == top2)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        arr[--top2] = val;
        printf("%d pushed in Stack2.\n", val);
    }
}

// Pop from Stack 1
void pop1()
{
    if (top1 == -1)
    {
        printf("Stack1 Underflow!\n");
    }
    else
    {
        printf("%d popped from Stack1.\n", arr[top1--]);
    }
}

// Pop from Stack 2
void pop2()
{
    if (top2 == MAX)
    {
        printf("Stack2 Underflow!\n");
    }
    else
    {
        printf("%d popped from Stack2.\n", arr[top2++]);
    }
}

// ENTRY POINT
int main()
{
    push1(10); // stack 1 -> 10
    push1(20); // stack 1 -> 10,20
    push2(50); // stack 2 -> 50
    push2(60); // stack 2 -> 50,60
    pop1(); // stack 1 -> 10
    pop2(); // stack 2 -> 50
    return 0;
}