#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int main(void) {
	int pid1, pid2;
	int count1 = 0;
	int count2 = 0;

	pid1 = fork();
	if(pid1 == 0) {
		while(1) {
			sleep(1);
			printf("자식 1 실행 : %d\n", ++count1);
		}
	}
	pid2 = fork();
	if(pid2 == 0) {
		while(1) {
			sleep(1);
			printf("자식 2 실행 : %d\n", ++count2);
		}
	}
	sleep(2);
	kill(pid1, SIGSTOP);
	sleep(2);
	kill(pid1, SIGCONT);
	sleep(2);
	kill(pid2, SIGSTOP);
	sleep(2);
	kill(pid2, SIGCONT);
	sleep(2);
	kill(pid1, SIGINT);
	sleep(2);
	kill(pid2, SIGINT);
}

