#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top--];
}

char peek()
{
    if (top == -1)
    {
        return '\0';
    }

    return stack[top];
}

int precedence(char ch)
{
    if (ch == '/' || ch == '*')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* Ignore spaces */
        if (ch == ' ')
            continue;

        /* Single digit operand */
        if (isdigit(ch))
        {
            postfix[j++] = ch;
        }

        /* Opening parenthesis */
        else if (ch == '(')
        {
            push(ch);
        }

        /* Closing parenthesis */
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }

        /* Operator */
        else if (isOperator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }

        /* Invalid character */
        else
        {
            printf("Invalid character '%c' in expression.\n", ch);
            postfix[0] = '\0';
            return;
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        if (peek() == '(')
        {
            printf("Invalid expression: unmatched '('.\n");
            postfix[0] = '\0';
            return;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%99[^\n]", infix);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0')
    {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}

