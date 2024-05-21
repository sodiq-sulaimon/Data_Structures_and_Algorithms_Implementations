#include <stdio.h>

char c = 'A';
char name[] = {'S', 'o', 'd', 'i', 'q', '\0'};


int main() {
    printf("%c\n", c);
    printf("%s\n", name);

    return 0;
}