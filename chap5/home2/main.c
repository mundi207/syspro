#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	int fd;
	char buf;
	char str[100][100];
	int i = 0;
	int j = 0;

	if(argc < 2) {
		fprintf(stderr, "How to use : %s", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) > 0) {
		while((read(fd, &buf, 1)) > 0) {
			str[j][i] = buf;
			i ++;
			if(buf == '\n') {
				j ++;
				i = 0;
			}
		}
		printf("File Read Success!\n");
		printf("Reverse Print!\n");
	}

	for(int i = j; i > 0; i --) {
		printf("%s", str[i - 1]);
	}
	close(fd);
	return 0;
}
