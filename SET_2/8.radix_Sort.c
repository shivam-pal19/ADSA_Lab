#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0], i;

    for(i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];

    return max;
}

void countingSort(int a[], int n, int exp)
{
    int output[100], count[10] = {0};
    int i;

    for(i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int a[100], n, i, max, exp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max = getMax(a, n);

    for(exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}