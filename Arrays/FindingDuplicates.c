#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

// checks if an array has duplicates
void CheckDuplicates(struct Array arr) {
    int lastDuplicate = 0;
    for(int i=0; i < arr.length - 1; i++) { // Stop just before the last element to allow comparison
        if(arr.A[i] == arr.A[i+1] && arr.A[i] !=lastDuplicate) {
            printf("%d ", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
};

// counts duplicates
void CountDuplicates(struct Array arr) {
    int i=0;
    int j = 0;
    for(i=0; i < arr.length - 1; i++) { // Stop before the last element to allow comparison
        if(arr.A[i] == arr.A[i+1]) {
            j = i + 1; // move j to the first duplicate
            while (arr.A[j] == arr.A[i]) { // increment j until there's no more duplicates
                j++;
            }
            printf("%d appears %d times\n", arr.A[i], j - i);
            i = j - 1; // move i to just before j to continue checking for other duplicates
        }
    }
};

// finds multiple duplicates in a sorted array with hashing.
void CheckDuplicates2(struct Array arr) {
    struct Array *H = (struct Array *)malloc(sizeof(struct Array));

    // find the maximum element in the array to create the hash table.
    int max = 0;
    for (int i=0; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }

    H->size = max + 1; // size and length of the hashing should be greater than the max element in the array
    H->length = max + 1;

    for (int i=0; i < arr.length; i++) {
        if (arr.A[i] < H->size) { // Ensure that the index is within bounds
            H->A[arr.A[i]]++; // increment the index of H matching the element in the arr
        }
    }

    for (int i=0; i < H->length; i++) {
        if (H->A[i] > 1) {
            printf("%d appears %d times\n", i, H->A[i]);
        }
    }
};

int main()
{
    struct Array arr1 = {{1, 4, 4, 5, 8, 8, 12, 12, 12, 12}, 10, 10};
    struct Array arr2 = {{5, 12, 8, 4, 5, 4, 5, 8, 12, 12}, 10, 10};

    printf("Checking Duplicates: \n");
    CheckDuplicates(arr1);

    printf("\nCounting Duplicates Method 1: \n");
    CountDuplicates(arr1);

    printf("\nCounting Duplicates Method 2: ");
    CheckDuplicates2(arr1);

    printf("\nCounting Duplicates in unsorted array with Method 2:\n");
    CheckDuplicates2(arr2);

    return 0;
}