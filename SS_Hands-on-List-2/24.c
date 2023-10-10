/*
============================================================================
Name : 24.c
Author : Billa Abhignan
Description : Write a program to create a message queue and print the key and message queue id.
Date: 9th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

int main(void) {
	
	int msg_queue = ftok(".", 1);
	if(msg_queue == -1) {
		perror("Error");
		return 0;
	}
	
	int que = msgget(msg_queue, IPC_CREAT | 0777);
	
	if(que == -1) {
		perror("Error while running msgget");
		return 0;
	}
	
	printf("Key: %d\n", msg_queue);
	printf("Message Queue ID: %d\n", que);
	
}
