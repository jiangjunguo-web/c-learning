#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revrse(char* str, int first, int last) {
	int temp;
	while (first < last) {
		temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}
char * reverseWords(char * s){
	//先调整格式
	int len = strlen(s);
	int i = 0;
	while (s[i] == ' ') {
		i++;
	}
	char* start = &s[i];
	int k, k1;
	int j ;
	while (s[i]) {
		if (s[i] == ' ') {
			k = k1 = i;
			while (s[k] == ' '){
				k++;
			}
			k = k - k1 - 1;
			j = i + 1;
			for (; j + k <= len && k; j++)
				s[j] = s[j + k];
		}
		i++;
	}
	i = i - 1;
	while (s[i] == ' ') 
		i--;
	s[i + 1] = 0;
	s = start;
	i = 0;
	int begin = 0;
	int end;
	int l = strlen(start);
	while (start[i]) {
		if (start[i] == ' ') {
			end = i - 1;
			revrse(start, begin, end);
			begin = i + 1;
		}
		i++;
	}
	end = i - 1;
	revrse(start, begin, end);
	revrse(start, 0, l-1);
	return s;
}

int main() {
	char s[] = "a good   example";
	
	puts(reverseWords(s));
	system("pause");
	return 0;
}