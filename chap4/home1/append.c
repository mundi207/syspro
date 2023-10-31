#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp1, *fp2;
	int c;

	if(argc != 3) {
		perror(argv[1]);
		perror(argv[2]);
	}
	fp1 = fopen(argv[1], "r");
	if(fp1 == NULL && fp2 == NULL) {
		perror(argv[1]);
		perror(argv[2]);
	}
	fp2 = fopen(argv[2], "a");
	while((c = fgetc(fp1)) != EOF) {
		if(c != '\n')
			fputc(c, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
