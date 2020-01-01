#include <stdio.h>
#include <stdbool.h>
#define SIZE 10000
#define INF 99999999

/*
	Title: 배열로 구현한 스택

	'Last In First Out'
	'Push와 Pop 과정이 한쪽에서 수행되는 자료구조'

	- Top이 되는 자료를 지정하여 활용


	* 구현함수

	[1] 탐색
	[2] 입력 [3] 제거
	[4] 전체 출력
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
		printf("스택 언더플로우가 발생했습니다.\n");
		return res;
	}
	for (int i = top; i >= 0; i--) {
		if (s[i] == n) {
			res = true;
			printf("정수 %d를 발견하였습니다.\n", n);
			return res;
		}
	}
	printf("정수 %d를 발견하지 못했습니다.\n", n);
	return res;
}

void push(int s[], int n) {
	if (count >= SIZE - 1) {
		printf("스택 오버플로우가 발생했습니다.\n");
		return;
	}
	s[++top] = n;
	count++;
}

int pop(int s[]) {
	if (count <= 0) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	int data = s[top--];
	count--;
	return data;
}

void showAll(int s[]) {
	if (count <= 0) {
		printf("스택 언더플로우가 발생했습니다.\n");
		return;
	}
	printf("--- 스택 상단부 ---\n");
	for (int i = top; i >= 0; i--) {
		printf("%d\n", s[i]);
	}
	printf("--- 스택 하단부 ---\n");
}