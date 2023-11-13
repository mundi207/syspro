#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(int argc, char *argv[]) {
	if(unlink(argv[1]) == EOF) {
		perror(argv[1]);
		exit(1);
	}
	exit(0);
}
