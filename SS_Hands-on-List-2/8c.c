/*
============================================================================
Name : 8c.c
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

void sigfpe_handler(int signum) {
    printf("Received SIGFPE (Floating Point Exception)\n");
    exit(1);
}

int main() {
    // Catch SIGFPE using the signal system call
    signal(SIGFPE, sigfpe_handler);

    printf("Enter a number to divide by zero: ");

    int divisor;
    scanf("%d", &divisor);

    int result = 10 / divisor; // Division by zero will cause a SIGFPE

    // This line will not be reached if a SIGFPE occurs
    printf("Result: %d\n", result);

    return 0;
}

