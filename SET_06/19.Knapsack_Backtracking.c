#include <stdio.h>

int n, W;
int weight[20], value[20];
int maxValue = 0;

void knapsack(int i, int currentWeight, int currentValue)
{
    if(i == n)
    {
        if(currentValue > maxValue)
            maxValue = currentValue;
        return;
    }

    /* Include the item */
    if(currentWeight + weight[i] <= W)
        knapsack(i + 1, currentWeight + weight[i],
                 currentValue + value[i]);

    /* Exclude the item */
    knapsack(i + 1, currentWeight, currentValue);
}

int main()
{
    int i;

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

    knapsack(0, 0, 0);

    printf("Maximum value = %d\n", maxValue);

    return 0;
}