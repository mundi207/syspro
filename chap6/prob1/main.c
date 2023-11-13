#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[]) {
	struct stat buf;

	for(int i = 1; i < argc; i ++) {
		printf("%s : ", argv[i]);
		if((lstat(argv[i], &buf)) < 0) {
			perror("lstat()");
			continue;
		}
		if(S_ISREG(buf.st_mode)) {
			printf("%s\n" ,"FILE");
		}
		if(S_ISDIR(buf.st_mode)) {
			printf("%s\n", "Directory");
		}
		if(S_ISBLK(buf.st_mode)) {
			printf("%s\n", "Block Machine File");
		}
		if(S_ISFIFO(buf.st_mode)) {
			printf("%s\n", "FIFO File");
		}
		if(S_ISLNK(buf.st_mode)) {
			printf("%s\n", "Symbolic link");
		}
		if(S_ISSOCK(buf.st_mode)) {
			printf("%s\n", "Socket");
		}
	}
	exit(0);
}
