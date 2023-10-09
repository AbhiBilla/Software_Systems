/*
============================================================================
Name : 15.c
Author : Billa Abhignan
Description :  Write a simple program to send some data from parent to the child process.
Date: 5th Oct, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
    int pipefd[2];
    int fd1;
    char *buf="How are you";
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(0);
    }

    fd1 = fork();
    if(fd1 == -1){
        perror("fork");
        exit(0);
    }
    else if(fd1 == 0){
        char b1[100];
        close(pipefd[1]);
        int s = read(pipefd[0],&b1,sizeof(buf));
        if(s==-1){
           perror("Error\n");
           exit(0);
        }
        printf("%s\n",buf);
        //close(pipefd[0]);
    }
    else{
        close(pipefd[0]);
        write(pipefd[1], &buf, strlen(buf));
        close(pipefd[1]);
        exit(0);
    }
    return 0;
}
