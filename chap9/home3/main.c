#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char str[10];
	int i = 0;

	while(1) {
		printf("mundi@mundi >> ");
		while(1) {
			str[i] = fgetc(stdin);
			str[i + 1] = '\0';
			if(str[i] == '\n') {
				system(str);
				str[0] = '\0';
				i = 0;
				break;
			}
			i ++;
		}
	}
	exit(0);
}
