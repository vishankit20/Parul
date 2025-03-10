#include <stdio.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_STUFFED_SIZE 200  // Allocating enough space for worst-case scenario

int main() {
    char data[MAX_DATA_SIZE], stuffedData[MAX_STUFFED_SIZE];
    int i, count = 0, j = 0;

    // Input Data
    printf("Enter the data (binary string): ");
    scanf("%s", data);

    // Bit Stuffing Logic
    for (i = 0; i < strlen(data); i++) {
        stuffedData[j++] = data[i];

        if (data[i] == '1') {
            count++;
        } else {
            count = 0; // Reset count on encountering '0'
        }

        if (count == 5) { 
            stuffedData[j++] = '0'; // Insert a '0' after five consecutive '1's
            count = 0; // Reset count after stuffing
        }
    }

    stuffedData[j] = '\0'; // Null-terminate the stuffed data string

    // Output the stuffed data
    printf("Data after bit stuffing: %s\n", stuffedData);

    return 0;
}