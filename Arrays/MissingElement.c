#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// finds the missing number in set of consecutive natural numbers starting from 1.
int Missing1(struct Array arr) {
    int sum = 0;
    int n = arr.A[arr.length - 1]; // last number in the array
    for (int i=0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    int s = (n * (n + 1)) / 2;

    return s - sum;
};

// finds the missing number in set of consecutive natural numbers not starting from 1.
int Missing2(struct Array arr) {
    int diff = arr.A[0] - 0; // First element minus first index
    int i=0;

    for (i=0; i < arr.length; i++) {
        if ((arr.A[i] - i) != diff) {
            break;
        }
    }
    return i + diff;
};

// finds multiple missing number in set of consecutive natural numbers.
void Missing3(struct Array arr) {
    int diff = arr.A[0] - 0; // First element minus first index
    int i = 0;
    int j = 0;
    struct Array missing;;
    missing.size = arr.size;
    missing.length = 0;

    for (i=0; i < arr.length; i++) {
        if ((arr.A[i] - i) != diff) {
            while (diff < arr.A[i] - i) {
                printf("%d ", diff + i);
                diff++;
            }
        }
    }
};

// finds multiple missing number in set of consecutive natural numbers with hashing.
void Missing4(struct Array arr) {
    struct Array *H = (struct Array *)malloc(sizeof(struct Array));
    H->size = arr.size;
    H->length = arr.length;

//    for (int i=0; i < H->length; i++) {
//        H->A[i]= 0;
//    }

    for (int i=0; i < arr.length; i++) {
        if (arr.A[i] < H->size) { // Ensure that the index is within bounds
            H->A[arr.A[i]]++; // assign 1 to the index of H matching the element in the arr
        }
    }
    for (int i=0; i < H->length; i++) {
        if (H->A[i] == 0) {
            printf("%d ", i);
        }
    }
};

int main()
{
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 7, 9, 10}, 10, 9};
    struct Array arr2 = {{6, 7, 8, 10, 11, 12, 13, 14, 15}, 10, 9};
    struct Array arr3 = {{3, 4, 5, 7, 8, 10, 13, 14, 15}, 10, 9};
    struct Array arr4 = {{1, 6, 7, 4, 5, 3, 9}, 10, 10};

    printf("Missing element: %d\n", Missing1(arr1));
    printf("Missing element: %d\n", Missing2(arr2));
    Missing3(arr3);
    printf("\n");
    Missing4(arr4);

    return 0;
}