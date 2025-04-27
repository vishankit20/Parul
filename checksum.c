#include <stdio.h>
#include <math.h>

int sender(int arr[], int n) {
    int checksum, sum = 0, i;
    printf("\n*** SENDER SIDE ***\n");
    for (i = 0; i < n; i++)
        sum += arr[i];
    printf("SUM IS: %d", sum);
    checksum = ~sum;
    printf("\nCHECKSUM IS: %d", checksum);
    return checksum;
}

void receiver(int arr[], int n, int sch) {
    int checksum, sum = 0, i;
    printf("\n\n*** RECEIVER SIDE ***\n");
    for (i = 0; i < n; i++)
        sum += arr[i];
    printf("SUM IS: %d", sum);
    sum += sch;
    checksum = ~sum;
    printf("\nCHECKSUM IS: %d", checksum);
    if (checksum == 0)
        printf("\nData is received correctly (NO ERROR).\n");
    else
        printf("\nData is corrupted (ERROR DETECTED).\n");
}

int main() {
    int n, sch;
    printf("ENTER SIZE OF THE ARRAY: ");
    scanf("%d", &n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY TO CALCULATE CHECKSUM:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sch = sender(arr, n);
    receiver(arr, n, sch);
    return 0;
}