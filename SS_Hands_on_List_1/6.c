/*
============================================================================
Name : 6.c
Author : Billa Abhignan
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 18th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
	char m[20];
	read(0,m,11);
	write(1,m,11);
	printf("\n");
}
