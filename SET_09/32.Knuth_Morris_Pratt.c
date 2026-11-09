#include <stdio.h>
#include <string.h>

void computeLPS(char pat[], int m, int lps[])
{
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i++] = ++len;
        }
        else if (len != 0)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
}

int main()
{
    char text[1000], pat[100];
    int lps[100], i = 0, j = 0;
    int n, m, found = 0;

    printf("Enter text: ");
    scanf("%999s", text);

    printf("Enter pattern: ");
    scanf("%99s", pat);

    n = strlen(text);
    m = strlen(pat);

    computeLPS(pat, m, lps);

    while (i < n)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (!found)
        printf("Pattern not found.\n");

    return 0;
}