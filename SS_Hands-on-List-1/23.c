/*
============================================================================
Name : 23.c
Author : Billa Abhignan
Description : Write a program to create a Zombie state of the running program.
Date:  8th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid == 0) {
        // This code runs in the child process
        printf("Child process is running.\n");
        printf("Child process is exiting.\n");
        printf("CHILD PID : %d\n",getpid());
        exit(0); // Child process exits
    } else if (child_pid > 0) {
        // This code runs in the parent process
        printf("PARENT PID : %d\n",getpid());
        printf("Parent process is running.\n");
        sleep(50); // Sleep for 5 seconds to ensure the child becomes a zombie
        printf("Parent process is exiting.\n");
    } else {
        perror("fork");
        return 1; // Fork failed
    }

    return 0;
}

