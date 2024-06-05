#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

int isFull(struct Stack *st)
{
    if (st->top == st->size - 1) { //top is initialized to -1.
        return 1;
    }
    return 0;

}

int isEmpty(struct Stack *st)
{
    if (st->top == - 1) { //top is initialized to -1.
        return 1;
    }
    return 0;

}

void Push(struct Stack *st, int x)
{
    if (!isFull(st)) {
        st->top++;
        st->s[st->top] = x;
    }
}

int Pop(struct Stack *st)
{
    int x = -1;
    if (isEmpty(st)) {
        printf("\nStack underflow");
    }
    else {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0 ) { // st.top - pos + 1 maps the pos to index
        printf("\nStack is empty");
    }
    else {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int stackTop(struct Stack st)
{
    int x = -1;
    if (st.top == -1 ) {
        return -1;
    }
    else {
        x = st.s[st.top];
    }
    return x;
}

void Display(struct Stack st)
{   if (st.top == -1) {
        printf("\nStack is empty");
    }
    else {
        for(int i = st.top; i >=0; i--) {
            printf("%d ", st.s[i]);
    }
    }
}

int main()
{
    struct Stack st;
    st.top = -1;
    printf("Enter the size of the stack: ");
    scanf("%d", &st.size);
    st.s = malloc(st.size);

    Push(&st, 3);
    Push(&st, 6);
    Push(&st, 10);
    Push(&st, 8);
    Push(&st, 12);
    Push(&st, 7);
    Display(st);
    printf("\nPeek: %d", Peek(st, 3));
    printf("\nStack top: %d",stackTop(st));

    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n%d", Pop(&st));
    printf("\n");
    Display(st);
}