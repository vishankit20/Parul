#include <stdio.h>
#include <stdlib.h>  // Added for exit()
#include <unistd.h>

#define MSGSIZE 16 

int main() {
    char inbuf[MSGSIZE];  
    int p[2], i;  
    char* msg1 = "hello friends";  
    char* msg2 = "hello, world #2";  
    char* msg3 = "hello, world #3";  

    if (pipe(p) < 0) {  
        perror("pipe failed");
        exit(1);  
    }  

    /* Write to the pipe */
    write(p[1], msg1, MSGSIZE);  
    write(p[1], msg2, MSGSIZE);  
    write(p[1], msg3, MSGSIZE);  

    close(p[1]);  // Close write end after writing

    /* Read from the pipe */
    for (i = 0; i < 3; i++) {  
        read(p[0], inbuf, MSGSIZE);  
        printf("%s\n", inbuf);  
    }  

    close(p[0]);  // Close read end after reading
    return 0;  
}