#include <stdio.h>
#include <stdlib.h>

int myAtoi(char * str){
	if (str == NULL) {
		return 0;
	}
	else {
		long result = 0;
		int i = 0;
		int flag = 1;
		while (str[i] == ' ') {
			i++;
		}
		if (str[i] == '-') {
			flag = -1;
			i++;
		}
		else if (str[i] == '+') {
			flag = 1;
			i++;
		}
			for (; str[i]; i++) {
				if (str[i] >= '0' && str[i] <= '9') {
					result = result * 10 + str[i] - 0x30;
				}
				else {
					break;
				}
			
		}
		result = result * flag;
		if (flag == -1) {
			if (result < INT_MIN) {
				return INT_MIN;
			}
			else {
				return (int)result;
			}
		}
		else {
			if (result > INT_MAX) {
				return INT_MAX;
			}
			else {
				return (int)result;
			}
		}
	}
}

int main() {
	char str[] = " -42";
	printf("%d", myAtoi(str));
	system("pause");
	return 0;
}