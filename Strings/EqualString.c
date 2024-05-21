#include <stdio.h>

void Equal(char A[], char B[])
{
    int i =0;
    int j = 0;

    for(i=0, j=0; A[i] != '\0' && B[j] != '\0'; i++, j++) {
        if (A[i] != B[j]) {
            break;
        }
    }
    if (A[i] == B[j]) {
        printf("Equal\n");
    }
    else if (A[i] < B[j]) {
        printf("Smaller\n");
    }
    else
        printf("Greater\n");
}

int main() {

    char s1[] = "Printer";
    char s2[] = "Printer";
    char s3[] = "Printing";

    Equal(s1, s2);
    Equal(s1, s3);

    return 0;
}