#include <stdio.h>
#include <stdlib.h>
//二分查找
void FindArray(int arr[],int len,int n) {
	int left = 0;
	int right = len-1;
	int middle;
	for (int i=0; i < len; i++) {
		middle = (right + left) / 2;
		if (left <= right) {
			if (arr[middle] < n) {
				left = middle + 1;
			}
			else if (arr[middle] > n) {
				right = middle - 1;
			}
			else {
				printf("找到了，下标为：%d\n",middle);
				break;
			}
		}
		else {
			printf("没找到\n");
			break;
		}
	}

}


int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 101 };
	int len =sizeof(arr)/sizeof(arr[0]);
	FindArray(arr, len, 10);
	system("pause");
	return 0;
}