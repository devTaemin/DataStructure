#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

/*
	Title: �켱���� ť

	- Queue(First In First Out)�� �켱������ �̿��Ͽ� ����
	- ���� ������ �ƴ� Ʈ�� ����, �ִ� ��(Max Heap)�� �̿��Ѵ�.
	
	* �ִ� ��
	: �θ� ��尡 �ڽ� ��庸�� ū ���� ����Ʈ��, ��Ʈ����� ���� ���� ũ��.

	* �Է�
	- �����
	- ������ ���Ҵ� ���� ���� Ʈ���� �����ϴ� ���·� ���������� ���Եȴ�.
	- ���� ����, ��Ʈ ������ �Ž��� �ö󰡸鼭 �ִ� ���� �����Ѵ�.

	* ����
	- �����
	- ������ ���Ҵ� �켱������ ���� ���� ��Ʈ��带 �����Ѵ�
	- ����, ���� ������ ���Ҹ� ��Ʈ ���� �ű�� ���� ������ �������鼭 �ִ����� �����Ѵ�.

*/

typedef struct {
	int heap[MAX_SIZE];
	int count;
} priorityQueue;


int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(priorityQueue *pq, int data);
int pop(priorityQueue *pq);


int main(void) {

	system("pause");
	return 0;
}

void push(priorityQueue *pq, int data) {
	if (pq->count >= MAX_SIZE) return;
	pq->heap[pq->count] = data;
	int now = pq->count;
	int parent = (now - 1) / 2;
	while (now > 0 && pq->heap[now] > pq->heap[parent]) {
		swap(&pq->heap[now], &pq->heap[parent]); 
		now = parent;
		parent = (parent - 1) / 2;
	}
	pq->count++;
}

int pop(priorityQueue *pq) {
	if (pq->count <= 0) return -9999;
	int res = pq->heap[0];
	pq->count--;
	pq->heap[0] = pq->heap[pq->count];
	int now = 0, leftChild = 1, rightChild = 2;
	int target = now;
	while (leftChild < pq->count) {
		if (pq->heap[target] < pq->heap[leftChild]) target = leftChild;
		if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) target = rightChild;
		if (target == now) break;
		else {
			swap(&pq->heap[now], &pq->heap[target]);
			now = target;
			leftChild = now * 2 + 1;
			rightChild = now * 2 + 2;
		}
	}
	return res;
}
