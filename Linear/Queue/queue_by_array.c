#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: 배열로 구현한 큐

	'First In First Out'
	'Push와 Pop 과정이 서로 반대쪽 에서 수행되는 자료구조'

	- 나가는 front, 들어오는 Rear 위치를 활용한다.


	* 구현함수

	[1] 탐색
	[2] 입력 [3] 제거
	[4] 전체 출력
*/

int queue[SIZE];
int front = 0, rear = 0;


bool search(int q[], int n);
void push(int q[], int n);
int pop(int q[]);
void showAll(int q[]);


int main(void) {
	
	push(queue, 1);
	push(queue, 2);
	push(queue, 3);
	push(queue, 4);
	push(queue, 5);
	showAll(queue);

	search(queue, 2);
	pop(queue);
	pop(queue);
	search(queue, 2);
	showAll(queue);

	system("pause");
	return 0;
}

bool search(int q[], int n) {
	bool res = false;
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다.");
		return res;
	}
	for (int i = front; i < rear; i++) {
		if (q[i] == n) {
			res = true;
			printf("정수 %d를 발견했습니다.\n", n);
			return res;
		}
	}
	printf("정수 %d를 발견하지 못했습니다.\n", n);
	return res;
}

void push(int q[], int n) {
	if (rear >= SIZE) {
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	q[rear++] = n;
}

int pop(int q[]) {
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	return q[front++];
}

void showAll(int q[]) {
	if (front == rear) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return;
	}
	printf("--- 큐 상단부 ---\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", q[i]);
	}
	printf("--- 큐 하단부 ---\n");
}