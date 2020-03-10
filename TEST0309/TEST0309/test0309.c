#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//创建strcmp函数
int Strcmp(char* str1,char* str2) {
	assert(str1 != NULL&&str2 != NULL);
	int flag;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i;
	int len = (len1 > len2) ? len1 : len2;
	if (str1 == str2) {
		if (len1 == len2) {
			flag = 0;
		}
	}
	else {
		for (i = 0; i <= len; i++) {
			if (str1[i] == str2[i]) {
				continue;
			}
			else if (str1[i] < str2[i]) {
				flag = -1;
				break;
			}
			else {
				flag = 1;
				break;
			}
		}
	}
	if (i == len+1) {
		flag = 0;
	}
	return flag;
}

//模拟实现strstr
char* Strstr(char* str1, char* str2) {
	//保险操作
	assert(str1!=NULL&&str2!=NULL);
	char* black = str1;
	char* red = str1;
	char* found = str2;
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	if (*str2 == 0) {
		return NULL;
	}
	while (*found != 0 && *red != 0 && (*found != *red)){
		black++;
		red = black;
		found = str2;
		while (*found != 0 && *red != 0 && (*found == *red)) {
			red++;
			found++;
		}
	}
	if (*found == 0) {
		return black;
	}
	else{
		return NULL;
	}
}


//模拟实现memcpy函数
void* Memcpy(void* destin, void* source, size_t n) {
	assert(destin != NULL&&source != NULL);
	for (size_t i = 0; i < n; i++) {
		*(char*)destin = *(char*)source;
		(char*)destin = (char*)destin + 1;
		(char*)source = (char*)source + 1;
	}
	return destin;
}


//模拟实现memmove函数
void* Memmove(void* dest, const void* src, size_t count) {
	assert(dest != NULL&&src != NULL);
	if ((char*)dest<(char*)src || (char*)dest>(char*)src + count) {
		for (size_t i = 0; i < count; i++) {
			*(char*)dest = *(const char*)src;
			(char*)dest = (char*)dest + 1;
			(const char*)src = (const char*)src + 1;
		}
	}
	else {
		(char*)dest = (char*)dest +count-1;
		(const char*)src = (char*)src + count - 1;
		for (size_t j = 0; j < count; j++) {
			*(char*)dest = *(const char*)src;
			(char*)dest = (char*)dest - 1;
			(const char*)src = (const char*)src - 1;
		}
	}
	return dest;
}

int main() {
	char str2[] = "abcdefg";
	char* str1 = str2 + 1;
	Memmove(str1, str2, 8);
	puts(str1);
	system("pause");
	return 0;
}