#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int pid, gid;

	printf("PARENT : PID = %d, GID = %d \n", getpid(), getpgrp());

	pid = fork();
	if(pid == 0) {
		printf("CHILD : PID = %d, GID = %d \n", getpid(), getpgrp());
	}

	exit(0);
}
