#include <stdio.h>
#include <stdbool.h>
#define SIZE 100000
#define INF 99999999

/*
	Title: 순차리스트(배열)

	'데이터를 순차적으로 저장하고 처리하는 자료구조'
	- 공간을 미리 할당
	- 데이터 수량 정보를 활용
	- 삭제시 데이터 전체 이동


	* 구현함수

	[1] 탐색
	[2] 전방 입력 [3] 후방 입력
	[4] 전방 제거 [5] 후방 제거 [6] 특정 위치 제거
	[7] 전체 출력
*/

int array[SIZE];
int count = 0;

bool search(int arr[], int n);
void front_push(int arr[], int n);
void rear_push(int arr[], int n);
int front_pop(int arr[]);
int rear_pop(int arr[]);
int spot_pop(int arr[], int index);
void showAll(int arr[]);




int main(void) {

	rear_push(array, 1);
	rear_push(array, 3);
	front_push(array, 5);
	rear_push(array, 7);
	front_push(array, 9);
	showAll(array);

	int n = 5;
	if (search(array, n)) { printf("정수 %d은 배열에 있습니다.\n", n); }
	else { printf("정수 %d는 배열에 없습니다.\n", n); }

	front_pop(array);
	rear_pop(array);
	front_pop(array);
	showAll(array);
	if (search(array, n)) { printf("정수 %d은 배열에 있습니다.\n", n); }
	else { printf("정수 %d는 배열에 없습니다.\n", n); }

	spot_pop(array, 0);
	showAll(array);


	system("pause");
	return 0;
}

bool search(int arr[], int n) {
	bool res = false;
	if (count <= 0) {
		printf("배열 언더플로우가 발생했습니다.\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		if (arr[i] == n) {
			res = true;
			return res;
		}
	}
	return res;
}

void front_push(int arr[], int n) {
	if (count >= SIZE) {
		printf("배열 오버플로우가 발생했습니다.\n");
		return;
	}
	for (int i = count; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = n;
	count++;
}

void rear_push(int arr[], int n) {
	if (count >= SIZE) {
		printf("배열 오버플로우가 발생했습니다.\n");
		return;
	}
	arr[count++] = n;
}


int front_pop(int arr[]) {
	int data;
	if (count <= 0) {
		printf("배열 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	data = arr[0];
	count--;
	for (int i = 0; i < count; i++) {
		arr[i] = arr[i + 1];
	}
	return data;
}

int rear_pop(int arr[]) {
	if (count <= 0) {
		printf("배열 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	int data = arr[--count];
	return data;
}

int spot_pop(int arr[], int index) {
	if (index >= SIZE) {
		printf("선택한 범위는 배열을 초과했습니다.\n");
		return -INF;
	}
	if (count <= 0) {
		printf("배열 언더플로우가 발생했습니다.\n");
		return -INF;
	}
	int data = arr[index];
	if (index == count - 1) {
		rear_pop(arr);
	}
	else {
		for (int i = index; i < count; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}
	return data;
}

void showAll(int arr[]) {
	if (count <= 0) {
		printf("배열 언더플로우가 발생했습니다.\n");
		return;
	}
	printf("--- 배열 상단부 ---\n");
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}
	printf("--- 배열 하단부 ---\n");
}



