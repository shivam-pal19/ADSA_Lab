#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    while(parent[x] != x)
        x = parent[x];

    return x;
}

void unionSet(int a, int b)
{
    parent[find(a)] = find(b);
}

int main()
{
    struct Edge e[100], temp;
    int n, m, i, j, count = 0, cost = 0;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v weight):\n");
    for(i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    for(i = 0; i < n; i++)
        parent[i] = i;

    /* Sort edges by weight */
    for(i = 0; i < m - 1; i++)
        for(j = i + 1; j < m; j++)
            if(e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }

    printf("Edges in MST:\n");

    for(i = 0; i < m && count < n - 1; i++)
    {
        if(find(e[i].u) != find(e[i].v))
        {
            printf("%d - %d : %d\n", e[i].u, e[i].v, e[i].w);

            cost += e[i].w;
            count++;

            unionSet(e[i].u, e[i].v);
        }
    }

    printf("Minimum cost = %d\n", cost);

    return 0;
}