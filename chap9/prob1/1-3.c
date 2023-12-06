#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(void) {
	int pid, pid2;

	printf("[Parent] : Hello, World! pid=%d\n", getpid());
	pid = fork();
	if(pid == 0) {
		printf("[Child 1] : Hello, World ! pid=%d\n", getpid());
		exit(1);
	}
	pid2 = fork();
	if(pid2 == 0) {
		printf("[Child 2] : Hello, World ! pid=%d\n", getpid());
		exit(2);
	}
	exit(0);
}
