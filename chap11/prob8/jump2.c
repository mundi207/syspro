#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>
#include<signal.h>

jmp_buf env;
void intHandler(int signo) {
	if(signo == SIGINT) {
		longjmp(env, 1);
	}
}

int main(void) {
	signal(SIGINT, intHandler);
	if(setjmp(env) != 0) {
		printf("인터럽트로 인한 복귀\n");
		exit(0);
	}
	else {
		printf("처음 통과\n");
		while(1) {
			sleep(1);
			printf("계속 실행중...\n");
		}
	}
}
	
