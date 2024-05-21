#include <stdio.h>

char name[] = "Sodiq";
char prog[] = "Programming";

void Reverse(char s[])
{
    int i =0;
    int j =0;
    // get the length of the string
    for(i =0; s[i] !='\0'; i++) {
    }
    i = i - 1; // move to the last index before \0
    char rString[i];
    for(j=0; i >=0; i--, j++) {
        rString[j] = s[i];
    }
    rString[j] = '\0'; // add null character to change rString to string
    printf("%s\n", rString);
}

void Reverse2(char s[])
{
    int i =0;
    int j = 0;
    char temp;
    // move j to the end of the string
    for(j =0; s[j] !='\0'; j++) {
    }
    j = j - 1; // move to the last index before \0

    for(i=0; i <= j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    printf("%s\n", s);
}

int main() {
    printf("Method 1: \n");
    Reverse(name);
    Reverse(prog);

    printf("Method 2: \n");
    Reverse2(name);
    Reverse2(prog);

    return 0;
}