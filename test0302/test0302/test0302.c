#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[3][4] = { { 1, 2, 1, 2 }, { 1, 3, 1, 2 }, {1,1,1,2} };
	printf("%d", a[1][1] + 1);
	system("pause");
	return 0;

}