#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
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

int main()
{
    struct Array arr;
    printf("Enter the size of an array: ");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int));

    printf("Enter number of elements to be inserted: ");
    scanf("%d", &arr.length);

    printf("Enter the elements: ");
    for (int i=0; i < arr.length; i++) {
        scanf("%d", &arr.A[i]);
    }
    Display(arr);

return 0;
}

