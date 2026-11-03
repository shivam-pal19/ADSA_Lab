#include <stdio.h>

int graph[20][20], path[20], n;

int isSafe(int v, int pos)
{
    int i;

    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int hamCycle(int pos)
{
    int v;

    if (pos == n)
        return graph[path[pos - 1]][path[0]];

    for (v = 1; v < n; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (hamCycle(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }

    return 0;
}

int main()
{
    int i, j, e, u, v;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    if (n < 3 || n > 20 || e < 0 || e > n * (n - 1) / 2)
    {
        printf("Invalid input.\n");
        return 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
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

    for (i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (hamCycle(1))
    {
        printf("Hamiltonian cycle exists:\n");
        for (i = 0; i < n; i++)
            printf("%d -> ", path[i]);
        printf("0\n");
    }
    else
        printf("Hamiltonian cycle does not exist.\n");

    return 0;
}