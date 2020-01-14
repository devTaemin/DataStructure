#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

/*
	Title: 우선순위 큐

	- Queue(First In First Out)를 우선순위를 이용하여 구현
	- 선형 구조가 아닌 트리 구조, 최대 힙(Max Heap)을 이용한다.
	
	* 최대 힙
	: 부모 노드가 자식 노드보다 큰 완전 이진트리, 루트노드의 값이 가장 크다.

	* 입력
	- 상향식
	- 삽입할 원소는 완전 이진 트리를 유지하는 형태로 순차적으로 삽입된다.
	- 삽입 이후, 루트 노드까지 거슬러 올라가면서 최대 힙을 구성한다.

	* 삭제
	- 하향식
	- 삭제할 원소는 우선순위가 가장 높은 루트노드를 삭제한다
	- 이후, 가장 마지막 원소를 루트 노드로 옮기고 리프 노드까지 내려가면서 최대힙을 구성한다.

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
