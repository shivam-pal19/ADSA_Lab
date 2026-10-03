#include <stdio.h>

#define INF 99999
#define MAX 20

void dijkstra(int graph[MAX][MAX], int n, int source) {
    int distance[MAX], visited[MAX];
    int i, j, count, min, u;

    for (i = 0; i < n; i++) {
        distance[i] = graph[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;

    for (count = 0; count < n - 1; count++) {
        min = INF;
        u = -1;

        /* Find unvisited vertex with minimum distance */
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        /* Update distances of adjacent vertices */
        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                graph[u][j] != 0 &&
                distance[u] + graph[u][j] < distance[j]) {

                distance[j] = distance[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for (i = 0; i < n; i++) {
        if (distance[i] == INF)
            printf("To %d = Not reachable\n", i);
        else
            printf("To %d = %d\n", i, distance[i]);
    }
}

int main() {
    int graph[MAX][MAX];
    int n, source;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of vertices.");
        return 0;
    }

    printf("Enter adjacency matrix:\n");
    printf("(Enter 0 if there is no edge)\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] < 0) {
                printf("Negative edge weight is not allowed.\n");
                return 0;
            }
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    if (source < 0 || source >= n) {
        printf("Invalid source vertex.");
        return 0;
    }

    dijkstra(graph, n, source);

    return 0;
}
