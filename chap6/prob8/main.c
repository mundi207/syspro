#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	if((symlink(argv[1], argv[2])) == EOF) {
		perror("symlink");
		exit(1);
	}
}
