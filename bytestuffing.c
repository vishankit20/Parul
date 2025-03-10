#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 50
#define MAX_LENGTH 50

int main() {
    char frame[MAX_STRINGS][MAX_LENGTH], str[MAX_STRINGS][MAX_LENGTH];
    char flag[] = "flag";
    char esc[] = "esc";
    int i, k = 0, n;

    strcpy(frame[k++], flag); // Start with flag

    // Get input length
    printf("Enter length of String: ");
    scanf("%d", &n);
    getchar(); // Clear newline left in buffer

    printf("Enter the strings:\n");
    for (i = 0; i < n; i++) {
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline character
    }

    // Display entered strings
    printf("\nYou entered:\n");
    for (i = 0; i < n; i++) {
        puts(str[i]);
    }

    // Perform Byte Stuffing
    for (i = 0; i < n; i++) {
        if (strcmp(str[i], flag) != 0 && strcmp(str[i], esc) != 0) {
            strcpy(frame[k++], str[i]);
        } else {
            strcpy(frame[k++], esc);
            strcpy(frame[k++], str[i]);
        }
    }
    strcpy(frame[k++], flag); // End with flag

    // Output Byte Stuffed Data
    printf("\n------------------------------\n");
    printf("Byte stuffing at sender side:\n");
    printf("------------------------------\n\n");

    for (i = 0; i < k; i++) {
        printf("%s\t", frame[i]);
    }
    printf("\n");

    return 0;
}