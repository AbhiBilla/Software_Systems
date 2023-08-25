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
