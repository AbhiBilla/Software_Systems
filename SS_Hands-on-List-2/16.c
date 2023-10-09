/*
============================================================================
Name : 16.c
Author : Billa Abhignan
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication
Date: 5th October, 2023.
============================================================================
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h>
     
int main(void) 
{
    int ptc[2];        
    int ctp[2];          
    int r, w;
    char *writeBuf, *readBuf;
    pipe(ptc); 
    pipe(ctp); 
    int child = fork(); 
    if (child != 0) { 
            close(ptc[0]);
            close(ctp[1]);
            writeBuf = "Data from parent process";
            w = write(ptc[1], &writeBuf, sizeof(writeBuf)); 
            if(w == -1)
            	perror("Error while writing from parent to child");
            	
            r = read(ctp[0], &readBuf, sizeof(readBuf));
            
            if(r == -1)
            	perror("Error while reading from child to parent");
            else 
            	printf("This parent read: %s\n", readBuf);
        } 
        
        else { 
            /* child */ 
            close(ptc[1]);
            close(ctp[0]);
            
            writeBuf = "Data from child process";
            w = write(ctp[1], &writeBuf, sizeof(writeBuf));
            
            if(w == -1)
            	perror("Error while writing to child to parent");
            
            r = read(ptc[0], &readBuf, sizeof(readBuf));
            if(r == -1)
            	perror("Error while reading from parent to child");
            
            else
            	printf("The child read : %s\n", readBuf);
      }
} 
