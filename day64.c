#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];    // Visited array
int queue[MAX];      // Queue for BFS

int front = -1, rear = -1;

// Enqueue function
void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = v;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    } else {
        return queue[front++];
    }
}

// BFS function
void bfs(int n, int start) {
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Main function
int main() {
    int n, i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    bfs(n, start);

    return 0;
}