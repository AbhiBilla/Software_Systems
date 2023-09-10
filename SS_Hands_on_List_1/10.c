/*
============================================================================
Name : 10.c
Author : Billa Abhignan
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
              a. check the return value of lseek
              b. open the file with od and check the empty spaces in between the data.
Date: 24th August, 2023.
============================================================================
*/
#include <stdio.h>
#include<sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char * argv[]) {
    int fd = open(argv[1], O_RDWR|O_CREAT);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    char data1[] = "0123456789";
    int w = write(fd, data1, sizeof(data1));
    if (w == -1) {
        perror("Error writing data");
        return 1;
    }
    int offset = 10;
    int l = lseek(fd, -1*offset, SEEK_CUR);
    printf("New position after lseek: %d\n", l);
    char data2[] = "abcdefghij";
    w = write(fd, data2, sizeof(data2));
    if (w == -1) {
        perror("Error writing data");
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

