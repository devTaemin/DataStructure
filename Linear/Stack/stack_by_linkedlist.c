#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: 연결리스트로 구현한 스택

	'Last In First Out'
	'Push와 Pop 과정이 한쪽에서 수행되는 자료구조'

	- Top이 되는 자료를 지정하여 활용


	* 구현함수

	[1] 탐색
	[2] 입력 [3] 제거
	[4] 전체 출력
	[5] 동적 할당 해제
*/

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* top;
} Stack;

Stack stack;

bool search(Stack* root, int n);
void push(Stack* root, int n);
int pop(Stack* root);
void showAll(Stack* root);
void freeAll(Stack* root);


int main(void) {


	system("pause");
	return 0;
}

bool search(Stack* root, int n) {
	Node* cur = root->top;
	bool res = false;
	if (cur == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return res;
	}
	while (cur != NULL) {
		if (cur->data == n) {
			res = true;
			printf("정수 %d를 발견했습니다.\n", n);
			return res;
		}
		cur = cur->next;
	}
	printf("정수 %d를 발견하지 못했습니다.\n", n);
	return res;
}

void push(Stack* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	node->next = root->top;
	root->top = node;
}

int pop(Stack* root) {
	if (root->top = NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* cur = root->top;
	int data = cur->data;
	root->top = cur->next;
	free(cur);
	return data;
}

void showAll(Stack* root) {
	Node* cur = root->top;
	if (cur == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return;
	}
	printf("--- 스택 상단부 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택 하단부 ---\n");
}

void freeAll(Stack* root) {
	Node* cur = root->top;
	if (cur == NULL) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return;
	}
	while (cur != NULL) {
		Node* temp = cur;
		cur = cur->next;
		free(temp);
	}
	printf("동적 할당 해제를 완료하였습니다.\n");
}
