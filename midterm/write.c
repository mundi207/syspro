#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[]) {
	int input;
	FILE *fp;

	if(argc < 3 && (strcmp(argv[1], "0") == 1 && strcmp(argv[1], "1")) == 1) {
		fprintf(stderr, "명령어 옵션값을 넣으시오.");
		exit(1);
	}
	if(strcmp(argv[1], "0") == 0) {
		fp = fopen(argv[2], "w");
		while((input = getc(stdin)) != EOF) {
			fprintf(fp, "%c", input);
		}
	}
	else {
		fp = fopen(argv[2], "a");
		while((input = getc(stdin)) != EOF) {
			fprintf(fp, "%c", input);
		}
	}
	fclose(fp);
	exit(0);
}



		
