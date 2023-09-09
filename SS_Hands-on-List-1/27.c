/*
============================================================================
Name : 27.c
Author : Billa Abhignan
Description :Write a program to execute ls -Rl by the following system calls
             a. execl
             b. execlp
             c. execled. 
             d. execv
             e. execvp
Date:  8th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Using execl:\n");
    if (fork() == 0) {
        execl("/bin/ls", "ls", "-Rl", NULL);
        perror("execl");
        exit(1);
    }

    printf("\nUsing execlp:\n");
    if (fork() == 0) {
        execlp("ls", "ls", "-Rl", NULL);
        perror("execlp");
        exit(1);
    }

    printf("\nUsing execle:\n");
    char *envp[] = { NULL };
    if (fork() == 0) {
        char *args[] = { "ls", "-Rl", NULL };
        execle("/bin/ls", "ls", "-Rl", NULL, envp);
        perror("execle");
        exit(1);
    }

    printf("\nUsing execv:\n");
    if (fork() == 0) {
        char *args[] = { "/bin/ls", "ls", "-Rl", NULL };
        execv("/bin/ls", args);
        perror("execv");
        exit(1);
    }

    printf("\nUsing execvp:\n");
    if (fork() == 0) {
        char *args[] = { "ls", "ls", "-Rl", NULL };
        execvp("ls", args);
        perror("execvp");
        exit(1);
    }

    return 0;
}

