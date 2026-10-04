#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, W;
    int weight[20], value[20];
    int dp[20][100];

    int i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter values:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &value[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    for(w = 0; w <= W; w++)
        dp[0][w] = 0;

    for(i = 1; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if(weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] +
                               dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum value = %d\n", dp[n][W]);

    return 0;
}