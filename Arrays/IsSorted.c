#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// checks if an array is sorted
int IsSorted(struct Array arr) {
    for(int i=0; i<arr.length - 1; i++) { // stops before the last element because we are comparing two elements
        if(arr.A[i] > arr.A[i+1]) {
            return 0;
        }
    }
    return 1;
};

int main()
{
    struct Array arr1 = {{2, 4, 5, 8, 12 }, 10, 5};
    struct Array arr2 = {{2, 4, 5, 8, 12, 3 }, 10, 6};

    printf("%d\n", IsSorted(arr1));
    printf("%d\n", IsSorted(arr2));

    return 0;
}