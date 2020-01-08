#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10000

/*
	Title: 계수 정렬

	- 해당 데이터의 크기를 기준으로 해당 값과 같은 데이터의 개수를 세는 정렬 알고리즘
	- 해당 value가 배열의 index가 되고 value의 갯수를 배열에 담는다고 생각하자


	* 시간 복잡도
	- N개의 데이터가 주어진 경우
	- 하나씩 읽어가면서 크기를 기준으로 분류한다.
												=> O(N)의 복잡도

*/

int arr[MAX_VALUE];
void countingSort(int arr[], int size);


int main(void) {
	int size;
	scanf("%d", &size);
	countingSort(arr, size);


	system("pause");
	return 0;
}


void countingSort(int arr[], int size) {
	int data, count = size;
	for (int i = 0; i < size; i++) { scanf("%d", &data); arr[data]++; }

	while (count) {
		for (int j = 0; j < MAX_VALUE; j++) {
			while (arr[j] != 0) {
				printf("%d ", j);
				arr[j]--;
				count--;
			}
		}
	}
}