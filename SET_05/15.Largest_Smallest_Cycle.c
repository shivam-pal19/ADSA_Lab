#include <stdio.h>

int graph[20][20], visited[20];
int n, directed;
int smallest = 100, largest = 0;

void DFS(int start, int u, int length)
{
    int v;

    for(v = 0; v < n; v++)
    {
        if(graph[u][v])
        {
            if(v == start && length >= 3)
            {
                if(length < smallest)
                    smallest = length;

                if(length > largest)
                    largest = length;
            }
            else if(!visited[v] && v != start)
            {
                /* For undirected graph, avoid duplicate cycles */
                if(directed || v >= start)
                {
                    visited[v] = 1;
                    DFS(start, v, length + 1);
                    visited[v] = 0;
                }
            }
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter 1 for directed, 0 for undirected: ");
    scanf("%d", &directed);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            visited[j] = 0;

        visited[i] = 1;
        DFS(i, i, 1);
    }

    if(largest == 0)
        printf("No cycle found.\n");
    else
    {
        printf("Smallest cycle = %d vertices\n", smallest);
        printf("Largest cycle = %d vertices\n", largest);
    }

    return 0;
}
