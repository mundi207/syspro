#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	int line = 0;
	int c;

	if(argc <= 1) {
		fprintf(stderr, "How to use : line FileName\n");
		exit(0);
	}
	if(strcmp(argv[1], "-n") == 0) {
		for(int i = 0; i < argc - 2; i ++) {
			fp = fopen(argv[i + 2], "r");
			if(fp == NULL) {
				perror(argv[i + 2]);
				continue;
			}
			line ++;
			fprintf(stdout, "%3d ", line);
			while((c = fgetc(fp)) != EOF) {
				fprintf(stdout, "%c", c);
			}
		}
	}
	else {
		for(int i = 0; i < argc - 1; i ++) {
			fp = fopen(argv[i + 1], "r");
			if(fp == NULL) {
				perror(argv[i + 1]);
				continue;
			}
			while((c = fgetc(fp)) != EOF) {
				fprintf(stdout, "%c", c);
			}
		}
	}	
	fclose(fp);
	exit(1);
}
