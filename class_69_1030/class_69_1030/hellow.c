#include <stdio.h>
#include <stdlib.h>

int main()
{    
	//1kb=1000�ֽڣ�
	//1MB=һ�����ֽڣ�
	//1GB=ʮ���ֽڣ�

	//int  4���ֽ�(0-65535,��-32768~32767)
	int a = 0;
	//char 1���ֽڣ�0-255����-128~+127��
	char b = 0;
	//short 4���ֽ�
	short c = 0;

	//long 4���ֽ�
	long d = 0;
	//long long 8���ֽ�
	long long e = 0;
	//float 4���ֽ�
	float f = 0;
	//double 8���ֽڣ�0-42��9ǧ�򣬼�-21��~+21�ڣ�
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

