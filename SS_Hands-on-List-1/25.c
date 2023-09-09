/*
============================================================================
Name : 25.c
Author : Billa Abhignan
Description :Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date:  8th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc ,char * argv[]){
  printf("%s\n",argv[1]);
  int status,pid2,pid3;
  int pid1=fork();
  if(pid1==0){
    printf("Child-1 Created \n");
    pid2 = fork();
    if(pid2==0){
       printf("Child-2 Created \n");
       pid3=fork();
       if(pid3==0){
         printf("Child-3 Created \n");
       }
       else{
         waitpid(pid3,&status,0);
         printf("Parent exit after Child-3 \n");
       }
    }
    else{
       waitpid(pid2,&status,0);
       printf("Parent exit after Child-2 \n");
    }
  }
  else{
    waitpid(pid1,&status,0);
    printf("Parent exit after Child-1 \n");
  }
  //printf("%d\n",status);
  return 0;
}
