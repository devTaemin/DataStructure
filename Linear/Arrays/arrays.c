#include <stdio.h>
#include <stdbool.h>
#define SIZE 100000
#define INF 99999999

/*
	Title: ��������Ʈ(�迭)

	'�����͸� ���������� �����ϰ� ó���ϴ� �ڷᱸ��'
	- ������ �̸� �Ҵ�
	- ������ ���� ������ Ȱ��
	- ������ ������ ��ü �̵�


	* �����Լ�

	[1] Ž��
	[2] ���� �Է� [3] �Ĺ� �Է�
	[4] ���� ���� [5] �Ĺ� ���� [6] Ư�� ��ġ ����
	[7] ��ü ���
*/

int array[SIZE];
int count = 0;

bool search(int arr[], int n);
void front_push(int arr[], int n);
void rear_push(int arr[], int n);
int front_pop(int arr[]);
int rear_pop(int arr[]);
int spot_pop(int arr[], int index);
void showAll(int arr[]);




int main(void) {

	rear_push(array, 1);
	rear_push(array, 3);
	front_push(array, 5);
	rear_push(array, 7);
	front_push(array, 9);
	showAll(array);

	int n = 5;
	if (search(array, n)) { printf("���� %d�� �迭�� �ֽ��ϴ�.\n", n); }
	else { printf("���� %d�� �迭�� �����ϴ�.\n", n); }

	front_pop(array);
	rear_pop(array);
	front_pop(array);
	showAll(array);
	if (search(array, n)) { printf("���� %d�� �迭�� �ֽ��ϴ�.\n", n); }
	else { printf("���� %d�� �迭�� �����ϴ�.\n", n); }

	spot_pop(array, 0);
	showAll(array);


	system("pause");
	return 0;
}

bool search(int arr[], int n) {
	bool res = false;
	if (count <= 0) {
		printf("�迭 ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	for (int i = 0; i < count; i++) {
		if (arr[i] == n) {
			res = true;
			return res;
		}
	}
	return res;
}

void front_push(int arr[], int n) {
	if (count >= SIZE) {
		printf("�迭 �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	for (int i = count; i > 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = n;
	count++;
}

void rear_push(int arr[], int n) {
	if (count >= SIZE) {
		printf("�迭 �����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	arr[count++] = n;
}


int front_pop(int arr[]) {
	int data;
	if (count <= 0) {
		printf("�迭 ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	data = arr[0];
	count--;
	for (int i = 0; i < count; i++) {
		arr[i] = arr[i + 1];
	}
	return data;
}

int rear_pop(int arr[]) {
	if (count <= 0) {
		printf("�迭 ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	int data = arr[--count];
	return data;
}

int spot_pop(int arr[], int index) {
	if (index >= SIZE) {
		printf("������ ������ �迭�� �ʰ��߽��ϴ�.\n");
		return -INF;
	}
	if (count <= 0) {
		printf("�迭 ����÷ο찡 �߻��߽��ϴ�.\n");
		return -INF;
	}
	int data = arr[index];
	if (index == count - 1) {
		rear_pop(arr);
	}
	else {
		for (int i = index; i < count; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}
	return data;
}

void showAll(int arr[]) {
	if (count <= 0) {
		printf("�迭 ����÷ο찡 �߻��߽��ϴ�.\n");
		return;
	}
	printf("--- �迭 ��ܺ� ---\n");
	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}
	printf("--- �迭 �ϴܺ� ---\n");
}



