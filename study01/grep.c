#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int len);
int strIdx(char s[], char f[]);

int main() {
	char pattern[] = "ha";
	char line[MAXLINE];
	while(getLine(line, MAXLINE) > 0) {
		if(strIdx(line, pattern) >= 0)
			puts(line);
	}
	return 0;
}


int getLine(char s[], int len) {
	int i, c;
	i = 0;
	while(--i < 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	return i;

}

int strIdx(char s[], char f[]) {
	int i, j, k;
	for(i = 0; s[i] != '\0'; i++) {
		for(j = 0, k = i; f[j] == s[k] && f[j] != '\0'; j++, k++);
		if(j > 0 && f[j] == '\0')
			return i;
	}
	return -1;
}
