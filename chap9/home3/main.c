#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
	char *buf;
	int i = 0;

	while(1) {
		buf = (char*)malloc(sizeof(char) * 1);
		printf("mundi@mundi >> ");
		while(1) {
			buf[i] = fgetc(stdin);
			buf = (char*)realloc(buf, sizeof(char) * strlen(buf));
			if(buf[i] == '\n') {
				buf[i + 1] = '\0';
				system(buf);
				rewind(stdin);
				free(buf);
				break;
			}
			i ++;
		}
	}
	exit(0);
}


