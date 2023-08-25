#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
	char m[20];
	read(0,m,10);
	write(1,m,10);
	printf("\n");
}
