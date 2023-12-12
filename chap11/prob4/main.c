#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_hadler(int signo) {
	if(signo == SIGINT) {
		printf("Ctrl-C 를 한번 더 누르면 종료됩니다.\n");
		sigaction(SIGINT, &oldact, NULL); // 시그널 처리를 원래대로 변경
	}
}
int main(void) {
	newact.sa_handler = sigint_hadler;
	sigfillset(&newact.sa_mask);

	sigaction(SIGINT, &newact, &oldact);
	while(1) {
		printf("Ctrl-C를 눌러보세요.\n");
		sleep(1);
	}
}
		
