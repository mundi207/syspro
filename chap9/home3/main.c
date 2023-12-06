#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char argv[30][30];
	int i = 0;
	int j = 0;

	while(1) {
		argv[i][j] = fgetc(stdin);
		j ++;
		if(argv[i][j] == '\n') {
			break;
		}
	}
}

