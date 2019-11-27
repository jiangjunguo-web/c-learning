#include <stdio.h>
#include <stdlib.h>


int main() {
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k <= i; k++) {
			printf(" ");
		}
		for (int j = 0; j < 4 - i; j++) {
			printf("* ");
			}
		printf("\n");
	}

	system("pause");
	return 0;
}