#include <stdio.h>
#define SIZE 10000
#define INF 99999999


/*
	Title: �迭�� ������ ����

	* �������� input�� output�� �Ǵ� ���ⱸ�� �ϳ��̴�.
	* �迭�� �����ϹǷ� ������ ������ ũ�⸦ �����Ѵ�
	* �ֻ���� Top���� �����ϰ� �̸� �̿��Ͽ� ���� �����͸� �ٷ��.

*/


int stack[SIZE];
int top = -1;

void push(int data) {
	if (top == SIZE - 1) {
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	stack[++top] = data;
}

int pop() {
	if (top < 0) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return INF;
	}
	return stack[top--];
}

void show() {
	if (top < 0) {
		printf("���� �����Ͱ� �����ϴ�.\n");
		return;
	}
	printf("--- ���� ��ܺ� ---\n");
	for (int i = top; i > -1; i--) {
		printf("%d\n", stack[i]);
	}
	printf("--- ���� �ϴܺ� ---\n");
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






