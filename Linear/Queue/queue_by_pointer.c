#include <stdio.h>
#include <stdlib.h>
#define INF 99999999;

/*
	Title: �����͸� �̿��� ť
	
	* �����͸� ��� ��� ����ü
	* ��, ��, �׸��� �������� �� ������ �ٷ�� ť ����ü
	* �ʱ� ť NULL, 0�� ����
	* Node������ ����� Queue ������ ó������� ���

*/

typedef struct {
	int data;
	struct Node *next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
	int count;
} Queue;

void push(Queue *queue, int data);
int pop(Queue *queue);
void show(Queue *queue);


int main(void) {
	Queue queue;
	queue.front = NULL;
	queue.rear = NULL;
	queue.count = 0;

	show(&queue);
	push(&queue, 1);
	push(&queue, 2);
	push(&queue, 3);
	push(&queue, 4);
	push(&queue, 5);
	show(&queue);
	pop(&queue);
	pop(&queue);
	show(&queue);


	system("pause");
	return 0;
}


void push(Queue *queue, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0) {
		queue->front = node;
	}
	else {
		queue->rear->next = node;
	}
	queue->rear = node;
	queue->count++;
}

int pop(Queue *queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node *node = queue->front;
	int data = node->data;
	queue->front = node->next;
	queue->count--;
	free(node);
	return data;
}

void show(Queue *queue) {
	if (queue->count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node *cur = queue->front;
	printf("--- ť ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ť �ϴܺ� ---\n");
}