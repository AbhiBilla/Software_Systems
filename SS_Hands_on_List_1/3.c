/*
============================================================================
Name : 3.c
Author : Billa Abhignan
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 17th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<fcntl.h>
void main(){
	int fd = creat("new.txt",S_IRWXU);
	printf("fd is %d\n",fd);

}
