#include <stdio.h>

void IsPalindrome(char A[])
{
    int i =0;
    int j = 0;

    // move j to the end of the string and change any uppercase letter to lowercase
    for(j=0; A[j] != '\0'; j++) {
        if (A[j] >= 65 && A[j] <= 90) { // numbers are ascii values
            A[j] += 32;
        }
    }
    j -= 1; // move j index to the character before the null character

    for(i=0; i <= j ; i++, j--) {
        if (A[i] != A[j]) {
            break;
        }
    }
    if (A[i] == A[j]) {
        printf("%s is a Palindrome\n", A);
    }
    else
        printf("%s is not a Palindrome\n", A);
}

int main() {

    char s1[] = "pap";
    char s2[] = "coacoa";
    char s3[] = "MaDAm";
//
    IsPalindrome(s1);
    IsPalindrome(s2);
    IsPalindrome(s3);

    return 0;
}