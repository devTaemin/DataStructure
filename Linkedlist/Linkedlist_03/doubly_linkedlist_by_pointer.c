#include <stdio.h>
#include <stdlib.h>

/*
	Title: 포인터를 이용한 양방향 연결리스트

	* 데이터와 이전, 다음 노드를 포함하는 구조체 작성
	* head와 tail을 이용하여 리스트의 처음과 끝을 나타낸다.
	* 오름차순 정렬
	* 예외처리 이전 기본 단계

*/

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head, *tail;

void insert(Node *root, int data);
void removeFront(Node *root);
void show(Node *root);

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	insert(head, 9);
	insert(head, 8);
	insert(head, 5);
	insert(head, 12);
	insert(head, 2);
	insert(head, 4);
	insert(head, 3);
	insert(head, 5);
	show(head);
	removeFront(head);
	removeFront(head);
	show(head);



	system("pause");
	return 0;
}

void insert(Node *root, int data) {
	// 자동 오름차순 입력으로 구현

	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node *cur = root->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node *prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront(Node *root) {
	Node *node1 = root->next;
	root->next = node1->next;
	Node *node2 = node1->next;
	node2->prev = root;
	free(node1);
}

void show(Node *root) {
	Node *cur = root->next;
	printf("--- 연결리스트 상단부 ---\n");
	while (cur != tail) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 연결리스트 하단부 ---\n");
}