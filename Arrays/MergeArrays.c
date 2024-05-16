#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// merges two sorted arrays.
struct Array* Merge(struct Array *arr1, struct Array *arr2) {
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = arr1->length + arr2->length;
    int i =0;
    int j =0;
    int k =0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k] = arr1->A[i];
            i++;
            k++;
        }
        else {
            arr3->A[k] = arr2->A[j];
            j++;
            k++;
        }
    }

    // copy the remaining elements from arr1 if any.
    for (;i < arr1->length; i++) {
        arr3->A[k] = arr1->A[i];
        k++;
    }
    // copy the remaining elements from arr2 if any.
    for (;j < arr2->length; j++) {
        arr3->A[k] = arr2->A[j];
        k++;
    }
    return arr3;
    free(arr3);
    arr3 = NULL;
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
    struct Array arr1 = {{3, 5, 8, 10, 13}, 5, 5};
    struct Array arr2 = {{1, 3, 7, 12, 15}, 5, 5};

    struct Array *arr3 = Merge(&arr1, &arr2);
    Display(*arr3);

    return 0;
}