
//��ӡ1000��2000֮�������
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 1000;
	for (a; a <= 2000; a++)
	{
		if ((a % 4) == 0 & (a % 100) != 0 | (a % 400) == 0)
		{
			printf("%d\t", a);

		}

	}
	system("pause");
}

