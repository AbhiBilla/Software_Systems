/*
============================================================================
Name : 14.c
Author : Billa Abhignan
Description :  Write a simple program to create a pipe, write to the pipe, read from pipe and display on 
               the monitor.
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
    char buf[100];
    int pipefd[2];
    
    if(pipe(pipefd) == -1){
        perror("pipe");
        exit(0);
    }

    write(pipefd[1],argv[1],strlen(argv[1]));
    read(pipefd[0],buf,strlen(argv[1]));
    printf("%s\n",buf);
    return 0;
}

