#include <stdio.h>
#include <stdlib.h>

void Fastsort(int* A, int low, int high) {
	int first = low;
	int least = high;
	if (low >= high) {
		return;
	}
	int tem = A[low];
	while (low<high) {
		while (A[high] >= tem && low<high) {
			high--;
		}
		A[low] = A[high];
		while (A[low] <= tem && low<high) {
			low++;
		}
		A[high] = A[low];
	}
	A[low] = tem;
	Fastsort(A, first, low - 1);
	Fastsort(A, low + 1, least);
}

int minIncrementForUnique(int* A, int ASize){
	int count = 0;
	Fastsort(A, 0, ASize - 1);
	int temp = 0;
	for (int i = 1; i<ASize; i++) {
		if (A[i] <= A[i - 1]) {
			temp = A[i];
			A[i] = A[i - 1] + 1;
			count += A[i] - temp;
		}
	}
	return count;
}

int main() {
	int a[] = { 1, 1, 2, 2, 3, 7 };
	int len = sizeof(a) / sizeof(a[0]);
	printf("%d", minIncrementForUnique(a,len));
	system("pause");
	return 0;
}