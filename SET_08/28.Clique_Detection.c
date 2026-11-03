#include <stdio.h>

int graph[20][20], chosen[20];
int n, m;

int isClique(int v, int count)
{
    int i;

    if(count == m)
        return 1;

    if(v == n)
        return 0;

    for(i = 0; i < v; i++)
        if(chosen[i] && !graph[i][v])
            break;

    if(i == v)
    {
        chosen[v] = 1;
        if(isClique(v + 1, count + 1))
            return 1;
        chosen[v] = 0;
    }

    return isClique(v + 1, count);
}

int main()
{
    int i, j, e = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);

    for(i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }

    printf("Enter clique size m: ");
    scanf("%d", &m);

    if(m > n || m < 1)
        printf("Invalid clique size.\n");
    else if(isClique(0, 0))
        printf("Clique of size %d exists.\n", m);
    else
        printf("No clique of size %d exists.\n", m);

    return 0;
}