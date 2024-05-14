#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// returns the index of the target element in a sorted array or -1 if not found.
int BinarySearch(struct Array arr, int target)
{
    int low = 0;
    int high = arr.length - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target == arr.A[mid]) {
            return mid;
        }
        else if (target > arr.A[mid]) {
            low = mid + 1;
        }
        else
            high = mid - 1;
    } return -1;
};

int main()
{
    struct Array arr = {{2, 3, 4, 5, 7, 9, 12, 15, 18, 20}, 10, 10};
    printf("%d\n", BinarySearch(arr, 12 ));

    return 0;
}