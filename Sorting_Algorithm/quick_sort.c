#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000

/*
	Title: 퀵 정렬

	- 퀵 정렬이란, 피벗을 기준으로 큰 값과 작은 값을 서로 교체하는 정렬 기법이다.
	- 왼쪽에서 부터는 피벗보다 큰 값, 오른쪽에서 부터는 피벗보다 작은 값을 찾고 교체한다.
	- 만일 큰 값과 작은 값의 위치가 엇갈린다면 피벗값과 작은 값을 교체해준다.
	- 그리고 피벗 위치 미만 배열과 피벗 위치 초과 배열에 대하여 [재귀적으로 퀵 정렬을 수행한다.

	* 시간 복잡도
	- N개의 데이터가 주어진 경우
	- 값을 교체하는데 N번, 데이터를 반으로 나누는데 logN번
												=> 평균 O(N * logN)의 복잡도

*/

int arr[SIZE];
void swap(int *a, int *b);
void quickSort(int arr[], int start, int end);


int main(void) {

}


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void quickSort(int arr[], int start, int end) {
	if (start >= end) return;
	int pivot = start;
	int left = pivot + 1, right = end;
	while (left <= right) {
		while (left <= end && arr[pivot] >= arr[left]) { left++; }
		while (right > pivot && arr[pivot] <= arr[right]) { right--; }
		if (left < right) { swap(&arr[left], &arr[right]); }
		else { swap(&arr[pivot], &arr[right]); }
	}
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}
