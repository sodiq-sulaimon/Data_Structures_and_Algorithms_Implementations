#include <stdio.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

// delete element at a given index
int Delete(struct Array *arr, int index)
{
    if (index >=0 && index < arr->length) {
        int x = arr->A[index];

        for (int i = index; i <= arr->length - 1; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
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
    struct Array arr = {{2, 3, 4, 5, 7}, 10, 5};
    printf("Deleted: %d\n", Delete(&arr, 4));
    Display(arr);

    return 0;
}