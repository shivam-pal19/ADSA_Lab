#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int val[MAX], top = -1;
char op[MAX];
int otop = -1;

int precedence(char c)
{
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void apply()
{
    int b = val[top--];
    int a = val[top--];
    char c = op[otop--];

    if (c == '+') val[++top] = a + b;
    else if (c == '-') val[++top] = a - b;
    else if (c == '*') val[++top] = a * b;
    else if (c == '/') val[++top] = a / b;
}

int main(int argc, char *argv[])
{
    int i, n;
    char c;

    if (argc < 2)
    {
        printf("Enter expression as command line argument.\n");
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        char *s = argv[i];

        while (*s)
        {
            if (isdigit(*s))
            {
                n = 0;
                while (isdigit(*s))
                {
                    n = n * 10 + (*s - '0');
                    s++;
                }
                val[++top] = n;
                continue;
            }

            c = *s;

            if (c == '(')
                op[++otop] = c;

            else if (c == ')')
            {
                while (otop >= 0 && op[otop] != '(')
                    apply();
                otop--;   /* remove '(' */
            }

            else if (c == '+' || c == '-' || c == '*' || c == '/')
            {
                while (otop >= 0 && op[otop] != '(' &&
                       precedence(op[otop]) >= precedence(c))
                    apply();

                op[++otop] = c;
            }

            s++;
        }
    }

    while (otop >= 0)
        apply();

    printf("%d\n", val[top]);

    return 0;
}