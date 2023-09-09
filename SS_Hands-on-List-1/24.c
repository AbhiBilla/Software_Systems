/*
============================================================================
Name : 24.c
Author : Billa Abhignan
Description :Write a program to create an orphan process.
Date:  8th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
  int pid  = fork();
  int status;
  if(pid==0){
    printf("Child Process Running\n");
    printf("CHILD PID : %d\n",getpid());
    printf("Child Became Orphan\n");
    sleep(20);
  }
  else{
    printf("Parent Process Running\n");
    printf("Parent Process exit\n");
    //waitpid(pid,&status,0);
    exit(0);
  }
  return 0;
}
