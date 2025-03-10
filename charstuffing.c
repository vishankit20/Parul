#include <stdio.h>
#include <string.h>

#define MAX_FRAME_SIZE 100

void characterStuffing(char* input, char* stuffed, char delimiter) {
    int i, j = 0;
    stuffed[j++] = delimiter; // Start delimiter

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == delimiter) {
            stuffed[j++] = delimiter; // Escape the delimiter
        }
        stuffed[j++] = input[i]; // Add the actual character
    }

    stuffed[j++] = delimiter; // End delimiter
    stuffed[j] = '\0'; // Null terminator
}

int main() {
    char input[MAX_FRAME_SIZE];
    char stuffed[MAX_FRAME_SIZE * 2]; // Maximum possible stuffed frame size
    char delimiter;

    printf("Enter the frame: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("Enter the delimiter character: ");
    delimiter = getchar();
    getchar(); // Consume leftover newline character

    characterStuffing(input, stuffed, delimiter);

    printf("Stuffed frame: %s\n", stuffed);

    return 0;
}