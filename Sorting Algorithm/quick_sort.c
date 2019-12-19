#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

/*
	Title: 퀵 정렬
	
	* 피벗을 기준으로 큰 값과 작은 값을 서로 교체


*/

int arr[SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) return; // 시작부분 예외처리***
	int key = start, i = key + 1, j = end;
	while (i <= j) { // 등호 주의
		while (i <= end && arr[i] <= arr[key]) i++; // 왼쪽에서 피벗보다 큰 수의 좌표
		while (j > start && arr[j] >= arr[key]) j--; // 오른쪽에서 피벗보다 작은 수의 좌표
		if (i > j) swap(&arr[j], &arr[key]); 
		else swap(&arr[i], &arr[j]);
	}
	quickSort(arr, start, j - 1); // 재귀
	quickSort(arr, j + 1, end); // 재귀
}



int main(void) {

	int n;
	printf("입력할 원소의 갯수를 입력하시오: ");
	scanf("%d", &n);
	printf("%d 개의 정수를 입력하시오\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");


	system("pause");
	return 0;
}