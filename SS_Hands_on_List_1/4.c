/*
============================================================================
Name : 4.c
Author : Billa Abhignan
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 18th August, 2023.
============================================================================
*/
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char* argv[]){
	int fd = open(argv[1], O_EXCL|O_CREAT|O_RDWR);
	if(fd<0){
		printf("Error\n");
	}
	else{
		printf("File Opened Successfully");
	}
}
