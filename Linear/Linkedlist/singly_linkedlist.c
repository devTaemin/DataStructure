#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define INF 99999999

/*
	Title: ���� ���Ḯ��Ʈ

	'����ü�� �����͸� �̿��Ͽ� ������ �ڷ� ����'
	- �����Ҵ�
	- �����͸� �̿��Ͽ� �ܹ������� ���� ��带 ����Ŵ


	* �����Լ�

	[1] Ž��
	[2] ���� �Է� [3] �Ĺ� �Է�
	[4] ���� ���� [5] �Ĺ� ���� 
	[6] ��ü ��� [7] ���� �Ҵ� ����
*/

typedef struct {
	int data;
	struct Node* next;
} Node;

Node* head;

bool search(Node* root, int n);
void front_push(Node* root, int n);
void rear_push(Node* root, int n);
int front_pop(Node* root);
int rear_pop(Node* root);
void showAll(Node* root);
void freeAll(Node* root);

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	front_push(head, 3);
	front_push(head, 4);
	rear_push(head, 2);
	rear_push(head, 1);
	front_push(head, 5);
	showAll(head);
	front_pop(head);
	rear_pop(head);
	showAll(head);



	

	system("pause");
	return 0;
}

bool search(Node* root, int n) {
	Node* cur = root->next;
	bool res = false;
	while (cur != NULL) {
		if (cur->data == n) {
			res = true;
			return res;
		}
		cur = cur->next;
	}
	return res;
}

void front_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	node->next = root->next;
	root->next = node;
}

void rear_push(Node* root, int n) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = n;
	Node* cur = root;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = node;
	node->next = NULL;
}

int front_pop(Node* root) {
	Node* cur = root->next;
	if (cur == NULL) {
		printf("���Ḯ��Ʈ ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	int data = cur->data;
	root->next = cur->next;
	free(cur);
	return data;
}

int rear_pop(Node* root) {
	Node* cur = root->next;
	Node* temp = root;
	if (cur == NULL) {
		printf("���Ḯ��Ʈ ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	while (cur->next != NULL) {
		cur = cur->next;
		temp = temp->next;
	}
	int data = cur->data;
	temp->next = NULL;
	free(cur);
	return data;
}

void showAll(Node* root) {
	Node* cur = root->next;
	printf("--- ���Ḯ��Ʈ ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ���Ḯ��Ʈ �ϴܺ� ---\n");
}

void freeAll(Node* root) {
	Node* cur = root->next;
	while (cur != NULL) {
		Node* temp = cur->next;
		free(cur);
		cur = temp;
	}
	printf("�����Ҵ� ������ �Ϸ�Ǿ����ϴ�.\n");
}