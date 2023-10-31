#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd1, fd2, n;
	char buf[1024];
	
	if(argc != 3) {
		fprintf(stderr, "How to use : %s file1 file2\n", argv[0]);
	}
	if((fd1 = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(1);
	}
	if((fd2 = open(argv[2], O_WRONLY)) == -1) {
		perror(argv[2]);
		exit(2);
	}
	while((n = read(fd1, buf, 1024)) > 0) {
		write(fd2, buf, n);
		exit(0);
	}
}
