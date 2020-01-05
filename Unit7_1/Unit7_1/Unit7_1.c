#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//选择排序法
void SelectSort(int arr[],int n) {	
	int temp1;
	for (int i = 0; i < n; i++) {
		int maxnum = i;
		for (int j = i; j < n; j++) {
			if (arr[j]<arr[j + 1]) {
				maxnum = j + 1;
			}
		}
		temp1 = arr[maxnum];
		arr[maxnum] = arr[i];
		arr[i] = temp1;
	}
}

void ArrOutput(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

//Unit7-2
void EveryOne(int arr[]) {
	int place[10] = {0};
	int output[10] = { 0 };
	int tem = 0;
	int count = 0;

	for (int i = 0; arr[i]; i++) {
		int flag = 1;
		int temp = 0;
		for (; flag==1; arr[i]=arr[i]/10) {
			temp = arr[i]%10;
			place[temp] = place[temp] + 1;
			if (arr[i] <= 9 )  {
				flag = 0;
			}
		}	
	}
	for (int j = 0; j < 9; j++) {
		if (place[tem]>place[j + 1]) {
			output[0] = tem;
		}
		else if (place[tem] == place[j + 1]) {
			count++;
			output[count] = j + 1;
		}
		else {
			tem = j + 1;
			count = 0;
			memset(output,0,10);
		} 
	}

	for (int k = 0; k <= count; k++) {
		printf("出现次数最多得数为%d,出现了%d次\n",output[k], place[output[k]]);
	}

}
//判断“上三角”数组
int Judge(int arr[100][100] , int len) {
	int flag = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (arr[0][0] != arr[i][j]) {
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int a[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", a[i][j]);
		}
	}
	if (Judge(a, n)){
		printf("是");
	}
	else{
		printf("不是");
	}
	return 0;
}