#include <stdio.h>

int graph[20][20], color[20], n;

int isBipartite()
{
    int queue[20], front, rear, i, u;

    for (i = 0; i < n; i++)
        color[i] = -1;

    for (i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            front = rear = 0;
            queue[rear++] = i;
            color[i] = 0;

            while (front < rear)
            {
                u = queue[front++];

                for (i = 0; i < n; i++)
                {
                    if (graph[u][i])
                    {
                        if (color[i] == -1)
                        {
                            color[i] = 1 - color[u];
                            queue[rear++] = i;
                        }
                        else if (color[i] == color[u])
                            return 0;
                    }
                }
            }
        }
    }

    return 1;
}

int main()
{
    int e, i, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    if (n < 1 || n > 20 || e < 0 || e > n * (n - 1) / 2)
    {
        printf("Invalid input.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v), vertices numbered 0 to %d:\n", n - 1);

    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n || u == v)
        {
            printf("Invalid edge.\n");
            return 0;
        }

        graph[u][v] = graph[v][u] = 1;
    }

    if (isBipartite())
        printf("Graph is bipartite.\n");
    else
        printf("Graph is not bipartite.\n");

    return 0;
}