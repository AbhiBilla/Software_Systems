/*
============================================================================
Name : 1c.c
Author : Billa Abhignan
Description :  Write a separate program (for each time domain) to set a interval timer in 10sec and 
10micro second        a. ITIMER_REAL        b. ITIMER_VIRTUAL        c. ITIMER_PROF
Date: 26th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Interval Timer Expired!\n");
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handler);

    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) {
        // Program will continue running and the timer will trigger every 10 seconds
        sleep(1);
    }

    return 0;
}
