#include <stdio.h>
#include <stdlib.h>

/*
	Title: �����͸� �̿��� ����� ���Ḯ��Ʈ

	* �����Ϳ� ����, ���� ��带 �����ϴ� ����ü �ۼ�
	* head�� tail�� �̿��Ͽ� ����Ʈ�� ó���� ���� ��Ÿ����.
	* �������� ����
	* ����ó�� ���� �⺻ �ܰ�

*/

typedef struct {
	int data;
	struct Node *prev;
	struct Node *next;
} Node;

Node *head, *tail;

void insert(Node *root, int data);
void removeFront(Node *root);
void show(Node *root);

int main(void) {
	head = (Node*)malloc(sizeof(Node));
	tail = (Node*)malloc(sizeof(Node));
	head->prev = head;
	head->next = tail;
	tail->prev = head;
	tail->next = tail;

	insert(head, 9);
	insert(head, 8);
	insert(head, 5);
	insert(head, 12);
	insert(head, 2);
	insert(head, 4);
	insert(head, 3);
	insert(head, 5);
	show(head);
	removeFront(head);
	removeFront(head);
	show(head);



	system("pause");
	return 0;
}

void insert(Node *root, int data) {
	// �ڵ� �������� �Է����� ����

	Node *node = (Node*)malloc(sizeof(Node));
	node->data = data;
	Node *cur = root->next;
	while (cur->data < data && cur != tail) {
		cur = cur->next;
	}
	Node *prev = cur->prev;
	prev->next = node;
	node->prev = prev;
	cur->prev = node;
	node->next = cur;
}

void removeFront(Node *root) {
	Node *node1 = root->next;
	root->next = node1->next;
	Node *node2 = node1->next;
	node2->prev = root;
	free(node1);
}

void show(Node *root) {
	Node *cur = root->next;
	printf("--- ���Ḯ��Ʈ ��ܺ� ---\n");
	while (cur != tail) {
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- ���Ḯ��Ʈ �ϴܺ� ---\n");
}