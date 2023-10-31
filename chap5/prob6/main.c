#include<stdio.h>
#include<unistd.h>
#include "student.h"
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
	int fd;
	char input;
	struct student record;

	if(argc < 2) {
		fprintf(stderr, "How to use : %s\n", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDONLY)) == -1) {
		perror(argv[1]);
		exit(1);
	}
	do {
		printf("검색할 학생의 학번 입력 : ");
		if(scanf("%d", &record.id) == 1) {
			lseek(fd, (record.id - START_ID) * sizeof(record), SEEK_SET);
		}
		if(read(fd, &record, sizeof(record)) > 0 && record.id != 0) {
			printf("Name : %s StuID : %d Score : %d\n", record.name, record.id, record.score);
		}
		else {
			printf("StuID us NULL!\n");
		}
		printf("Continue?(Y/n) :" );
		scanf(" %c", &input);
	}
	while(input == 'Y' || input == 'y');
	close(fd);
	exit(0);
}