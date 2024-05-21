#include <stdio.h>

char greeting[] = {'w', 'e', 'l', 'c', 'o', 'm', 'e', '\0'};
char name[] = "Sodiq";

void length(char s[])
{
    int i = 0;
    while(s[i] !='\0') {
        i++;
    }
    printf("%d\n", i);
}

int main() {
    length(greeting);
    length(name);

    return 0;
}