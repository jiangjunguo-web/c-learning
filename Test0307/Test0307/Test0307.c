#include <stdio.h>
#include <stdlib.h>

//自创建strcat函数
char* Strcat(char* destination, char* str) {
	if (destination == NULL || str == NULL) {
		return NULL;
	}
	else {
		int count = 0;
		while (destination[count] != 0) {
			count++;
		}
		int i = 0;
		while (str[i] != 0) {
			destination[count + i] = str[i];
			i++;
		}
		destination[i+count] = 0;
		return destination;
	}
}

//自创建函数Strcpy
char* Strcpy(char* str, char* arr) {
	if (str == NULL || arr == NULL) {
		return NULL;
	}
	else {
		char* begin = str;
		while (*arr != '\0') {
			*str = *arr;
			str++;
			arr++;
		}
		*str = '\0';
		return begin;
	}
}

//自创建Strlen函数
int Strlen(char* str) {
	if (str == NULL) {
		return 0;
	}
	else {
		int count = 0;
		while (*str != 0) {
			str++;
			count++;
		}
		return count;
	}
}
int main() { 
	char str1[200] = "haha";
	
	char str2[200] = "heheheuiheii";

	Strcpy(str1, str2);
	puts(str1);
	system("pause");
	return 0;
}