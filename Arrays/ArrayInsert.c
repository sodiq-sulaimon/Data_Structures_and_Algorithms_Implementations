#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display (struct Array arr)
{
    printf("\nArray elements: \n");
    for (int i=0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
};

// appends element to the end of an array
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length++;
    }
};

// insert element of a given index into an array
void Insert(struct Array *arr, int index, int x)
{
    if (index >=0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
};

int main()
{
    struct Array arr = {{2, 3, 4, 5, 7}, 10, 5};
    Insert(&arr, 1, 9);
    Display(arr);

    return 0;
}