#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��ӡ������
void PrintTrigle() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k <= i; k++) {
			printf(" ");
		}
		for (int j = 0; j < 4 - i; j++) {
			printf("* ");
		}
		printf("\n");
	}
}

//��ʽת���϶�
int  Ftoc(int fahr) {
	int celsius = 0;
	celsius = (fahr - 32) * 5 / 9;
	return celsius;
}

//�����������λ��
int Displacement(int second) {
	int displacement = 0;
	displacement = 5 * second * second; 
	return displacement;
}

//�ֶκ���
float func(int x) {
	float y;
	if (x == 0) {
		y = 0;
	}
	else {
		y = (float)1/x;
	}
	return y;
}

//�ֶκ���2
float func1(int x) {
	float outnum;
	if (x >= 0) {
		outnum = (float)sqrt(x);
	}
	else {
		outnum =(float)(pow(x, 5) + 2 * x + (float)1 / x);
	}
	return outnum;
}

int main() {
	int x;
	scanf("%d", &x); 
	printf("%.2f\n", func1(x));
	system("pause");
	return 0;
}