#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 10000

/*
	Title: 선택 정렬

	* 배열에서 최소 값을 찾아 배열 첫 자리로 이동한다.
	* 다음 위치 부터 배열의 최소값을 찾아 시작 자리로 이동한다.
	* 데이터끼리 비교하면서 최소값의 자리를 변수로 저장한다.

*/

int arr[SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int size) {
	int min, index;
	for (int i = 0; i < size; i++) {
		min = INT_MAX;
		for (int j = i; j < size; j++) {
			if (arr[j] < min) { 
				min = arr[j];
				index = j;
			}
		}
		swap(&arr[i], &arr[index]);
	}
}

int main(void) {

	int n;
	printf("입력할 원소의 갯수를 입력하시오: ");
	scanf("%d", &n);
	printf("%d 개의 정수를 입력하시오\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
	
	selectionSort(arr, n);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");

	system("pause");
	return 0;
}