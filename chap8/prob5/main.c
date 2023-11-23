#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
	printf("프로세스 id : %d\n", getpid());
	printf("부모 프로세스 id : %d\n", getppid());
	exit(0);
}
