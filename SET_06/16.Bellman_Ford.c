#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int main()
{
    struct Edge e[100];
    int n, m, source;
    int dist[100];
    int i, j;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (source destination weight):\n");
    for(i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    for(i = 0; i < n; i++)
        dist[i] = 9999;

    dist[source] = 0;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(dist[e[j].u] != 9999 &&
               dist[e[j].u] + e[j].w < dist[e[j].v])
            {
                dist[e[j].v] = dist[e[j].u] + e[j].w;
            }
        }
    }

    /* Check for negative weight cycle */
    for(j = 0; j < m; j++)
    {
        if(dist[e[j].u] != 9999 &&
           dist[e[j].u] + e[j].w < dist[e[j].v])
        {
            printf("Graph contains a negative weight cycle.\n");
            return 0;
        }
    }

    printf("Shortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++)
    {
        if(dist[i] == 9999)
            printf("%d -> %d = INF\n", source, i);
        else
            printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}