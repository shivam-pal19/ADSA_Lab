#include <stdio.h>

struct Job
{
    int id, deadline, profit;
};

int main()
{
    struct Job job[20], temp;
    int n, i, j, maxDeadline = 0, totalProfit = 0;
    int slot[20] = {0};

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter deadline and profit for each job:\n");
    for(i = 0; i < n; i++)
    {
        job[i].id = i + 1;
        scanf("%d %d", &job[i].deadline, &job[i].profit);

        if(job[i].deadline > maxDeadline)
            maxDeadline = job[i].deadline;
    }

    /* Sort jobs by decreasing profit */
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(job[i].profit < job[j].profit)
            {
                temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }

    if(maxDeadline > n)
        maxDeadline = n;

    /* Schedule each job in the latest available slot */
    for(i = 0; i < n; i++)
        for(j = job[i].deadline < maxDeadline ?
                job[i].deadline : maxDeadline; j >= 1; j--)
            if(!slot[j])
            {
                slot[j] = job[i].id;
                totalProfit += job[i].profit;
                break;
            }

    printf("Scheduled jobs: ");
    for(i = 1; i <= maxDeadline; i++)
        if(slot[i])
            printf("J%d ", slot[i]);

    printf("\nMaximum profit = %d\n", totalProfit);

    return 0;
}