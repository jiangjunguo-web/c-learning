#include <stdio.h>
#include <stdlib.h>

int main()
{    
	//1kb=1000字节；
	//1MB=一百万字节；
	//1GB=十亿字节；

	//int  4个字节(0-65535,即-32768~32767)
	int a = 0;
	//char 1个字节（0-255，即-128~+127）
	char b = 0;
	//short 4个字节
	short c = 0;

	//long 4个字节
	long d = 0;
	//long long 8个字节
	long long e = 0;
	//float 4个字节
	float f = 0;
	//double 8个字节（0-42亿9千万，即-21亿~+21亿）
	double g = 0;
	printf("int: %d\r\n", sizeof(a));
	printf("char: %d\r\n", sizeof(b));
	printf("short: %d\r\n", sizeof(c));
	printf("long: %d\r\n", sizeof(d));
	printf("long long: %d\r\n", sizeof(e));
	printf("float: %d\r\n", sizeof(f));
	printf("double: %d\r\n", sizeof(g));
	system("pause");
}

