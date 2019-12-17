#include <stdio.h>
#include <stdlib.h>

void Reverse(char * str)

{

	int len = sizeof(str) / sizeof(str[0]) - 1;
	
	if (*str)

	{

		

		char tmp;



		tmp = str[0];

		str[0] = str[len];

		str[len] = '\0';

		Reverse(str + 1);

		str[len] = tmp;

	}

	for (int i = 0; i <= len; i++) {
		printf("%c", str[i]);
	}

}

int main() {
	char str[] = "hello bit";
	
	//在这里完成下面函数，参数自己设计，要求：使用指针
	Reverse(str);
	
	system("pause");
	return 0;
}