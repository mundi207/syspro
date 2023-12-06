#include<stdio.h>
#include<stdlib.h>
#include "LinkedList.h"

node *Head;
node *Tail;

void nodeAdd(int input) {
	node newNode = (node*)malloc(sizeof(node));
	
}
int main(void) {
	int input;
	
	Head = (node*)malloc(sizeof(node));
	while((scanf("%d", &input)) == 1) {
		nodeAdd(input);
	}
	free(Head);
	free(Tail);

	exit(0);
}

