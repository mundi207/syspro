#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include "student.h"
#include<unistd.h>

int main(int argc, char *argv[]) {
	int fd, id;
	struct student rec;

	if(argc < 2) {
		fprintf(stderr, "How to use : %s", argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) < 0) {
		perror(argv[1]);
		exit(1);
	}

	printf("\n수정할 학생의 학번 입력 :");
	while((scanf("%d", &id)) == 1) {
		lseek(fd, (long)(id - START_ID) * sizeof(rec), SEEK_SET);
		if(lockf(fd, F_LOCK, sizeof(rec)) == -1) {
			perror(argv[1]);
			exit(1);
		}
		if((read(fd, &rec, sizeof(rec)) > 0) && (rec.id > 0)) {
			printf("이름:%s\t 학번:%d\t 점수:%d\n", rec.name, rec.id, rec.score);
		}
		else {
			printf("파일 레코드 없음.");
		}

		printf("새로운 점수 : ");
		scanf("%d", &rec.score);
		lseek(fd, (long) -sizeof(rec), SEEK_CUR);
		write(fd, &rec, sizeof(rec));

		lseek(fd, (id - START_ID) * sizeof(rec), SEEK_SET);
		lockf(fd, F_ULOCK, sizeof(rec));
		printf("\n수정할 학생의 학번 입력:");
	}
	close(fd);
	exit(0);
}
