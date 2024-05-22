#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// checks if an array has duplicates
void Duplicates(struct Array arr) {
    int lastDuplicate = 0;
    for(int i=0; i<arr.length; i++) {
        if(arr.A[i] == arr.A[i+1] && arr.A[i] !=lastDuplicate) {
            printf("%d ", arr.A[i]);
            lastDuplicate = arr.A[i];
        }
    }
};

int main()
{
    struct Array arr1 = {{1, 2, 4, 5, 8, 8, 12, 12, 12, 15}, 10, 10};

    Duplicates(arr1);

    return 0;
}