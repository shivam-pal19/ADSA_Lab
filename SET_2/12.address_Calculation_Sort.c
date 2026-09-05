#include <stdio.h>

int main()
{
    int a[100], b[100][100], count[100] = {0};
    int n, i, j, k, index, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = a[0];

    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];

    for(i = 0; i < n; i++)
    {
        index = (a[i] * n) / (max + 1);
        b[index][count[index]++] = a[i];
    }

    for(i = 0; i < n; i++)
        for(j = 1; j < count[i]; j++)
        {
            int temp = b[i][j];
            k = j - 1;

            while(k >= 0 && b[i][k] > temp)
            {
                b[i][k + 1] = b[i][k];
                k--;
            }

            b[i][k + 1] = temp;
        }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        for(j = 0; j < count[i]; j++)
            printf("%d ", b[i][j]);

    return 0;
}