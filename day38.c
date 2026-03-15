#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front > 0) {
        front--;
        deque[front] = x;
    }
    else {
        printf("Deque Overflow\n");
    }
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    deque[rear] = x;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    front++;

    if (front > rear)
        front = rear = -1;
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    rear--;

    if (rear < front)
        front = rear = -1;
}

int getFront() {
    if (isEmpty()) return -1;
    return deque[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_back(30);

    pop_front();

    printf("Front: %d\n", getFront());
    printf("Back: %d\n", getBack());
    printf("Size: %d\n", size());

    printf("Deque elements: ");
    display();

    return 0;
}