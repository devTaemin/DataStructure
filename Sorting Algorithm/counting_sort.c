#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10000

/*
	Title: 계수 정렬
	
	* 크기를 기준으로 데이터의 개수를 세는 정렬 알고리즘
	* 테이블을 작성하는 것과 같이 해당 수를 count해서 저장
	* 계수를 출력하면서 count는 하나씩 감소
	* 기준이 되는 값의 한계 사이즈를 미리 설정해야한다

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
	printf("입력할 정수의 개수를 입력하시오: ");
	scanf("%d", &size);
	printf("%d 개의 정수를 입력하시오\n-> ", size);
	countSort(arr, size);
	system("pause");
	return 0;
}