#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: �迭�� ������ ť

	'First In First Out'
	'Push�� Pop ������ ���� �ݴ��� ���� ����Ǵ� �ڷᱸ��'

	- ������ front, ������ Rear ��ġ�� Ȱ���Ѵ�.


	* �����Լ�

	[1] Ž��
	[2] �Է� [3] ����
	[4] ��ü ���
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
		printf("ť ����÷ο찡 �߻��߽��ϴ�.");
		return res;
	}
	for (int i = front; i < rear; i++) {
		if (q[i] == n) {
			res = true;
			printf("���� %d�� �߰��߽��ϴ�.\n", n);
			return res;
		}
	}
	printf("���� %d�� �߰����� ���߽��ϴ�.\n", n);
	return res;
}

void push(int q[], int n) {
	if (rear >= SIZE) {
		printf("ť �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	q[rear++] = n;
}

int pop(int q[]) {
	if (front == rear) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	return q[front++];
}

void showAll(int q[]) {
	if (front == rear) {
		printf("ť ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	printf("--- ť ��ܺ� ---\n");
	for (int i = front; i < rear; i++) {
		printf("%d\n", q[i]);
	}
	printf("--- ť �ϴܺ� ---\n");
}