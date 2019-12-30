#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

/*
	Title: 포인터로 구현한 스택

	* 연결리스트 노드 구조를 만든다.
	* 스택 형태로 데이터를 다루기 위해 top 데이터를 다루는 스택 구조체를 만든다
	* 초기화로 NULL 값을 top에 지정한다.


*/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node *top;
} Stack;


void push(Stack *stack, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int pop(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	
	Node *temp = stack->top;
	int data = temp->data;
	stack->top = temp->next;
	free(temp);
	return data;
}

void show(Stack *stack) {
	if (stack->top == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return;
	}
	Node *cur = stack->top;
	printf("--- 스택 상단부 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택 하단부 ---\n");
}

int main(void) {
	Stack stack;
	stack.top = NULL;

	show(&stack);
	push(&stack,1);
	push(&stack,2);
	push(&stack,3);
	push(&stack,4);
	push(&stack,5);
	show(&stack);
	pop(&stack);
	pop(&stack);
	show(&stack);

	system("pause");
	return 0;
}
