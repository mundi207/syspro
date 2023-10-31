#include<stdio.h>
void copy(char from[], char to[]) {
	int i = 0;
	while((from[i] = to[i]) != '\0') {
		++i;
	}
}
