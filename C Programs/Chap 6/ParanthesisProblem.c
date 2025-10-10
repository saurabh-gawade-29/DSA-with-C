#include <stdio.h>
#include <string.h> // string manupulation functions

char stack[100]; // variable - 100
int top = -1;    // empty stack

void push(char c) { stack[++top] = c; } // push expression
char pop() { return stack[top--]; }     // delete expression

int isMatching(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '{' && b == '}') ||
           (a == '[' && b == ']');
}

int isBalanced(char exp[]) // check for balanced expression 
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
    // Use fgets instead of gets // depricated function
    fgets(exp, sizeof(exp), stdin);
    // Remove newline character added by fgets
    exp[strcspn(exp, "\n")] = 0;

    if (isBalanced(exp))
        printf("Expression is Balanced\n");
    else
        printf("Expression is Not Balanced\n");
    return 0;
}