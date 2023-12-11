#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int data;
	char name[20];
	struct node *next;
}Node;

int main(void) {
	Node *head = NULL;
	Node *p = NULL;
	int count;
	int id;
	char name[20];

	printf("학번과 이름을 입력하세요.\n");
	while((scanf("%d%s", &id, name)) == 2) {
		if((sizeof(id)) != 4)
			exit(1);
		p = malloc(sizeof(Node));
		p -> data = id;
		strcpy(p -> name, name);
		p -> next = head;
		head = p;
	}
	printf("* 학생 정보(역순) *\n");
	while(p != NULL) {
		printf("%d %s\n", p -> data, p -> name);
		p = p -> next;
		count ++;
	}
	printf("총 %d명 입니다.\n", count);
	while(p != NULL) {
		free(p);
		p = p -> next;
	}
	exit(0);
}
