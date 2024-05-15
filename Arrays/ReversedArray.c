#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// reverse with auxiliary array
void Reverse(struct Array *arr) {
    int *B;
    int i, j;
    B = (int *)malloc(arr->length * sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++) {
        B[j] = arr->A[i];
    }
    for(i = 0, j = 0; i < arr->length; i++, j++){
        arr->A[i] = B[j];
    }
    free(B);
};

// reverse with swapping
void Reverse2(struct Array *arr) {
    int temp;
    int i, j;
    for(i = 0, j = arr->length - 1; i < j; i++, j--) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
};

void Display (struct Array arr)
{
    printf("Array elements: \n");
    for (int i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
};

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    Display(arr);

    Reverse(&arr);
    Display(arr);

    Reverse2(&arr);
    Display(arr);

    return 0;
}