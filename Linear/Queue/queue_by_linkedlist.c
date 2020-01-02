#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: ���Ḯ��Ʈ�� ������ ť

	'First In First Out'
	'Push�� Pop ������ ���� �ݴ��� ���� ����Ǵ� �ڷᱸ��'

	- ������ front, ������ Rear ��ġ�� Ȱ���Ѵ�.
	- ť ���ο� data�� ���� count�ϴ� ������ �ٷ��.
	- ť �ʱ�ȭ *


	* �����Լ�

	[1] Ž��
	[2] �Է� [3] ����
	[4] ��ü ���
	[5] ���� �Ҵ� ����
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
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return res;
	}
	while (cur != NULL) {
		if (cur->data == n) {
			res = true;
			printf("���� %d�� �߰��߽��ϴ�.\n", n);
			return res;
		}
		cur = cur->next;
	}
	printf("���� %d�� �߰����� ���߽��ϴ�.\n", n);
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
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
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
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	Node* cur = root->front;
	printf("--- ť ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ť �ϴܺ� --- \n");
}

void freeAll(Queue* root) {
	if (root->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
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
