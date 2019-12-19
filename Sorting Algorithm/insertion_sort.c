#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

/*
	Title: 삽입 정렬

	* 앞에서부터 차례대로 이미 정렬된 부분을 비교하여 위치를 찾는다.
	* 선택된 좌표에서 다음 데이터와 크기를 비교
	* 만약 다음 데이터보다 현재 데이터가 크면 바꿔준다.
	* 좌표를 뒤로 이동하면서 확인한다.

*/

int arr[SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(int arr[], int size) {
	
	for (int i = 0; i < size - 1; i++) {
		int index = i;
		while (index >= 0 && arr[index] > arr[index + 1]) {
			swap(&arr[index], &arr[index + 1]);
			index--;
		}
	}
}

int main(void) {

	int n;
	printf("입력할 원소의 갯수를 입력하시오: ");
	scanf("%d", &n);
	printf("%d 개의 정수를 입력하시오\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	insertionSort(arr, n);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");



	system("pause");
	return 0;
}