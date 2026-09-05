#include <stdio.h>

void radixExchange(int a[], int left, int right, int bit)
{
    if(left >= right || bit < 0)
        return;

    int i = left, j = right, temp;

    while(i <= j)
    {
        while(i <= j && !(a[i] & (1 << bit)))
            i++;

        while(i <= j && (a[j] & (1 << bit)))
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    radixExchange(a, left, j, bit - 1);
    radixExchange(a, i, right, bit - 1);
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixExchange(a, 0, n - 1, 30);

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}