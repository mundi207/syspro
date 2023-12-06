#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
	char str[10];

	scanf("%s", str);
	printf("%s\n", str);

	str[0] = '\0';

	printf("%c\n", str[0]);

	return 0;
}
