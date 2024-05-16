#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// rearranges an array such that negatives are moved to the left side while positives are to the right.
void Rearrange(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;
    while(i < j) {
        while (arr->A[i] < 0) {
            i++;
        }
        while (arr->A[j] >= 0) {
            j--;
        }
        if (i < j) {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
};

void Display (struct Array arr)
{
    printf("Array elements: \n");
    for (int i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
};

int main()
{
    struct Array arr = {{2, 4, -5, 8, -12, 0, 9, -3}, 10, 8};

    Rearrange(&arr);
    Display(arr);

    return 0;
}