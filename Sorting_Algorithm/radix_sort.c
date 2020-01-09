#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define MAX 10000

/*
	Title: ��� ����

	* �ڸ����� �������� ���ʴ�� �����͸� �����ϴ� �˰���
	* 1�� �ڸ��� ����, �迭���� �ִ� ���� �ֻ�� �ڸ������� ����
	* �ڸ����� �迭�� ó���ϰ� ���� ���� ���
	* �迭 ���ڸ��������� �����ؼ� �ش� �ڸ����� (������ - 1)�� �ڸ��� �� ��� �迭�� �Է�
	* ������ ���� �⺻ �迭 ����

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
	
	printf("�Է��� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &size);

	printf("%d ���� ������ �Է��Ͻÿ�\n-> ", size);
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