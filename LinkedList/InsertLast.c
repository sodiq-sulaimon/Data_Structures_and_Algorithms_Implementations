#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Node is self-referential
}*first = NULL; // global pointer to node

void InsertLast(struct Node *p, int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last;
    last = first;
    t->data = x;
    t->next = NULL;

    if (first == NULL) {
        first = t;
    }
    else {
        while (last->next) {
            last = last->next;
        }
        last->next = t;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
//    int arr[] = {3, 2, 9, 4, 6, 10};
    InsertLast(first, 3);
    InsertLast(first, 2);
    InsertLast(first, 9);
    InsertLast(first, 4);
    InsertLast(first,6);
    InsertLast(first,10);
    Display(first);
}