#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>

void mul(int n) {
	int i = 1;
	
	for (i; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d*%d=%d\t",i,j,i*j);
		}
		printf("\n");
	}
}
int main() {
	int num;
	scanf("%d", &num);
	mul(num);
    system ("pause");
    return 0;
}