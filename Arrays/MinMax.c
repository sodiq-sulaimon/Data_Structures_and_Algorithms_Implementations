#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

// finds pair of elements that sums to a given number using hash table.
void MinMax(struct Array arr) {
    int min = arr.A[0];
    int max = arr.A[0];

    for (int i=1; i<arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
};

int main()
{
    struct Array arr = {{5, 6, 7, 4, 1, 2, 5, -8, 3, 12}, 10, 10};
    MinMax(arr);

    return 0;
}