#include <stdio.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: 배열로 구현한 큐
	
	* 배열 기반, 큐의 사이즈, 앞, 뒤, 그리고 데이터의 수를 다루는 변수를 할용한다.
	* 선입 선출


*/

int Queue[SIZE];
int front = 0; rear = -1; count = 0;
void push(int data);
int pop();
void show();


int main(void) {

	show();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	pop();
	pop();
	show();

	system("pause");
	return 0;
}


void push(int data) {
	if (rear == SIZE - 1) {
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	Queue[++rear] = data;
	count++;
}

int pop() {
	if (count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	count--;
	return Queue[front++];
}

void show() {
	if (count == 0) {
		printf("큐 언더플로우가 발생했습니다.\n");
		return;
	}
	printf("--- 큐 상단부 ---\n");
	for (int i = front; i <= rear; i++) {
		printf("%d\n", Queue[i]);
	}
	printf("--- 큐 하단부 ---\n");
}