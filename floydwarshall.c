#include <stdio.h>

#define INF 9999

void floydWarshall(int graph[][4], int V) {
    int dist[V][V], i, j, k;

    /* Initialize the dist matrix as same as the input graph */
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    /* Floyd Warshall algorithm */
    for (k = 0; k < V; k++) {
        // Pick all vertices as intermediate vertices one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as source
            for (j = 0; j < V; j++) {
                // If relax(dist[i][j], dist[i][k], dist[k][j]) is possible then update dist[i][j]
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("Shortest all-pairs shortest paths :\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%s", "INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Define the number of vertices in the graph */
    int V = 4;

    /* Define the weight matrix as per the graph in the image */
    int graph[4][4] = {
        {0, 1, INF, 8},
        {INF, 0, 4, INF},
        {INF, INF, 0, 3},
        {INF, INF, INF, 0}
    };

    // Print the source graph
    printf("Source Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Find shortest path using Floyd Warshall Algorithm
    floydWarshall(graph, V);

    return 0;
}