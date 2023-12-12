#include<stdio.h>

int main(void) {
	int i = 0;

	alarm(5);
	printf("무한루프\n");
	while(1) {
		i ++;
		sleep(1);
		printf("%d초 경과\n", i);
	}
}
