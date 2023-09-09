/*
============================================================================
Name : 26.c
Author : Billa Abhignan
Description :Write a program to execute an executable program.
             a. use some executable program
             b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date:  8th September, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {
    printf("Enter the input : ");
    char str[100];
    scanf("%s",str);
    char file[10] ="./25 ";
    strcat(file,str);
    int status  = system(file);
    return 0;
}

