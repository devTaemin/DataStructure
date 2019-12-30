#include <stdio.h>
#define SIZE 10000
#define INF 99999999


/*
	Title: 배열로 구현한 스택

	* 데이터의 input과 output이 되는 입출구가 하나이다.
	* 배열로 구현하므로 사전에 스택의 크기를 선언한다
	* 최상단을 Top으로 설정하고 이를 이용하여 스택 데이터를 다룬다.

*/


int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("스택 오버플로우가 발생했습니다.\n");
		return;
	}
	stack[++top] = data;
}

int pop() {
	if (top < 0) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return INF;
	}
	return stack[top--];
}

void show() {
	if (top < 0) {
		printf("스택 데이터가 없습니다.\n");
		return;
	}
	printf("--- 스택 상단부 ---\n");
	for (int i = top; i > -1; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--- 스택 하단부 ---\n");
}


int main(void) {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	show();
	pop();
	pop();
	show();

	system("pause");
	return 0;
}






