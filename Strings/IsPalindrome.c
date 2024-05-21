#include <stdio.h>

void IsPalindrome(char A[])
{
    int i =0;
    int j = 0;

    // if first character is uppercase, change to lowercase
    if (A[0] >= 65 && A[0] <= 90) { // numbers are ascii values
        A[0] += 32;
    }

    // move j to the end of the string
    for(j=0; A[j] != '\0'; j++) {
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

    char s1[] = "poop";
    char s2[] = "coacoa";
    char s3[] = "madam";
//
    IsPalindrome(s1);
    IsPalindrome(s2);
    IsPalindrome(s3);

    return 0;
}