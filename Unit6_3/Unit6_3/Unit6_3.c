#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//完数
int factorsum(int num) {
	int sum = 0;
	for (int i = 1; i < num; i++) {
		if (num%i == 0) {
			sum = sum + i;
		}
	}
	return sum;
}

//斐波那契数列
int Fibonacci(int m) {
	if (m == 1) {
		return 1;
	}
	if (m == 2) {
		return 1;
	}
	else {
		return Fibonacci(m - 1) + Fibonacci(m - 2);
	}
}


int IsPrime(int n) { 
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	else {
		for (int i = 3; i <= sqrt(n); i++) {
			if (n%i == 0) {
				return 0;
			}
		}
		return 1;
	}

}
//哥德巴赫猜想
void GeDeBaHe(int num) {
	int n = num / 2;
	int temp1 = 0;
	int temp2 = 0;
	int count = 0;
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j < i * 2; j++) {
			temp1 = 2 * j + 1;
			for (int k = j; k < i * 2; k++) {
				temp2 = 2 * k + 1;
				if (IsPrime(temp1) && IsPrime(temp2)) {
					if (temp2 + temp1 == i * 2) {
						count++;
						printf("%d=%d+%d   ",i*2,temp1,temp2);
						if (count == 5) {
							printf("\n");
							count = 0;
						}
						}
					}
				}
			}

	    }
	}

//逆序整数
void Reverse(int num) {
	for (int i = num; i > 0;i = i / 10) {
		printf("%d", i % 10);
	}
}

int main() {
	int num = 654321;
	Reverse(num);
	system("pause");
	return 0;
}