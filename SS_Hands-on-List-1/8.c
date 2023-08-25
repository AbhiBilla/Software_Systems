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
