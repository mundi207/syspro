#include<stdio.h>
#include<stdlib.h>

static void exit_hendler1(void);
static void exit_hendler2(void);

int main(void) {
	if((atexit(exit_hendler1)) != 0) {
		perror("처리할 수 없음 (hendler1)");
		exit(1);
	}
	if((atexit(exit_hendler2)) != 0) {
		perror("처리할 수 없음 (hendler2)");
		exit(1);
	}
	printf("main 함수 끝\n");
	exit(0);
}
static void exit_hendler1(void) {
	printf("첫 번째 exit처리\n");
}
static void exit_hendler2(void) {
	printf("두 번째 exit처리\n");
}
