/*
============================================================================
Name : 30.c
Author : Billa Abhignan
Description :Write a program to run a script at a specific time using a Daemon process
Date:  8th September, 2023.
============================================================================
*/
#include <time.h>     
#include <stdio.h>     
#include <stdlib.h>    
#include <sys/types.h> 
#include <unistd.h>   
#include <sys/stat.h>  

void main(int argc, char *argv[])
{
    time_t currentEpoch, deadlineEpoch; 
    struct tm *deadline;                
    pid_t child;
    if (argc < 2)
        printf("Pass at least one argument\n");
    else
    {
        time(&currentEpoch); 
        deadline = localtime(&currentEpoch);
        deadline->tm_hour = atoi(argv[1]);
        deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
        deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);
        deadlineEpoch = mktime(deadline); // 
        if ((child = fork()) == 0)
        {
            setsid();
            chdir("/");
            umask(0);
            do
            {
                time(&currentEpoch);
            } while (difftime(deadlineEpoch, currentEpoch) > 0);
            printf("Boo! Got ya!\n");
            exit(0);
        }
        exit(0);
    }
}
