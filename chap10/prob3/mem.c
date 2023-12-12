#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
	char str[32] = "Do you like Linux?";
	char *ptr, *p;

	ptr = malloc(32);
	memcpy(ptr, str, strlen(str)); // str의 내용을 ptr로 str의 문자열 길이만큼 복사한다.
	puts(ptr);
	memset(ptr + 12, 'l', 1); // ptr + 12번째 문자 L을 l로 바꾼다. 단, 1바이트만큼
	puts(ptr);

	p = (char *)memchr(ptr, 'l', 18); // ptr이 가리키는 18바이트 만큼의 범위에서 문자 l을 찾는다.
	puts(p);
	memmove(str + 12, str + 7, 10); // str + 7자리에 있는 문자를 str + 12번째 자리에 10바이트를 복사한다.
	puts(str);

	free(ptr);
	return 0;
}
