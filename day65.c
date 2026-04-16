#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];

// DFS function to detect cycle
bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            }
            else if (i != parent) {
                // Visited node that is not parent → cycle found
                return true;
            }
        }
    }
    return false;
}

// Function to check cycle
void hasCycle(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

// Main
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    hasCycle(n);

    return 0;
}