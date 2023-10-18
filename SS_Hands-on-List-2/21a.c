/*
============================================================================
Name : 21a.c
Author : Billa Abhignan
Description : Write two programs so that both can communicate by FIFO -Use two way communication. 
Date: 9th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
   char buff1[50];
   char buff2[50]; 
   int e = mkfifo("myfifo1",0666);
   if(e<0)
     perror("mkfifo returns");
   e = mkfifo("myfifo2",0666);
   if(e<0)
     perror("mkfifo returns");
   int fd1 = open("myfifo1", O_WRONLY);
   int fd2 = open("myfifo2", O_RDONLY);
   if(fd1==-1 || fd2==-1){
     printf("unable to open files\n");
     return 1;
   }
   
   printf("Enter the text:\n");
   scanf(" %[^\n]", buff1);
   
   int fd_write = write(fd1, buff1, sizeof(buff1));
   if(fd_write==-1){
     perror("returns:");
     close(fd1);
     return 1;
   }
   
   int fd_read = read(fd2, buff2, sizeof(buff2));
   if(fd_read==-1){
     perror("returns:");
     close(fd2);
     return 1;
   }
   printf("The text from program 2 is: %s\n", buff2);
   close(fd1);
   close(fd2);
   return 1;
}
