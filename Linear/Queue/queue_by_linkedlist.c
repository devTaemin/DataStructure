#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: 연결리스트로 구현한 큐

	'First In First Out'
	'Push와 Pop 과정이 서로 반대쪽 에서 수행되는 자료구조'

	- 나가는 front, 들어오는 Rear 위치를 활용한다.
	- 큐 내부에 data의 수를 count하는 변수를 다룬다.
	- 큐 초기화 *


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
	Node* front;
	Node* rear;
	int count;
} Queue;


bool search(Queue* root, int n);
void push(Queue* root, int n);
int pop(Queue* root);
void showAll(Queue* root);
void freeAll(Queue* root);


int main(void) {
	Queue queue;
	queue.front = NULL;
	queue.rear = NULL;
	queue.count = 0;

	push(&queue, 1);
	push(&queue, 2);
	push(&queue, 3);
	push(&queue, 4);
	push(&queue, 5);
	showAll(&queue);

	search(&queue, 2);
	pop(&queue);
	pop(&queue);
	search(&queue, 2);
	showAll(&queue);




	system("pause");
	return 0;
}

bool search(Queue* root, int n) {
	bool res = false;
	Node* cur = root->front;
	if (root->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
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

void push(Queue* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	node->next = NULL;
	if (root->count == 0) {
		root->front = node;
	}
	else {
		root->rear->next = node;
	}
	root->rear = node;
	root->count++;
}

int pop(Queue* root) {
	if (root->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node* cur = root->front;
	int data = cur->data;
	root->front = cur->next;
	root->count--;
	free(cur);
	return data;
}

void showAll(Queue* root) {
	if (root->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return;
	}
	Node* cur = root->front;
	printf("--- 큐 상단부 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 큐 하단부 --- \n");
}

void freeAll(Queue* root) {
	if (root->count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return;
	}
	Node* cur = root->front;
	while (cur != NULL) {
		Node* temp = cur;
		cur = cur->next;
		root->count--;
		free(temp);
	}
}
