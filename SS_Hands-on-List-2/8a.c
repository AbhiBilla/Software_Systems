/*
============================================================================
Name : 8a.c
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

void sigsegv_handler(int signum) {
    printf("Received SIGSEGV (Segmentation Fault)\n");
    exit(1);
}

int main() {
    // Catch SIGSEGV using the signal system call
    signal(SIGSEGV, sigsegv_handler);

    // Trigger a segmentation fault
    int *ptr = NULL;
    *ptr = 42; // This will cause a segmentation fault

    // This line will not be reached due to the segmentation fault
    printf("Program continues after the segmentation fault.\n");

    return 0;
}

