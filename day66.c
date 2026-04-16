#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];      // Adjacency matrix
bool visited[MAX];      // Visited nodes
bool recStack[MAX];     // Recursion stack

// DFS function to detect cycle
bool dfs(int node, int n) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            if (!visited[i]) {
                if (dfs(i, n))
                    return true;
            }
            else if (recStack[i]) {
                // Node is in recursion stack → cycle
                return true;
            }
        }
    }

    recStack[node] = false; // Remove from recursion stack
    return false;
}

// Function to check cycle
void hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
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