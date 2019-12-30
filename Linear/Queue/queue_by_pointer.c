#include <stdio.h>
#include <stdlib.h>
#define INF 99999999;

/*
	Title: 포인터를 이용한 큐
	
	* 데이터를 담는 노드 구조체
	* 앞, 뒤, 그리고 데이터의 수 변수를 다루는 큐 구조체
	* 초기 큐 NULL, 0값 설정
	* Node사이의 관계와 Queue 데이터 처리방식을 사용

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
		printf("큐 언더플로우가 발생했습니다.\n");
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
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	Node *cur = queue->front;
	printf("--- 큐 상단부 ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 큐 하단부 ---\n");
}