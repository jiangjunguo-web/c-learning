#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//F to C 转换函数
void convet(int lower, int upper) {
	double t;
	if (lower <= upper) {
		for (int i = lower; i <= upper; i = i + 2) {
			t = (5 * (i - 32)) / 9.0;
			printf("F=%d      c=%.1f\n", i, t);
		}
	}
	else {
		printf("输入范围有误\n");
	}
	
}

//计算1+1/2+1/3...函数
double math1(int n) {
	double sum=0;
	for (int i = 1; i <= n; i++) {
		double x = 1.0/ i;
		sum = x + sum;
	}
	return sum;
}

//计算1+1/3+1/5...函数
double math2(int n) {
	double sum = 0;
	for (int i = 0; i < n; i = i++) {
		double x = 1.0 / (1 + i*2);
		sum = x + sum;
	}
	return sum;
}

////计算1-1/4+1/7...函数
double math3(int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		double x = pow(-1,i)*1.0 / (3*i+1);
		sum = x + sum;
	}
	return sum;
}




int main() {
	int n;
	scanf("%d", &n);
	printf("%f\n", math3(n));
	system("pause");
	return 0;
}