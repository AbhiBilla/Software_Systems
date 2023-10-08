/*
============================================================================
Name : 10c.c
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

void sigfpe_handler(int signum) {
    printf("Received SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigfpe_handler;
    sa.sa_flags = 0;

    // Register the signal handler for SIGFPE using sigaction
    if (sigaction(SIGFPE, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Enter a number to perform an illegal floating-point operation:\n");

    double result = 1.0 / 0.0; // This will cause a SIGFPE

    // This line will not be reached due to the SIGFPE
    printf("Result: %f\n", result);

    return 0;
}

