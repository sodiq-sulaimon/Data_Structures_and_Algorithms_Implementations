#include <stdio.h>

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

int main()
{
    struct Array arr1 = {{1, 2, 3, 4, 5, 6, 7, 9, 10}, 10, 9};
    struct Array arr2 = {{6, 7, 8, 10, 11, 12, 13, 14, 15}, 10, 9};

    printf("Missing element: %d\n", Missing1(arr1));
    printf("Missing element: %d\n", Missing2(arr2));

    return 0;
}