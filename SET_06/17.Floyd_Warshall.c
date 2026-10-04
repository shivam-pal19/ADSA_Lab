#include <stdio.h>

#define INF 9999

int main()
{
    int a[20][20], n;
    int i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    printf("(Enter 9999 for no direct edge)\n");

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][k] != INF && a[k][j] != INF &&
                   a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
    }

    printf("All Pairs Shortest Path:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}