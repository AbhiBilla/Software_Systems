#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include<unistd.h>

int main() {
    int pid;  // Process ID of the current process
    int current_policy, new_policy;
    struct sched_param param;

    // Get the current process ID
    pid = getpid();

    // Get the current scheduling policy
    current_policy = sched_getscheduler(pid);
    if (current_policy == -1) {
        perror("Error getting current scheduling policy");
        return 1;
    }

    // Print the current scheduling policy
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

    // Set a new scheduling policy (SCHED_FIFO)
    new_policy = SCHED_FIFO;
    param.sched_priority = 50; // Priority value (adjust as needed)

    if (sched_setscheduler(pid, new_policy, &param) == -1) {
        perror("Error setting new scheduling policy");
        return 1;
    }

    // Get and print the new scheduling policy
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

