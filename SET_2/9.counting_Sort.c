#include <stdio.h>

int main()
{
    int a[100], count[100] = {0};
    int n, i, j, max;

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
        count[a[i]]++;

    printf("Sorted array: ");
    for(i = 0; i <= max; i++)
        while(count[i]--)
            printf("%d ", i);

    return 0;
}