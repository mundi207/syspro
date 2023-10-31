#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd;

	if((fd = open(argv[1], O_RDONLY)) == -1) { // 예외처리
		printf("File Open Error\n");
	}
	else { // 읽은 파일이 있으면 fd 출력
		printf("file %s Open Sucess : %d\n", argv[1], fd);
	}

	close(fd);
	exit(0);
}
