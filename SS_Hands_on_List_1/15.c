/*
============================================================================
Name : 15.c
Author : Billa Abhignan
Description : Write a program to display the environmental variable of the user (use environ).
Date:  25th August, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char **environ;  

int main() {
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
    return 0;
}

