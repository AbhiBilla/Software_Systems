/*
============================================================================
Name : 10a.c
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

void sigsegv_handler(int signum) {
    printf("Received SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    // Initialize the sigaction struct
    sa.sa_handler = sigsegv_handler;
    sa.sa_flags = 0;
    
    // Register the signal handler for SIGSEGV using sigaction
    if (sigaction(SIGSEGV, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Trigger a segmentation fault
    int *ptr = NULL;
    *ptr = 42; // This will cause a segmentation fault

    // This line will not be reached due to the segmentation fault
    printf("Program continues after the segmentation fault.\n");

    return 0;
}

