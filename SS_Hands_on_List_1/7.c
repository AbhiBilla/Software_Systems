/*
============================================================================
Name : 7.c
Author : Billa Abhignan
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 18th August, 2023.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	printf("%d",argc);
	if(argc!=3){
		printf("Error");
	}
	int fd = open(argv[1], O_RDONLY);
        int fdw  = open(argv[2],O_WRONLY|O_CREAT);
	if(fd==-1 || fdw==-1){
		printf("Error");
	}
	while(1){
	  char buf;
	  int char_read = read(fd,&buf,1);
	  if(char_read==0){
		  break;
	  }
	  int char_write = write(fdw,&buf,1);
	}
	int fd_close  = close(fd);
	int fdw_close = close(fdw);
	if(fd_close==-1 || fdw_close==-1){
		printf("Closing Error");
	}
	return 0;
}
