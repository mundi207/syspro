#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int pid;

void arm_hendler(int signo) {
	if(signo == SIGALRM) {
		printf("시간 초과\n");
		kill(pid, SIGINT);
	}
}
		
int main(int argc, char **argv) {
	int child, status, limit;

	signal(SIGALRM, arm_hendler);
	sscanf(argv[1], "%d", &limit);
	alarm(limit);

	pid = fork();

	if(pid == 0) {
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s error\n", argv[2]);
	}
	else {
		child = wait(pid, &status);
		printf("자식 프로세스 종료 : %d\n", pid);
	}
}

