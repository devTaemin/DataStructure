#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 10000

/*
	Title: ���� ����

	* �迭���� �ּ� ���� ã�� �迭 ù �ڸ��� �̵��Ѵ�.
	* ���� ��ġ ���� �迭�� �ּҰ��� ã�� ���� �ڸ��� �̵��Ѵ�.
	* �����ͳ��� ���ϸ鼭 �ּҰ��� �ڸ��� ������ �����Ѵ�.

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
	printf("�Է��� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);
	printf("%d ���� ������ �Է��Ͻÿ�\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }
	
	selectionSort(arr, n);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");

	system("pause");
	return 0;
}