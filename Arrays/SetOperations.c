#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Function to check if an element is present in the array
int isPresent(struct Array *arr, int element) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->A[i] == element) {
            return 1;
        }
    }
    return 0;
}

// union for unsorted arrays
struct Array* Union1(struct Array *arr1, struct Array *arr2) {
    int i=0;
    int j=0;
    int k=0;
    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->length = 0;
    arr3->size = arr1->size + arr2->size;

    for (i=0; i<arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;

    for (j=0; j<arr2->length; j++) {
        if (!(isPresent(arr1, arr2->A[j]))) {
            arr3->A[k++] = arr2->A[j];
        }

    }
    arr3->length = k;

    return arr3;
    free(arr3);
    arr3 = NULL;
}

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
    struct Array arr1 = {{3, 2, 4, 6, 8, 10}, 10, 6};
    struct Array arr2 = {{6, 4, 9, 8, 1}, 10, 5};

   struct Array *arr3 = Union1(&arr1, &arr2);
   Display(*arr3);

    return 0;
}