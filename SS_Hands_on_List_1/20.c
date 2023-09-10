/*
============================================================================
Name : 20.c
Author : Billa Abhignan
Description :Find out the priority of your running program. Modify the priority with nice command.
Date:  8th September, 2023.
============================================================================
*/
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    int priority, newp;
    if (argc != 2)
        printf("Please pass the integer value to be added to the current nice value\n");
    else
    {
        newp = atoi(argv[1]);
        priority = nice(0); 
        printf("Current priority: %d\n", priority);
        priority = nice(newp);
        printf("New priority: %d\n", priority);
    }
}
