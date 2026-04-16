#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int front = 0, rear = -1;

// Enqueue
void enqueue(int v) {
    queue[++rear] = v;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Kahn's Algorithm
void topoSort(int n) {
    int count = 0;

    // Step 1: Calculate indegree
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    // Step 3: Process queue
    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 4: Check cycle
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
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

    topoSort(n);

    return 0;
}