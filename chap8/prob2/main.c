#include<stdio.h>
#include<stdlib.h>

int main(void) {
	extern char **environ;

	while(*environ != 0) {
		printf("%s\n", *environ);
		environ ++;
	}
	return 0;
}
