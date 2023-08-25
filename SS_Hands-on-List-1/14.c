#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char * argv[]){
   struct stat fileinfo;
   int t=stat(argv[1], &fileinfo);
   if(t==-1){
     perror("Error");
     return 1;
   }
   int mode  = fileinfo.st_mode;
   if(S_ISREG(mode)){
     printf("Regular File\n");
   }
   else if(S_ISDIR(mode)){
      printf("Directory\n");
   }
   else if(S_ISCHR(mode)){
     printf("Character special file\n");
   }
   else if(S_ISBLK(mode)){
     printf("Block Special File\n");
   }
   else if(S_ISFIFO(mode)){
     printf("FIFO Named pipe\n");
   }
   else if(S_ISLINK(mode)){
     printf("Symbolic Link\n");
   }
   return 0;
}
