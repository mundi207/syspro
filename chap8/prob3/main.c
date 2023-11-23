#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char *ptr;

	ptr = getenv("HOME");
	printf("%s\n", ptr);

	ptr = getenv("SHELL");
	printf("%s\n", ptr);

	printf("%s\n", getenv("PATH"));

	return 0;
}
