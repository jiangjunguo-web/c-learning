#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void revrse(char* str, int first, int last) {
//	int temp;
//	while (first < last) {
//		temp = str[first];
//		str[first] = str[last];
//		str[last] = temp;
//		first++;
//		last--;
//	}
//}
//char * reverseWords(char * s){
//	//�ȵ�����ʽ
//	int len = strlen(s);
//	int i = 0;
//	while (s[i] == ' ') {
//		i++;
//	}
//	char* start = &s[i];
//	int k, k1;
//	int j ;
//	while (s[i]) {
//		if (s[i] == ' ') {
//			k = k1 = i;
//			while (s[k] == ' '){
//				k++;
//			}
//			k = k - k1 - 1;
//			j = i + 1;
//			for (; j + k <= len && k; j++)
//				s[j] = s[j + k];
//		}
//		i++;
//	}
//	i = i - 1;
//	while (s[i] == ' ') 
//		i--;
//	s[i + 1] = 0;
//	s = start;
//	i = 0;
//	int begin = 0;
//	int end;
//	int l = strlen(start);
//	while (start[i]) {
//		if (start[i] == ' ') {
//			end = i - 1;
//			revrse(start, begin, end);
//			begin = i + 1;
//		}
//		i++;
//	}
//	end = i - 1;
//	revrse(start, begin, end);
//	revrse(start, 0, l-1);
//	return s;
//}

#define swap(a,b) {{a ^= b ; b ^= a; a ^= b;}}

void reve(char *s, int l, int r) {
	if (r <= l) return;
	while (l < r) {
		swap(s[l], s[r]);
		l++, r--;
	}
}

char* reverseWords(char* s) {
	int l = 0, r = strlen(s) - 1;
	reve(s, l, r);
	while (s[0] == ' ') s++;//����ǰ���ո�
	int i = 0, j = 0;
	int a = 0;
	char *temp = s;
	while (j <= r) {
		while (s[j] != ' ' && s[j] != 0) j++;//���㵥�ʳ���
		reve(s, i, j - 1);//��ת
		for (int k = 0; k < j - i; k++) {
			*(temp + k) = s[i + k];
		}
		//strncpy(temp, s + i,j - i);//��ֵ
		temp = temp + j - i;
		printf("%d %d\n", j, i);
		while (s[j] == ' ') j++;
		i = j;
		if (s[j] == 0) {
			*temp = 0;
			break;
		}
		*temp = ' ';//Ĭ�ϴ�����һ�����ʣ���һ���ո������һ���ǿո񲻻᲻���һ��������Ȼ���һ���ո�������ǰ�����ǰ���ո�
		temp++;

	}
	return s;
}
int main() {
	char s[] = "a good   example";
	
	puts(reverseWords(s));
	system("pause");
	return 0;
}