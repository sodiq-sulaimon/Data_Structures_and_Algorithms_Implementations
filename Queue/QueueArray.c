#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void initializeQueue(struct Queue *q, int size)
{
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->Q = (int *)malloc(size * sizeof(int));
    if (q->Q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1) {
        printf("Queue is full");
        exit(1);
    }
    else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front > q->rear) {
        printf("Queue is empty\n");
        exit(1);
    }
    else {
        x = q->Q[q->front];
        q->front++;
    }
    return x;
}

void Display(struct Queue *q)
{
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        exit(1);
    }
    else {
        for (int i = q->rear; i >= q->front; i--) {
            printf("%d ", q->Q[i]);
        }
    }
    printf("\n");
}

int main()
{
    struct Queue queue;
    initializeQueue (&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 8);
    enqueue(&queue, 12);
    enqueue(&queue, 7);
    enqueue(&queue, 9);

    Display(&queue);

    printf("%d \n",dequeue(&queue));
    printf("%d \n",dequeue(&queue));
    printf("%d \n",dequeue(&queue));
    printf("%d \n",dequeue(&queue));
    printf("%d \n",dequeue(&queue));
    printf("%d \n",dequeue(&queue));

    Display(&queue);

    free(queue.Q);

    return 0;
}