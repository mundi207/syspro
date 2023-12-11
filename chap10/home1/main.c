#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *newNode = NULL;
Node *oldNode = NULL;

void push(struct node *top, int data);
int pop(struct node *top);

int main(void) {
	int input;

	while((scanf("%d", &input)) == 1) { // 입력받은 값이 하나다?
		push(newNode, input); // 노드를 생성한다.
		if((sizeof(input) != 4)) { // integer형이 아니면
			break; // 나가라
		}
	}
	pop(newNode); // 노드 하나를 없애보았습니다.
	while(newNode != NULL) { // 연결리스트 출력
		printf("%d\n", newNode -> data);
		newNode = newNode -> next;
	}
	free(newNode); // 메모리 누수 방지
	exit(0);
}
int pop(Node *top) {
	int del_data; // 삭제할 데이터 백업

	top = newNode; // newNode에 값이 반영되어 있으므로 top이 newNode를 가리키고 있는 구조체를 가리키게 함
	del_data = top -> data; // 백업
	oldNode = top -> next; // oldNode에 잠시 저장했다가
	free(top); // oldNode에 잠시 저장 했으므로 top 날림
	top = oldNode; // top에 다시 값 넣음
	newNode = top; // 전역변수에 반영

	return del_data; // 백업한 데이터 반환
}
void push(Node *top, int data) {
	top = (struct node*)malloc(sizeof(Node)); // 구조체 생성

	top -> data = data; // 값 반영
	top -> next = newNode; // 노드 앞에 노드를 계속 생성함
	newNode = top; // 전역변수에 반영함
}


