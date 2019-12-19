#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10000

/*
	Title: ��� ����
	
	* ũ�⸦ �������� �������� ������ ���� ���� �˰���
	* ���̺��� �ۼ��ϴ� �Ͱ� ���� �ش� ���� count�ؼ� ����
	* ����� ����ϸ鼭 count�� �ϳ��� ����
	* ������ �Ǵ� ���� �Ѱ� ����� �̸� �����ؾ��Ѵ�

*/

int arr[MAX_VALUE];


void countSort(int arr[], int n) {
	int num, count = n;
	while (count) {
		scanf("%d", &num);
		arr[num]++;
		count--;
	}

	for (int i = 0; i < MAX_VALUE; i++) {
		while (arr[i] != 0) {
			printf("%d ", i);
			arr[i]--;
		}
	}
}


int main(void) {

	int size;
	printf("�Է��� ������ ������ �Է��Ͻÿ�: ");
	scanf("%d", &size);
	printf("%d ���� ������ �Է��Ͻÿ�\n-> ", size);
	countSort(arr, size);
	system("pause");
	return 0;
}