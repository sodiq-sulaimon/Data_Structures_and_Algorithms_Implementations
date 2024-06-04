#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;

void Create(int A[], int n)
{
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    struct Node *p = first;

    struct Node *t;

    for (int i=1; i < n; i++) {
        struct Node *t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = p->next;
        t->prev = p;
        p->next = t;
        p = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


int Length(struct Node *p) {
    int len = 0;

    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

int main()
{
    int arr[] = {8, 1, 12, 5, 10, 16, 2};
    Create(arr, 7);
    printf("Doubly Linkedlist:\n");
    Display(first);
    printf("Length: %d \n", Length(first));
}