/*
============================================================================
Name : 6.c
Author : Billa Abhignan
Description :  Write a simple program to create three threads. 
Date: 26th Sept, 2023.
============================================================================
*/
#include <stdio.h>
#include <pthread.h>

void* thread_function(void* arg) {
    int thread_num = *((int*)arg);
    printf("This is thread %d\n", thread_num);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    int thread_num[3] = {1, 2, 3};

    pthread_create(&thread1, NULL, thread_function, &thread_num[0]);
    pthread_create(&thread2, NULL, thread_function, &thread_num[1]);
    pthread_create(&thread3, NULL, thread_function, &thread_num[2]);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}
