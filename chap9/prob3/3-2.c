#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int pid1, pid2, pid3;

	printf("Parental Process Start\n");
	pid1 = fork();
	if(pid1 == 0) {
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "echo 실패\n");
		exit(1);
	}
	pid2 = fork();
	if(pid2 == 0) {
		execl("/bin/date", "date", NULL);
		fprintf(stderr, "date 실패\n");
		exit(2);
	}
	pid3 = fork();
	if(pid3 == 0) {
		execl("/bin/ls", "ls", "-l",  NULL);
		fprintf(stderr, "date 실패\n");
		exit(3);
	}
	printf("Parental Process End\n");

	exit(0);
}
