#define  _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>

int Fibonacci(int n) {
	 int result=0;
	 int a1 = 1;
	 int a2 = 1;
	 if (n < 3) {
	    return 1;
	    }
	else {
		for (int i = 3; i <= n; i++) {
			result = a1 + a2;
			a1 = a2;
			a2 = result;
		}
		return result;
	}
}

int Fibonacci1(int n) {
	int buf = 0;
	if (n < 3) {
		return 1;
	}
	else {
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
	}

}

int main() {
	int n;
	printf("������һ������\n");
	scanf("%d", &n);
	printf("�ǵݹ��%d��Ϊ��%d\n",n, Fibonacci(n));
	printf("�ݹ��%d��Ϊ��%d\n", n, Fibonacci1(n));
    system ("pause");
    return 0;
}