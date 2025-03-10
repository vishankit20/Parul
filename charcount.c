#include <stdio.h>
#include <string.h>

int main() {
    char s[1000], c;  
    int i, count = 0;

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);  // Using fgets instead of gets

    printf("Enter character to be searched: ");
    c = getchar();  // Read the character

    // Count occurrences of 'c' in 's'
    for (i = 0; s[i]; i++) {
        if (s[i] == c) {
            count++;
        }
    }

    printf("Character '%c' occurs %d times\n", c, count);

    return 0;
}