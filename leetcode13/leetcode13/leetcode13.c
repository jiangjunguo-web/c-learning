#include <stdio.h>
#include <stdlib.h>

//enum {
//	I = 1,
//	V = 5,
//	X = 10,
//	L = 50
//};

//int num(char* str) {
//	printf("%d", str[0]);
//	return 0;
//}
//
//int main() {
//	char a[] = "LVI";
//	int x = num(a);
//	system("pause");
//	return 0;
//}

enum weekday
{
	A, B, C, D, E, F, G
};
int main()
{
	enum  weekday   day = A;
	printf("%d", day + 1);
	system("pause");
	return 0;
}