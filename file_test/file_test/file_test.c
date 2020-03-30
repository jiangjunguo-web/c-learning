#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int haha(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return haha(n - 1) + haha(n - 2);
	}
}


int main() {
	int i = 1;
	int N;
	scanf("%d", &N);

	while (i) {
		if (haha(i) > N) {
			break;
		}
		i++;
	}
	int a = 0;
	int b = 0;
	a = haha(i) - N;
	b = N - haha(i - 1);
	int c = (a > b) ? b : a;
	printf("%d", c);
	system("pause");
	return 0;
}
