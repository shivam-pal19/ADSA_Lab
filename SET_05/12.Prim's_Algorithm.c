#include <stdio.h>

#define INF 99999
#define MAX 20

void prim(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    int edgeCount = 0;
    int totalCost = 0;
    int min, u, v;
    int i, j;

    selected[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edgeCount < n - 1) {
        min = INF;
        u = -1;
        v = -1;

        /* Find minimum edge from selected to unselected vertex */
        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] &&
                        graph[i][j] != 0 &&
                        graph[i][j] < min) {

                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("MST cannot be formed. Graph is disconnected.\n");
            return;
        }

        printf("%d - %d : %d\n", u, v, min);

        totalCost += min;
        selected[v] = 1;
        edgeCount++;
    }

    printf("Minimum Cost = %d\n", totalCost);
}

int main() {
    int graph[MAX][MAX];
    int n;
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
                printf("Negative edge weight is not allowed.");
                return 0;
            }
        }
    }

    prim(graph, n);

    return 0;
}