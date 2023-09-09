/*
============================================================================
Name : 29.c
Author : Billa Abhignan
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date:  8th September, 2023.
============================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include<unistd.h>

int main() {
    int pid;
    int current_policy, new_policy;
    struct sched_param param;
    pid = getpid();
    current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("Error getting current scheduling policy");
        return 1;
    }
    printf("Current scheduling policy: ");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER (normal)\n");
            break;
        default:
            printf("Unknown\n");
    }
    new_policy = SCHED_FIFO;
    param.sched_priority = 50; 
    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("Error setting new scheduling policy");
        return 1;
    }
    current_policy = sched_getscheduler(pid);
    printf("New scheduling policy: ");
    switch (current_policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER (normal)\n");
            break;
        default:
            printf("Unknown\n");
    }

    return 0;
}

