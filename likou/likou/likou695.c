#include <stdio.h>
#include <stdlib.h>

void code(int** a ) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

}
int main() {
	int a[3][4] = { { 1, 1, 1, 1 },
					{ 3, 3, 3, 3 },
					{ 4, 4, 4, 4 } };

	int *p[3] = { NULL };
	for (int i = 0; i < 3; i++) {
		p[i] = a[i];
	}
	code(p);
	system("pause");
	return 0;
}