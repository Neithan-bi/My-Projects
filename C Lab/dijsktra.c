#include <stdio.h>
#include <limits.h>

#define V 10  // Maximum number of vertices (can be adjusted)

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to implement Dijkstra’s algorithm
void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];     // The output array (shortest distances)
    int visited[V];  // visited[i] will be true if vertex i is finalized

    // Initialize distances and visited[]
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;  // Distance to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        // Update dist[v] for all adjacent vertices of u
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the shortest distance from source
    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

// Driver code
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];
    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);
    return 0;
}
