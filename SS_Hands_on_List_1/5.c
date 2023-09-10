/*
============================================================================
Name : 5.c
Author : Billa Abhignan
Description : Write a program to create five new files with infinite loop. Execute the program in the background
              and check the file descriptor table at /proc/pid/fd.
Date: 18th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(void){
        printf("PID : %d\n",getpid());
	while(1){
		int fd = open("file2",O_CREAT);
		if(fd==-1){
			printf("ERROR\n");
			sleep(100);
			break;
		}
		int fd1 = open("file2",O_CREAT);
		if(fd1==-1){
			printf("ERROR\n");
			sleep(100);
			break;
		}
		printf("%d %d",fd,fd1);
	}
	return 0;
}
