#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Node is self-referential
}*first = NULL; // global pointer to node

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

int Add(struct Node * p) {
    int sum = 0;

    while(p != NULL) {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

int Max(struct Node * p) {
    int max = INT32_MIN; // Minimum integer -32768

    while(p) {
        if (max < p->data) {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Min(struct Node * p) {
    int min = INT32_MAX; // Maximum integer

    while(p) {
        if (min > p->data) {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}

int Search(struct Node * p, int target) {
    while(p != NULL) {
        if (p->data == target) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

// moves the node of the searched element to the front
struct Node * SearchMoveToHead(struct Node *p, int target) {
    struct Node *q;
    while(p != NULL) {
        if (p->data == target) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// reverses a linkedlist with sliding pointers
void Reverse(struct Node *x) {
    struct Node *p = first;
    struct Node *q = NULL;
    struct Node *r = NULL;

    while(p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    int arr[] = {3, 2, 9, 4, 6};
    Create(arr, 5);
    printf("Linkedlist:\n");
    Display(first);

    struct Node *temp = NULL;
    temp = SearchMoveToHead(first, 9);

    if (temp != NULL) {
        printf("\n%d Found", temp->data);
    }
    else
        printf("\nNot found");

    printf("\nLinkedlist after move-to-head search: \n");
    Display(first);

    printf("\nDisplay with Recursion: \n");
    RDisplay(first);

    printf("\nCount: %d", Count(first));

    printf("\nSum: %d", Add(first));

    printf("\nMax: %d", Max(first));

    printf("\nMin: %d", Min(first));

    printf("\nSearch Result: %d", Search(first, 6));
    printf("\nSearch Result: %d", Search(first, 23));

    Reverse(first);
    printf("\nReversed linkedlist: \n");
    Display(first);

    return 0;
}

