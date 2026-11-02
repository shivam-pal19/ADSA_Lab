#include <stdio.h>

int graph[20][20], visited[20], stack[20];
int n, top = -1;

void topologicalSort(int v)
{
    int i;

    visited[v] = 1;

    for(i = 0; i < n; i++)
        if(graph[v][i] && !visited[i])
            topologicalSort(i);

    stack[++top] = v;
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
            topologicalSort(i);

    printf("Topological order: ");
    while(top >= 0)
        printf("%d ", stack[top--]);

    return 0;
}