#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int args, char **argv) {
	int pid1, child, status;

	pid1 = fork();
	if(pid1 == 0) {
		execvp(argv[1], &argv[1]);
		fprintf(stderr, "%s Error\n", argv[1]);
		exit(1);
	}
	if(pid1 == EOF) {
		fprintf(stderr, "fork Error\n");
	}
	child = waitpid(pid1, &status, 0);
	printf("[%d] child process %d end : code %d\n", getpid(), child, status >> 8);
	exit(0);
}
