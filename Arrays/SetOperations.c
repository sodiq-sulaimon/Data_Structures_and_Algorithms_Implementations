#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Function to check if an element is present in the array
int IsPresent(struct Array *arr, int element) {
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

    for (i=0; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    arr3->length = k;

    for (j=0; j<arr2->length; j++) {
        if (!(IsPresent(arr1, arr2->A[j]))) {
            arr3->A[k++] = arr2->A[j];
        }

    }
    arr3->length = k;

    return arr3;
    free(arr3);
    arr3 = NULL;
}

// union for sorted arrays
struct Array* Union2(struct Array *arr1, struct Array *arr2) {
    int i=0;
    int j=0;
    int k=0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        }
        else if (arr1->A[i] > arr2->A[j]) {
            arr3->A[k++] = arr2->A[j++];
        }
        else {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    // copy the remaining elements if any
    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }

    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }

    arr3->length = k;
    return arr3;
    free(arr3);
    arr3 = NULL;
}

// union for sorted arrays
struct Array* Intersection(struct Array *arr1, struct Array *arr2) {
    int i=0;
    int j=0;
    int k=0;

    struct Array *arr3 = (struct Array *) malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->length = 0;

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            i++;
        }
        else if (arr1->A[i] > arr2->A[j]) {
            j++;
        }
        else if (arr1->A[i] == arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
            j++;
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
//    struct Array *arr3 = Union1(&arr1, &arr2);

    struct Array arr3 = {{2, 3, 4, 6, 8, 10}, 10, 6};
    struct Array arr4 = {{1, 4, 6, 8, 9, 12}, 10, 6};
//    struct Array *arr5 = Union2(&arr3, &arr4);
    struct Array *arr5 = Intersection(&arr3, &arr4);

    printf("Union of Unsorted Arrays: \n");
    Display(*Union1(&arr1, &arr2));

    printf("Union of Sorted Arrays: \n");
    Display(*Union2(&arr3, &arr4));

    printf("Intersect: \n");
    Display(*arr5);

    return 0;
}