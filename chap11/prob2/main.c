#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void alarmHendler(int signo) {
	if(signo == SIGALRM) {
		printf("인나라\n");
		exit(0);
	}
}
int main(void) {
	int i = 0;

	signal(SIGALRM, alarmHendler);
	alarm(5);

	while(1) {
		i ++;
		sleep(1);
		printf("%d\n", i);
	}
}
