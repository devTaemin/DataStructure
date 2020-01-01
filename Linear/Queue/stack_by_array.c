#include <stdio.h>
#include <stdbool.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: �迭�� ������ ����

	'Last In First Out'
	'Push�� Pop ������ ���ʿ��� ����Ǵ� �ڷᱸ��'

	- Top�� �Ǵ� �ڷḦ �����Ͽ� Ȱ��


	* �����Լ�

	[1] Ž��
	[2] �Է� [3] ����
	[4] ��ü ���
*/

int stack[SIZE];
int top = -1;
int count = 0;

bool search(int s[], int n);
void push(int s[], int n);
int pop(int s[]);
void showAll(int s[]);


int main(void) {


	system("pause");
	return 0;
}


bool search(int s[], int n) {
	bool res = false;
	if (count <= 0) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return res;
	}
	for (int i = top; i >= 0; i--) {
		if (s[i] == n) {
			res = true;
			printf("���� %d�� �߰��Ͽ����ϴ�.\n", n);
			return res;
		}
	}
	printf("���� %d�� �߰����� ���߽��ϴ�.\n", n);
	return res;
}

void push(int s[], int n) {
	if (count >= SIZE - 1) {
		printf("���� �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	s[++top] = n;
	count++;
}

int pop(int s[]) {
	if (count <= 0) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	int data = s[top--];
	count--;
	return data;
}

void showAll(int s[]) {
	if (count <= 0) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	printf("--- ���� ��ܺ� ---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", s[i]);
	}
	printf("--- ���� �ϴܺ� ---\n");
}