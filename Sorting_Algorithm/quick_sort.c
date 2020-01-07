#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000

/*
	Title: �� ����

	- �� �����̶�, �ǹ��� �������� ū ���� ���� ���� ���� ��ü�ϴ� ���� ����̴�.
	- ���ʿ��� ���ʹ� �ǹ����� ū ��, �����ʿ��� ���ʹ� �ǹ����� ���� ���� ã�� ��ü�Ѵ�.
	- ���� ū ���� ���� ���� ��ġ�� �������ٸ� �ǹ����� ���� ���� ��ü���ش�.
	- �׸��� �ǹ� ��ġ �̸� �迭�� �ǹ� ��ġ �ʰ� �迭�� ���Ͽ� [��������� �� ������ �����Ѵ�.

	* �ð� ���⵵
	- N���� �����Ͱ� �־��� ���
	- ���� ��ü�ϴµ� N��, �����͸� ������ �����µ� logN��
												=> ��� O(N * logN)�� ���⵵

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
