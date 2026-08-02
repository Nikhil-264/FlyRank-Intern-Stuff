//counting number of letters
//not written by me learn
#include <stdio.h>
#include <ctype.h>

int main() {
    char word[100];
    int count = 0, i = 0;
    printf("Enter a word: ");
    scanf("%s", word);
    while (word[i] != '\0') {
        if (isalpha(word[i])) {
            count++;
        }
        i++;
    }
    printf("The word \"%s\" has %d letters.\n", word, count);
    return 0;
}