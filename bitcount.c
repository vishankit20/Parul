#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Add 1 if the least significant bit is set
        n >>= 1;         // Right shift the number by 1 bit
    }
    return count;
}

int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
   
    int result = countSetBits(num);
    printf("Number of set bits in %d: %d\n", num, result);
   
    return 0;
}