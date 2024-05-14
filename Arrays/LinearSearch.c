#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// searches for an element of a given index
int LinearSearch(struct Array arr, int key)
{
    for (int i = 0; i < arr.length; i++) {
        if (key == arr.A[i]) {
            return i;
        }
    } return -1;
};

int main()
{
    struct Array arr = {{2, 3, 4, 5, 7}, 10, 5};
    printf("%d\n", LinearSearch(arr, 7));

    return 0;
}