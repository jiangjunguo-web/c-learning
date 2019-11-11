#include <stdio.h>
#include <stdlib.h>

//求两个数的最大公约数
int main() {
	int a = 14;
	int b = 21;
	int temp, i, max_divisor;
	if (a < b) {
		temp = a;
	}
	else {
		temp = b;
	}
	for (i = 1; i <= temp; i++) {
		if (a%i == 0 & b%i == 0) {
			max_divisor = i;
		}		
	}
    printf("最大公约数：%d\n", max_divisor);
	system("pause");
}