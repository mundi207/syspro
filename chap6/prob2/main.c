#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int args, char *argv[]) {
	long strtol();
	int newmode;

	if(args < 2) {
		fprintf(stderr, "How to use : %s", argv[0]);
		exit(1);
	}
	newmode = strtol(argv[1], NULL, 8); // 문자열 8진수로 변환
	if((chmod(argv[2], newmode)) < 0) {
		perror(argv[2]);
	}

	exit(0);
}
