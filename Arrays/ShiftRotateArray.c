#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// left shift array
void LeftShift(struct Array *arr) {
    for(int i = 0; i < arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length - 1] = 0;
};

// right shift array
void RightShift(struct Array *arr) {
    for(int i = arr->length; i >=0;  i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
};

// left rotate
void LeftRotate(struct Array *arr) {
    int temp = arr->A[0];
    for(int i = 0; i < arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length - 1] = temp;
};

// right rotate
void RightRotate(struct Array *arr) {
    int temp = arr->A[arr->length - 1];
    for(int i = arr->length; i >=0;  i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
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
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
    Display(arr);

//    LeftShift(&arr);
//    Display(arr);
//
//    RightShift(&arr);
//    Display(arr);
//
//    LeftRotate(&arr);
//    Display(arr);

    RightRotate(&arr);
    Display(arr);

    return 0;
}