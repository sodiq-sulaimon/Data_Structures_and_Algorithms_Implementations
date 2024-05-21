#include <stdio.h>

char *name = "Sodiq";
char *name2 = "Sodiq1?234";

int validString(char *s)
{
    for(int i =0; s[i] !='\0'; i++) {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] > 97 && s[i] <= 122)) { // numbers are ascii values of uppercase and lowercase letters
            return 0;
        }
    }
    return 1;
};

int validAlphaNumeric(char *s)
{
    for(int i =0; s[i] !='\0'; i++) {
        if (!(s[i] >= 65 && s[i] <= 90) && !(s[i] >= 97 && s[i] <= 122) && !(s[i] > 48 && s[i] <= 57)) { // numbers are ascii values of numbers 0 -9, uppercase and lowercase letters
            return 0;
        }
    }
    return 1;
}

int main() {
    if (validString(name)) {
        printf("%s\n", "true");
    }
    else
        printf("%s\n", "false");

    if (validAlphaNumeric(name2)) {
        printf("%s\n", "true");
    }
    else
        printf("%s\n", "false");

    return 0;
}