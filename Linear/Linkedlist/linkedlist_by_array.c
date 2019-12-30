#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000

/*
	Title: 배열을 이용한 연결 리스트 구현

	* 배열 특성상 size와 count를 사전에 구현해야함
	* count를 이용하여 data 삽입, 삭제, 정렬과정을 정리함
	
*/

int arr[SIZE];
int count = 0;

void addBack(int elem) {
	arr[count++] = elem;
}

void addFirst(int elem) {
	for (int i = count; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = elem;
	count++;
}

void show() {
	printf("--- 리스트 상단 ---\n");
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}
	printf("--- 리스트 하단 ---\n");
}

void removeAt(int index) {
	if (index >= count) {
		printf("리스트 범위를 초과했습니다.\n");
	}
	else {
		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}
}


int main(void) {
	addFirst(1);
	addBack(2);
	addBack(3);
	addBack(4);
	removeAt(2);
	show();
	system("pause");
	return 0;
}