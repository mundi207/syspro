#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int pid;

	pid = fork();

	if(pid == 0) {
		printf("[Child] : Hello, World pid = %d\n", getpid());
		exit(1);
	}
	printf("[Parent] : Hello, World pid = %d\n", getpid());
	exit(0);
}
