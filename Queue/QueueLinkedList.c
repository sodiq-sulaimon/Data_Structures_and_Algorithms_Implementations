#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enqueue (int x)
{
    struct Node *t;
    t = (struct Node *) malloc(sizeof(struct Node));

    if (t == NULL) {
        printf("Queue is full\n"); // Heap is full
        exit(1);
    }
    else {
        t->data = x;
        t->next = NULL;

        if (front == NULL) { // Queue is empty
            front = t;
            rear = t;
        }
        else {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue ()
{
    int x = -1;
    struct Node *p;
    if (front == NULL) { // Queue is empty
        printf("Queue is empty\n");
        exit(1);
    }
    else {
        x = front->data;
        p = front;
        front = front->next;
        free(p);
    }
    return x;
}

void Display()
{
    struct Node *p=front;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    enqueue(4);
    enqueue(12);
    enqueue(8);
    enqueue(5);
    enqueue(10);
    Display();

    dequeue();
    dequeue();

    Display();

    return 0;
}

