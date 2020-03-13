#include <stdio.h>
#include <stdlib.h>

int reverse(int x){
	double result = 0;
	for (; x; x = x / 10) {
		result = result * 10;
		result += (x % 10);
	}
	if (result>INT_MAX || result<INT_MIN) {
		return 0;
	}
	else {
		return (int)result;
	}
}

int main() {
	int x = -2147483647;
	printf("%d", reverse(x));
	system("pause");
	return 0;
}