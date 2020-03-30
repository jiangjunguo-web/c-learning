#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int a = 0;
	int b = 0;
	while (1) {
		if (nums2[b] < nums1[a]) {
			for (int j = m + b - 1; j >= a; j--) {
				nums1[j + 1] = nums1[j];
			}
			nums1[a] = nums2[b];
			a++;
			b++;
		}
		else {
			a++;
		}
		if (nums1[a] == 0) {
			nums1[a] = nums2[b];
			a++;
			b++;
		}
		if (b == n) {
			break;
		}
	}
}

int main() {
	int str1[10] = { 1, 2, 3 };
	int str2[] = { 2, 5, 6 };
	merge(str1, 10, 3, str2, 3, 3);

	system("pause");
	return 0;
}