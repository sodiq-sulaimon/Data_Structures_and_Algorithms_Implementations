#include <stdio.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

// Gets an element at a given index
int Get (struct Array arr, int index)
{
    if (index >= 0 && index <= arr.length - 1) {
        return arr.A[index];
    }
    return -1;
};

// Sets an element to a given index
int Set (struct Array *arr, int index, int num)
{
    if (index >= 0 && index <= arr->length - 1) {
        return arr->A[index] = num;
    }
    return -1;
};

// Returns the maximum element in an array of ints
int Max (struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = (arr.A[i]);
        }
    }
    return max;
};

// Returns the minimum element in an array of ints
int Min (struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = (arr.A[i]);
        }
    }
    return min;
};

// Returns the sum of all element in an array of ints
int Sum (struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum;
};

// Returns the avg of all element in an array
float Avg (struct Array arr)
{
    float sum = 0;
    for (int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }
    return sum / arr.length;
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
    struct Array arr = {{2, 3, 4, 5, 7, 9, 12, 15, 18, 20}, 10, 10};
    printf("%d\n", Get(arr, 5 ));

    printf("%d\n", Set(&arr, 5, 8));
    Display(arr);

    printf("\nMax: %d\n", Max(arr));

    printf("Min: %d\n", Min(arr));

    printf("Sum: %d\n", Sum(arr));

    printf("Average: %.2f\n", Avg(arr));

    return 0;
}