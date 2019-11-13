#define  _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <string.h>

void half_search(int a) {
	int mid;
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int left = 0;
	int right = (sizeof(arr) / sizeof(arr[0])) - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a > arr[mid]) {
			left = mid + 1;
		}
		else if (a < arr[mid]) {
			right = mid - 1;
		}
		else {
			printf("找到了,下标为:%d\n", mid);
			break;
		}
		if (left>right) {
			printf("没找到!\n");
		}
	}
}

int main() {
	int a;
	printf("请输入你要找的数:\n");
	scanf("%d", &a);
	half_search(a);
	system("pause");
	return 0;
}