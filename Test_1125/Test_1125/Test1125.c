#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
//题目：传入n个数，取其中的k个进行相加输出其所有结果

void ReloadSum(int n, int k,int start,int arr[],int an) {
	int i;

	if (k <= 0) {
		printf("%d  ", an);
		printf("\n");
		return;
	}
	for (i = start; i < n; i++) {
		ReloadSum(n, k - 1, i + 1, arr,an+arr[i]);
		
	}

}

int main() {
	int arr[32];
	int n;
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	ReloadSum(n, k, 0, arr,0);
    system ("pause");
    return 0;
}