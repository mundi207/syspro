#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/time.h>
#include<utime.h>

int main(int argc, char *argv[]) {
	struct stat buf;
	struct utimbuf time;

	if(argc < 2) {
		fprintf(stderr, "How to use : %s", argv[0]);
		exit(1);
	}
	if((lstat(argv[1], &buf)) < 0) {
		perror(argv[1]);
		exit(1);
	}

	time.actime = buf.st_atime;
	time.modtime = buf.st_mtime;

	if((utime(argv[2], &time)) < 0) {
		perror("utime()");
		exit(1);
	}
	exit(0);
}
	

