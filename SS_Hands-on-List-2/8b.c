/*
============================================================================
Name : 8b.c
Author : Billa Abhignan
Description :  Write a separate program using signal system call to catch the following signals.
               a. SIGSEGV
               b. SIGINT
               c. SIGFPE
               d. SIGALRM (use alarm system call)
               e. SIGALRM (use setitimer system call)
               f. SIGVTALRM (use setitimer system call)
               g. SIGPROF (use setitimer system call)
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
    // Catch SIGINT using the signal system call
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl+C to send a SIGINT signal...\n");

    while (1) {
        // Program continues running until SIGINT is received
    }

    return 0;
}

