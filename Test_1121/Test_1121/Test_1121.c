#define  _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>

int math(int n, int k) {
		if (k == 1) {
			return n;
		}
		else {
			n = n * math(n, k - 1);
		}
}

int main() {
	int  n;
	int  k;
	printf("请输入底数n和指数k\n");
	scanf("%d%d",&n,&k);
	math(n, k);
	printf("结果为：%d\n", math(n, k));
    system ("pause");
    return 0;
}