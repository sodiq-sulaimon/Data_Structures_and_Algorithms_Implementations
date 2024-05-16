#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// inserts an element into a sorted array
void InsertSort(struct Array *arr, int x) {
    if (arr->length == arr->size){
        return;
    }
    int i = arr->length - 1;
    while (i >= 0 && arr->A[i] > x) {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
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
    struct Array arr = {{2, 4, 5, 8, 12 }, 10, 5};
    Display(arr);


    InsertSort(&arr, 6);
    Display(arr);

    return 0;
}