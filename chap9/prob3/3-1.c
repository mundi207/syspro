#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void) {
	int pid;

	printf("부모 프로세스 시작 [%d]\n", getpid());
	pid = fork();

	if(pid == 0) {
		execl("/bin/echo", "echo", "hello", NULL);
		fprintf(stderr, "첫 번째 실패\n");
		exit(1);
	}
	printf("부모 프로세스 끝\n");
	exit(0);
}
