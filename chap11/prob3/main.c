#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void intHendler(int signo) {
	if(signo == SIGINT) {
		printf("프로그램 종료 : %d\n", signo);
		exit(0);
	}
}
void armHendler(int signo) {
	if(signo == SIGALRM) {
		printf("프로그램 종료 : %d\n", signo);
		exit(0);
	}
}
int main(void) {
	int i = 0;

	signal(SIGINT, intHendler);
	signal(SIGALRM, armHendler);
	alarm(5);

	while(1) {
		printf("%d\n", ++i); 
		sleep(1);
	}
}

