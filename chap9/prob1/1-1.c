#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int pid;

	pid = fork();
	if(pid != 0)
		printf("[%d] Process Start\n", getpid());
	printf("[%d] Process return value : %d\n", getpid(), pid);

	exit(0);
}

