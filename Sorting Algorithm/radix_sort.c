#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX 10000

/*
	Title: 기수 정렬

	* 자릿수를 기준으로 차례대로 데이터를 정렬하는 알고리즘
	* 1의 자릿수 부터, 배열상의 최대 값의 최상단 자릿수까지 정렬
	* 자릿수의 배열을 처리하고 누적 값을 계산
	* 배열 뒷자리에서부터 시작해서 해당 자릿수의 (누적값 - 1)을 자리로 한 결과 배열에 입력
	* 정렬을 위한 기본 배열 갱신

*/
void radixSort(int *arr, int size) {
	int list[MAX], maxValue = INT_MIN, exp = 1;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= maxValue) maxValue = arr[i];
	}
	while (maxValue / exp % 10 != 0) {
		int bucket[10] = { 0, };
		for (int i = 0; i < size; i++) {
			bucket[arr[i] / exp % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			bucket[i] += bucket[i - 1];
		}
		for (int i = size - 1; i >= 0; i--) {
			list[--bucket[arr[i] / exp % 10]] = arr[i];
		}
		for (int i = 0; i < size; i++) {
			arr[i] = list[i];
		}
		exp *= 10;
	}
}

int main(void) {
	int arr[MAX];
	int index, size;
	
	printf("입력할 정수의 개수를 입력하시오: ");
	scanf("%d", &size);

	printf("%d 개의 정수를 입력하시오\n-> ", size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}

	radixSort(arr, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}