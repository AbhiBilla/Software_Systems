/*
============================================================================
Name : 8d.c
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
#include <unistd.h>

void sigalrm_handler(int signum) {
    printf("Received SIGALRM\n");
    exit(0);
}

int main() {
    // Catch SIGALRM using the signal system call
    signal(SIGALRM, sigalrm_handler);

    printf("Setting an alarm for 5 seconds...\n");
    alarm(5); // Set an alarm for 5 seconds

    printf("Waiting for the alarm...\n");

    while (1) {
        // Program continues running until SIGALRM is received
    }

    return 0;
}

