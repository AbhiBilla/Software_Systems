/*
============================================================================
Name : 8f.c
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
#include <sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Received SIGVTALRM (Virtual Timer Alarm)\n");
    exit(0);
}

int main() {
    // Catch SIGVTALRM using the signal system call
    signal(SIGVTALRM, sigvtalrm_handler);

    printf("Setting a virtual interval timer for 5 seconds...\n");

    struct itimerval itimer;
    itimer.it_value.tv_sec = 5;
    itimer.it_value.tv_usec = 0;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &itimer, NULL) == -1) {
        perror("setitimer");
        return 1;
    }

    printf("Waiting for the virtual timer to expire...\n");

    while (1) {
        // Program continues running until SIGVTALRM is received
    }

    return 0;
}

