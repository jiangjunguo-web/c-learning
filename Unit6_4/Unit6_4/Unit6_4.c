#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ģ�������ȼ������
int Computer(char arr[],int len) {
	int temp = arr[0]-0x30;
	for (int i = 0; i < len; i++) {
		if (arr[i] == '+') {
			temp += arr[i + 1]-0x30;
		}
		if (arr[i] == '*') {
			temp *= arr[i + 1] - 0x30;
		}
		if (arr[i] == '/') {
			temp /= arr[i + 1] - 0x30;
		}
		if (arr[i] == '-') {
			temp -= arr[i + 1] - 0x30;
		}
		if (arr[i] == '=') {
			break;
		}
	}
	return temp;
}


//ͳ��һ�仰�е��ʵĸ���
int CountWord(char* arr,int len) {
	int count = 0;
	for (int i = 0;arr[i]; i++) {
		if (arr[i] == ' ') {
			count++;
		}
	}
	count=count + 1;
	return count;
}


int main() {
	char arr[100];
	gets(arr);
	int len = strlen(arr);
	int endnum = CountWord(arr, len);
	printf("%d\n",endnum);
	system("pause");
	return 0;
}