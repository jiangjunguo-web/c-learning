#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//函数求解
double func(int m, int n) {
	double sum = 0;
	for (int i = m; i <= n; i++) {
		sum += (i*i + 1.0 / i);
	}
	return sum;
}


//函数数列求解2
double func2(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += (i / (i * 2.0 - 1))*pow(-1,i+1);
	}
	return sum;
}


//函数程序求解3
double func3(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += sqrt(i);
	}
	return sum;
}
//求解阶乘
int fat(int n) {
	int mul = 1;
	for (int i = 1; i <= n; i++) {
		mul *= i;
	}
	return mul;
}


//函数求解4
double fun4(int n) {
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += fat(i);
	}
	return sum;
}

int main() {
	int n =2;
	double sum = fun4(n);
	printf("%.2f\n",sum);
	system("pause"); 
	return 0;
}