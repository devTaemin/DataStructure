#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10000

/*
	Title: �迭�� �̿��� ���� ����Ʈ ����

	* �迭 Ư���� size�� count�� ������ �����ؾ���
	* count�� �̿��Ͽ� data ����, ����, ���İ����� ������
	
*/

int arr[SIZE];
int count = 0;

void addBack(int elem) {
	arr[count++] = elem;
}

void addFirst(int elem) {
	for (int i = count; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = elem;
	count++;
}

void show() {
	printf("--- ����Ʈ ��� ---\n");
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}
	printf("--- ����Ʈ �ϴ� ---\n");
}

void removeAt(int index) {
	if (index >= count) {
		printf("����Ʈ ������ �ʰ��߽��ϴ�.\n");
	}
	else {
		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}
}


int main(void) {
	addFirst(1);
	addBack(2);
	addBack(3);
	addBack(4);
	removeAt(2);
	show();
	system("pause");
	return 0;
}