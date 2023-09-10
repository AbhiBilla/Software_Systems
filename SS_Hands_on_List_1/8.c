/*
============================================================================
Name : 8.c
Author : Billa Abhignan
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date: 18th August, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
	int fd = open(argv[1], O_RDONLY);
	while(1){
		char c;
		int cr= read(fd,&c,1);
		if(cr==0){
			break;
		}
		if(cr=='\n'){
			printf("\n");
		}
		else{
			printf("%c",c);
		}
	}
	return 0;
}
