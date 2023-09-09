/*
============================================================================
Name : 22.c
Author : Billa Abhignan
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
              parent processes. Check output of the file.
Date:  8th September, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char * argv[]){
  int fd = open(argv[1], O_CREAT | O_RDWR);
  if(fd<0){
    perror("Cant open a file");
    return 1;
  }
  int pid = fork();
  if(pid==0){
    char buf[]="Written from Child process\n";
    int wr  = write(fd,&buf,sizeof(buf));
    if(wr<0){
      perror("Cant write using child process\n");
      return 1;
    }
  }
  else{
    char bf[]="Written from parent process\n";
    int wr  = write(fd,&bf,sizeof(bf));
    if(wr<0){
      perror("Cant write using child process\n");
      return 1;
    }
  }
  return 0;
}
