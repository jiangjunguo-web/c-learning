#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countCharacters(char ** words, int wordsSize, char * chars){
	int collen = 0;
	int len = strlen(chars) + 1;
	char* colsize;
	int* flag = (int*)malloc(len * 4);
	int k;
	int count = 0;
	int flag1 = 0;
	for (int i = 0; i<wordsSize; i++) {
		colsize = words[i];
		for (int z = 0; z<len; z++) {
			flag[z] = 0;
		}
		flag1 = 0;
		for (collen = 0; colsize[collen]; collen++);
		//每个单词的元素提出来比较
		for (int j = 0; j<collen; j++) {
			for (k = 0; k<len; k++) {
				if (words[i][j] == chars[k] && flag[k] == 0) {
					flag[k] = 1;
					break;
				}
				else {
					continue;
				}
			}
			if (k == len) {
				flag1 = 1;
				break;
			}
		}
		if (flag1 != 1) {
			count += collen;
		}
	}
	free(flag);
	return count;
}

int main() {
	char words[][9] = { "hello", "world", "leetcode" };
	char *a[3];
	for (int i = 0; i < 3; i++) {
		a[i] = words[i];
	}
	char chars[] = "welldonehoneyr";
	printf("%d", countCharacters(a, 3, chars));

	system("pause");
	return 0;
}