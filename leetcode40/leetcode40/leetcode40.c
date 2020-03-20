#include <stdlib.h>
#include <stdio.h>

void Fastsort(int* arr, int low, int high) {
	if (low >= high) {
		return;
	}
	int temp = arr[low];
	int first = low;
	int last = high;
	while (first < last) {
		while (arr[last]>temp&&last >= first) {
			last--;
		}
		arr[first] = arr[last];
		while (arr[first] <= temp&&last>first) {
			first++;
		}
		arr[last] = arr[first];
	}
	arr[first] = temp;
	Fastsort(arr, low, first - 1);
	Fastsort(arr, first + 1, high);
}

int main() {
	int arr[] = { 4, 3, 3, 3, 3,3, 3, 8 };
	int arrSize = 8;

	Fastsort(arr, 0, arrSize-1);
	
	system("pause");
	return 0;
}