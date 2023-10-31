#include<stdio.h>
#include "db.h"
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
	struct lib s1;
	struct lib s2;
	struct lib s3;
	struct lib s4;

	int fd;

	if((fd = open(argv[1], O_WRONLY)) == -1) {
		perror(argv[1]);
	}
	while(scanf("%d %s %s %d %d %d", &s1.ID, s1.book, s1.name, &s1.year, &s1.loan, &s1.loanFlag) == 6) {
		lseek(fd, (s1.ID - START_ID) * sizeof(s1), SEEK_SET);
		write(fd, (char *) &s1, sizeof(s1));
	}
	while(scanf("%d %s %s %d %d %d", &s2.ID, s2.book, s2.name, &s2.year, &s2.loan, &s2.loanFlag) == 6) {
		lseek(fd, (s2.ID - START_ID) * sizeof(s2), SEEK_SET);
		write(fd, (char *) &s2, sizeof(s2));
	}
	while(scanf("%d %s %s %d %d %d", &s3.ID, s3.book, s3.name, &s3.year, &s3.loan, &s3.loanFlag) == 6) {
		lseek(fd, (s3.ID - START_ID) * sizeof(s3), SEEK_SET);
		write(fd, (char *) &s3, sizeof(s3));
	}
	while(scanf("%d %s %s %d %d %d", &s4.ID, s4.book, s4.name, &s4.year, &s4.loan, &s4.loanFlag) == 6) {
		lseek(fd, (s4.ID - START_ID) * sizeof(s4), SEEK_SET);
		write(fd, (char *) &s4, sizeof(s4));
	}
	close(fd);
	exit(0);
}