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
	
	//������������溯���������Լ���ƣ�Ҫ��ʹ��ָ��
	Reverse(str);
	
	system("pause");
	return 0;
}