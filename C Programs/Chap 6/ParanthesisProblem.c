#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }

int isMatching(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int isBalanced(char exp[])
{
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
                return 0; // no opening bracket to match
            if (!isMatching(pop(), exp[i]))
                return 0; // mismatch
        }
    }
    return (top == -1); // empty stack = balanced
}

int main()
{
    char exp[100];
    printf("Enter expression: ");
    // Use fgets instead of gets
    fgets(exp, sizeof(exp), stdin);
    // Remove newline character added by fgets
    exp[strcspn(exp, "\n")] = 0;

    if (isBalanced(exp))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");
    return 0;
}