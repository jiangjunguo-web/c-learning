#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//函数表达式求解
double func(int n) {
	double sum = 0;
	int mul = 1;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			mul = 1;
		}
		else {
			for (int j = 1; j < i; j++) {
				mul *= j;
			}
		}
		sum = sum + 1.0 / mul;
	}
	return sum;
}

//求素数程序
int Isprime(int n) {
	int count = 0;
	if (n == 1) {
		return 0;
	}
	else if (n == 2) {
		return 1;
	}
	else {
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				count++;
				break;
			} 
		}
		if (count == 0) {
			return 1;
		}
		else {
			return 0;
		}	
	}
}


//猴子吃桃
int Pealnum(int n) {
	int pealNum = 1;
	if (n == 1) {
		pealNum = 1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			pealNum = (pealNum + 1) * 2;
		}
	}
	return pealNum;
}


//兔子生崽问题
int RabbitBaby(int n) {
	int sum = 0;
	if (n == 1) {
		return sum = 1;
	}
	if (n == 2) {
		return sum = 1;
	}
	if (n > 2) {
		return sum = RabbitBaby(n - 1) + RabbitBaby(n - 2);
	}
}



int main(){
	int n = 7;
	int sum = RabbitBaby(n);
	printf("%d\n",sum);
	system("pause");
	return 0;
}