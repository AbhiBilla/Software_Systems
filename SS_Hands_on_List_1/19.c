/*
============================================================================
Name : 19.c
Author : Billa Abhignan
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date:  8th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(){
   clock_t t;
   t = clock();
   double an = (double)t/CLOCKS_PER_SEC;
   printf("Start time is %f\n",an);
   pid_t pid = getpid();
   t = clock();
   double ans = (double)t/CLOCKS_PER_SEC;
   printf("End time is : %f\n",ans);
   double f = ans-an;
   printf("Total Time Taken is %f\n",f);
   return 0;
}

