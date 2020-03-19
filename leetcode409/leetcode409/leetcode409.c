#include <stdio.h>
#include <stdlib.h> 
int longestPalindrome(char * s){
	int* str = (int*)calloc(52, 4);
	int i = 0;
	int tem;
	int count = 0;
	while (s[i]) {
		if (s[i]>='A'&&s[i]<='Z') {
			tem = s[i] - 'A';
			str[tem]++;
		}
		if (s[i]>='a'&&s[i]<='z') {
			tem = s[i] - 'a' + 26;
			str[tem]++;
		}
		i++;
	}

	tem = 0;
	for (int j = 0; j<52; j++) {
		if (str[j] % 2 == 0) {
			if (str[j] != 0) {
				count += str[j];
			}
		}
		else {
			tem = 1;
			if (str[j]>1) {
				count += str[j] - 1;
			}
			else {
				continue;
			}
		}
	}
	return count+tem;
}

int main() {
	char s[] = "abccccdd";
	printf("%d", longestPalindrome(s));
	system("pause");
	return 0;
}