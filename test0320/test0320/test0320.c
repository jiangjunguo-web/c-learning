#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//模拟实现字符串转整数
int Atoi(char* str) {
	double result = 0;
	int flag = 0;
	int len = strlen(str);
	if (str == NULL) {
		return 0;
	}
	
	for (int i = 0; i < len; i++) {
		if (str[i] == '-'&&i==0) {
			flag = 1;
		}
		else if (str[i]<='9'&&str[i]>='0') {	
			result = result * 10 + (str[i]-'0');
		}
		else if(str[i]='.') {
			break;
		}
		else {
			return 0;
		}
	}
	if (flag == 0) {
		if (result > INT_MAX) {
			return 0;
		}
		else {
			return (int)result;
		}
	}
	else {
		if (-result < INT_MIN) {
			return 0;
		}
		else {
			return (int)-result;
		}
	}
}

//找单身狗
int* FindDog(int* result,int* str,int len) {
	int count = 0;
	int* begin = result;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (str[i] == str[j]) {
				count++;
			}
		}
		if (count == 1) {
			*result = str[i];
			result = result + 1;
		}
		count = 0;
	}
	return result;
}

//模拟实现strncat
char * Strncat(char *dest, const char *src, size_t n){
	assert(dest != NULL&&src != NULL);
	int i;
	for (i = 0; dest[i]; i++);
	for (size_t j = i; j < i + n; j++) {
		dest[j] = src[j-i];
	}
	dest[i + n] = 0;
	return dest;
}

//模拟实现Strncpy
char* Strncpy(char *dest, const char *src, size_t n) {
	assert(dest != NULL&&src != NULL);
	int i;
	for (i = 0; dest[i]; i++);
	memset(dest,0,i);
	for (size_t i = 0; i < n; i++) {
		dest[i] = src[i];
	}
	return dest;
}


int main() {
	char dest[20] = "hello";
	char str[] = "world";
	Strncpy(dest, str, 4);
	printf("%s", dest);
	system("pause");
	return 0;
}