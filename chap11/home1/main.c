#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

struct sigaction old;
struct sigaction new;

void SIGNAL(int signo, void (*func)(int)) {
	new.sa_handler = func;
	sigaction(signo, &new, &old);
	sigfillset(&new.sa_mask);
}
void arm_hendler(int signo) {
	if(signo == SIGALRM) {
		printf("프로그램 종료\n");
		exit(0);
	}
}
int main(void) {
	int count = 0;
	SIGNAL(SIGALRM, arm_hendler);

	alarm(5);
	while(1) {
		printf("%d\n", ++count);
		sleep(1);
	}
}


