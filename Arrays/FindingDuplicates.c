#include <stdio.h>

struct Array
{
    int A[10];
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

int main()
{
    struct Array arr1 = {{1, 4, 4, 5, 8, 8, 12, 12, 12, 12}, 10, 10};

    CheckDuplicates(arr1);
    printf("\n");
    CountDuplicates(arr1);

    return 0;
}