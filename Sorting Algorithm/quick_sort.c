#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

/*
	Title: �� ����
	
	* �ǹ��� �������� ū ���� ���� ���� ���� ��ü


*/

int arr[SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int start, int end) {
	if (start >= end) return; // ���ۺκ� ����ó��***
	int key = start, i = key + 1, j = end;
	while (i <= j) { // ��ȣ ����
		while (i <= end && arr[i] <= arr[key]) i++; // ���ʿ��� �ǹ����� ū ���� ��ǥ
		while (j > start && arr[j] >= arr[key]) j--; // �����ʿ��� �ǹ����� ���� ���� ��ǥ
		if (i > j) swap(&arr[j], &arr[key]); 
		else swap(&arr[i], &arr[j]);
	}
	quickSort(arr, start, j - 1); // ���
	quickSort(arr, j + 1, end); // ���
}



int main(void) {

	int n;
	printf("�Է��� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &n);
	printf("%d ���� ������ �Է��Ͻÿ�\n -> ", n);
	for (int i = 0; i < n; i++) { scanf("%d", &arr[i]); }

	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
	printf("\n");


	system("pause");
	return 0;
}