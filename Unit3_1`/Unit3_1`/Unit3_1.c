#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int len) {
	int temp;
	for (int i = 1; i <= len; i++) {
		for (int j = 0; j < len-i; j++) {
			if (arr[j] <arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {
	int arr[] = { 2,6,3,8,2,9,1,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, len);
	for (int i = 0; i < len; i++) {
		printf("%d",arr[i]);
	}

	system("pause");
	return 0;
}

