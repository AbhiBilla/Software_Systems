#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc ,char * argv[]){
	int v = symlink("t1","link");
	if(v<0)
        {
		perror("Failed");
		return 1;
	}
	int f = link("t1","hardlink");
	if(f<0){
		perror("Failed");
		return 1;
	}
	int e = mknod("destFIFO",S_IFIFO,0);
	if(e<0){
		perror("Failed");
		return 1;
	}
	return 0;
}
