#include <stdio.h>
#define MAX_NODES 100
#define MAX_EDGES 1000
#define INF 999999

int main() {
    int n, e;
    int u[MAX_EDGES], v[MAX_EDGES], w[MAX_EDGES];
    int dist[MAX_NODES];
    int source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter each edge in the format: u v w\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    printf("Enter the source node: ");
    scanf("%d", &source);

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int from = u[j];
            int to = v[j];
            int weight = w[j];

            if (dist[from] != INF && dist[from] + weight < dist[to]) {
                dist[to] = dist[from] + weight;
            }
        }
    }

    for (int j = 0; j < e; j++) {
        int from = u[j];
        int to = v[j];
        int weight = w[j];

        if (dist[from] != INF && dist[from] + weight < dist[to]) {
            printf("Graph contains a negative weight cycle\n");
            return 0;
        }
    }

    printf("\nShortest distances from node %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("To node %d: No path\n", i);
        } else {
            printf("To node %d: %d\n", i, dist[i]);
        }
    }

    return 0;
}
