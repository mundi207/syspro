#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char **argv) {
	int pid;
	int fd;
	int status;
	int child;

	pid = fork();
	if(pid == 0) {
		if((fd = open(argv[1], O_CREAT |O_TRUNC |O_WRONLY, 0660) < 0)) {
			perror(argv[1]);
			exit(1);
		}
		dup2(fd, 1);
		close(fd);
		execvp(argv[2], &argv[2]);
		fprintf(stderr, "%s 실행불가\n", argv[1]);
	}
	else {
		child = wait(&status);
		printf("[%d] 자식프로세스 종료 : %d\n", child, status >> 8);
	}
	exit(0);
}


