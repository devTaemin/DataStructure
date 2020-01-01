#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: ���Ḯ��Ʈ�� ������ ����

	'Last In First Out'
	'Push�� Pop ������ ���ʿ��� ����Ǵ� �ڷᱸ��'

	- Top�� �Ǵ� �ڷḦ �����Ͽ� Ȱ��


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
	Node* top;
} Stack;

Stack stack;

bool search(Stack* root, int n);
void push(Stack* root, int n);
int pop(Stack* root);
void showAll(Stack* root);
void freeAll(Stack* root);


int main(void) {


	system("pause");
	return 0;
}

bool search(Stack* root, int n) {
	Node* cur = root->top;
	bool res = false;
	if (cur == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
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

void push(Stack* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	node->next = root->top;
	root->top = node;
}

int pop(Stack* root) {
	if (root->top = NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	Node* cur = root->top;
	int data = cur->data;
	root->top = cur->next;
	free(cur);
	return data;
}

void showAll(Stack* root) {
	Node* cur = root->top;
	if (cur == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	printf("--- ���� ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ���� �ϴܺ� ---\n");
}

void freeAll(Stack* root) {
	Node* cur = root->top;
	if (cur == NULL) {
		printf("���� ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	while (cur != NULL) {
		Node* temp = cur;
		cur = cur->next;
		free(temp);
	}
	printf("���� �Ҵ� ������ �Ϸ��Ͽ����ϴ�.\n");
}
