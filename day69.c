#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix (weights)
int dist[MAX];       // Distance array
bool visited[MAX];   // Visited array

// Function to find node with minimum distance
int minDistance(int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra function
void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(n);
        if (u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// Main
int main() {
    int n, src;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}