#include <stdio.h>
#include <string.h>

#define MAX 1000
#define CHAR 256

int main()
{
    char text[MAX], pat[MAX];
    int bad[CHAR], n, m, i, j, s, found = 0;

    printf("Enter text: ");
    scanf("%999s", text);

    printf("Enter pattern: ");
    scanf("%999s", pat);

    n = strlen(text);
    m = strlen(pat);

    if (m > n)
    {
        printf("Pattern not found.\n");
        return 0;
    }

    for (i = 0; i < CHAR; i++)
        bad[i] = -1;

    for (i = 0; i < m; i++)
        bad[(unsigned char)pat[i]] = i;

    s = 0;

    while (s <= n - m)
    {
        j = m - 1;

        while (j >= 0 && pat[j] == text[s + j])
            j--;

        if (j < 0)
        {
            printf("Pattern found at index %d\n", s);
            found = 1;

            if (s + m < n)
                s += m - bad[(unsigned char)text[s + m]];
            else
                s++;
        }
        else
        {
            int shift = j - bad[(unsigned char)text[s + j]];
            s += (shift > 1) ? shift : 1;
        }
    }

    if (!found)
        printf("Pattern not found.\n");

    return 0;
}