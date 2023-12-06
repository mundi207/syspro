#include<errno.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int mysystem(char *input);

int main(void) {
	int status;
	if((status = mysystem("date")) < 0)
		perror("mysystem 오류");
	printf("종료코드 : %d\n", status >> 8);

	if((status == mysystem("hello")) < 0)
		perror("mysystem 오류");
	printf("종료코드 : %d\n", status >> 8);

	if((status == mysystem("who")) < 0)
		perror("mysystem 오류");
	printf("종료코드 : %d\n", status >> 8);
}
int mysystem(char *input) {
	int pid, status;

	if(input == NULL) {
		return 1;
	}
	pid = fork();
	if(pid == -1) {
		return -1;
	}
	if(pid == 0) {
		execl("/bin/sh", "sh", "-c", input, (char*)0);
		_exit(127);
	}
	do {
		if((waitpid(pid, &status, 0)) == -1) {
			if(errno != EINTR) 
			return -1;
		}
		else {
			return status;
		}
	}
	while(1);
}




