#include <stdio.h>

#define MAX 10  

int n;                 
int graph[MAX][MAX];   
int color[MAX];        

int isSafe(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c)
            return 0; 
    }
    return 1;
}

int graphColoring(int v, int m) {
    if (v == n)
        return 1; 

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoring(v + 1, m))
                return 1;
            color[v] = 0; 
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int minColors;
    for (minColors = 1; minColors <= n; minColors++) {
        for (int i = 0; i < n; i++)
            color[i] = 0;

        if (graphColoring(0, minColors)) {
            printf("\nMinimum number of colors needed: %d\n", minColors);
            printf("Color assigned to vertices:\n");
            for (int i = 0; i < n; i++)
                printf("Vertex %d --> Color %d\n", i + 1, color[i]);
            return 0;
        }
    }

    printf("\nNo valid coloring possible.\n");
    return 0;
}
