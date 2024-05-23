#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

// finds pair of elements that sums to a given number using hash table.
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

// finds pair of elements that sums to a given number in a sorted array.
void SumOfPairSorted(struct Array arr, int k) {
    int i = 0;
    int j = arr.length - 1; // last index of the array.

    while(i < j) {
        if (arr.A[i] + arr.A[j] == k) {
            printf("%d and %d adds up to %d\n", arr.A[i], arr.A[j], k);
            i++; j--;
        }
        else if (arr.A[i] + arr.A[j] < k) { // means that the element from the left is smaller. increment i.
            i++;
        }
        else // if the sum is greater, the element from the right is bigger. decrement j.
            j--;
    }
};

int main()
{
    struct Array arr = {{5, 6, 7, 4, 1, 2, 5, 8, 3, 12}, 10, 10};
    struct Array arr2 = {{1, 2, 5, 6, 8, 9, 10, 12}, 7, 7};

    printf("Unsorted Array:\n");
    SumOfPair(arr, 10);
    printf("\nSorted Array:\n");
    SumOfPairSorted(arr2, 10);

    return 0;
}