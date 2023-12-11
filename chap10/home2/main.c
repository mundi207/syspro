#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}node;

void addq(struct Node *head, struct Node *tail, int data);
int delete(struct Node *head, struct Node *tail);

node *Head = NULL; // 전역 구조체 포인터 선언
node *Tail = NULL;
node *n = NULL;

int main(void) {
	int data; // 데이터 입력 받기 위한 변수

	while((scanf("%d", &data)) == 1) { // 입력받은 값이 하나라면
		addq(Head, Tail, data); // 연결리스트 생성
		if((sizeof(data)) != 4) { // 입력받은 값이 정수가 아니면 
			break; // 넌 나가라
		}
	}
	delete(Head, Tail); // 큐 삭제 (가장 먼저 들어온 친구가 나감)
	delete(Head, Tail); // 두 번 삭제 해봤습니다.
	while(Head != NULL) { // 큐 출력부분
		printf("%d\n", Head -> data);
		Head = Head -> next;
	}
	free(Head); // 메모리 누수 막기위한 조치 (첫번째 노드만 삭제)
	exit(0);
}
void addq(node *head, node *tail, int data) { // 노드 추가하는 함수
	if(Head == NULL) { // 첫번째 노드가 존재하지 않는다면
		head = (struct Node*)malloc(sizeof(node)); // 구조체 생성하고
		head -> data = data; // 데이터 반영
		tail = head; // 노드가 하나뿐이라면 마지막 노드또한 헤드이므로
		Head = head; // 전역변수에 반영
		Tail = tail; // 전역변수에 반영2
	}
	else { // 두번째 노드 추가부터는
		n = (struct Node*)malloc(sizeof(node)); // n으로 추가함
		n -> data = data; // 데이터 반영하고
		tail -> next = n; // tail이 head를 가리키고 있음, head -> next에 넣기위한 조치
		tail = n; // 마지막 노드는 n이 되므로
		Tail = tail; // 전역변수에 반영
	}
}
int delete(node *head, node *tail) {
	int del_num = head -> data; // 첫번째 노드 데이터 백업하고
	Head = head -> next; // 헤드 다음 노드를 헤드로 만들고
	free(head); // 첫번째 노드 삭제
	return del_num; // 백업한 값 리턴
}
	
