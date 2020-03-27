#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

char* haha(char* str, int len) {

	int count = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') {
			count++;
		}
	}
	char* arr = (char*)malloc(len + count * 2);
	memcpy(arr, str, len);
	int a = len - 1;
	int b = len + count * 2 - 1;
	for (int i = a; i>0; i--,b--) {
		if (arr[i] != ' ') {
			arr[b] = arr[i];
		}
		else {
			arr[b] = '0';
			b--;
			arr[b] = '2';
			b--;
			arr[b] = '%';
		}
	}
	str = arr;
	return str;
}

int main(){
	char str[] = "We Are Happy";

	puts(haha(str, 13));
	system("pause");
	return 0;
}