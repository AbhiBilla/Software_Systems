/*
============================================================================
Name : 10b .c
Author : Billa Abhignan
Description : Write a separate program using sigaction system call to catch the following signals.
              a. SIGSEGV
              b. SIGINT
              c. SIGFPE
Date: 26th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler(int signum) {
    printf("Received SIGINT (Interrupt)\n");
    exit(0);
}

int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;

    // Register the signal handler for SIGINT using sigaction
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Press Ctrl+C to send a SIGINT signal...\n");

    while (1) {
        // Program continues running until Ctrl+C is pressed
    }

    return 0;
}

