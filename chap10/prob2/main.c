#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

int main(void) {
	int *id;
	char **name;
	int count;
	int count2;

	printf("몇 명의 학생을 입력하시겠습니까? : ");
	scanf("%d", &count);
	printf("%d명의 학번과 이름을 입력하세요\n", count);
	
	id = (int*)malloc(sizeof(int) * count);

	for(int i = 0; i < count; i ++) {
			name[i] = (char*)malloc(sizeof(char) * count2);


