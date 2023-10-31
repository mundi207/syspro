#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd1, fd2; 

	if((fd1 = open("mylife.txt", O_RDWR | O_CREAT | O_TRUNC, 0600)) == -1) {
		perror("mylife.txt");
		exit(0);
	}
	write(fd1, "I love Linux\n", 14);
	fd2 = dup(fd1);
	write(fd2, "Bye! Linux\n", 12);
	exit(1);
}



