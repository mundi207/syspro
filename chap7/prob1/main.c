#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "student.h"

int main(int argc, char **argv) {
	int fd, id;
	struct student rec;
	struct flock lock;

	if(argc < 2) {
		perror(argv[0]);
		exit(1);
	}
	if((fd = open(argv[1], O_RDWR)) < 0) {
		perror(argv[1]);
		exit(1);
	}
	
	printf("수정할 학생의 학번 입력 : ");
	while((scanf("%d", &id)) == 1) {
		lock.l_type = F_WRLCK;
		lock.l_whence = SEEK_SET;
		lock.l_start = (id - START_ID) * sizeof(rec);
		lock.l_len = sizeof(rec);
		if((fcntl(fd, F_SETLKW, &lock)) == -1) {
			perror("쓰기 잠금");
			exit(1);
		}
		lseek(fd, (id - START_ID) * sizeof(rec), SEEK_SET);
		if(((read(fd, &rec, sizeof(rec))) > 0) && (rec.id != 0)) {
			printf("%s : %s  %5s : %d\n %s : %hd\n", "이름", rec.name, "학번", rec.id, "점수", rec.score);
		}
		else {
			printf("레코드 %d 없음\n", id);
		}
		printf("새로운 점수 : ");
		scanf("%d", &rec.score);
		lseek(fd, -sizeof(rec), SEEK_CUR); 
		write(fd, &rec, sizeof(rec));

		lock.l_type = F_UNLCK;
		fcntl(fd, F_SETLK, &lock);
		printf("\n수정할 학생의 학번 입력 : ");
	}
	close(fd);
	exit(0);
}
