/*
============================================================================
Name : 17b.c
Author : Billa Abhignan
Description :  17. Write a program to execute ls -l | wc.    a. use dup    b. use dup2    c. use fcntl
Date: 5th Oct, 2023.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main() {
    int pipe_fd[2];

    pipe(pipe_fd);

    if (fork() == 0) {
        close(pipe_fd[0]); // Close read end

        dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pipe_fd[1]); // Close the duplicated file descriptor

        execlp("ls", "ls", "-l", NULL); // Execute ls -l
    } else {
        close(pipe_fd[1]); // Close write end

        dup2(pipe_fd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipe_fd[0]); // Close the duplicated file descriptor

        execlp("wc", "wc", NULL); // Execute wc
    }

    return 0;
}
