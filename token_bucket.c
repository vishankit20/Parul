#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

int main() {
    int bucket_size, output_rate;

    printf("Enter the bucket size: ");
    scanf("%d", &bucket_size);
    printf("Enter the output rate of the bucket: ");
    scanf("%d", &output_rate);

    int bucket = 0;

    while (true) {
        int incoming_packets;
        printf("\nEnter the number of incoming packets: ");
        scanf("%d", &incoming_packets);

        if (bucket + incoming_packets <= bucket_size) {
            bucket += incoming_packets;
            printf("Added %d packets to bucket. Current bucket: %d\n", incoming_packets, bucket);
        } else {
            printf("Bucket overflow! Dropping %d packets.\n", incoming_packets + bucket - bucket_size);
            bucket = bucket_size;
        }

        if (bucket >= output_rate) {
            printf("%d packets transmitted.\n", output_rate);
            bucket -= output_rate;
        } else {
            printf("Bucket empty.\n");
            bucket = 0;
        }

        usleep(1000000);
    }

    return 0;
}