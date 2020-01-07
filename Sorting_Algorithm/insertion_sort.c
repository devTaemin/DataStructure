#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000

/*
	Title: ���� ����

	* �տ������� ���ʴ�� �̹� ���ĵ� �κ��� ���Ͽ� ��ġ�� ã�´�.
	* ���õ� ��ǥ���� ���� �����Ϳ� ũ�⸦ ��
	* ���� ���� �����ͺ��� ���� �����Ͱ� ũ�� �ٲ��ش�.
	* ��ǥ�� �ڷ� �̵��ϸ鼭 Ȯ���Ѵ�.

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
	printf("�Է��� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);
	printf("%d ���� ������ �Է��Ͻÿ�\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	insertionSort(arr, n);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");



	system("pause");
	return 0;
}