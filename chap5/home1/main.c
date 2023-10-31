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
	char input[10];
	int n, m;

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
	}
	printf("Total Line : %d\n", j);
	printf("You can Choose 1 ~ %d line\n", j);
	printf("Plz Enter the line to select : ");

	scanf("%s", input);

	if((atoi(input) > 0) && (strlen(input) == 1)) {
		for(int i = 0; i <= j; i ++) {
			if(i == atoi(input)) {
				printf("%s", str[i - 1]);
			}
		}
	}
	else if((strcmp(input, "*")) == 0) {
		for(int i = 0; i < j; i ++) {
			printf("%s", str[i]);
		}
	}
	else if((strlen(input)) == 3 && input[1] == ',') {
		n = input[0] - '0';
		m = input[2] - '0';
		printf("%s", str[n - 1]);
		printf("%s", str[m - 1]);
	}
	else if((strlen(input)) == 3 && input[1] == '-') {
		n = input[0] - '0';
		m = input[2] - '0';
		for(int i = n; i <= m; i ++) {
			printf("%s", str[i - 1]);
		}
	}

	close(fd);
	return 0;
}
