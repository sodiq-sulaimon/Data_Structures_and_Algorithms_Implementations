#include <stdio.h>

char greeting[] = {'w', 'e', 'l', 'c', 'o', 'm', 'e', '\0'};
char name[] = "SODIQ";
char name2[] = "SuLaImOn";

void UpperCase(char s[])
{
    int i = 0;
    while(s[i] !='\0') {
        s[i] -= 32;
        i++;
    }
    printf("%s\n", s);
}

void LowerCase(char s[])
{
    int i = 0;
    while(s[i] !='\0') {
        s[i] += 32;
        i++;
    }
    printf("%s\n", s);
}

void ToggleCase(char s[])
{
    for(int i =0; s[i] !='\0'; i++) {
        // if uppercase, change to lowercase
        if (s[i] >= 65 && s[i] <= 90) { // numbers are ascii values
            s[i] += 32;
        }
        // if lowercase, change to uppercase
        else if(s[i] > 90 && s[i] <= 122) {
            s[i] -= 32;
        }
    }
    printf("%s\n", s);
}

int main() {
    UpperCase(greeting);
    LowerCase(name);
    ToggleCase(name2);

    return 0;
}