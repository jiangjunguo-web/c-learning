#include <stdio.h>
#include <stdlib.h>

int GetNum(int num) {
	int bottle = 0;
	bottle = num / 2;
	int sum = num;
	if (num > 1) {
		num = bottle;
		sum = sum + GetNum(num);		
	}
	return sum;
}

int main() {
	int num = 20;
	int sum = GetNum(num);
	printf("%d\n",sum);
	system("pause");
	return 0;
}
