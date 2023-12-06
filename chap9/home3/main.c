#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

int main(void) {
	char buf[MAX_SIZE];
	char *argv;
	int argc = 0;
	int i = 0;

	while(1) {
		printf("[shell] >> ");
		while(1) {
			buf[i] = fgetc(stdin);
			if(buf[i] == '\n') {
				argv = buf;
				if(strcmp(argv, "\n") == 0) {
					argv[0] = '\0';
				}
				printf("%s", argv);
				break;
			}
			i ++;
		}
	}
	exit(0);
}
