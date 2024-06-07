#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void initializeQueue(struct Queue *q, int size) {
    q->front = 0;
    q->rear = 0;
    q->size = size + 1; // One extra space to differentiate between full and empty
    q->Q = (int *)malloc(q->size * sizeof(int));
    if (q->Q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void enqueue(struct Queue *q, int x) {
    if ((q->rear + 1) % q->size == q->front) {
        printf("Queue is full\n");
        return;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return x;
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q) {
    int i = (q.front + 1) % q.size;
    if (q.front == q.rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (i != (q.rear + 1) % q.size) {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initializeQueue(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 8);
    enqueue(&queue, 12);
    enqueue(&queue, 7);
    enqueue(&queue, 9);

    Display(queue);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Dequeued element: %d\n", dequeue(&queue));
    Display(queue);

    enqueue(&queue, 15);
    enqueue(&queue, 20);
    Display(queue);

    free(queue.Q);

    return 0;
}
