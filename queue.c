#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int front, rear;
} Queue;

// Initializing the queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Checking if the queue is empty
bool isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// checking if the queue is full
bool isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Adding an element to the queue 
void push(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot push element.\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    q->arr[q->rear] = value;
}

// Removing an element from the queue 
int pop(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot pop element.\n");
        return -1; // Let's assume that -1 is not a valid element in the queue
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) { // Last element in the queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

int main() {
    Queue q;
    initQueue(&q);

    push(&q, 10);
    push(&q, 20);
    push(&q, 30);

    printf("Popped element: %d\n", pop(&q));
    printf("Popped element: %d\n", pop(&q));
    printf("Popped element: %d\n", pop(&q));

    printf("Popped element: %d\n", pop(&q));

    return 0;
}
