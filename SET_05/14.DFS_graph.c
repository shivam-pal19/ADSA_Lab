#include <stdio.h>

int graph[20][20], visited[20], start[20], finish[20];
int time = 0, n;

void DFS(int u)
{
    int v;

    visited[u] = 1;
    start[u] = ++time;

    for(v = 0; v < n; v++)
    {
        if(graph[u][v])
        {
            if(!visited[v])
            {
                printf("Tree Edge: %d -> %d\n", u, v);
                DFS(v);
            }
            else if(!finish[v])
                printf("Back Edge: %d -> %d\n", u, v);
            else if(start[u] < start[v])
                printf("Forward Edge: %d -> %d\n", u, v);
            else
                printf("Cross Edge: %d -> %d\n", u, v);
        }
    }

    finish[u] = ++time;
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for(i = 0; i < n; i++)
        if(!visited[i])
            DFS(i);

    return 0;
}