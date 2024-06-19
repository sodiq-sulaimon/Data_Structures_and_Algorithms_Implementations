#include <stdio.h>
#include "Queue.h"

struct Node *root = NULL; // global variable

void createTree()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    initializeQueue(&q, 100);

    printf("Enter root value: ");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q)) {
        p = dequeue(&q);
        printf("Enter a left child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1 ) {// -1 means not available
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter a right child of %d: ", p->data);
        scanf("%d", &x);
        if (x != -1 ) {// -1 means not available
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preOrderTransversal(struct Node *p)
{
    if (p) {
        printf("%d ", p->data);
        preOrderTransversal(p->lchild);
        preOrderTransversal(p->rchild);
    }
}

void postOrderTransversal(struct Node *p)
{
    if (p) {
        postOrderTransversal(p->lchild);
        postOrderTransversal(p->rchild);
        printf("%d ", p->data);
    }
}

void inOrderTransversal(struct Node *p)
{
    if (p) {
        inOrderTransversal(p->lchild);
        printf("%d ", p->data);
        inOrderTransversal(p->rchild);
    }
}

int main()
{
    createTree();
    printf("Pre-order transversal:\n");
    preOrderTransversal(root);
    printf("\nIn-order transversal:\n");
    inOrderTransversal(root);
    printf("\nPost-order transversal:\n");
    postOrderTransversal(root);

    return 0;
}