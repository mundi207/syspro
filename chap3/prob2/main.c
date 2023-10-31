#include<stdio.h>
#include<string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];
char result[5][MAXLINE];
char swap[MAXLINE];

void copy(char from[], char to[]);
int main(void) {

    for(int i = 0; i < 5; i ++) {
		fgets(line, MAXLINE, stdin);
		copy(result[i], line);
    }
	for(int i = 0; i < 5; i ++) {
		for(int j = i + 1; j < 5; j ++) {
			if(strlen(result[i]) < strlen(result[j])){
				copy(swap, result[i]);
				copy(result[i], result[j]);
				copy(result[j], swap);
			}
		}
	}
    for(int i = 0; i < 5; i ++) {
		printf("%s", result[i]);
	}
    return 0;
}
