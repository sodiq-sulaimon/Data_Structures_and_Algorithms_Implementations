#include <stdio.h>

char greeting[] = "How are  you,    John?";

void CountVowel(char s[])
{
    int vowelsCount = 0;
    int consonantsCount = 0;
    for (int i = 0; s[i] !='\0'; i++) {
        if(s[i]=='a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' ||
                s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            vowelsCount++;
            }
        else if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122) {//Exclude special characters
            consonantsCount++;
        }
    }
    printf("Vowels: %d\n", vowelsCount);
    printf("Consonants: %d\n", consonantsCount);
}

void CountWords(char s[])
{
    int wordsCount = 1; // initialized to 1 to account for the last word
    for (int i = 0; s[i] !='\0'; i++) {
        if (s[i] == ' ' && s[i+1] != ' ') { //skip whitespace"
            wordsCount++;
        }
    }
    printf("Words: %d\n", wordsCount);
}

int main() {
    CountVowel(greeting);
    CountWords(greeting);


    return 0;
}