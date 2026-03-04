#include <stdio.h>
#define MAX 1000

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

// Pop function
void pop() {
    if (top >= 0) {
        top--;
    }
}

int main() {
    int n, m, value;

    // Input number of elements
    scanf("%d", &n);

    // Push elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Input number of pops
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print remaining stack (top to bottom)
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}