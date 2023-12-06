#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"student.h"

int main(void) {
	struct student* ptr;
	int id;
	int count;
	char name[10];

	printf("몇 명의 학생을 입력하시겠습니까? : ");
	scanf("%d", &count);
	printf("%d명의 학번과 이름을 입력하세요\n", count);
	ptr = (struct student*)malloc(sizeof(struct student) * count);

	for(int i = 0; i < count; i ++) {
		if((scanf("%d%s", &id, name)) == 2) {
			ptr[i].id = id;
			strcpy(ptr[i].name, name);
		}
		else {
			fprintf(stderr, "잘못된 입력");
			exit(1);
		}
	}
	printf("* 학생 정보(역순) *\n");
	for(int i = count - 1; i >= 0; i --) {
		printf("%d %s\n", ptr[i].id, ptr[i].name);
	}
	free(ptr);
	exit(0);	
}

