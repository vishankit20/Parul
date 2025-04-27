#include <stdio.h>

int main() {
    int data[10], vrc = 0;
    
    printf("Enter 7 bits of data: ");
    for(int i = 0; i < 7; i++) {
        scanf("%d", &data[i]);
    }
    
    for(int i = 0; i < 7; i++) {
        vrc ^= data[i];
    }
    
    printf("VRC bit is: %d\n", vrc);
    
    return 0;
}
