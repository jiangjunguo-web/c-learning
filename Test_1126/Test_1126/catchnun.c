#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>

//һ��������������
void Bubble(int arr[], int len) {
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
	printf("����������Ϊ��\n");
	for (int k = 0; k <= len; k++) {
		printf("%d ",arr[k]);
	}
	printf("\n");
}

void HalfFind(int arr[], int len,int catchnum) {
	int left = 0;
	int right = len;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (catchnum > arr[mid]) {
		left = mid + 1;
	}
	else if (catchnum < arr[mid]) {
		right = mid - 1;
	}
	else {
		printf("�ҵ��ˣ�Ԫ�±�λ��Ϊ%d\n", mid);
		break;
	}
	}
	if (left > right) {
		printf("û����һ��Ԫ�أ�\n");
	}
	
}

int main() {
	//����һ������
	int catchnum;
	int arr[] = {1,5,4,0,3,2,8,7,10};
	int len = sizeof(arr) / sizeof(arr[0])-1;
	Bubble(arr, len);
	printf("��������Ҫ���ҵ�Ԫ�أ�\n");
	scanf("%d", &catchnum);
	HalfFind(arr,len,catchnum);
    system ("pause");
    return 0;
}