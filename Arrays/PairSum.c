#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

// finds pair of elements that sums to a given using hash table.
void SumOfPair(struct Array arr, int k) {
    struct Array *H = (struct Array *)malloc(sizeof(struct Array));
    int max = 0;

    // find the maximum element in the array to create the hash table.
    for (int i=0; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }

    H->size = max + 1; // size and length of the hashing should be greater than the max element in the array
    H->length = max + 1;

    for (int i=0; i < arr.length; i++) {
        H->A[arr.A[i]]++; // increment the index of H matching the element in the arr
        if (H->A[k - arr.A[i]] != 0) {
            printf("%d and %d adds up to %d\n", arr.A[i], k - arr.A[i], k);
        }
    }
};

int main()
{
    struct Array arr = {{5, 6, 7, 4, 1, 2, 5, 8, 3, 12}, 10, 10};

    SumOfPair(arr, 10);

    return 0;
}