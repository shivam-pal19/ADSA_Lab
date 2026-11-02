#include <stdio.h>

int main()
{
    int coins[10], n, amount, i, count = 0;

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    printf("Enter denominations in descending order: ");
    for(i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Coins used: ");

    for(i = 0; i < n; i++)
    {
        while(amount >= coins[i])
        {
            printf("%d ", coins[i]);
            amount -= coins[i];
            count++;
        }
    }

    if(amount != 0)
        printf("\nExact amount cannot be formed.\n");
    else
        printf("\nNumber of coins = %d\n", count);

    return 0;
}