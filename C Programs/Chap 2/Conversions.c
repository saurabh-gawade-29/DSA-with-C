/* simple_expr_conv_eval.c
   Compile: gcc -o expr simple_expr_conv_eval.c
   Run: ./expr
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ---------- helper utilities ---------- */
int isOperatorChar(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%';
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void reverseStr(char *s)
{
    int i = 0, j = strlen(s) - 1;
    while (i < j)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

/* ---------- Infix -> Postfix (single-char operands) ---------- */
void infixToPostfix(const char *infix, char *postfix)
{
    char stack[256];
    int top = -1;
    int k = 0; // postfix index

    for (int i = 0; infix[i] != '\0'; ++i)
    {
        char c = infix[i];
        if (isspace((unsigned char)c))
            continue;

        if (isalnum((unsigned char)c))
        { // operand (letter or digit)
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[k++] = stack[top--];
            if (top >= 0 && stack[top] == '(')
                top--; // pop '('
        }
        else if (isOperatorChar(c))
        {
            while (top >= 0 && isOperatorChar(stack[top]) &&
                   (precedence(stack[top]) >= precedence(c) &&
                    stack[top] != '('))
            {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top >= 0)
        postfix[k++] = stack[top--];
    postfix[k] = '\0';
}

/* ---------- Infix -> Prefix (uses reverse trick) ---------- */
void infixToPrefix(const char *infix, char *prefix)
{
    // 1) reverse infix into temp, swapping parentheses
    int n = strlen(infix);
    char tmp[512];
    int idx = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        char c = infix[i];
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
        tmp[idx++] = c;
    }
    tmp[idx] = '\0';

    // 2) convert tmp (modified reversed infix) to postfix
    char post[512];
    infixToPostfix(tmp, post);

    // 3) reverse postfix -> prefix
    strcpy(prefix, post);
    reverseStr(prefix);
}

/* ---------- Evaluate Postfix (space-separated tokens) ---------- */
long long applyOpLong(long long a, long long b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b; // integer division
    case '%':
        return a % b;
    case '^':
    { // integer power
        long long res = 1;
        for (long long i = 0; i < b; ++i)
            res *= a;
        return res;
    }
    }
    return 0;
}

long long evaluatePostfix(const char *expr)
{
    // tokens split by space, supports multi-digit numbers
    char *copy = strdup(expr);
    char *token = strtok(copy, " ");
    long long stack[512];
    int top = -1;

    while (token)
    {
        if (strlen(token) == 1 && isOperatorChar(token[0]))
        {
            long long b = stack[top--];
            long long a = stack[top--];
            long long r = applyOpLong(a, b, token[0]);
            stack[++top] = r;
        }
        else
        {
            stack[++top] = atoll(token); // parse number (supports multi-digit)
        }
        token = strtok(NULL, " ");
    }
    long long result = (top >= 0) ? stack[top] : 0;
    free(copy);
    return result;
}

/* ---------- Evaluate Prefix (space-separated tokens) ---------- */
long long evaluatePrefix(const char *expr)
{
    // tokenize into array
    char *copy = strdup(expr);
    int cap = 128;
    char **tokens = malloc(sizeof(char *) * cap);
    int cnt = 0;

    char *t = strtok(copy, " ");
    while (t)
    {
        if (cnt >= cap)
        {
            cap *= 2;
            tokens = realloc(tokens, sizeof(char *) * cap);
        }
        tokens[cnt++] = strdup(t);
        t = strtok(NULL, " ");
    }
    long long stack[512];
    int top = -1;

    for (int i = cnt - 1; i >= 0; --i)
    {
        char *tok = tokens[i];
        if (strlen(tok) == 1 && isOperatorChar(tok[0]))
        {
            long long a = stack[top--];
            long long b = stack[top--];
            long long r = applyOpLong(a, b, tok[0]);
            stack[++top] = r;
        }
        else
        {
            stack[++top] = atoll(tok);
        }
        free(tokens[i]);
    }
    free(tokens);
    free(copy);
    return (top >= 0) ? stack[top] : 0;
}

/* ---------- Demo main ---------- */
int main()
{
    // Part 1: Conversions (example: (A+B)*C )
    const char *infixExample = "(A+B)*C";
    char postfix[512], prefix[512];

    infixToPostfix(infixExample, postfix);
    infixToPrefix(infixExample, prefix);

    printf("Infix : %s\n", infixExample);
    printf("Postfix : %s\n", postfix); // Should be AB+C*
    printf("Prefix : %s\n\n", prefix); // Should be *+ABC

    // Part 2: Evaluations (numeric examples)
    const char *postfixNum = "5 3 + 2 *"; // from your notes
    long long postRes = evaluatePostfix(postfixNum);
    printf("Evaluate Postfix: \"%s\"  => %lld\n", postfixNum, postRes); // 16

    const char *prefixNum = "* + 5 3 2"; // from your notes
    long long preRes = evaluatePrefix(prefixNum);
    printf("Evaluate Prefix: \"%s\" => %lld\n", prefixNum, preRes); // 16

    return 0;
}