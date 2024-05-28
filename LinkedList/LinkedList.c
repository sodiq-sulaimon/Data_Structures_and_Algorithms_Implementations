#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Node is self-referential
}*first = NULL;

void Create(int elements[], int n) {
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = elements[0];
    first->next = NULL;

    struct Node *current, *last;
    last = first;

    for(int i=1; i < n; i++) {
        current = (struct Node *)malloc(sizeof(struct Node));
        current->data = elements[i];
        current->next = NULL;
        last->next = current;
        last = current;
    }
};

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

}

// Display recursively
void RDisplay(struct Node * p) {
    if (p != NULL) {
        printf("%d ", p->data);
        RDisplay(p->next);
    }

}

int Count(struct Node * p) {
    int count = 0;

    while(p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int main()
{
    int arr[] = {3, 2, 9, 4, 6};
    Create(arr, 5);
    Display(first);

    printf("\nDisplay with Recursion: \n");
    RDisplay(first);

    printf("\n");
    printf("Count: %d\n", Count(first));

    return 0;
}

