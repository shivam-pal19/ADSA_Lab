#include <stdio.h>
#include <string.h>

#define d 256
#define q 101

int main()
{
    char text[1000], pat[100];
    int i, j, n, m, p = 0, t = 0, h = 1;

    printf("Enter text: ");
    scanf("%999s", text);

    printf("Enter pattern: ");
    scanf("%99s", pat);

    n = strlen(text);
    m = strlen(pat);

    if (m > n)
    {
        printf("Pattern not found.\n");
        return 0;
    }

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
                if (text[i + j] != pat[j])
                    break;

            if (j == m)
                printf("Pattern found at index %d\n", i);
        }

        if (i < n - m)
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }

    return 0;
}