#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	extern char **environ;
	char **ptr;

	for(ptr = environ; ptr != 0; ptr ++) {
		printf("%s \n", *ptr);
	}
	exit(0);
}
