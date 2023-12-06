#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(void) {
	int pid, gid;

	printf("PARENT : PID = %d, GID = %d\n", getgid(), getpgrp());

	pid = fork();
	if(pid == 0) {
		setpgid(0, 0);
		printf("PARENT : PID = %d, GID = %d\n", getgid(), getpgrp());
		exit(1);
	}
	exit(0);
}

