#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	Title: ����Ʈ��

	- �ִ� 2���� �ڽ��� ���� �� �ִ� Ʈ��
	- ����ü�� �̿��Ͽ� �����͸� ���, �ڽ� ���� �����Ͽ� ���� ����

	* ����Ʈ�� ��ȸ
	[������ȸ]: �ڱ� �ڽ� ��� -> ���� �ڽ� -> ������ �ڽ�
	[������ȸ]: ���� �ڽ� -> �ڱ� �ڽ� ���-> ������ �ڽ�
	[������ȸ]: ���� �ڽ� -> ������ �ڽ� -> �ڱ� �ڽ� ���
	
	- ��͸� �̿��Ͽ� Ʈ���� ��ȸ�Ѵ�
*/

typedef struct {
	int data;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;



Node* initNode(int data, Node* left, Node* right);
void preorder(Node* root);
void inorder(Node* root);
void postorder(Node* root);


int main(void) {

	system("pause");
	return 0;
}


Node* initNode(int data, Node* left, Node* right) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->leftChild = left;
	node->rightChild = right;
	return node;
}

void preorder(Node* root) {
	if (root) {
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void inorder(Node* root) {
	if (root) {
		inorder(root->leftChild);
		printf("%d ", root->data);
		inorder(root->rightChild);
	}
}

void postorder(Node* root) {
	if (root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root->data);
	}
}