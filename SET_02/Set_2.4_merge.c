#include <stdio.h>

typedef struct
{
    int low, high;
} Stack;

int main()
{
    int a[100], n, i, j, k, mid, temp;
    Stack s[100];
    int top = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    s[++top].low = 0;
    s[top].high = n - 1;

    while(top >= 0)
    {
        int low = s[top].low;
        int high = s[top].high;
        top--;

        if(low >= high)
            continue;

        mid = (low + high) / 2;

        s[++top].low = low;
        s[top].high = mid;

        s[++top].low = mid + 1;
        s[top].high = high;
    }

    /* Bottom-up merging */
    for(int size = 1; size < n; size *= 2)
    {
        for(int left = 0; left < n - size; left += 2 * size)
        {
            mid = left + size - 1;
            int right = left + 2 * size - 1;

            if(right >= n)
                right = n - 1;

            i = left;
            j = mid + 1;
            k = 0;
            int b[100];

            while(i <= mid && j <= right)
                b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];

            while(i <= mid)
                b[k++] = a[i++];

            while(j <= right)
                b[k++] = a[j++];

            for(i = left, j = 0; i <= right; i++, j++)
                a[i] = b[j];
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}