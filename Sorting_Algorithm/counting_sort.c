#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10000

/*
	Title: ��� ����

	- �ش� �������� ũ�⸦ �������� �ش� ���� ���� �������� ������ ���� ���� �˰���
	- �ش� value�� �迭�� index�� �ǰ� value�� ������ �迭�� ��´ٰ� ��������


	* �ð� ���⵵
	- N���� �����Ͱ� �־��� ���
	- �ϳ��� �о�鼭 ũ�⸦ �������� �з��Ѵ�.
												=> O(N)�� ���⵵

*/

int arr[MAX_VALUE];
void countingSort(int arr[], int size);


int main(void) {
	int size;
	scanf("%d", &size);
	countingSort(arr, size);


	system("pause");
	return 0;
}


void countingSort(int arr[], int size) {
	int data, count = size;
	for (int i = 0; i < size; i++) { scanf("%d", &data); arr[data]++; }

	while (count) {
		for (int j = 0; j < MAX_VALUE; j++) {
			while (arr[j] != 0) {
				printf("%d ", j);
				arr[j]--;
				count--;
			}
		}
	}
}