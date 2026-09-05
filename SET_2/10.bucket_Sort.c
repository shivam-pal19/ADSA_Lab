#include <stdio.h>

int main()
{
    int a[100], bucket[10][100], count[10] = {0};
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
        index = (a[i] * 10) / (max + 1);
        bucket[index][count[index]++] = a[i];
    }

    for(i = 0; i < 10; i++)
        for(j = 1; j < count[i]; j++)
        {
            int temp = bucket[i][j];
            k = j - 1;

            while(k >= 0 && bucket[i][k] > temp)
            {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }

            bucket[i][k + 1] = temp;
        }

    printf("Sorted array: ");
    for(i = 0; i < 10; i++)
        for(j = 0; j < count[i]; j++)
            printf("%d ", bucket[i][j]);

    return 0;
}