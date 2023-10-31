#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include "db.h"
#include<string.h>

int main(int argc, char *argv[]) {
	int fd;
	int op;
	int id = 0;
	
	printf("0: list of all books, 1: list of available books" );
	scanf("%d", &op);

	if(op == 0) {
		printf("\t%s%2s%3s%2s\t%s %s, "id", "bookname", "author", "year", "numofborrow", "borrow);
	if((fd = open(argv[2], O_RDONLY)) == -1) {
		perror(argv[2]);
	}
	do {
		id ++;
		lseek(fd, (id - START_ID) * sizeof(lib), SEEK_SET);
		if((read(fd, &lib, sizeof(lib)) > 0) {
			printf("%d\t\t%s\t%2s%2d%5d %d",  			
		

