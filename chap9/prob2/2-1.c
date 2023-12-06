#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(void) {
	int pid, child, status;

	printf("[%d] Parental Process start\n", getpid());
	pid = fork();

	if(pid == 0) {
		printf("[%d] child Process start\n", getpid());
		printf("[%d] Hello, World!\n", getpid());
		printf("[%d] child Process end\n", getpid());
		exit(1);
	}
	child = wait(&status); // 자식 프로세스 반환 
	printf("end code : %d\n", status >> 8);

	exit(0);
}
