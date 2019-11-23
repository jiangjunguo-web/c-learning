#include  <stdio.h>
#include <stdlib.h>
//√∞≈›≈≈–Ú∑®
void bubblesort(int arr[],int len) {
	int temp = 0;
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (arr[j] >= arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main() {
	int arr[] = {9,1,4,5,6,7,5,2};
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	bubblesort(arr,len);
	//for (int i = 0; i <= len; i++) {
	//	printf("%d", arr[i]);
	//}
    system ("pause");
    return 0;
}