/*
============================================================================
Name : 28.c
Author : Billa Abhignan
Description :Write a program to get maximum and minimum real time priority.
Date:  8th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <sched.h>

int main() {
    int maxp= sched_get_priority_max(SCHED_FIFO);
    if (maxp == -1) {
        perror("Error\n");
        return 1;
    }
    int minp = sched_get_priority_min(SCHED_FIFO);
    if (minp== -1) {
        perror("Error\n");
        return 1;
    }
    printf("Maximum real-time priority: %d\n", maxp);
    printf("Minimum real-time priority: %d\n", minp);

    return 0;
}

