#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display (struct Array arr)
{
    printf("Array elements: \n");
    for (int i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
};

void Swap(int *x, int *y)
{
    int temp;
     temp = *x;
    *x = *y;
    *y = temp;
}

// Linear search with transposition
int LinearSearchTransposition(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            Swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    } return -1;
};

// Linear search with move to head
int LinearSearchMTH(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++) {
        if (key == arr->A[i]) {
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    } return -1;
};

int main()
{
    struct Array arr = {{2, 3, 4, 5, 7}, 10, 5};
    printf("%d\n", LinearSearchTransposition(&arr, 7));
    Display (arr);
    printf("\n%d\n", LinearSearchMTH(&arr, 4));
    Display (arr);

    return 0;
}