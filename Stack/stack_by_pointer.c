#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

/*
	Title: �����ͷ� ������ ����

	* ���Ḯ��Ʈ ��� ������ �����.
	* ���� ���·� �����͸� �ٷ�� ���� top �����͸� �ٷ�� ���� ����ü�� �����
	* �ʱ�ȭ�� NULL ���� top�� �����Ѵ�.


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
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
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
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	Node *cur = stack->top;
	printf("--- ���� ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ���� �ϴܺ� ---\n");
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
