#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: 단일 연결리스트

	'구조체와 포인터를 이용하여 연결한 자료 구조'
	- 동적할당
	- 포인터를 이용하여 단방향으로 다음 노드를 가리킴


	* 구현함수

	[1] 탐색
	[2] 전방 입력 [3] 후방 입력
	[4] 전방 제거 [5] 후방 제거 
	[6] 전체 출력 [7] 동적 할당 해제
*/

typedef struct {
	int data;
	struct Node* next;
} Node;

Node* head;

bool search(Node* root, int n);
void front_push(Node* root, int n);
void rear_push(Node* root, int n);
int front_pop(Node* root);
int rear_pop(Node* root);
void showAll(Node* root);
void freeAll(Node* root);

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	front_push(head, 3);
	front_push(head, 4);
	rear_push(head, 2);
	rear_push(head, 1);
	front_push(head, 5);
	showAll(head);
	front_pop(head);
	rear_pop(head);
	showAll(head);



	

	system("pause");
	return 0;
}

bool search(Node* root, int n) {
	Node* cur = root->next;
	bool res = false;
	while (cur != NULL) {
		if (cur->data == n) {
			res = true;
			return res;
		}
		cur = cur->next;
	}
	return res;
}

void front_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	node->next = root->next;
	root->next = node;
}

void rear_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	Node* cur = root;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = node;
	node->next = NULL;
}

int front_pop(Node* root) {
	Node* cur = root->next;
	if (cur == NULL) {
		printf("연결리스트 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	int data = cur->data;
	root->next = cur->next;
	free(cur);
	return data;
}

int rear_pop(Node* root) {
	Node* cur = root->next;
	Node* temp = root;
	if (cur == NULL) {
		printf("연결리스트 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	while (cur->next != NULL) {
		cur = cur->next;
		temp = temp->next;
	}
	int data = cur->data;
	temp->next = NULL;
	free(cur);
	return data;
}

void showAll(Node* root) {
	Node* cur = root->next;
	printf("--- 연결리스트 상단부 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 연결리스트 하단부 ---\n");
}

void freeAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		Node* temp = cur->next;
		free(cur);
		cur = temp;
	}
	printf("동적할당 해제가 완료되었습니다.\n");
}