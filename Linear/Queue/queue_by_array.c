#include <stdio.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: �迭�� ������ ť
	
	* �迭 ���, ť�� ������, ��, ��, �׸��� �������� ���� �ٷ�� ������ �ҿ��Ѵ�.
	* ���� ����


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
		printf("ť �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	Queue[++rear] = data;
	count++;
}

int pop() {
	if (count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	count--;
	return Queue[front++];
}

void show() {
	if (count == 0) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	printf("--- ť ��ܺ� ---\n");
	for (int i = front; i <= rear; i++) {
		printf("%d\n", Queue[i]);
	}
	printf("--- ť �ϴܺ� ---\n");
}