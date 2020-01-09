#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	Title: 이진트리

	- 최대 2개의 자식을 가질 수 있는 트리
	- 구조체를 이용하여 데이터를 담고, 자식 노드와 연결하여 구조 형성

	* 이진트리 순회
	[전위순회]: 자기 자신 출력 -> 왼쪽 자식 -> 오른쪽 자식
	[중위순회]: 왼쪽 자식 -> 자기 자신 출력-> 오른쪽 자식
	[후위순회]: 왼쪽 자식 -> 오른쪽 자식 -> 자기 자신 출력
	
	- 재귀를 이용하여 트리를 순회한다
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