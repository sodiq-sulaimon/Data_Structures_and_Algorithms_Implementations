#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue {
    int size;
    int front;
    int rear;
    struct Node **Q; //double pointer: Node* for Node, *Q for array
};

void initializeQueue(struct Queue *q, int size) {
    q->front = 0;
    q->rear = 0;
    q->size = size + 1; // One extra space to differentiate between full and empty
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node* dequeue(struct Queue *q) {
    struct Node* x = NULL;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return x;
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

