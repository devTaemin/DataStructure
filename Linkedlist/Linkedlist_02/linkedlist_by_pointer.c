#include <stdio.h>
#include <stdlib.h>


/*
	Title: �����͸� �̿��� ���� ���Ḯ��Ʈ

	* �����Ϳ� ���� ��带 �����ϴ� ����ü�� ����
	* head�� NULL�� �̿��Ͽ� ���۰� ���� �̿��Ͽ� ��ġ ����
	* �����Ҵ� Ȱ��
	* ����ó�� ���� �⺻ �ܰ�

*/


typedef struct {
	int data;
	struct Node *next;
} Node;

Node *head;
void addFront(Node *root, int data);
void removeFront(Node *root);
void freeAll(Node *root);
void showAll(Node *root);

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	Node *node1 = (Node*)malloc(sizeof(Node));
	Node *node2 = (Node*)malloc(sizeof(Node));
	Node *node3 = (Node*)malloc(sizeof(Node));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;

	head->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	addFront(head, 0);
	addFront(head, -1);
	showAll(head);
	removeFront(head);
	removeFront(head);
	showAll(head);
	freeAll(head);


	system("pause");
	return 0;
}

void addFront(Node *root, int data) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = root->next;
	root->next = node;
}

void removeFront(Node *root) {
	Node *node = root->next;
	root->next = node->next;
	free(node);
}

void freeAll(Node *root) {
	Node *cur = root->next;
	while (cur != NULL) {
		Node *next = cur->next;
		free(cur);
		cur = next;
	}
}

void showAll(Node *root) {
	Node *cur = root->next;
	printf("--- ���Ḯ��Ʈ ��ܺ� ---\n");
	while (cur != NULL) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ���Ḯ��Ʈ �ϴܺ� ---\n");
}
