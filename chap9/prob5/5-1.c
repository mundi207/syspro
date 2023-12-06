#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	int fd;

	if((fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0660)) < 0) {
		perror(argv[1]);
		exit(1);
	}
	dup2(fd, 1);
	close(fd);
	printf("Hello stdout\n");
	fprintf(stderr, "Hello stderr\n");
	exit(0);
}
