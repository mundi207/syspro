#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void) {
	int pid1, pid2, child, status;

	printf("부모 프로세스 시작[%d]\n", getpid());
	pid1 = fork();

	if(pid1 == 0) {
		printf("자식 프로세스1 시작 [%d]\n", getpid());
		sleep(1);
		printf("자식 프로세스1 종료 [%d]\n", getpid());
		exit(1);
	}
	pid2 = fork();
	if(pid2 == 0) {
		printf("자식 프로세스2 시작 [%d]\n", getpid());
		sleep(2);
		printf("자식 프로세스2 종료 [%d]\n", getpid());
		exit(2);
	}
	child = waitpid(pid1, &status, 0);
	printf("자식 프로세스1 종료코드 [%d] : %d\n", child, status >> 8);
	printf("부모 프로세스 종료 [%d]\n", getpid());
	exit(0);
}


