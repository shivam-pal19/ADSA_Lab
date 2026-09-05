#include <stdio.h>

int main()
{
    int a[100], temp[100];
    int n, i, j, k, size, left, mid, right;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(size = 1; size < n; size *= 2)
    {
        for(left = 0; left < n - 1; left += 2 * size)
        {
            mid = left + size - 1;
            right = left + 2 * size - 1;

            if(mid >= n)
                continue;

            if(right >= n)
                right = n - 1;

            i = left;
            j = mid + 1;
            k = left;

            while(i <= mid && j <= right)
            {
                if(a[i] <= a[j])
                    temp[k++] = a[i++];
                else
                    temp[k++] = a[j++];
            }

            while(i <= mid)
                temp[k++] = a[i++];

            while(j <= right)
                temp[k++] = a[j++];

            for(i = left; i <= right; i++)
                a[i] = temp[i];
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}