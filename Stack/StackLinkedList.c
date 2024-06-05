#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void Push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL) {
        printf("Stack is full");
    }
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Pop()
{
    int x = -1;
    if (top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        struct Node *t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct Node *p;
    p = top;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct Node *stack;

    Push(8);
    Push(3);
    Push(7);
    Push(1);
    Push(10);
    Push(12);

    Display();

    printf("\n");
    printf("%d\n", Pop());
    printf("%d\n", Pop());
    printf("%d\n", Pop());
    printf("%d\n", Pop());
    printf("%d\n", Pop());
    printf("%d\n", Pop());
    printf("%d\n", Pop());


}

