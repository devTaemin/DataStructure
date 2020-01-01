#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: 양방향 연결리스트

	'구조체와 포인터를 이용하여 연결한 자료 구조'
	- 동적할당
	- 포인터를 이용하여 양방향으로 이전 노드와 다음 노드를 가리킴


	* 구현함수

	[1] 탐색
	[2] 전방 입력 [3] 후방 입력
	[4] 오름차순 입력 [5] 내림차순 입력
	[6] 전방 제거 [7] 후방 제거
	[8] 전체 출력 [9] 동적 할당 해제
*/

typedef struct {
	int data;
	struct Node* front;
	struct Node* rear;
} Node;

Node* head;
Node* tail;

bool search(Node* root, int n);
void front_push(Node* root, int n);
void rear_push(Node* root, int n);
void asc_push(Node* root, int n);
void desc_push(Node* root, int n);
int front_pop(Node* root);
int rear_pop(Node* root);
void showAll(Node* root);
void freeAll(Node* root);


int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->front = head;
	head->rear = tail;
	tail->front = head;
	tail->rear = tail;


	system("pause");
	return 0;
}


bool search(Node* root, int n) {
	Node* cur = root->rear;
	bool res = false;
	while (cur != tail) {
		if (cur->data == n) {
			res = true;
			return res;
		}
	}
	return res;
}

void front_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	Node* cur = root->rear;
	node->data = n;
	root->rear = node;
	node->front = root;
	node->rear = cur;
	cur->front = node;
}

void rear_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	Node* cur = root->rear;
	node->data = n;
	while (cur != tail) {
		cur = cur->rear;
	}
	Node* temp = cur->front;
	temp->rear = node;
	node->front = temp;
	node->rear = cur;
	cur->front = node;
}

void asc_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	Node* cur = root->rear;
	node->data = n;
	while (cur != tail) {
		if (cur->data < n) {
			cur = cur->rear;
		}
		else { break; }
	}
	Node* temp = cur->front;
	temp->rear = node;
	node->front = temp;
	node->rear = cur;
	cur->front = node;
}

void desc_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	Node* cur = root->rear;
	node->data = n;
	while (cur != tail) {
		if (cur->data > n) {
			cur = cur->rear;
		}
		else { break; }
	}
	Node* temp = cur->front;
	temp->rear = node;
	node->front = temp;
	node->rear = cur;
	cur->front = node;
}

int front_pop(Node* root) {
	Node* cur = root->rear;
	Node* temp = cur->rear;
	int data = cur->data;
	root->rear = temp;
	temp->front = root;
	free(cur);
	return data;
}

int rear_pop(Node* root) {
	Node* cur = root->rear;
	while (cur != tail) { cur = cur->rear; }
	Node* temp = cur->front;
	int data = temp->data;
	Node* ftemp = temp->front;
	ftemp->rear = cur;
	cur->front = ftemp;
	free(temp);
	return data;
}

void showAll(Node* root) {
	Node* cur = root->rear;
	printf("--- 연결리스트 상단부 ---\n");
	while (cur != tail) {
		printf("%d\n", cur->data);
		cur = cur->rear;
	}
	printf("--- 연결리스트 하단부 ---\n");
}

void freeAll(Node* root) {
	Node* cur = root->rear;
	while (cur != tail) {
		Node* temp = cur;
		cur = cur->rear;
		free(temp);
	}
	printf("동적할당 해제가 완료되었습니다.\n");
}