#include <stdio.h>

int graph[20][20], color[20];
int n, m;

int isSafe(int v, int c)
{
    int i;

    for(i = 0; i < n; i++)
        if(graph[v][i] && color[i] == c)
            return 0;

    return 1;
}

int graphColoring(int v)
{
    int c;

    if(v == n)
        return 1;

    for(c = 1; c <= m; c++)
    {
        if(isSafe(v, c))
        {
            color[v] = c;

            if(graphColoring(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
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

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if(graphColoring(0))
    {
        printf("Vertex\tColor\n");
        for(i = 0; i < n; i++)
            printf("%d\t%d\n", i, color[i]);
    }
    else
        printf("No solution exists.\n");

    return 0;
}