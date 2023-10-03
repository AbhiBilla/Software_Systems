/*
============================================================================
Name : 4.c
Author : Billa Abhignan
Description :  Write a program to measure how much time is taken to execute 100 getppid ( ) 
system call. Use time stamp counter. 
Date: 26th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include<unistd.h>
#include <x86intrin.h>

unsigned long long rdtsc() {
    return __rdtsc();
}

int main() {
    unsigned long long start, end;
    int i;

    start = rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();

    printf("Time taken to execute 100 getppid(): %llu cycles\n", end - start);

    return 0;
}
