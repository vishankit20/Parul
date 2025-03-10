#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 1000

void generateFrames(char *message, int frameLength) {
    int messageLength = strlen(message);
    
    if (frameLength <= 0) {
        printf("Error: Frame length must be greater than zero.\n");
        return;
    }
    
    int numFrames = (messageLength + frameLength - 1) / frameLength; // Calculate number of frames
    int i, j;

    printf("\nFrames:\n");
    for (i = 0; i < numFrames; i++) {
        printf("Frame %d: ", i + 1);
        for (j = 0; j < frameLength && (i * frameLength + j) < messageLength; j++) {
            printf("%c", message[i * frameLength + j]);
        }
        printf("\n");
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int frameLength;

    printf("Enter the message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove trailing newline

    printf("Enter the frame length: ");
    if (scanf("%d", &frameLength) != 1) {  // Ensure valid input
        printf("Error: Invalid frame length.\n");
        return 1;
    }

    generateFrames(message, frameLength);

    return 0;
}