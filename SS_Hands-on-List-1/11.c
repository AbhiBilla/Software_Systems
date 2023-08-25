#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char * argv[]){
  int orgfd = open(argv[1], O_WRONLY);
  if(orgfd==-1){
      perror("Error in Opening File");
      return 1;
  }
  int dfd = dup(orgfd);
  if(dfd==-1){
     perror("Error in Duplicating fd");
     return 1;
  }
  lseek(orgfd,-1,SEEK_END);
  const char str[] = "How are you.\n";
  int t = write(orgfd,str,sizeof(str));
  if(t==-1){
    perror("Error in writing");
    return 1;
  }
  const char str1[] = "This is appended using duplicate fd.\n";
  int t1 = write(dfd,str1,sizeof(str1));
  if(t1==-1){
    perror("Error in writing");
    return 1;
  }
  close(orgfd);
  close(dfd);
}
