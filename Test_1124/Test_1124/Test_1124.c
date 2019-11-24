#include  <stdio.h>
#include <stdlib.h>


//ц╟ещеепР
void BubbleSort(int arr[] ,int len) {
	int temp = 0;
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j < len - i; j++) {
			if (arr[j] >= arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
}

int main() {
	int arr[] = { 1, 5, 1, 72, 738, 2, 5, 8, 3 };
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	BubbleSort(arr,len);
	for (int i = 0; i <= len; i++) {
		printf("%d ", arr[i]);
	}
    system ("pause");
    return 0;
}