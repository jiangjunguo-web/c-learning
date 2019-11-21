#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>


void reverse_string(char arr[4]) 
{
	if (*arr == '\0')
	{
		printf("%d", 1);;
	}
	else 
	{
		reverse_string(arr + 1);
	}
	printf("%c", arr);
}

int main() {
	char arr[4];
	printf("ÇëÊäÈë×Ö·û´®\n");
	scanf("%s", arr);
	reverse_string(arr);
    system ("pause");
    return 0;
}